#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n, deg[N], g_result;
std::vector<int> tree[N];

int dfs(int p, int u) {
  int result = deg[u] - 1;
  for (int v : tree[u]) {
    if (v != p) {
      int sub = dfs(u, v);
      g_result = std::max(g_result, result + sub);
      result = std::max(result, deg[u] - 1 + sub);
    }
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int u = 0; u < n; ++u) {
      tree[u].clear();
    }
    for (int i = 0, a, b; i < n - 1; ++i) {
      scanf("%d%d", &a, &b);
      a--;
      b--;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    for (int u = 0; u < n; ++u) {
      deg[u] = tree[u].size();
    }
    g_result = 0;
    dfs(-1, 0);
    printf("%d\n", g_result + 2);
  }
}