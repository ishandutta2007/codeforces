#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 18;

int n, m, coef[N], outs[N], result[N];
std::pair<int, int> dp[N + 1][1 << N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, u, v, w; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    coef[u] += w;
    coef[v] -= w;
    outs[u] |= 1 << v;
  }
  std::vector<int> order;
  for (int r = 0, cur = 0; r < n; ++r) {
    int v = 0;
    while ((cur >> v & 1) || (outs[v] & cur) != outs[v]) {
      v++;
    }
    order.push_back(v);
    cur |= 1 << v;
  }
  std::reverse(order.begin(), order.end());

  memset(dp, -1, sizeof(dp));
  dp[0][0] = {0, -1};
  for (int lv = 1; lv <= n; ++lv) {
    for (int mask = 0; mask < 1 << n; ++mask) {
      dp[lv][mask] = {dp[lv - 1][mask].first, 0};
    }
    for (int u : order) {
      for (int mask = 0; mask < 1 << n; ++mask) {
        if (~mask >> u & 1) {
          auto [value, ways] = dp[lv][mask];
          if (~value && (outs[u] & mask) == outs[u]) {
            int nvalue = value + coef[u] * lv;
            auto &new_dp = dp[lv][mask | 1 << u];
            if (!~new_dp.first || nvalue < new_dp.first) {
              new_dp = {nvalue, ways | 1 << u};
            }
          }
        }
      }
    }
  }
  for (int lv = n, mask = (1 << n) - 1; lv > 0; lv--) {
    int cur = dp[lv][mask].second;
    for (int u = 0; u < n; ++u) {
      if (cur >> u & 1) {
        result[u] = lv;
      }
    }
    mask ^= cur;
  }
  for (int u = 0; u < n; ++u) {
    printf("%d%c", result[u], " \n"[u + 1 == n]);
  }
}