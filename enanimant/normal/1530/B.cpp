/*
 * author:  ADMathNoob
 * created: 07/17/21 10:32:12
 * problem: https://codeforces.com/contest/1530/problem/B
 */

/*
g++ 1530B.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1530B.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

const vector<int> di = {1, 1, 0, -1, -1, -1, 0, 1};
const vector<int> dj = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    auto InRange = [&](int i, int j) {
      return (0 <= i && i < n && 0 <= j && j < m);
    };
    vector<string> a(n, string(m, '0'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bool ok = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
        for (int d = 0; d < 8; d++) {
          int ni = i + di[d];
          int nj = j + dj[d];
          if (InRange(ni, nj) && a[ni][nj] == '1') {
            ok = false;
          }
        }
        if (ok) {
          a[i][j] = '1';
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << '\n';
    }
  }
  return 0;
}