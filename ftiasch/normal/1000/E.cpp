#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n, m, head[N], to[N << 1], next[N << 1], depth[N], low[N], dp[N], result;
bool used[N];

void dfs(int u, int d) {
  low[u] = depth[u] = d;
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    if (!used[iterator >> 1]) {
      used[iterator >> 1] = true;
      int v = to[iterator];
      if (~depth[v]) {
        low[u] = std::min(low[u], depth[v]);
      } else {
        dfs(v, d + 1);
        low[u] = std::min(low[u], low[v]);
        int down = dp[v] + (depth[u] < low[v]);
        result = std::max(result, dp[u] + down);
        dp[u] = std::max(dp[u], down);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", to + i);
    to[i]--;
  }
  memset(head, -1, sizeof(head));
  for (int i = 0; i < m << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  memset(depth, -1, sizeof(depth));
  dfs(0, 0);
  printf("%d\n", result);
}