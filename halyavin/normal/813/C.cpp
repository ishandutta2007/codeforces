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
  int x;
  std::vector<std::vector<int>> graph;
  std::vector<int> parent;
  std::vector<int> depth;
  std::vector<int> level;

  int dfs(int v, int prev) {
    if (prev >= 0) {
      level[v] = level[prev] + 1;
    } else {
      level[v] = 0;
    }
    int gl = 0;
    parent[v] = prev;
    for (int nv : graph[v]) {
      if (nv != prev) {
        dfs(nv, v);
        gl = std::max(gl, depth[nv] + 1);
      }
    }
    depth[v] = gl;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> x;
    x--;
    parent.assign(n, 0);
    depth.assign(n, 0);
    level.assign(n, 0);
    graph.assign(n, std::vector<int>());
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      in >> a >> b;
      a--;b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    dfs(0, -1);
    int ans = depth[x] + level[x];
    int steps = 0;
    while (x != 0) {
      x = parent[x];
      steps++;
      if (level[x] <= steps) break;
      ans = std::max(ans, depth[x] + level[x]);
    }
    out << 2 * ans << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}