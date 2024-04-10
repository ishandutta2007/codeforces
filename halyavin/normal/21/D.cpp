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

const int inf = 100000;

int rec(size_t gl, std::vector<int>& odd, std::vector<bool>& flags, std::vector<std::vector<int>>& graph) {
  if (gl == odd.size()) {
    return 0;
  }
  if (flags[gl]) {
    return rec(gl + 1, odd, flags, graph);
  }
  int res = 1000000000;
  for (size_t i = gl + 1; i < odd.size(); i++) {
    if (!flags[i]) {
      flags[i] = true;
      res = std::min(res, graph[odd[gl]][odd[i]] + rec(gl + 1, odd, flags, graph));
      flags[i] = false;
    }
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<std::vector<int>> graph(n, std::vector<int>(n, inf));
  for (int i = 0; i < n; i++) graph[i][i] = 0;
  std::vector<int> degs(n);
  int64_t sum = 0;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    in >> x >> y >> w;
    x--;y--;
    degs[x]++;
    degs[y]++;
    sum += w;
    graph[x][y] = std::min(graph[x][y], w);
    graph[y][x] = std::min(graph[y][x], w);
  }
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      for (size_t k = 0; k < n; k++) {
        if (graph[j][k] > graph[j][i] + graph[i][k]) {
          graph[j][k] = graph[j][i] + graph[i][k];
        }
      }
    }
  }
  for (size_t i = 0; i < n; i++) {
    if (graph[0][i] == inf && degs[i] != 0) {
      out << "-1" << std::endl;
      return;
    }
  }
  std::vector<int> odd;
  for (size_t i = 0; i < n; i++) {
    if ((degs[i] % 2) != 0) {
      odd.push_back(i);
    }
  }
  std::vector<bool> flags(odd.size());
  sum += rec(0, odd, flags, graph);
  out << sum << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}