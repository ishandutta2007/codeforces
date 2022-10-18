#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int dp[2][505][505], mod;

void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int main() {
  int n, m, b, a[505];
  cin >> n >> m >> b >> mod;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int cur = 0, next = 1;
  dp[0][0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j)
      for (int t = 0; t <= b; ++t)
        if (t + a[i] <= b)
          add(dp[cur][j + 1][t + a[i]], dp[cur][j][t]);
    for (int j = 0; j <= m; ++j) {
      for (int t = 0; t <= b; ++t) {
        dp[next][j][t] = dp[cur][j][t];
        // for (int k = 0; k + j <= m && t + a[i] * k <= b; ++k)
        //   add(dp[i + 1][j + k][t + a[i] * k], dp[i][j][t]);
      }
    }
    swap(cur, next);
    memset(dp[next], 0, sizeof(dp[next]));
  }

  int ans = 0;
  for (int j = 0; j <= b; ++j)
    add(ans, dp[cur][m][j]);
  cout << ans << endl;

  return 0;
}