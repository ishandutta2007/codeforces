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
  string s;
  cin >> s;
  int n = s.size();
  int k = 0;
  for(int i =0; i<n; i++){
    if(s[i] == '4' || s[i] == '7' ){
      k++;
    }
  }
  if(k == 7 || k == 4) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}