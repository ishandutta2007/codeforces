#include <bits/stdc++.h>

namespace {

const int N = 500;
const int M = (N - 1) * N + 1;

int n, mod;

void add(int &x, int a) {
  x += a;
  if (x >= mod) {
    x -= mod;
  }
}

int fact[N], dp[M], sum[M + 1];

} // namespace

int main() {
  scanf("%d%d", &n, &mod);
  fact[n - 1] = 1;
  for (int i = n - 1; i > 0; -- i) {
      fact[i - 1] = fact[i] * (i + 1LL) % mod;
  }
  int offset = (n - 1) * n / 2;
  dp[offset] = sum[offset] = 1 % mod;
  sum[offset + 1] = 0;
  int result = 0;
  int m = 0;
  for (int k = 0; k < n; ++k) {
    int result_k = 0;
    for (int d = 1; d <= k; ++d) {
      if (d < m) {
        add(result_k,
            (k - d + 1LL) *
                (sum[offset - m] + mod - sum[offset + std::min(-d, m + 1)]) %
                mod);
      }
    }
    add(result, 1LL * fact[k] * result_k % mod);
    // x
    for (int s = -(m + k); s <= (m + k); ++s) {
      // s <= t <= s + k
      const int min = std::max(s, -m);
      const int max = std::min(s + k, m);
      if (min <= max) {
        dp[offset + s] = sum[offset + min];
        add(dp[offset + s], mod - sum[offset + max + 1]);
      }
    }
    m += k;
    sum[offset + m + 1] = 0;
    for (int s = m; s >= -m; --s) {
      sum[offset + s] = dp[offset + s];
      add(sum[offset + s], sum[offset + s + 1]);
    }
    // y
    for (int s = -m; s <= m; ++s) {
      // s - k <= t <= s
      const int min = std::max(s - k, -m);
      const int max = std::min(s, m);
      if (min <= max) {
        dp[offset + s] = sum[offset + min];
        add(dp[offset + s], mod - sum[offset + max + 1]);
      }
    }
    sum[offset + m + 1] = 0;
    for (int s = m; s >= -m; --s) {
      sum[offset + s] = dp[offset + s];
      add(sum[offset + s], sum[offset + s + 1]);
    }
  }
  printf("%d\n", result);
}