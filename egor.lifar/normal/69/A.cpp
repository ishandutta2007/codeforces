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
  int n, x[100], y[100], z[100];
  cin >> n;
  int k2 = 0, k1 = 0, k3 = 0;
  for(int i =0; i<n; i++){
    cin >> x[i] >> y[i] >> z[i];
    k1 += x[i];
    k2 += y[i];
    k3 += z[i];
  }
  if((k1 == k2 && k2 == k3) && k3  == 0){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}