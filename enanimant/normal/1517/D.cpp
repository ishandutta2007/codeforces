/*
 * author:  ADMathNoob
 * created: 04/23/21 10:33:27
 * problem: https://codeforces.com/contest/1517/problem/D
 */

/*
g++ 1517D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1517D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;
const int N = 505;

const int di[4] = {0, 0, 1, -1};
const int dj[4] = {1, -1, 0, 0};

int n, m, k;
int g[N][N][4];

int dp[N][N];
int new_dp[N][N];

bool InRange(int i, int j) {
  return (0 <= i && i < n && 0 <= j && j < m);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m - 1; j++) {
      cin >> g[i][j][0];
      g[i][j + 1][1] = g[i][j][0];
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j][2];
      g[i + 1][j][3] = g[i][j][2];
    }
  }
  if (k % 2 == 1) {
    memset(dp, -1, sizeof dp);
    // hack, but works since joining four 1111 (== -1) bytes yields -1
  } else {
    memset(dp, 0, sizeof dp);
    for (int it = 0; it < k / 2; it++) {
      memset(new_dp, 0x3f, sizeof new_dp);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (InRange(ni, nj)) {
              new_dp[ni][nj] = min(new_dp[ni][nj], dp[i][j] + 2 * g[i][j][d]);
            }
          }
        }
      }
      memcpy(dp, new_dp, sizeof dp);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << dp[i][j];
    }
    cout << '\n';
  }
  return 0;
}