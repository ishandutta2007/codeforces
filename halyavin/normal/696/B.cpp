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
  std::vector<int> parent;
  std::vector<std::vector<int>> graph;
  std::vector<int> subTreeSize;
  std::vector<double> ans;

  int dfsSubTreeSize(int v) {
    int res = 1;
    for (int nv : graph[v]) {
      res += dfsSubTreeSize(nv);
    }
    subTreeSize[v] = res;
    return res;
  }

  void dfsAnswer(int v, double res) {
    ans[v] = res;
    std::vector<int> childrenSizes(graph[v].size());
    for (size_t i = 0; i < graph[v].size(); i++) {
      childrenSizes[i] = subTreeSize[graph[v][i]];
    }
    int sum = std::accumulate(childrenSizes.begin(), childrenSizes.end(), 0);
    for (size_t i = 0; i < graph[v].size(); i++) {
      dfsAnswer(graph[v][i], res + (sum - childrenSizes[i]) * 0.5 + 1);
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    parent.resize(n);
    graph.assign(n, std::vector<int>());
    for (int i = 1; i < n; i++) {
      in >> parent[i];
      parent[i]--;
      graph[parent[i]].push_back(i);
    }
    subTreeSize.assign(n, 0);
    dfsSubTreeSize(0);
    ans.assign(n, 0);
    dfsAnswer(0, 1);
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