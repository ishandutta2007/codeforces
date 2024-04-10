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
  cin >>s >> s2;
  int n = s.size();
  for(int i = 0; i < n ; i++){
    if(s[i] >= 'A' && s[i] <= 'Z'){
      s[i] = s[i] - ('A' - 'a');
    }
  }
  for(int i = 0; i < n ; i++){
    if(s2[i] >= 'A' && s2[i] <= 'Z'){
      s2[i] = s2[i] - ('A' - 'a');
    }
  }
  for(int i = 0; i < n ; i++){
    if(s[i] != s2[i]) {
      if(s[i] < s2[i]){
        printf("-1\n");
      } else {
        printf("1\n");
      }
      return 0;

    }
  }
  printf("0\n");
  return 0;
}