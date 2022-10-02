

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
  int j = 0;
  bool b[256];
  for(int i = 0; i<256; i++) {
      b[i] = false;
  }
  for(int i = 0; i<n; i++) {
      b[s[i]] = true;
  }
  for(int i = 0; i<256; i++) {
      if(b[i] == true) {
         j++;
      }
  }
  if(j % 2 == 1) {
    printf("IGNORE HIM!");
   } else {
    printf("CHAT WITH HER!");
   }


}