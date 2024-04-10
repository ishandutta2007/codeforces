#include <bits/stdc++.h>

const int N = 500001;
const int MOD = 998244353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

struct Constraint {
  int l, r, x;
} c[N];

bool operator<(const Constraint &a, const Constraint &b) { return a.r < b.r; }

int n, k, m, high[N], one[N], dp[N];

int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &c[i].l, &c[i].r, &c[i].x);
  }
  std::sort(c, c + m);
  int result = 1;
  while (k--) {
    memset(one, 0, sizeof(one));
    for (int j = 0; j < m; ++j) {
      if (c[j].x >> k & 1) {
        one[c[j].l - 1]++;
        one[c[j].r]--;
      }
    }
    int sum = dp[0] = 1;
    for (int i = 1, j = 0, runone = 0, runlow = 0; i <= n; ++i) {
      runone += one[i - 1];
      dp[i] = runone ? 0 : sum;
      add(sum, dp[i]);
      while (j < m && c[j].r == i) {
        if (~c[j].x >> k & 1) {
          while (runlow < c[j].l) {
            add(sum, MOD - dp[runlow++]);
          }
        }
        j++;
      }
    }
    result = static_cast<uint64_t>(result) * sum % MOD;
  }
  printf("%d\n", result);
}