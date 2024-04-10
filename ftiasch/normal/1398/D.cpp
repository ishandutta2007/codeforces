#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 201;

void update(long long &x, long long a) { x = std::max(x, a); }

int n, m, l, a[N], b[N], c[N];
long long dp[N][N][N];

int main() {
  scanf("%d%d%d", &n, &m, &l);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < l; ++i) {
    scanf("%d", c + i);
  }
  std::sort(a, a + n, std::greater<int>());
  std::sort(b, b + m, std::greater<int>());
  std::sort(c, c + l, std::greater<int>());
  for (int i = n; i >= 0; --i) {
    for (int j = m; j >= 0; --j) {
      for (int k = l; k >= 0; --k) {
        if (i < n) {
          update(dp[i][j][k], dp[i + 1][j][k]);
        }
        if (j < m) {
          update(dp[i][j][k], dp[i][j + 1][k]);
        }
        if (k < l) {
          update(dp[i][j][k], dp[i][j][k + 1]);
        }
        if (i < n && j < m) {
          update(dp[i][j][k], dp[i + 1][j + 1][k] + a[i] * b[j]);
        }
        if (i < n && k < l) {
          update(dp[i][j][k], dp[i + 1][j][k + 1] + a[i] * c[k]);
        }
        if (j < m && k < l) {
          update(dp[i][j][k], dp[i][j + 1][k + 1] + b[j] * c[k]);
        }
      }
    }
  }
  printf("%lld\n", dp[0][0][0]);
}