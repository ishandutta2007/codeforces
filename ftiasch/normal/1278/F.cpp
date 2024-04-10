#include <bits/stdc++.h>

namespace {

const int MOD = 998244353;
const int K = 5000;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int inv(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int dp[K + 1][K + 1];

} // namespace

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  dp[0][0] = 1;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j <= i; ++j) {
      add(dp[i + 1][j], 1LL * dp[i][j] * j % MOD);
      if (j < n) {
        add(dp[i + 1][j + 1], 1LL * dp[i][j] * (n - j) % MOD);
      }
    }
  }
  int inv_m = inv(m);
  int power = 1;
  int result = 0;
  for (int j = 0; j <= k; ++j) {
    add(result, 1LL * dp[k][j] * power % MOD);
    power = 1LL * power * inv_m % MOD;
  }
  printf("%d\n", result);
}