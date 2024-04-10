/*
 * author:  ADMathNoob
 * created: 04/23/21 10:33:27
 * problem: https://codeforces.com/contest/1517/problem/B
 */

/*
g++ 1517B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1517B.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 2e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<deque<int>> b(n, deque<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
      }
      sort(b[i].begin(), b[i].end());
    }
    vector<vector<int>> ret(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
      int mn = INF;
      int bid = -1;
      for (int i = 0; i < n; i++) {
        if (b[i][0] < mn) {
          mn = b[i][0];
          bid = i;
        }
      }
      for (int i = 0; i < n; i++) {
        if (i == bid) {
          ret[i][j] = b[i][0];
          b[i].pop_front();
        } else {
          ret[i][j] = b[i].back();
          b[i].pop_back();
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j > 0) {
          cout << ' ';
        }
        cout << ret[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}