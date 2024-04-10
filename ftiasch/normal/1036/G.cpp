#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;
const int K = 20;

int n, m, k, indeg[N], visited[N], match[K];
bool g[K][K];
std::vector<int> graph[N];

void dfs(int u) {
  if (!visited[u]) {
    visited[u] = true;
    for (int v : graph[u]) {
      dfs(v);
    }
  }
}

bool find(int u) {
  if (visited[u]) {
    return false;
  }
  visited[u] = true;
  for (int v = 0; v < k; ++v) {
    if (g[u][v] && (!~match[v] || find(match[v]))) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

void dfs2(int u) {
  if (!visited[u]) {
    visited[u] = true;
    for (int v = 0; v < k; ++v) {
      if (g[u][v]) {
        dfs2(match[v]);
      }
    }
  }
}

bool check() {
  std::vector<int> sources, sinks;
  for (int u = 0; u < n; ++u) {
    if (!indeg[u]) {
      sources.push_back(u);
    }
    if (graph[u].empty()) {
      sinks.push_back(u);
    }
  }
  k = sources.size();
  for (int i = 0; i < k; ++i) {
    memset(visited, 0, sizeof(visited));
    dfs(sources[i]);
    for (int j = 0; j < k; ++j) {
      g[i][j] = visited[sinks[j]];
    }
  }
  memset(match, -1, sizeof(match));
  for (int u = 0; u < k; ++u) {
    memset(visited, 0, sizeof(*visited) * k);
    if (!find(u)) {
      return false;
    }
  }
  for (int u = 0; u < k; ++u) {
    memset(visited, 0, sizeof(*visited) * k);
    dfs2(u);
    if (std::count(visited, visited + k, false) > 0) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, u, v; i < m; ++i) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    graph[u].push_back(v);
    indeg[v]++;
  }
  puts(check() ? "YES" : "NO");
}