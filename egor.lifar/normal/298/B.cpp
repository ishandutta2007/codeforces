#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int main(){

   int t, sx, sy, ex, ey, v=0;
   string s;
   scanf("%d %d %d %d %d", &t, &sx, &sy, &ex, &ey);
   cin >> s;
   int dx[255], dy[255];
   memset(dx, 0, sizeof(dx));
   memset(dy, 0, sizeof(dy));
   dy['N'] = 1;
   dy['S'] = -1;
   dx['W'] = -1;
   dx['E'] = 1;
   int x = sx- ex;
   int y = sy- ey;
   t = s.size();
   for(int i =0; i<t && (x != 0 || y != 0); i++) {
          v+=1;
          if (abs(x) > abs(x + dx[s[i]])){
              x += dx[s[i]];
          }
          if (abs(y) > abs(y + dy[s[i]])) {
             y += dy[s[i]];
          }
   }
  if (x == 0 && y == 0) {
     printf("%d\n", v);
  } else {
     printf("-1\n");
  }


}