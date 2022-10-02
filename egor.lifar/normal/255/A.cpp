

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
  int n, a[100];
  scanf("%d", &n);
  int x = 0, y = 0, z = 0;
  for(int i = 1; i<=n; i++){
    scanf("%d", &a[i]);
    if(i % 3 == 1 ){
      x+=a[i];
    }
    if(i % 3 == 2) {
      y+=a[i];
    }
    if(i % 3 == 0) {
      z+=a[i];
    }
  }
  if(x > y && x > z) {
    printf("chest");
  } else {
    if(y > x &&  y > z) {
      printf("biceps");
    }else{
      printf("back");
    }
  }

}