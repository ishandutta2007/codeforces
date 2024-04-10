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

const int64_t inf = 1LL << 62;
struct Solution {
  int n;
  std::vector<int64_t> diff;
  std::vector<std::vector<std::pair<int, int>>> graph;

  int64_t dfs(int v) {
    int64_t res = diff[v];
    for (auto& edge : graph[v]) {
      int64_t value = dfs(edge.first);
      if (value >= 0) {
        if (value > (inf - res) / edge.second) {
          res = inf;
        } else {
          res += value * edge.second;
        }
      } else {
        res += value;
      }
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    diff.assign(n, 0);
    for (int i =0; i < n; i++) {
      int64_t b;
      in >> b;
      diff[i] -= b;
    }
    for (int i = 0; i < n; i++) {
      int64_t a;
      in >> a;
      diff[i] += a;
    }
    graph.assign(n, std::vector<std::pair<int, int>>());
    for (int i = 1; i < n; i++) {
      int k, x;
      in >> x >> k;
      graph[x - 1].emplace_back(i, k);
    }
    int64_t ans = dfs(0);
    if (ans <= 0) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}