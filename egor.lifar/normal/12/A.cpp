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
  string  a[3];
  for(int i = 0; i < 3; i++){
      cin >> a[i];
  }
  for(int i = 0; i<3; i++){
   for(int j = 0; j < 3; j++){
        if(a[2 - i][2 - j] != a[i][j]){
          printf("NO\n");
          return 0;
        }
    }
  }
  printf("YES\n");
  return 0;
}