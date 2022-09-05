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
  std::vector<int> parent;
  std::vector<int> vSize;
  std::vector<int> vMaxChild;
  std::vector<int> center;
  std::vector<std::vector<int>> children;
  void dfs(int v) {
    int curMaxChild = 0;
    int curSize = 1;
    int maxChild = -1;
    for (int nv : children[v]) {
      dfs(nv);
      curSize += vSize[nv];
      if (vSize[nv] > curMaxChild) {
        curMaxChild = vSize[nv];
        maxChild = nv;
      }
    }
    vSize[v] = curSize;
    vMaxChild[v] = curMaxChild;
    if (curSize == 1) {
      center[v] = v;
      return;
    }
    int childCenter = center[maxChild];
    while (true) {
      int bigSize = curSize - vSize[childCenter];
      if (2 * bigSize <= curSize) break;
      childCenter = parent[childCenter];
    }
    center[v] = childCenter;
  }
  void run(std::istream& in, std::ostream& out) {
    int n, q;
    in >> n >> q;
    parent.assign(n, 0);
    parent[0] = -1;
    children.assign(n, std::vector<int>());
    for (int i = 1; i < n; i++) {
      in >> parent[i];
      parent[i]--;
      children[parent[i]].push_back(i);
    }
    vSize.resize(n);
    vMaxChild.resize(n);
    center.resize(n);
    dfs(0);
    for (int i = 0; i < q; i++) {
      int v;
      in >> v;
      v--;
      out << (center[v] + 1) << "\n";
    }
  }
};
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}