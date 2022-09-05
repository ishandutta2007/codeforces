#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <queue>

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> graph(n);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    in >> x >> y >> w;
    x--;
    y--;
    graph[x].emplace_back(y, w);
    graph[y].emplace_back(x, w);
  }
  std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>, std::greater<std::pair<int64_t, int>>> queue;
  const int64_t inf = 1LL << 62;
  std::vector<int64_t> distance(n, inf);
  std::vector<int> prev(n);
  distance[n - 1] = 0;
  queue.emplace(0LL, n - 1);
  while (!queue.empty()) {
    std::pair<int64_t, int> cur = queue.top();
    queue.pop();
    int v = cur.second;
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i].first;
      int weight = graph[v][i].second;
      if (distance[nv] > distance[v] + weight) {
        distance[nv] = distance[v] + weight;
        queue.emplace(distance[nv], nv);
        prev[nv] = v;
      }
    }
  }
  if (distance[0] == inf) {
    out << -1 << std::endl;
  } else {
    int cur = 0;
    while (true) {
      out << (cur + 1) << " ";
      if (cur == n - 1) break;
      cur = prev[cur];
    }
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}