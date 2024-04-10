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
  for(int i =0; i<n; i++){
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  for (int i = 0; i <n; i++){
     if(a[i] > a[0]){
      printf("%d", a[i]);
      return 0;
     }
  }
  printf("NO\n");
  return 0;
}