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
    int len = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
      if (s[i] == 'A') {
        ++len;
      } else {
        if (len == 0) {
          ++len;
        } else {
          --len;
        }
      }
    }
    cout << len << '\n';
  }
}