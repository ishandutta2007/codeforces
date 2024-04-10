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

class TarjanBridgeFlags {
  const Graph& graph;
  std::vector<int> idx;
  std::vector<int> stack;
  std::vector<int> colors;
  std::vector<int> badEdges;
  int oddUp;
  int oddEdgeCount;
  int oddEdge;
  int oddVertex;

  TarjanBridgeFlags(const Graph& graph) :
      graph(graph),
      idx(graph.size(), -1),
      stack(),
      colors(graph.size(), -1),
      badEdges(),
      oddUp(0)
      { }

  std::pair<int, int> dfs(int v, int prev) {
    int curIdx = stack.size();
    stack.push_back(v);
    std::pair<int, int> res = {curIdx, curIdx};
    idx[v] = curIdx;
    int oddUpBefore = oddUp;
    int back_edge = -1;
    for (const std::pair<int, int>& edge : graph[v]) {
      int nv = edge.first;
      if (nv == prev) {
        back_edge = edge.second;
        continue;
      }
      if (idx[nv] > curIdx) {
        continue;
      }
      if (idx[nv] < 0) {
        colors[nv] = colors[v] ^ 1;
        std::pair<int, int> dfs_res = dfs(nv, v);
        res.first = std::min(res.first, dfs_res.first);
        res.second = std::min(res.second, dfs_res.second);
      } else {
        if (colors[nv] == colors[v]) {
          oddUp++;
          if (oddUp == 1) {
            oddEdge = edge.second;
            oddVertex = v;
            oddEdgeCount = 1;
          }
          badEdges.push_back(edge.second);
          res.second = std::min(res.second, idx[nv]);
        } else {
          res.first = std::min(res.first, idx[nv]);
          res.second = std::min(res.second, idx[nv]);
        }
      }
    }
    if (res.first == curIdx) {
      if (oddUpBefore == 0 && res.second < res.first && oddUp > oddEdgeCount) {
        oddEdge = back_edge;
        oddEdgeCount = oddUp;
        oddVertex = v;
      }
      for (size_t i = curIdx; i < stack.size(); i++) {
        idx[stack[i]] = graph.size();
      }
      stack.resize(curIdx);
      if (res.second < res.first) {
        badEdges.push_back(back_edge);
      }
    }
    return res;
  }

  void dfsClear(int v) {
    idx[v] = -1;
    colors[v] = -1;
    for (const std::pair<int, int>& edge : graph[v]) {
      if (idx[edge.first] >= 0) {
        dfsClear(edge.first);
      }
    }
  }

  std::pair<int, int> dfs2(int v, int prev) {
    int curIdx = stack.size();
    stack.push_back(v);
    std::pair<int, int> res = {curIdx, curIdx};
    idx[v] = curIdx;
    int back_edge = -1;
    for (const std::pair<int, int>& edge : graph[v]) {
      int nv = edge.first;
      if (edge.second == oddEdge && idx[nv] < 0) {
        continue;
      }
      if (nv == prev) {
        back_edge = edge.second;
        continue;
      }
      if (idx[nv] > curIdx) {
        continue;
      }
      if (idx[nv] < 0) {
        colors[nv] = colors[v] ^ 1;
        std::pair<int, int> dfs_res = dfs2(nv, v);
        res.first = std::min(res.first, dfs_res.first);
        res.second = std::min(res.second, dfs_res.second);
      } else {
        if (colors[nv] == colors[v]) {
          if (edge.second != oddEdge) {
            oddUp = -1;
          } else {
            oddUp++;
            badEdges.push_back(edge.second);
          }
          res.second = std::min(res.second, idx[nv]);
        } else {
          res.first = std::min(res.first, idx[nv]);
          res.second = std::min(res.second, idx[nv]);
        }
      }
    }
    if (res.first == curIdx) {
      for (size_t i = curIdx; i < stack.size(); i++) {
        idx[stack[i]] = graph.size();
      }
      stack.resize(curIdx);
      if (res.second < res.first) {
        badEdges.push_back(back_edge);
      }
    }
    return res;
  }

public:
  static std::vector<int> getComponents(const Graph& graph) {
    TarjanBridgeFlags t(graph);
    std::vector<int> result;
    for (size_t i = 0; i < graph.size(); i++) {
      if (t.idx[i] < 0) {
        t.colors[i] = 0;
        t.oddUp = 0;
        t.oddEdge = -1;
        t.oddVertex = -1;
        t.oddEdgeCount = 0;
        t.badEdges.clear();
        t.stack.clear();
        t.dfs(i, graph.size());
        if (t.oddUp == 0) {
          continue;
        }
        if (result.size() != 0) {
          return {};
        }
        if (t.oddUp == 1) {
          result = t.badEdges;
          continue;
        }
        t.dfsClear(i);
        t.colors[i] = 0;
        t.oddUp = 0;
        t.badEdges.clear();
        t.stack.clear();
        t.dfs2(t.oddVertex, graph.size());
        if (t.oddUp != 1) {
          return {};
        }
        result = t.badEdges;
      }
    }
    if (result.size() == 0) {
      int size = 0;
      for (size_t i = 0; i < graph.size(); i++) {
        size += graph[i].size();
      }
      size /= 2;
      result.resize(size);
      std::iota(result.begin(), result.end(), 0);
    }
    return result;
  }
};

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    in >> x >> y;
    x--;y--;
    graph[x].emplace_back(y, i);
    graph[y].emplace_back(x, i);
  }
  std::vector<int> edges = TarjanBridgeFlags::getComponents(graph);
  std::sort(edges.begin(), edges.end());
  out << edges.size() << std::endl;
  for (size_t i = 0; i < edges.size(); i++) {
    out << edges[i] + 1 << " ";
  }
  out << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}