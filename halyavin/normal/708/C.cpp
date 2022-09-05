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
  int half;
  std::vector<std::vector<int>> graph;
  std::vector<int> subSize;
  std::vector<int> parent;
  int root;
  int dfsSize(int v, int prev) {
    int res = 1;
    for (int nv : graph[v]) {
      if (nv != prev) {
        res += dfsSize(nv, v);
      }
    }
    parent[v] = prev;
    subSize[v] = res;
    return res;
  }
  void findCenter() {
    root = 0;
    dfsSize(0, -1);
    for (int i = 0; i < n; i++) {
      bool good = true;
      if (n - subSize[i] > half) {
        continue;
      }
      for (int nv : graph[i]) {
        if (nv == parent[i]) {
          continue;
        }
        if (subSize[nv] > half) {
          good = false;
          break;
        }
      }
      if (good) {
        root = i;
        break;
      }
    }
    dfsSize(root, -1);
  }

  std::vector<bool> answer;

  void dfsMain(int v, int prev, int maxOther) {
    if (maxOther >= n - subSize[v] - half) {
      answer[v] = true;
    }
    if (n - subSize[v] <= half) {
      maxOther = std::max(maxOther, n - subSize[v]);
    }
    int max1 = -1;
    int max2 = -1;
    for (int nv : graph[v]) {
      if (nv == prev) {
        continue;
      }
      if (subSize[nv] >= max1) {
        max2 = max1;
        max1 = subSize[nv];
      } else if (subSize[nv] > max2) {
        max2 = subSize[nv];
      }
    }
    for (int nv : graph[v]) {
      if (nv == prev) {
        continue;
      }

      if (subSize[nv] < max1) {
        dfsMain(nv, v, std::max(max1, maxOther));
      } else {
        dfsMain(nv, v, std::max(max2, maxOther));
      }
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    half = n / 2;
    graph.assign(n, std::vector<int>());
    for (int i = 0; i < n- 1; i++) {
      int from, to;
      in >> from >> to;
      from--;to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    subSize.assign(n, 0);
    parent.assign(n, -1);
    findCenter();
    answer.assign(n, false);
    dfsMain(root, -1, 0);
    answer[root] = true;
    for (int i = 0; i < n; i++) {
      if (answer[i]) {
        out << 1 << " ";
      } else {
        out << 0 << " ";
      }
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