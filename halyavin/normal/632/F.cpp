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

struct Edge {
  int from;
  int to;
  int length;
  Edge(int from, int to, int length) : from(from), to(to), length(length) { }
};

struct Solution {
  std::vector<int> next;
  std::vector<int> size;
  std::vector<int> edges;

  int getRoot(int x) {
    if (next[x] == x) {
      return x;
    }
    int res = getRoot(next[x]);
    next[x] = res;
    return res;
  }

  void Union(int x, int y) {
    int rx = getRoot(x);
    int ry = getRoot(y);
    if (rx != ry) {
      if (size[rx] > size[ry]) std::swap(rx, ry);
      next[rx] = ry;
      size[ry] += size[rx];
      edges[ry] += edges[rx];
    }
    edges[ry]++;
  }

  void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        in >> g[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      if (g[i][i] != 0) {
        out << "NOT MAGIC" << std::endl;
        return;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (g[i][j] != g[j][i]) {
          out << "NOT MAGIC" << std::endl;
          return;
        }
      }
    }
    std::vector<Edge> edgesList;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        edgesList.emplace_back(j, i, g[i][j]);
      }
    }
    std::sort(edgesList.begin(),
              edgesList.end(),
              [](const Edge& left, const Edge& right) { return left.length < right.length; });
    next.resize(n);
    std::iota(next.begin(), next.end(), 0);
    size.assign(n, 1);
    edges.assign(n, 0);
    size_t prev = 0;
    for (size_t i = 0; i < edgesList.size(); i++) {
      if (edgesList[i].length != edgesList[prev].length) {
        for (size_t j = prev; j < i; j++) {
          int root = getRoot(edgesList[j].from);
          // Check for clique
          if (edges[root] != size[root] * (size[root] - 1) / 2) {
            out << "NOT MAGIC" << std::endl;
            return;
          }
        }
        prev = i;
      }
      Union(edgesList[i].from, edgesList[i].to);
    }
    // No need to check last group since the resulting graph is full.
    out << "MAGIC" << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}