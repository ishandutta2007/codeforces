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

using Graph = std::vector<std::vector<std::pair<int, int>>>;

class TarjanBridge {
  using Components = std::vector<std::vector<int>>;
  const Graph& graph;
  Components components;
  std::vector<int> idx;
  std::vector<int> stack;
  std::vector<int> flags;
  int final;
  bool ans;
 public:
  TarjanBridge(const Graph& graph) :
      graph(graph),
      components(),
      idx(graph.size(), -1),
      flags(graph.size() + 1, -1),
      stack() { }

  int dfs(int v, int prev) {
    int curIdx = stack.size();
    stack.push_back(v);
    int res = curIdx;
    idx[v] = curIdx;
    for (auto& edge : graph[v]) {
      int nv = edge.first;
      if (nv == prev) {
        continue;
      }
      if (idx[nv] < 0) {
        res = std::min(res, dfs(nv, v));
      } else {
        res = std::min(res, idx[nv]);
      }
    }
    if (res == curIdx) {
      if (std::find(stack.begin() + curIdx, stack.end(), final) != stack.end()) {
        for (size_t i = curIdx; i < stack.size(); i++) {
          flags[stack[i]] = v;
        }
        flags[prev] = v;
        for (size_t i = curIdx; i < stack.size(); i++) {
          for (auto& edge : graph[stack[i]]) {
            if (flags[edge.first] == v && edge.second == 1) {
              ans = true;
            }
          }
        }
        flags[prev] = -1;
        final = prev;
      }
      for (size_t i = curIdx; i < stack.size(); i++) {
        idx[stack[i]] = graph.size();
      }
      stack.resize(curIdx);
    }
    return res;
  }

 public:

  bool getAns(int a, int b) {
    final = b;
    ans = false;
    dfs(a, graph.size());
    return ans;
  }
};


void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; i++) {
    int from, to, z;
    in >> from >> to >> z;
    from--;
    to--;
    g[from].emplace_back(to, z);
    g[to].emplace_back(from, z);
  }
  int a, b;
  in >> a >> b;
  a--;
  b--;
  TarjanBridge tarjan(g);
  if (tarjan.getAns(a, b)) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}