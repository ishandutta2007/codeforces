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
  std::vector<int> w;
  std::vector<int> sum;
  std::vector<int> ind3;
  int allSum;
  int allSum3;
  std::pair<int, int> ans;
  int root;
  bool dfs(int v, int prev) {
    int curInd3 = -1;
    int curSum = w[v];
    for (int nv : graph[v]) {
      if (nv != prev) {
        if (dfs(nv, v)) {
          return true;
        }
        curSum += sum[nv];
        if (ind3[nv] != -1) {
          if (curInd3 != -1) {
            ans.first = curInd3;
            ans.second = ind3[nv];
            return true;
          }
          curInd3 = ind3[nv];
        }
      }
    }
    if (curSum == 2 * allSum3 && curInd3 != -1 && prev != -1) {
      ans.first = v;
      ans.second = curInd3;
      return true;
    }
    if (curSum == allSum3) {
      curInd3 = v;
    }
    sum[v] = curSum;
    ind3[v] = curInd3;
    return false;
  }
  void run(std::istream& in, std::ostream& out) {
    in >> n;
    graph.assign(n, std::vector<int>());
    w.resize(n);
    sum.resize(n);
    ind3.resize(n);
    for (int i = 0; i < n; i++) {
      int prev;
      in >> prev >> w[i];
      if (prev == 0) {
        root = i;
      } else {
        prev--;
        graph[prev].push_back(i);
        graph[i].push_back(prev);
      }
    }
    allSum = std::accumulate(w.begin(), w.end(), 0);
    if (allSum % 3 != 0) {
      out << -1 << std::endl;
      return;
    }
    allSum3 = allSum / 3;
    if (!dfs(root, -1)) {
      out << -1 << std::endl;
    } else {
      out << (ans.first + 1) << " " << (ans.second + 1) << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}