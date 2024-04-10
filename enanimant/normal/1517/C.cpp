/*
 * author:  ADMathNoob
 * created: 04/23/21 10:33:27
 * problem: https://codeforces.com/contest/1517/problem/C
 */

/*
g++ 1517C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1517C.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> sz(n);
  for (int i = 0; i < n; i++) {
    cin >> sz[i];
  }
  auto InRange = [&](int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < n);
  };
  vector<vector<int>> ret(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    int x = i;
    int y = i;
    ret[i][i] = sz[i];
    for (int it = 0; it < sz[i] - 1; it++) {
      if (InRange(x, y - 1) && ret[x][y - 1] == -1) {
        y -= 1;
        ret[x][y] = sz[i];
      } else {
        assert(InRange(x + 1, y));
        x += 1;
        ret[x][y] = sz[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << ret[i][j];
    }
    cout << '\n';
  }
  return 0;
}