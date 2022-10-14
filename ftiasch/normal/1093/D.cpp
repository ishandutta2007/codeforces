#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;
const int MOD = 998'244'353;

int n, m, color[N], product[2];
std::vector<int> graph[N];

bool dfs(int u, int c) {
  if (~color[u]) {
    return color[u] == c;
  }
  color[u] = c;
  product[c] += product[c];
  if (product[c] >= MOD) {
    product[c] -= MOD;
  }
  for (int v : graph[u]) {
    if (!dfs(v, c ^ 1)) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int u = 0; u < n; ++u) {
      graph[u].clear();
    }
    for (int i = 0, a, b; i < m; ++i) {
      scanf("%d%d", &a, &b);
      a--;
      b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    memset(color, -1, sizeof(*color) * n);
    int result = 1;
    for (int u = 0; u < n; ++u) {
      if (!~color[u]) {
        product[0] = product[1] = 1;
        if (!dfs(u, 0)) {
          product[0] = product[1] = 0;
        }
        result = 1LL * result * (product[0] + product[1]) % MOD;
      }
    }
    printf("%d\n", result);
  }
}