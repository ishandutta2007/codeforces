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

bool dfs(int v, std::vector<int>& flags, const std::vector<std::vector<int>>& graph) {
  int nextFlags = -flags[v];
  for (int nv : graph[v]) {
    if (flags[nv] == 0) {
      flags[nv] = nextFlags;
      if (!dfs(nv, flags, graph)) {
        return false;
      }
    } else {
      if (flags[nv] != nextFlags) {
        return false;
      }
    }
  }
  return true;
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<std::pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    in >> edges[i].first >> edges[i].second;
    edges[i].first--;
    edges[i].second--;
    if (edges[i].first > edges[i].second) std::swap(edges[i].first, edges[i].second);
  }
  std::vector<std::vector<int>> graph(m, std::vector<int>());
  for (int i= 0; i<m; i++) {
    for (int j = i + 1; j < m; j++) {
      if (edges[j].first == edges[i].first || edges[j].first == edges[i].second) continue;
      if (edges[j].second == edges[i].first || edges[j].second == edges[i].second)continue;
      int count = 0;
      if (edges[j].first > edges[i].first && edges[j].first < edges[i].second) count++;
      if (edges[j].second > edges[i].first && edges[j].second < edges[i].second) count++;
      if (count == 1) {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }
  std::vector<int> res(m);
  for (int i = 0; i < m; i++) {
    if (res[i] == 0) {
      res[i] = 1;
      if (!dfs(i, res, graph)) {
        out << "Impossible" << std::endl;
        return;
      }
    }
  }
  for (int i = 0; i< m; i++) {
    if (res[i] < 0) {
      out << "i";
    } else {
      out << "o";
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}