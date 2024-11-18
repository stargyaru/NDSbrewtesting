/*---------------------------------------------------------------------------------

	Basic template code for starting a DS app

---------------------------------------------------------------------------------*/
#include <nds.h>
#include <stdio.h>

#include "homescreen.h"

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG);

	consoleDemoInit();
	// consoleDemoInit();
	// iprintf("Hello World!");

	// int i = 0;
	// touchPosition touch;

	// videoSetMode(MODE_0_2D | DISPLAY_BG0_ACTIVE);

	// vramSetBankA(VRAM_A_MAIN_BG);
	int bg = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	dmaCopy(homescreenBitmap, bgGetGfxPtr(bg), homescreenBitmapLen);
	dmaCopy(homescreenPal, BG_PALETTE, homescreenPalLen);

	touchPosition touch;

	int conversation_state = 0;

	bool just_pressed = false;

	while(pmMainLoop()) {
		swiWaitForVBlank();

		scanKeys();
		if (keysDown()&KEY_START) break;

		bool touch_read = touchRead(&touch);

		if (just_pressed == false && touch_read) {
			just_pressed = true;
			conversation_state += 1;
		} else if (!touch_read) {
			just_pressed = false;
		}

		consoleClear();
		if (conversation_state == 0) {
			iprintf("pemis");
		} else if (conversation_state == 1) {
			iprintf("bepis");
		} else if (conversation_state == 2) { 
			iprintf("bopis");
		}
	}

	return 0;

}
