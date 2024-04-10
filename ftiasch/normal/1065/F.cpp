#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int n, limit, up[N], dp[N], size[N];
std::vector<int> children[N];

void dfs(int u, int depth) {
  if (children[u].empty()) {
    up[u] = std::max(depth - limit, 0);
    size[u] = 1;
  } else {
    up[u] = n;
    for (int v : children[u]) {
      dfs(v, depth + 1);
      if (depth + 1 <= up[v]) {
        dp[u] = std::max(dp[u], dp[v] + size[v]);
      } else {
        up[u] = std::min(up[u], up[v]);
        size[u] += size[v];
        dp[u] = std::max(dp[u], dp[v]);
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &limit);
  for (int i = 1, p; i < n; ++i) {
    scanf("%d", &p);
    children[p - 1].push_back(i);
  }
  dfs(0, 0);
  printf("%d\n", dp[0] + size[0]);
}