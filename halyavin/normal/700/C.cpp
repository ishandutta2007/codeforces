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

using Edge = std::pair<int, int>;

int vertex(const Edge& edge) {
  return edge.first;
}

int edgeIdx(const Edge& edge) {
  return edge.second;
}

struct TarjanFindEdges {
  using Graph = std::vector<std::vector<Edge>>;
  using ComponentNums = std::vector<int>;
  const Graph& graph;
  std::vector<std::pair<int, int>>& edges;
  ComponentNums components;
  std::vector<int> idx;
  std::vector<int> stack;
  int component;

  TarjanFindEdges(const Graph& graph, std::vector<std::pair<int, int>>& edges) :
      graph(graph),
      edges(edges),
      components(graph.size(), -1),
      idx(graph.size(), -1),
      stack(),
      component(0) {}

  int dfs(int v, int prevEdge) {
    int curIdx = stack.size();
    stack.push_back(v);
    int res = curIdx;
    int bestIdx = -1;
    idx[v] = curIdx;
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = vertex(graph[v][i]);
      if (edgeIdx(graph[v][i]) == prevEdge) {
        continue;
      }
      if (idx[nv] < 0) {
        edges.emplace_back(v, i);
        res = std::min(res, dfs(nv, edgeIdx(graph[v][i])));
      } else {
        if (idx[nv] < res) {
          res = idx[nv];
          bestIdx = (int) i;
        }
      }
    }
    if (bestIdx >= 0) {
      edges.emplace_back(v, bestIdx);
    }
    if (res == curIdx) {
      for (size_t i = curIdx; i < stack.size(); i++) {
        components[stack[i]] = component;
        idx[stack[i]] = graph.size();
      }
      stack.resize(curIdx);
      component++;
    }
    return res;
  }

  static ComponentNums getComponents(const Graph& graph, std::vector<std::pair<int, int>>& edges) {
    TarjanFindEdges t(graph, edges);
    for (size_t i = 0; i < graph.size(); i++) {
      if (t.idx[i] < 0) {
        t.dfs(i, graph.size());
      }
    }
    return std::move(t.components);
  }
};

class Tarjan {
  using Graph = std::vector<std::vector<Edge>>;
  using ComponentNums = std::vector<int>;
  const Graph& graph;
  ComponentNums components;
  std::vector<int> idx;
  std::vector<int> stack;
  int component;
  int forbiddenEdge;

  Tarjan(const Graph& graph, int forbiddenEdge) :
      graph(graph),
      components(graph.size(), -1),
      idx(graph.size(), -1),
      stack(),
      component(0),
      forbiddenEdge(forbiddenEdge) {}

  int dfs(int v, int prevEdge) {
    int curIdx = stack.size();
    stack.push_back(v);
    int res = curIdx;
    idx[v] = curIdx;
    for (const Edge& edge : graph[v]) {
      int nv = vertex(edge);
      if (edgeIdx(edge) == forbiddenEdge || edgeIdx(edge) == prevEdge) {
        continue;
      }
      if (idx[nv] < 0) {
        res = std::min(res, dfs(nv, edgeIdx(edge)));
      } else {
        res = std::min(res, idx[nv]);
      }
    }
    if (res == curIdx) {
      for (size_t i = curIdx; i < stack.size(); i++) {
        components[stack[i]] = component;
        idx[stack[i]] = graph.size();
      }
      stack.resize(curIdx);
      component++;
    }
    return res;
  }

 public:
  static ComponentNums getComponents(const Graph& graph, int forbiddenEdge) {
    Tarjan t(graph, forbiddenEdge);
    for (size_t i = 0; i < graph.size(); i++) {
      if (t.idx[i] < 0) {
        t.dfs(i, graph.size());
      }
    }
    return std::move(t.components);
  }
};

struct Solution {
  int n;
  std::vector<std::vector<Edge>> graph;
  std::vector<int> edgeCost;
  int s, t;
  std::vector<std::pair<int, int>> edges;
  int optC;
  int opt;
  std::vector<int> ans;

  std::vector<int>* curComp;
  int minEdge;
  int minCost;
  int forbiddenEdge;
  std::vector<bool> visited;

  bool dfs(int v, int prev) {
    if (v == t) {
      return true;
    }
    visited[v] = true;
    for (const Edge& edge : graph[v]) {
      int nv = vertex(edge);
      if (edgeIdx(edge) == forbiddenEdge || nv == prev || visited[nv])  {
        continue;
      }
      bool res = dfs(nv, v);
      if (res) {
        if ((*curComp)[v] != (*curComp)[nv]) {
          int curCost = edgeCost[edgeIdx(edge)];
          if (curCost < minCost) {
            minCost = curCost;
            minEdge = edgeIdx(edge);
          }
        }
        return true;
      }
    }
    return false;
  }


  bool checkConnected() {
    visited.assign(n, false);
    minEdge = -1;
    minCost = 1000000001;
    return dfs(s, -1);
  }

  void solve() {
    std::vector<std::pair<int, int>> edges;
    std::vector<int> components = TarjanFindEdges::getComponents(graph, edges);
    forbiddenEdge = -1;
    curComp = &components;
    bool connected = checkConnected();
    if (!connected) {
      optC = 0;
      opt = 0;
      return;
    }
    if (minEdge >= 0) {
      optC = 1;
      opt = minCost;
      ans = std::vector<int>{minEdge};
    }
    for (std::pair<int, int>& e : edges) {
      int from = e.first;
      Edge& edge = graph[from][e.second];
      int to = vertex(edge);
      int idx = edgeIdx(edge);
      int cost = edgeCost[idx];
      components = Tarjan::getComponents(graph, idx);
      forbiddenEdge = idx;
      curComp = &components;
      bool connected2 = checkConnected();
      if (connected2 && minEdge >= 0) {
        int curCost = cost + minCost;
        if (curCost < opt) {
          opt = curCost;
          optC = 2;
          ans = std::vector<int>{idx, minEdge};
        }
      }
    }
  }

  void run(std::istream& in, std::ostream& out) {
    int m;
    in >> n >> m;
    in >> s >> t;
    s--;
    t--;
    edgeCost.assign(m, 0);
    graph.assign(n, {});
    for (int i = 0; i < m; i++) {
      int x, y, w;
      in >> x >> y >> w;
      x--;
      y--;
      graph[x].emplace_back(y, i);
      graph[y].emplace_back(x, i);
      edgeCost[i] = w;
    }
    optC = -1;
    opt = 2000000001;
    ans.clear();
    solve();
    if (optC < 0) {
      out << "-1" << std::endl;
      return;
    }
    out << opt << std::endl;
    out << optC << std::endl;
    for (int edge : ans) {
      out << (edge + 1) << " ";
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