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
  cin >> n;
  int k = n / 4;
  int l = n % 4;
  for(int i =0; i<k; i++){
    printf("abcd");
  }
  if(l == 1){
    printf("a\n");
  }
  if(l == 2){
    printf("ab\n");
  }
  if(l == 3){
    printf("abc\n");
  }
  if(l == 0){
    printf("\n");
  }
  return 0;
}