#include <bits/stdc++.h>

const int N = 5000;
const int M = 1000002;

int n, k, m, size, limit, a[N], timestamp[N];
std::vector<int> graph[N];
std::vector<std::pair<int, int>> bucket[M];

void dfs(int u)
{
  size ++;
  timestamp[u] = m;
  for (int v : graph[u]) {
    if (timestamp[v] != m) {
      dfs(v);
    }
  }
}

bool check()
{
  std::vector<int> vertices;
  int count = 0;
  for (int i = 0; i < M; i += m) {
    for (const auto& e : bucket[i]) {
      count ++;
      if (count > limit) {
        return false;
      }
      vertices.push_back(e.first);
      vertices.push_back(e.second);
    }
  }
  std::sort(vertices.begin(), vertices.end());
  vertices.erase(std::unique(vertices.begin(), vertices.end()), vertices.end());
  for (int v : vertices) {
    graph[v].clear();
  }
  for (int i = 0; i < M; i += m) {
    for (const auto& e : bucket[i]) {
      graph[e.first].push_back(e.second);
      graph[e.second].push_back(e.first);
    }
  }
  int need = 0;
  for (int v : vertices) {
    if (timestamp[v] != m) {
      size = 0;
      dfs(v);
      need += size - 1;
      if (need > k) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  limit = k * (k + 1) / 2;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n);
  for (int i = 0; i < M; ++ i) {
    bucket[i].reserve(limit + 1);
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = i + 1; j < n; ++ j) {
      auto& b = bucket[a[j] - a[i]];
      if (static_cast<int>(b.size()) <= limit) {
        b.emplace_back(i, j);
      }
    }
  }
  m = 1;
  while (!check()) {
    m ++;
  }
  printf("%d\n", m);
}