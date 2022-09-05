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
  std::vector<std::vector<std::pair<int, int>>> graph;
  std::vector<int> cycles;
  std::vector<int> weight;
  int n;
  void dfs(int v) {
      int cur = weight[v];
      for (auto& edge : graph[v]) {
          if (weight[edge.first] == -1) {
              weight[edge.first] = cur ^ edge.second;
              dfs(edge.first);
          } else {
              int cycle = cur ^ edge.second ^ weight[edge.first];
              if (cycle != 0) {
                  cycles.push_back(cycle);
              }
          }
      }
  }
  void run(std::istream& in, std::ostream& out) {
      in >> n;
      graph.clear();
      graph.resize(n);
      int m;
      in >> m;
      for (int i = 0; i < m; i++) {
          int from, to, w;
          in >> from >> to >> w;
          from--;
          to--;
          graph[from].emplace_back(to, w);
          if (to != from) {
              graph[to].emplace_back(from, w);
          }
      }
      weight.assign(n, -1);
      weight[0] = 0;
      cycles.clear();
      dfs(0);
      int res = weight[n - 1];
      for (int bit = 30; bit >= 0; bit--) {
          int idx = -1;
          for (int i = 0; i < cycles.size(); i++) {
              if (((cycles[i] >> bit) & 1) != 0) {
                  idx = i;
              }
          }
          if (idx != -1) {
              int diff = cycles[idx];
              if (((res >> bit) & 1) != 0) {
                  res ^= diff;
              }
              if (idx != cycles.size() - 1) {
                  std::swap(cycles[idx], cycles[cycles.size() - 1]);
              }
              for (size_t i = 0; i + 1 < cycles.size(); i++) {
                  if (((cycles[i] >> bit) & 1) != 0) {
                      cycles[i] ^= diff;
                  }
              }
              cycles.resize(cycles.size() - 1);
          }
      }
      out << res << std::endl;
  }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}