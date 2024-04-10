// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> ct(2);
    int ans = 0;
    for (char c : s) {
      if (c == '(') {
        ++ct[0];
      } else if (c == ')') {
        if (ct[0]) {
          --ct[0];
          ++ans;  
        }  
      } else if (c == '[') {
        ++ct[1];
      } else {
        if (ct[1]) {
          --ct[1];
          ++ans;  
        }  
      
      }  
    }
    cout << ans << '\n';
  }
}