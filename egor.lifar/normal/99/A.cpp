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
  bool b = false;
  for(int i = 0; i<n; i++){
    if(s[i] == '.'){
      b = true;
      if(s[i-1] == '9'){
        printf("GOTO Vasilisa.");
        return 0;
      } 
      if(s[i + 1] >= '5'){
        s[i-1] = s[i-1] + 1;
      }
    }
  }
  if(b == false){
    cout << s;
  } else {
    int i =0;
    while(s[i] != '.' ){
      printf("%c", s[i]);
      i++;
    }
  }
  return 0;
}