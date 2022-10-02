

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool test(int i, int j, string  *a){
   if(a[i][j-1] ==  a[i-1][j] && a[i-1][j] == a[i-1][j-1] && (a[i][j-1] == '#' || a[i][j-1] == '.')) {
     return true;
   }
  if(a[i][j+1] ==  a[i+1][j] && a[i+1][j] == a[i+1][j+1] && (a[i][j+1] == '#' || a[i][j+1] == '.')) {
     return true;
   }
    if(a[i][j-1] ==  a[i+1][j] && a[i+1][j] == a[i+1][j-1] && (a[i][j-1] == '#' || a[i][j-1] == '.')) {
     return true;
   }
    if(a[i][j+1] ==  a[i-1][j] && a[i-1][j] == a[i-1][j+1] && (a[i][j+1] == '#' || a[i][j+1] == '.')) {
     return true;
   }


   return false;
}


int main() {                               
    bool s = false;
    string a[6];
    for(int i = 0; i<6; i++) {
      a[0][i] = '0';
      a[i][0] = '0';
      a[5][i] = '0';
      a[i][5] = '0';
    }
    for(int i = 1; i<=4; i++) {
         cin >> a[i];
    }
    for(int i = 1; i<=4; i++) {
      for(int j =1; j<=4; j++) {
         if(test(i, j, a)) {
            s = true;
         }
      }
    }
    if(s) {
      printf("YES");
    } else{
      printf("NO");
    }
    return 0;
}