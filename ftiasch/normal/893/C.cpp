#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

int n, m, c[N];
std::vector<int> graph[N];

int dfs(int u) {
  int result = c[u];
  c[u] = -1;
  for (int v : graph[u]) {
    if (~c[v]) {
      result = std::min(result, dfs(v));
    }
  }
  return result;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", c + i);
  }
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  long long result = 0;
  for (int u = 0; u < n; ++u) {
    if (~c[u]) {
      result += dfs(u);
    }
  }
  printf("%lld\n", result);
}