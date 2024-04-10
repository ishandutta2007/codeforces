// #include "debug.h"

#include <bits/stdc++.h>

const int N = 5000;
const int MOD = 998'244'353;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

int n, d, dp[N][N], sum[N];
std::vector<int> tree[N];

int dfs(int p, int u) {
  int m = 0;
  dp[u][0] = 1;
  for (int v : tree[u]) {
    if (v != p) {
      int subm = dfs(u, v);
      for (int j = m; j >= 0; --j) {
        int old = dp[u][j];
        dp[u][j] = 1LL * old * sum[v] % MOD;
        for (int k = 0; k <= subm && j + 1 + k <= d; ++k) {
          add(dp[u][std::max(j, k + 1)], 1LL * old * dp[v][k] % MOD);
        }
      }
      m = std::max(m, subm + 1);
    }
  }
  for (int i = 0; i <= m; ++i) {
    add(sum[u], dp[u][i]);
  }
  //   std::cout << KV(u + 1) << std::vector<int>(dp[u], dp[u] + (m + 1))
  //             << std::endl;
  return m;
}

int main() {
  scanf("%d%d", &n, &d);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(-1, 0);
  printf("%d\n", sum[0]);
}