/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "web_content.h"

/*
 *	FUnctions
 ***********************************************************************/

/* html page head */
void dom_head()
{

  printf(

  "<!DOCTYPE html>\n"
  "<html>\n"
  "	<head>\n"
  "		<title>Batalha Naval</title>\n"
  "		<meta charset=\"UTF-8\">\n"
  "   <script src=\"https://code.jquery.com/jquery-3.0.0.min.js\" integrity=\"sha256-JmvOoLtYsmqlsWxa7mDSLMwa6dZ9rrIdtrrVYRnDRH0=\" crossorigin=\"anonymous\"></script>\n"
  "		<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js\" integrity=\"sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS\" crossorigin=\"anonymous\"></script>\n"
  "   <script type=\"text/javascript\" src=\"../script/navalb.js\"></script>\n"
  "		<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\" integrity=\"sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7\" crossorigin=\"anonymous\">\n"
  "		<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css\" integrity=\"sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r\" crossorigin=\"anonymous\">\n"
  "		<link rel=\"stylesheet\" type=\"text/css\" href=\"../css/navalb.css\">\n"
  "		<link href=\"https://maxcdn.bootstrapcdn.com/font-awesome/4.6.3/css/font-awesome.min.css\" rel=\"stylesheet\" integrity=\"sha384-T8Gy5hrqNKT+hzMclPo118YTQO6cYprQmhrYwIiQ/3axmI1hQomh7Ud2hPOy8SP1\" crossorigin=\"anonymous\">\n"
  "		<link href=\"http://fonts.googleapis.com/css?family=Lato:400,700\" rel=\"stylesheet\" type=\"text/css\">\n"
  "	</head>\n"

  );

}

/* displays initial page */
void show_menu()
{

  dom_head();

  printf(

  "	<body id=\"menu\">\n"
  "		<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\">Batalha Naval</h1>\n"
  "			</div>\n"
  "			<div id=\"menu-container\">\n"
  "				<div id=\"header-menu\"></div>\n"
  "				<div id=\"buttons-container\">\n"
  "					<div id=\"single-player\" class=\"button-container\">\n"
  "           <a href=\"?mode=1&build=0&name=player1\">\n"
  "             <button type=\"sub\" class=\"button-dialog\" >Single Player</button>\n"
  "           </a>\n"
  "					</div>\n"
  "           <a href=\"?mode=2&build=0&name=player1\">\n"
  "             <button type=\"sub\" class=\"button-dialog\" >Multi Player</button>\n"
  "           </a>\n"
  "					</div>\n"
  "				</div>\n"
  "			</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"

  );

}

/* displays player board on screen */
void add_board(Players *player, int mode, int index, int link)
{
  int i, j;

    printf(

    "				<div id=\"map2\" class=\"ship-board\">\n"
    "					<div id=\"player-name\" class=\"name-container\">\n"
    "						<div id=\"name-input-feelings\">\n"
    "	            <input id=\"Player2-input\" class=\"input-properties\" placeholder=\"Insira seu nome\" autocomplete=\"off\" type=\"text\"></input>\n"
    "							<button type=\"button\" class=\"button-dialog name-dialog\"><a class=\"fa fa-angle-right\"></a></button>\n"
    "						</div>\n"
    "						<div class=\"player-name\">\n"
    "							<span id=\"player2-span\">%s</span>\n"
    "						</div>\n"
    "          </div>\n"
    "          <div id=\"map-container\" class=\"map-container-box\">\n"
    "            <table>\n"
    "              <tr class=\"map-line map-letters\">\n"
    "                <td class=\"map-n coor\"></td>\n"
    "                <td class=\"map-n  coor\">A</td>\n"
    "                <td class=\"map-n  coor\">B</td>\n"
    "                <td class=\"map-n  coor\">C</td>\n"
    "                <td class=\"map-n  coor\">D</td>\n"
    "                <td class=\"map-n  coor\">E</td>\n"
    "                <td class=\"map-n  coor\">F</td>\n"
    "                <td class=\"map-n  coor\">G</td>\n"
    "                <td class=\"map-n  coor\">H</td>\n"
    "                <td class=\"map-n  coor\">I</td>\n"
    "                <td class=\"map-n  coor\">J</td>\n"
    "              </tr>\n", player->name

    );

    for (i = 1; i <= MAP_SIZE; ++i) {
      printf(

      "              <tr class=\"map-line\">\n"
      "                <td class=\"map-n\">%d</td>\n", i

      );

      for (j = 1; j <= MAP_SIZE; ++j) {

        if (player->map[i - 1][j - 1].isVisible) { /* only if slot was hit */

          /* hard level compilation don't show boat types */
          if (LEVEL && player->map[i - 1][j - 1].presentation) {
            printf(

            "                <td class=\"map-column orange\">%c</td>\n", SHOT

            );
          } else {
            if (player->map[i - 1][j - 1].presentation == EMPTY) {
              printf(

              "                <td class=\"map-column light-blue\">%c</td>\n", player->map[i - 1][j - 1].presentation

              );
            } else {
              printf(

              "                <td class=\"map-column orange\">%c</td>\n", player->map[i - 1][j - 1].presentation

              );
            }
          }

        } else {
          if (link || (mode == 4 && index == 1))
            printf(

            "               <td class=\"map-column hit-pos\"><a href=\"navalb.cgi?mode=%d&player=%d&posx=%d&posy=%d\"><div>%c</div></a></td>\n", mode, index, j - 1, i - 1, WATER

            );
          else
            printf(

            "               <td class=\"map-column\">%c</td>\n", WATER

            );
        }

      }

      printf(

      "              </tr>\n"

      );
    }

    printf(

    "            </table>\n"
    "          </div>\n"

    );

    /* link slots */
    if (mode == 1 && index == 0) {
      printf(

      "					<div id=\"button233r243\" class=\"generate-map\">\n"
      "           <a href=\"?mode=%d&build=%d&name=%s\">\n"
      "					  	<button type=\"button\" class=\"button-dialog gen-map\">Gerar novo mapa</button>\n"
      "           </a>\n"
      "					</div>\n"
      "					<div id=\"button233r243\" class=\"generate-map\">\n"
      "						<a href=\"?mode=%d\">\n"
      "						 <button type=\"button\" class=\"button-dialog jogar\">Jogar</button>\n"
      "						</a>\n"
      "					</div>\n", mode, index, player->name, 4

      );
    } else  if (mode == 2 && index == 0) {
      printf(

      "					<div id=\"button233r243\" class=\"generate-map\">\n"
      "           <a href=\"?mode=%d&build=%d&name=%s\">\n"
      "					  	<button type=\"button\" class=\"button-dialog gen-map\">Gerar novo mapa</button>\n"
      "           </a>\n"
      "					</div>\n"
      "					<div id=\"button233r243\" class=\"generate-map\">\n"
      "						<a href=\"?mode=%d&build=%d&name=%s\">\n"
      "						 <button type=\"button\" class=\"button-dialog jogar\">Player 2</button>\n"
      "						</a>\n"
      "					</div>\n", mode, index, player->name, mode, (index + 1), "player2"

      );
    } else  if (mode == 2 && index == 1){
      printf(

      "					<div id=\"button233r243\" class=\"generate-map\">\n"
      "           <a href=\"?mode=%d&build=%d&name=%s\">\n"
      "					  	<button type=\"button\" class=\"button-dialog gen-map\">Gerar novo mapa</button>\n"
      "           </a>\n"
      "					</div>\n"
      "						<a href=\"?mode=%d&player=%d\">\n"
      "						 <button type=\"button\" class=\"button-dialog jogar\">Jogar</button>\n"
      "						</a>\n", mode, index, player->name, 3, (rand() % 2)

      );
    }

    printf(

    "        </div>\n"

    );
}

/* draw gameboard on screen */
void draw_board()
{
  int i, index, n;
  char *query;
  Players player;

  dom_head();

  printf(

  "	<body id=\"mapa\">\n"
  "		<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\"></h1>\n"
  "			</div>\n"
  "      <div id=\"board-container\">\n"

  );

  for (i = 0; i < 2; ++i) {
    get_log(&player, i);
    query = getenv("QUERY_STRING");
    if ((sscanf(query, "mode=3&player=%d", &index) == 1) && (index != i))
      add_board(&player, 3, i, 1);
    else if ((sscanf(query, "mode=3&player=%d", &index) == 1) && (index == i))
      add_board(&player, 3, i, 0);
    else if ((sscanf(query, "mode=%d", &n) == 1) && n == 4)
      add_board(&player, 4, i, 0);
  }

  printf(

  "  		</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"

  );
}

/* displayer winner screen */
void we_have_a_winner(char name[])
{
  int i;
  char winner[50] = "Ninguem"; /* if page is fired without winners */
  Players player;

  for (i = 0; i < 2; ++i) {
    get_log(&player, i);
    if (player.score == TOTAL_SLOTS)
      strcpy(winner, player.name);
  }
  dom_head();

  printf(

  "<body id=\"mapa\">\n"
  "<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\"></h1>\n"
  "			</div>\n"
  "      <div id=\"board-container\">\n"
  "				<div id=\"map2\" class=\"ship-board\">\n"
  "					<div id=\"player-name\" class=\"name-container\" style=\"min-height: 100px;\">\n"
  "						<div style=\"display: none;\" id=\"name-input-feelings\">\n"
  "	            <input id=\"Player2-input\" class=\"input-properties\" placeholder=\"Insira seu nome\" autocomplete=\"off\" type=\"text\">\n"
  "							<button type=\"button\" class=\"button-dialog name-dialog\"><a class=\"fa fa-angle-right\"></a></button>\n"
  "						</div>\n"
  "						<div style=\"text-align: center; display: block; padding: 25px; font-size: 30px;\" class=\"player-name\">\n"
  "							<span id=\"player2-span\" style=\"text-align: center;\">%s ganhou o jogo!!!</span>\n"
  "						</div>\n"
  "           <div id=\"button-container\">\n"
  "             <a href=\"navalb.cgi\">\n"
  "               <button type=\"sub\" class=\"button-dialog play-again\" style=\"\" >Jogar Novamente</button>\n"
  "             </a>\n"
  "           </div>\n"
  "         </div>\n"
  "        </div>\n"
  "     </div>\n"
  "   </div>\n"
  "</div>\n"
  "</body>\n"
  "</html>\n", winner
  );

}
