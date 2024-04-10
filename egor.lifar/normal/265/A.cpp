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
  string s, s2;
  cin >> s >> s2;
  char c = s[0];
  int k = 1;
  int n = s2.size();
  for(int i = 0; i < n; i++){
    if(s2[i] == c){
      c = s[k];
      k++;
    }
  }
  printf("%d", k);
  return 0;
}