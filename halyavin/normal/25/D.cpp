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

void dfs(int v, int prev,
         std::vector<std::vector<int>>& graph,
         std::vector<bool>& flags,
         std::vector<std::pair<int, int>>& edges) {
  flags[v] = true;
  for (int nv : graph[v]) {
    if (nv == prev) continue;
    if (flags[nv]) {
      if (v > nv) {
        edges.emplace_back(v, nv);
      }
    } else {
      dfs(nv, v, graph, flags, edges);
    }
  }
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; i++) {
    int from, to;
    in >> from >> to;
    from--;
    to--;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  std::vector<bool> flags(n, false);
  std::vector<int> starts;
  std::vector<std::pair<int, int>> edges;
  for (int i = 0; i < n; i++) {
    if (!flags[i]) {
      starts.push_back(i);
      dfs(i, -1, graph, flags, edges);
    }
  }
  out << starts.size() - 1 << std::endl;
  for (size_t i = 0; i < edges.size(); i++) {
    out << edges[i].first + 1 << " " << edges[i].second + 1 << " "
        << starts[0] + 1 << " " << starts[i + 1] + 1 << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}