#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<std::vector<int>> tree(n);
    for (int i = 0, a, b; i < n - 1; ++i) {
      scanf("%d%d", &a, &b);
      a--;
      b--;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    std::vector<int> color(n);
    std::function<void(int, int, int)> dfs = [&](int p, int u, int c) -> void {
      color[u] = c;
      for (int v : tree[u]) {
        if (v != p) {
          dfs(u, v, c ^ 1);
        }
      }
    };
    dfs(-1, 0, 0);
    for (int i = 0; i < n; ++i) {
      int deg = tree[i].size();
      printf("%d%c", color[i] ? deg : -deg, " \n"[i + 1 == n]);
    }
  }
}