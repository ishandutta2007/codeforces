#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, x, depth[N], result;
std::vector<int> tree[N];

void prepare(int p, int u) {
  depth[u] = ~p ? depth[p] + 1 : 0;
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v);
    }
  }
}

void dfs(int p, int u, int d) {
  if (d < depth[u]) {
    result = std::max(result, 2 * depth[u]);
  }
  for (int v : tree[u]) {
    if (v != p) {
      dfs(u, v, d + 1);
    }
  }
}

int main() {
  scanf("%d%d", &n, &x);
  x--;
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  prepare(-1, 0);
  dfs(-1, x, 0);
  printf("%d\n", result);
}