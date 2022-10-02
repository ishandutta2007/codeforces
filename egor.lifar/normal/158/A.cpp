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
  int n, k;
  scanf("%d %d", &n, &k);
  int a[101];
  int s = 0;
  for(int i =1; i<=n; i++){
    scanf("%d", &a[i]);
  }
  for(int i =1; i<=n; i++){
    if(a[i] >= a[k] && a[i] > 0){
      s++;
    }
  }
  printf("%d", s);
  return 0;
}