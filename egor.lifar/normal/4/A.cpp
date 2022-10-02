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
  int n;
  scanf("%d", &n);
  if(n % 2 == 0 && n != 2){
    printf("YES");
  } else {
    printf("NO");
  }
  return 0;
}