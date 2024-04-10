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
  int n;
  cin >> n;
  for(int i = 0; i<n; i++) {
    string s;
    cin >> s;
    int k = s.size();
    if(k <= 10){
      cout << s << "\n";
    } else {
      cout << s[0] << k - 2 << s[k - 1] << "\n";
    }
  }
  return 0;
}