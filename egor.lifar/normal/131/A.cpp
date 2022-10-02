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
  for(int i =1; i < n; i++){
    if(s[i] >= 'a' && s[i] <= 'z'){
      cout << s;
      return 0;
    }
  }
  for(int i =0; i < n; i++){
    if(s[i] >= 'a' && s[i] <= 'z'){
      s[i] = 'A' + s[i] - 'a';
    } else {
      s[i] = 'a' + s[i] - 'A';
    }
  }
  cout << s;
  return 0;
}