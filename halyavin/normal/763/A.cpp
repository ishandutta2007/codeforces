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
  std::vector<std::vector<int>> ans;
  std::vector<int> color;

  int dfs(int v, int prev, int& res) {
    if (res != -2) return res;
    res = color[v];
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv == prev) continue;
      int c = dfs(nv, v, ans[v][i]);
      if (res != c) {
        res = -1;
        break;
      }
    }
    return res;
  }

  bool good (int v) {
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (dfs(nv, v, ans[v][i]) == -1) {
        return false;
      }
    }
    return true;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    graph.assign(n, std::vector<int>());
    ans.assign(n, std::vector<int>());
    for (int i = 0; i < n- 1; i++) {
      int x, y;
      in >> x >> y;
      x--;y--;
      graph[x].push_back(y);
      ans[x].push_back(-2);
      graph[y].push_back(x);
      ans[y].push_back(-2);
    }
    color.resize(n);
    for (int i = 0; i < n; i++) {
      in >> color[i];
    }
    for (int i = 0; i < n; i++) {
      if (good(i)) {
        out << "YES" << std::endl;
        out << (i + 1) << std::endl;
        return;
      }
    }
    out << "NO" << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}