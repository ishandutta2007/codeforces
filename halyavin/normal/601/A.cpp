#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

int dist(std::vector<std::vector<int>>& g, int c) {
  int n = g.size();
  std::vector<int> queue(n);
  std::vector<int> dist(n, -1);
  queue[0] = 0;
  dist[0] = 0;
  int bq = 0;
  int eq = 1;
  while (eq > bq) {
    int v = queue[bq];
    bq++;
    if (v == n - 1) {
      return dist[n - 1];
    }
    for (int i = 0; i < n; i++) {
      if (g[v][i] == c && dist[i] < 0) {
        dist[i] = dist[v] + 1;
        queue[eq] = i;
        eq++;
      }
    }
  }
  return dist[n - 1];
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int from, to;
    in >> from >> to;
    from--;to--;
    g[from][to] = 1;
    g[to][from] = 1;
  }
  int d1 = dist(g, 0);
  int d2 = dist(g, 1);
  if (d1 < 0 || d2 < 0) {
    out << -1 << std::endl;
  } else {
    out << std::max(d1, d2) << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}