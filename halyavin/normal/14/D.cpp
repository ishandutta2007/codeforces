#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

using Graph = std::vector<std::vector<int>>;

void dfsMax(const Graph& graph, std::vector<int>& maxDown, std::vector<int>& maxPath, int v, int prev) {
  int maxNDown = 0;
  int maxNDown2 = 0;
  int maxNPath = 0;
  for (int next : graph[v]) {
    if (next == prev) continue;
    dfsMax(graph, maxDown, maxPath, next, v);
    if (maxDown[next] >= maxNDown) {
      maxNDown2 = maxNDown;
      maxNDown = maxDown[next];
    } else {
      maxNDown2 = std::max(maxNDown2, maxDown[next]);
    }
    maxNPath = std::max(maxNPath, maxPath[next]);
  }
  maxDown[v] = maxNDown + 1;
  maxPath[v] = std::max(maxNPath, maxNDown + maxNDown2);
}

int dfsAns(const Graph& graph, std::vector<int>& maxPath, int v, int prev, int path, int maxOther) {
  int res = path * maxOther;
  int maxNPath = 0;
  int maxNPath2 = 0;
  for (int next : graph[v]) {
    if (next == prev) continue;
    if (maxPath[next] >= maxNPath) {
      maxNPath2 = maxNPath;
      maxNPath = maxPath[next];
    } else {
      maxNPath2 = std::max(maxNPath2, maxPath[next]);
    }
  }
  for (int next : graph[v]) {
    if (next == prev) continue;
    if (maxPath[next] == maxNPath) {
      res = std::max(res, dfsAns(graph, maxPath, next, v, path + 1, std::max(maxOther, maxNPath2)));
    } else {
      res = std::max(res, dfsAns(graph, maxPath, next, v, path + 1, std::max(maxOther, maxNPath)));
    }
  }
  return res;
}

int calcAns(const Graph& graph, int root) {
  std::vector<int> maxDown(graph.size());
  std::vector<int> maxPath(graph.size());
  dfsMax(graph, maxDown, maxPath, root, -1);
  return dfsAns(graph, maxPath, root, -1, 0, 0);
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  Graph graph(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    in >> x >> y;
    x--;
    y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = std::max(ans, calcAns(graph, i));
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}