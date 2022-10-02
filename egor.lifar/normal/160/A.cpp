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
  int n,  a[100];
  scanf("%d", &n);
  int s = 0;
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
    s+=a[i];
  }
  sort(a, a+n);
  double r = s;
  int k =0;
  for(int i =n-1; i>=0; i--){
    s-=a[i];
    k++;
    if(s < r / 2) {
      break;
    }
  }
  printf("%d", k);
  return 0;
}