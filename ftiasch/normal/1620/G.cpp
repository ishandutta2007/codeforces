#include <bits/stdc++.h>

const int N = 23;
const int C = 26;
const int MOD = 998'244'353;

int n, a[N][C], st[N + 1][C], dp[1 << N];
long long result;
char buffer[20001];

void prepare(int i, int mask) {
  if (i < n) {
    memcpy(st[i + 1], st[i], sizeof(int) * C);
    prepare(i + 1, mask);
    for (int j = 0; j < C; ++j) {
      st[i + 1][j] = std::min(st[i][j], a[i][j]);
    }
    prepare(i + 1, mask | 1 << i);
  } else {
    int &pd = dp[mask];
    pd = __builtin_parity(mask) ? 1 : MOD - 1;
    for (int j = 0; j < C; ++j) {
      pd = pd * (st[n][j] + 1LL) % MOD;
    }
  }
}

void summary(int i, int mask, int k, int sum_i) {
  if (i < n) {
    summary(i + 1, mask, k, sum_i);
    summary(i + 1, mask | 1 << i, k + 1, sum_i + (i + 1));
  } else {
    result ^= 1LL * k * sum_i * dp[mask];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    for (int j = 0; buffer[j]; ++j) {
      a[i][buffer[j] - 'a']++;
    }
  }
  for (int j = 0; j < C; ++j) {
    st[0][j] = INT_MAX;
  }
  prepare(0, 0);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int mask0 = 0; mask0 < 1 << n; ++mask0) {
      if (~mask0 >> i & 1) {
        int mask1 = mask0 | 1 << i;
        dp[mask1] += dp[mask0];
        if (dp[mask1] >= MOD) {
          dp[mask1] -= MOD;
        }
      }
    }
  }
  summary(0, 0, 0, 0);
  printf("%lld\n", result);
}