

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;




int main() {
  int a[5][5];
  int x, y;
  for(int i = 0; i<5; i++){
    for(int j = 0; j<5; j++) {
      scanf("%d", &a[i][j]);
      if(a[i][j] == 1) {
         x = j;
         y = i;
      }
    }
  }
  int k = abs(2-x) + abs(2-y);
  printf("%d", k);
}