#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, m;
int a[1002][1002];
int dp[4][1002][1002];

bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    dp[0][i][0] = a[i][0];
    if (i > 0) dp[0][i][0] += dp[0][i - 1][0];
    // cout << dp[0][i][0] << "  ";
    for (int j = 1; j < m; ++j) {
      dp[0][i][j] = a[i][j] + max(dp[0][i][j - 1], i > 0 ? dp[0][i - 1][j] : 0);
      // cout << dp[0][i][j] << "  ";
    }
    // cout << endl;
  }

  for (int i = 0; i < n; ++i) {
    dp[1][i][m - 1] = a[i][m - 1];
    if (i > 0) dp[1][i][m - 1] += dp[1][i - 1][m - 1];
    // cout << dp[0][i][0] << "  ";
    for (int j = m - 2; j >= 0; --j) {
      dp[1][i][j] = a[i][j] + max(dp[1][i][j + 1], i > 0 ? dp[1][i - 1][j] : 0);
      // cout << dp[0][i][j] << "  ";
    }
    // cout << endl;
  }

  for (int i = n - 1; i >= 0; --i) {
    dp[3][i][0] = a[i][0];
    if (i + 1 < n) dp[3][i][0] += dp[3][i + 1][0];
    // cout << dp[0][i][0] << "  ";
    for (int j = 1; j < m; ++j) {
      dp[3][i][j] = a[i][j] + max(dp[3][i][j - 1], i + 1 < n ? dp[3][i + 1][j] : 0);
      // cout << dp[0][i][j] << "  ";
    }
    // cout << endl;
  }

  for (int i = n - 1; i >= 0; --i) {
    dp[2][i][m - 1] = a[i][m - 1];
    if (i + 1 < n) dp[2][i][m - 1] += dp[2][i + 1][m - 1];
    // cout << dp[0][i][0] << "  ";
    for (int j = m - 2; j >= 0; --j) {
      dp[2][i][j] = a[i][j] + max(dp[2][i][j + 1], i + 1 < n ? dp[2][i + 1][j] : 0);
      // cout << dp[0][i][j] << "  ";
    }
    // cout << endl;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int i1 = 0; i1 < 2; ++i1)
        for (int i2 = 0; i2 < 2; ++i2)
          for (int o1 = 0; o1 < 2; ++o1)
            for (int o2 = 0; o2 < 2; ++o2) {
              if (i1 == 0 && o2 == 1 || i1 == 1 && i2 == 1 || i2 == 0 && o1 == 1 || o1 == 0 && o2 == 0) continue;
              int cur = 0;
              if (i1 == 0) {
                if (i == 0) continue;
                cur += dp[0][i - 1][j];
              } else {
                if (j == 0) continue;
                cur += dp[0][i][j - 1];
              }
              if (i2 == 0) {
                if (i + 1 == n) continue;
                cur += dp[3][i + 1][j];
              } else {
                if (j == 0) continue;
                cur += dp[3][i][j - 1];
              }
              if (o1 == 0) {
                if (j + 1 == m) continue;
                cur += dp[2][i][j + 1];
              } else {
                if (i + 1 == n) continue;
                cur += dp[2][i + 1][j];
              }
              if (o2 == 0) {
                if (j + 1 == m) continue;
                cur += dp[1][i][j + 1];
              } else {
                if (i == 0) continue;
                cur += dp[1][i - 1][j];
              }
              // cout << i1 << " " << i2 << "  " << o1 << "  " << o2 << endl;
              // cout << i << "  " << j << " " << cur << endl;
              ans = max(ans, cur);
            }
      // int cur = 0;
      // int u1 = 0, u2 = 0;
      // if (i + 1 < n)
      //   u1 = dp[0][i][j] + dp[3][i + 1][j];
      // if (i > 0)
      //   u2 = dp[0][i - 1][j] + dp[3][i][j];
      // cur += max(u1, u2);
      // u1 = 0, u2 = 0;
      // if (i + 1 < n)
      //   u1 = dp[1][i][j] + dp[2][i + 1][j];
      // if (i > 0)
      //   u2 = dp[1][i - 1][j] + dp[2][i][j];
      // cur += max(u1, u2);
      // ans = max(ans, cur - 2 * a[i][j]);
      // cout << i << "  " << j << " " << cur - 2 * a[i][j] << endl;
    }
  }
  printf("%d\n", ans);
  return 0;
}