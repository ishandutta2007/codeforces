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
  long long k, l, i;
  cin >> k >> l;
  i = 0;
  long long k2 = k;
  while(k < l){
     k = k * k2;
     i++;
  }
  if(k == l){
    printf("YES\n");
    cout << i << "\n";
  } else {
    printf("NO\n");
  }
  return 0;
}