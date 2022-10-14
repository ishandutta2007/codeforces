#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;
const int Z = 6;

void update(int &x, int a) { x = std::max(x, a); }

int n, m, z, a[N], dp[N][Z];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &z);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    memset(dp, 0, sizeof(int) * (m + 1) * Z);
    dp[0][0] = a[0];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; 2 * j <= i && j <= z; ++j) {
        int idx = i - 2 * j;
        if (idx + 1 < n) {
          update(dp[i + 1][j], dp[i][j] + a[idx + 1]);
        }
        if (i + 1 == m && j < z && idx) {
          update(dp[i + 1][j + 1], dp[i][j] + a[idx - 1]);
        }
        if (i + 2 <= m && j < z && idx) {
          update(dp[i + 2][j + 1], dp[i][j] + a[idx - 1] + a[idx]);
        }
      }
    }
    int result = 0;
    for (int j = 0; j <= z; ++j) {
      update(result, dp[m][j]);
    }
    printf("%d\n", result);
  }
}