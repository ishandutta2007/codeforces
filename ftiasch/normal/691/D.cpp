#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  std::vector<std::vector<int>> graph(n);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<bool> visited(n);
  std::vector<int> values, indices;
  std::function<void(int)> dfs = [&](int u) {
    if (!visited[u]) {
      values.push_back(p[u]);
      indices.push_back(u);
      visited[u] = true;
      for (int v : graph[u]) {
        dfs(v);
      }
    }
  };
  for (int s = 0; s < n; ++s) {
    if (!visited[s]) {
      values.clear();
      indices.clear();
      dfs(s);
      std::sort(values.begin(), values.end(), std::greater<int>());
      std::sort(indices.begin(), indices.end());
      for (int i = 0; i < indices.size(); ++i) {
        p[indices[i]] = values[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", p[i], " \n"[i + 1 == n]);
  }
}