#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 2000;
const int MOD = 1'000'000'007;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

void update_max(int &x, int a) { x = std::max(x, a); }

int n, m, q, a[N], b[N], c[N], dp[2][N], offset[N];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", a + i, b + i, c + i);
    a[i]--;
    b[i]--;
  }
  int result = 0;
  std::fill(offset, offset + m, INT_MIN);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  // [1, n]
  for (int len = 0; len < n - 1; ++len) {
    int *old_dp = dp[len & 1];
    int *new_dp = dp[(len + 1) & 1];
    memset(new_dp, -1, sizeof(int) * n);
    for (int i = 0; i < m; ++i) {
      if (~old_dp[a[i]]) {
        update_max(offset[i], old_dp[a[i]] - len * c[i]);
        update_max(new_dp[b[i]], old_dp[a[i]] + c[i]);
      }
      if (~old_dp[b[i]]) {
        update_max(offset[i], old_dp[b[i]] - len * c[i]);
        update_max(new_dp[a[i]], old_dp[b[i]] + c[i]);
      }
    }
    add(result, *std::max_element(new_dp, new_dp + n) % MOD);
  }
  // -2e9 <= offset <= 2e9
  // for (int len = n + 1; len <= q; ++len) {
  //   std::pair<long long, int> max = {0, -1};
  //   for (int i = 0; i < m; ++i) {
  //     max = std::max(max, {1LL * c[i] * len + offset[i], i});
  //   }
  //   std::cout << KV(len) << max.second << std::endl;
  // }
  for (int i = 0; i < m; ++i) {
    int low = n;
    int high = q;
    for (int j = 0; j < m; ++j) {
      if (i != j) {
        // c[j] * x + offset[j] + (i < j) <= c[i] * x + offset[i]
        int k = c[j] - c[i];
        long long b = static_cast<long long>(offset[i]) - offset[j] - (i < j);
        // k * x <= b
        if (k == 0) {
          if (b < 0) {
            // no solution
            high = 0;
          }
        } else if (k > 0) {
          high = std::min(static_cast<long long>(high), b / k);
        } else {
          // (-k) * x >= (-b)
          low = std::max(static_cast<long long>(low), ((-b) + (-k - 1)) / (-k));
        }
      }
    }
    if (low <= high) {
      // std::cout << KV(i) << KV(low) << KV(high) << std::endl;
      int count = high - low + 1;
      int sum = 1LL * (low + high) * count / 2 % MOD;
      int r = (1LL * c[i] * sum + 1LL * offset[i] * count) % MOD;
      if (r < 0) {
        r += MOD;
      }
      add(result, r);
    }
  }
  printf("%d\n", result);
}