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

struct Solution {
  int n;
  std::vector<std::vector<int>> diagonals;
  std::vector<std::vector<int>> graph;
  std::vector<int> colors;
  std::vector<int> subtreeSizes;
  void build_graph() {
    std::vector<std::pair<int, int>> next(n);
    for (int i = 1; i < n; i++) {
      next[i].first = i - 1;
      next[i].second = -1;
    }
    graph.clear();
    diagonals[n - 1].insert(diagonals[n - 1].begin(), 0);
    for (int i = 2; i < n; i++) {
      if (diagonals[i].empty()) {
        continue;
      }
      if (diagonals[i][0] > i) {
        continue;
      }
      int firstNode = graph.size();
      for (int k = 0; k < diagonals[i].size(); k++) {
        int v = diagonals[i][k];
        if (v > i) break;
        int nv;
        if (k + 1 < diagonals[i].size()) {
          nv = diagonals[i][k + 1];
        } else {
          nv = i;
        }
        int node = graph.size();
        graph.emplace_back();
        for (int j = nv; j != v; j = next[j].first) {
          int other = next[j].second;
          if (other >= 0) {
            graph[node].push_back(other);
            graph[other].push_back(node);
          }
        }
        if (k > 0) {
          graph[node].push_back(node - 1);
          graph[node - 1].push_back(node);
        }
      }
      next[i].first = diagonals[i][0];
      next[i].second = firstNode;
    }
  }

  void dfs(int v, int prev) {
    int size = 1;
    for (int nv : graph[v]) {
      if (nv != prev && colors[nv] == -1) {
        dfs(nv, v);
        size += subtreeSizes[nv];
      }
    }
    subtreeSizes[v] = size;
  }

  void color_part(int v, int color) {
    dfs(v , -1);
    int prev = -1;
    int all = subtreeSizes[v];
    while (true) {
      int maxSize = 0;
      int maxNv = -1;
      for (int nv : graph[v]) {
        if (nv != prev && colors[nv] == -1) {
          if (subtreeSizes[nv] > maxSize) {
            maxSize = subtreeSizes[nv];
            maxNv = nv;
          }
        }
      }
      if (maxSize <= all / 2) {
        break;
      }
      prev = v;
      v = maxNv;
    }
    colors[v] = color;
    for (int nv : graph[v]) {
      if (colors[nv] == -1) {
        color_part(nv, color + 1);
      }
    }
  }

  void color_graph() {
    colors.assign(graph.size(), -1);
    subtreeSizes.resize(graph.size());
    color_part(0, 1);
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    diagonals.assign(n, std::vector<int>());
    int m;
    in >> m;
    for (int i = 0; i < m; i++) {
      int a, b;
      in >> a >> b;
      a--;
      b--;
      diagonals[a].push_back(b);
      diagonals[b].push_back(a);
    }
    for (std::vector<int>& d : diagonals) {
      std::sort(d.begin(), d.end());
    }
    build_graph();
    color_graph();
    for (int c : colors) {
      out << c << " ";
    }
    out << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}