#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

const int N = 50;
const int N2 = N << 1;
const int MOD = 998244353;

int inverse(int a) {
  return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inverse(MOD % a) % MOD;
}

int n, a[N], b[N], inv[N + 1], dp[N + 1][N2];

int main() {
  scanf("%d", &n);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }
  std::vector<int> values;
  for (int i = n; i--; ) {
    scanf("%d%d", a + i, b + i);
    values.push_back(a[i]);
    values.push_back(b[i] + 1);
  }
  std::sort(ALL(values));
  values.erase(std::unique(ALL(values)), values.end());
  int m = values.size() - 1;
  for (int j = 0; j <= m; ++ j) {
    dp[n][j] = 1;
  }
  for (int i = n; i--;) {
    for (int j = m; j--;) {
      dp[i][j] = dp[i][j + 1];
      int length = values[j + 1] - values[j];
      int ways = 1;
      for (int k = i; k < n && a[k] <= values[j] && values[j + 1] - 1 <= b[k];
           ++k) {
        ways = 1LL * ways * (length + k - i) % MOD * inv[k - i + 1] % MOD;
        dp[i][j] += 1LL * ways * dp[k + 1][j + 1] % MOD;
        if (dp[i][j] >= MOD) {
          dp[i][j] -= MOD;
        }
      }
    }
  }
  int result = dp[0][0];
  for (int i = 0; i < n; ++i) {
    result = 1LL * result * inverse(b[i] - a[i] + 1) % MOD;
  }
  printf("%d\n", result);
}