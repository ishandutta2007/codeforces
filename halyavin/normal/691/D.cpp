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
  std::vector<std::vector<int>> graph;
  std::vector<bool> flags;
  std::vector<int>* set;

  void dfs(int v) {
    flags[v] = true;
    set->push_back(v);
    for (int nv : graph[v]) {
      if (!flags[nv]) {
        dfs(nv);
      }
    }
  }

  void run(std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    std::vector<int> ps(n);
    for (int i = 0; i < n; i++) {
      in >> ps[i];
    }
    graph.assign(n, std::vector<int>());
    for (int i = 0; i < m; i++) {
      int x, y;
      in >> x >> y;
      x--;
      y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    std::vector<std::vector<int>> sets;
    flags.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (!flags[i]) {
        sets.emplace_back();
        set = &sets.back();
        dfs(i);
      }
    }
    std::vector<int> ans(n);
    for (std::vector<int>& connectedSet : sets) {
      std::sort(connectedSet.begin(), connectedSet.end());
      std::vector<int> values(connectedSet.size());
      for (size_t i = 0; i < connectedSet.size(); i++) {
        values[i] = ps[connectedSet[i]];
      }
      std::sort(values.begin(), values.end(), std::greater<int>());
      for (size_t i = 0; i < connectedSet.size(); i++) {
        ans[connectedSet[i]] = values[i];
      }
    }
    for (int i = 0; i < n; i++) {
      out << ans[i] << " ";
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