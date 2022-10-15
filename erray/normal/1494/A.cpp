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
    bool ok = false;
    int add[] = {-1, 1};
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b <  2; ++b) {
        for (int c = 0; c < 2; ++c) {
          bool can = true;
          int cur = 0;
          for (char cc : s) {
            cur += add[(cc == 'A' ? a : (cc == 'B' ? b : c))];
            can &= (cur >= 0);
          }
          ok |= can && !cur;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}