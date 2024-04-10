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
  std::vector<std::vector<int>> graph;
  std::vector<int> stats;
  int dfs(int v, int prev, int gl) {
    if (graph[v].size() == 1) {
      stats[gl]++;
      return gl;
    }
    int res = gl;
    for (int nv : graph[v]) {
      if (nv != prev) {
        res = std::max(res, dfs(nv, v, gl + 1));
      }
    }
    return res;
  }
  int getAns(int v) {
    int maxGl = dfs(v, 0, 0);
    int res = 0;
    int cur = 0;
    for (int i = 0; i <= maxGl; i++) {
      cur += stats[i];
      if (cur > 0) {
        cur--;
      }
      stats[i] = 0;
    }
    return cur + maxGl + 1;
  }
  void run(std::istream& in, std::ostream& out) {
    in >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int from, to;
      in >> from >> to;
      from--;
      to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    int res = 1;
    stats.resize(n);
    for (int v : graph[0]) {
      res = std::max(res, getAns(v));
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