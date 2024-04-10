#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Graph = std::vector<std::vector<int>>;

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

std::vector<int> sssp(int n, const Graph &graph, int s) {
  PQ<std::pair<int, int>> pq;
  std::vector<int> d(n, INT_MAX);
  pq.emplace(d[s] = 0, s);
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();
    if (du == d[u]) {
      for (int v : graph[u]) {
        if (d[v] > d[u] + 1) {
          pq.emplace(d[v] = d[u] + 1, v);
        }
      }
    }
  }
  return d;
}

int main() {
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);
  s--;
  t--;
  Graph graph(n);
  std::vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    a[i]--;
    b[i]--;
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }
  auto ds = sssp(n, graph, s);
  auto dt = sssp(n, graph, t);
  auto check = [&](int x, int y) {
    return std::min(ds[x] + dt[y], ds[y] + dt[x]) + 1 >= ds[t];
  };
  int result = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = x + 1; y < n; ++y) {
      result += check(x, y);
    }
  }
  for (int i = 0; i < m; ++i) {
    result -= check(a[i], b[i]);
  }
  printf("%d\n", result);
}