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
  std::vector<bool> university;
  std::vector<int64_t> sum;
  std::vector<int64_t> count;
  int n, k;
  void dfsSum(int v, int prev) {
    int64_t localSum = 0;
    int64_t localCount = 0;
    for (int nv : graph[v]) {
      if (nv == prev) {
        continue;
      }
      dfsSum(nv, v);
      localSum += sum[nv];
      localCount += count[nv];
    }
    localSum += localCount;
    if (university[v]) {
      localCount++;
    }
    sum[v] = localSum;
    count[v] = localCount;
  }

  int64_t dfs(int up, int v, int prev) {
    int64_t res = up;
    int maxSize = -1;
    int maxV = -1;
    for (int nv : graph[v]) {
      if (nv != prev) {
        if (count[nv] > maxSize) {
          maxV = nv;
          maxSize = count[nv];
        }
      }
    }
    if (maxV == -1) {
      return res;
    }
    if (maxSize <= k) {
      for (int nv : graph[v]) {
        if (nv != prev) {
          res += count[nv];
          res += sum[nv];
        }
      }
      return res;
    }
    for (int nv : graph[v]) {
      if (nv != prev && nv != maxV) {
        res+= count[nv];
        res += sum[nv];
        up += count[nv];
      }
    }
    if (university[v]) {
      up++;
    }
    res += dfs(up, maxV, v);
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> k;
    graph.assign(n, {});
    university.assign(n, false);
    for (int i = 0; i < 2 * k; i++) {
      int u;
      in >> u;
      university[u - 1] = true;
    }
    for (int i = 0; i < n- 1; i++) {
      int x, y;
      in >> x >> y;
      x--;y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    sum.assign(n, 0);
    count.assign(n, 0);
    dfsSum(0, -1);
    int64_t res = dfs(0, 0, -1);
    out << res << std::endl;
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}