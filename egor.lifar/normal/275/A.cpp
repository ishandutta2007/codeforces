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
  int b[5][5];
  for(int i =1; i<4; i++) {
    for(int j =1; j<4; j++){
      scanf("%d", &b[i][j]);
    }
  }
  for(int i =1; i<4; i++) {
    for(int j =1; j<4; j++){
      a[i][j] = 1;
    }
  }
  for(int i =1; i<4; i++) {
    for(int j =1; j<4; j++){
      if(b[i][j] % 2 == 1) {
        a[i][j] = 1 - a[i][j];
        a[i-1][j] = 1 - a[i-1][j];
        a[i][j-1] = 1 - a[i][j-1];
        a[i+1][j] = 1 - a[i+1][j];
        a[i][j+1] = 1 - a[i][j+1];
      }
    }
  }
  for(int i =1; i<4; i++) {
     for(int j =1; j<4; j++){
      printf("%d", a[i][j]);
     }
     printf("\n");
  }
  return 0;
}