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
  std::vector<int> weights;
  std::vector<std::vector<std::pair<int, int64_t>>> graph;

  int dfs(int v, int prev, int64_t sum) {
    int res = 1;
    for (std::pair<int, int64_t>& edge : graph[v]) {
      int nv = edge.first;
      int64_t cost = edge.second;
      if (nv == prev) continue;
      int64_t sumNV = cost + sum;
      if (sumNV <= weights[nv]) {
        res += dfs(nv, v, std::max(int64_t(0), sumNV));
      }
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
      in >> weights[i];
    }
    graph.clear();
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int p;
      int64_t c;
      in >> p >> c;
      p--;
      graph[i + 1].emplace_back(p, c);
      graph[p].emplace_back(i + 1, c);
    }
    int answer = n - dfs(0, -1, 0);
    out << answer << "\n";
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}