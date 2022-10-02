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
  string a;
  cin >> a;
  int n = a.size();
  bool b = false;
  for(int i =0; i<n; i++){
    if(i <= n - 7 && a[i] == a[i+1] && a[i + 1] == a[i + 2] && a[i] == a[i + 3] && a[i] == a[i + 4] && a[i] == a[i + 5] && a[i] == a[i + 6]){
      b = true;
      break;
    }
  }
  if(b){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}