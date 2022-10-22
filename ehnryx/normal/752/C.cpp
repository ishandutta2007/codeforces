#include <iostream>
using namespace std;

#define UPLEFT 1
#define UPRIGHT 2
#define DOWNLEFT 3
#define DOWNRIGHT 4
#define UP 5
#define LEFT 6
#define DOWN 7
#define RIGHT 8

int main() {
   int len, dir, points;
   string com;
   cin >> len >> com;
   for (int i = dir = points = 0; i < len; i++) {
      switch (com[i]) {
      case 'R':
         if (!dir)
            dir = RIGHT;
         else if (dir == UPLEFT || dir == DOWNLEFT || dir == LEFT) {
            points++;
            dir = RIGHT;
         }
         else if (dir == UP)
            dir = UPRIGHT;
         else if (dir == DOWN)
            dir = DOWNRIGHT;
         break;
      case 'L':
         if (!dir)
            dir = LEFT;
         else if (dir == UPRIGHT || dir == DOWNRIGHT || dir == RIGHT) {
            points++;
            dir = LEFT;
         }
         else if (dir == UP)
            dir = UPLEFT;
         else if (dir == DOWN)
            dir = DOWNLEFT;
         break;
      case 'U':
         if (!dir)
            dir = UP;
         else if (dir == DOWNRIGHT || dir == DOWNLEFT || dir == DOWN) {
            points++;
            dir = UP;
         }
         else if (dir == RIGHT)
            dir = UPRIGHT;
         else if (dir == LEFT)
            dir = UPLEFT;
         break;
      case 'D':
         if (!dir)
            dir = DOWN;
         else if (dir == UPRIGHT || dir == UPLEFT || dir == UP) {
            points++;
            dir = DOWN;
         }
         else if (dir == RIGHT)
            dir = DOWNRIGHT;
         else if (dir == LEFT)
            dir = DOWNLEFT;
         break;
      }
   }
   if (dir)
      points++;
   cout << points << endl;
   return 0;
}