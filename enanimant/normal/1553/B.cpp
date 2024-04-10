/*
 * author:  ADMathNoob
 * created: 07/22/21 10:35:08
 * problem: https://codeforces.com/contest/1553/problem/B
 */

/*
g++ 1553B.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1553B.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size();
    int m = (int) t.size();
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int len = j - i + 1;
        if (len > m) {
          continue;
        }
        string p = s.substr(i, len);
        if (len + j < m) {
          continue;
        }
        for (int k = j - 1; k >= j - (m - len); k--) {
          p += s[k];
        }
        if (p == t) {
          ok = true;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}