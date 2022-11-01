/*
 * author:  ADMathNoob
 * created: 06/13/21 11:35:03
 * problem: https://codeforces.com/contest/1534/problem/A
 */

/*
g++ 1534A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1534A.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        a[i][j] = (s[j] == 'R' ? 0 : s[j] == 'W' ? 1 : -1);
      }
    }
    bool done = false;
    for (int rot = 0; rot < 2; rot++) {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          ok &= (a[i][j] == (i + j + rot) % 2 || a[i][j] == -1);
        }
      }
      if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            cout << "RW"[(i + j + rot) % 2];
          }
          cout << '\n';
        }
        done = true;
        break;
      }
    }
    if (!done) {
      cout << "NO\n";
    }
  }
  return 0;
}