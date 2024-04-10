#line 1 "sol.cpp"
#include <bits/stdc++.h>

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::vector<std::pair<int, long long>>> graph(n);
  for (int i = 0, a, b; i < m; ++i) {
    long long c;
    scanf("%d%d%lld", &a, &b, &c);
    a--;
    b--;
    c <<= 1;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }
  std::vector<long long> dist(n);
  PQ<std::pair<long long, int>> pq;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &dist[i]);
    pq.emplace(dist[i], i);
  }
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();
    if (du == dist[u]) {
      for (auto [v, w] : graph[u]) {
        if (dist[v] > dist[u] + w) {
          pq.emplace(dist[v] = dist[u] + w, v);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", dist[i], " \n"[i + 1 == n]);
  }
}