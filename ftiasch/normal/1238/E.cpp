#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;
const int M = 20;

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

int n, m, cnt[M][M], sum[M][1 << M], dp[1 << M];
char s[N + 1];

int main() {
  scanf("%d%d%s", &n, &m, s);
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] != s[i]) {
      int a = s[i - 1] - 'a';
      int b = s[i] - 'a';
      cnt[a][b]++;
      cnt[b][a]++;
    }
  }
  for (int i = 0; i < M; ++i) {
    sum[i][0] = 0;
    for (int mask = 1, j = 0; mask < 1 << m; ++mask) {
      j += (mask >> (j + 1) & 1);
      sum[i][mask] = sum[i][mask ^ (1 << j)] + cnt[i][j];
    }
  }
  memset(dp, -1, sizeof(int) << m);
  dp[0] = 0;
  int full = (1 << m) - 1;
  for (int mask = 0; mask < 1 << m; ++mask) {
    int pos = __builtin_popcount(mask);
    for (int i = 0; i < m; ++i) {
      if (~mask >> i & 1) {
        int comp = full ^ mask ^ (1 << i);
        update(dp[mask | 1 << i],
               dp[mask] + pos * sum[i][mask] - pos * sum[i][comp]);
      }
    }
  }
  printf("%d\n", dp[full]);
}