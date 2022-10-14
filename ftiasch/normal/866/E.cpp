#include <bits/stdc++.h>

using LL = long long;

const int N = 14;
const LL INF = 1LL << 56;

int n, d[N], e[N], sum[1 << N];
char buffer[N + 1];
LL result, dp[1 << N];

void update(LL &x, LL a) { x = ~x ? std::min(x, a) : a; }

void dfs(int i, int es, int ed) {
  if (~i) {
    e[i] = d[i] + ed;
    dfs(i - 1, es, 0);
    if (es && i) {
      e[i] = d[i] + ed - 16;
      dfs(i - 1, es - 1, 1);
    }
  } else if (!es && 0 <= e[0] && e[0] < 16) {
    // sum{e[i]} = 0
    sum[0] = 0;
    for (int msk = 1; msk < 1 << n; ++msk) {
      int i = __builtin_ctz(msk);
      sum[msk] = sum[msk ^ 1 << i] + e[i];
    }
    memset(dp, -1, sizeof(*dp) << n);
    dp[1] = 0;
    for (int msk = 1; msk < 1 << n; ++msk) {
      LL s = sum[msk];
      if (~dp[msk] && 0 <= s && s < 16) {
        for (int i = 0; i < n; ++i) {
          if (~msk >> i & 1) {
            update(dp[msk | 1 << i], dp[msk] | s << (n - 1 - i << 2));
          }
        }
      }
    }
    LL r = dp[(1 << n) - 1];
    if (~r) {
      result = std::min(result, r);
    }
  }
}

LL solve() {
  n = strlen(buffer);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    d[i] = islower(buffer[i]) ? buffer[i] - 'a' + 10 : buffer[i] - '0';
    sum += d[i];
  }
  if (sum % 15 != 0) {
    return INF;
  }
  result = INF;
  dfs(n - 1, sum / 15, 0);
  return result;
}

int main() {
  while (scanf("%s", buffer) == 1) {
    auto result = solve();
    if (result < INF) {
      for (int i = n - 1; i >= 0; --i) {
        int digit = result >> (i << 2) & 15;
        putchar(digit < 10 ? '0' + digit : 'a' + digit - 10);
      }
      puts("");
    } else {
      puts("NO");
    }
  }
}