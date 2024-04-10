#include <bits/stdc++.h>

const int N = 200'000;

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int n, m;
long long dist[N << 2];
std::vector<std::pair<int, int>> graph[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, a, b, c; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }
  memset(dist, -1, sizeof(dist));
  PQ<std::pair<long long, int>> pq;
  pq.emplace(dist[3] = 0, 3);
  auto update = [&](int s, long long d) {
    if (dist[s] == -1 || dist[s] > d) {
      pq.emplace(dist[s] = d, s);
    }
  };
  while (!pq.empty()) {
    auto [dists, s] = pq.top();
    pq.pop();
    if (dists == dist[s]) {
      int u = s >> 2;
      s &= 3;
      for (auto [v, w] : graph[u]) {
        int sv = v << 2 | s;
        update(sv, dists + w);
        if (s & 1) {
          update(sv & ~1, dists);
        }
        if (s & 2) {
          update(sv & ~2, dists + w + w);
        }
        if (s == 3) {
          update(sv & ~3, dists + w);
        }
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    printf("%lld%c", dist[i << 2], " \n"[i + 1 == n]);
  }
}