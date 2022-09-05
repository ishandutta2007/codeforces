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
#include <cmath>
#include <queue>
#include <array>
#include <random>

const int gl = 18;
const int64_t inf = 1LL << 60;

struct Solution {
  int n;
  std::vector<std::vector<int>> graphDown;
  std::vector<std::vector<int>> graphUp;
  std::vector<std::vector<int>> graphTree;
  std::vector<std::array<int, 18>> treePrev;
  std::vector<std::vector<std::pair<int, int>>> initGraph;
  std::vector<int64_t> dist;
  std::vector<int> order;
  int start;

  int dfs(int v) {
    int res = 1;
    for (int nv : graphTree[v]) {
      res += dfs(nv);
    }
    return res;
  }

  void buildGraph() {
    graphUp.clear();
    graphUp.resize(n);
    graphDown.clear();
    graphDown.resize(n);
    for (int i = 0; i < n; i++) {
      if (dist[i] == inf) {
        continue;
      }
      for (const std::pair<int, int>& edge : initGraph[i]) {
        if (edge.second == dist[i] - dist[edge.first]) {
          graphUp[i].push_back(edge.first);
          graphDown[edge.first].push_back(i);
        }
      }
    }
    std::fill(dist.begin(), dist.end(), -1);
    initGraph.clear();
    initGraph.shrink_to_fit();
  }

  int lca(int x, int y) {
    int dx = dist[x];
    int dy = dist[y];
    if (dx > dy) {
      std::swap(dx, dy);
      std::swap(x, y);
    }
    for (int level = gl - 1; level >= 0; level --) {
      if (dy >= dx + (1 << level)) {
        y = treePrev[y][level];
        dy -= (1 << level);
      }
    }
    if (x == y) {
      return x;
    }
    for (int level = gl - 1; level >= 0; level --) {
      if (treePrev[x][level] != treePrev[y][level]) {
        x = treePrev[x][level];
        y = treePrev[y][level];
      }
    }
    return treePrev[x][0];
  }

  void buildTree() {
    treePrev.resize(n);
    for (auto& entry : treePrev) {
      std::fill(entry.begin(), entry.end(), -1);
    }
    graphTree.clear();
    graphTree.resize(n);
    std::fill(treePrev[start].begin(), treePrev[start].end(), start);
    dist[start] = 0;
    for (int v : order) {
      if (v == start) continue;
      int res = v;
      for (int nv : graphUp[v]) {
        if (res == v) {
          res = nv;
        } else {
          res = lca(res, nv);
        }
      }
      graphTree[res].push_back(v);
      dist[v] = dist[res] + 1;
      treePrev[v][0] = res;
      for (int i = 1; i < gl; i++) {
        treePrev[v][i] = treePrev[treePrev[v][i - 1]][i - 1];
      }
    }
  }

  void calcDistances() {
    std::vector<uint8_t> flags(n);
    dist.assign(n, inf);
    std::priority_queue<std::pair<int64_t, int>> queue;
    dist[start] = 0;
    queue.push(std::pair<int64_t, int>(0, start));
    order.clear();
    while (!queue.empty()) {
      int v = queue.top().second;
      queue.pop();
      if (flags[v]) continue;
      order.push_back(v);
      flags[v] = true;
      for (std::pair<int, int>& edge : initGraph[v]) {
        if (dist[edge.first] > dist[v] + edge.second) {
          dist[edge.first] = dist[v] + edge.second;
          queue.push(std::pair<int64_t, int>(-dist[edge.first], edge.first));
        }
      }
    }
  }

  int getAnswer(int start, std::vector<std::vector<std::pair<int,int>>>& graph) {
    this->start = start;
    initGraph = graph;
    n = graph.size();
    if (initGraph[start].size() == 0) {
      return 0;
    }
    calcDistances();
    buildGraph();
    buildTree();
    int ans = 0;
    for (int v : graphTree[start]) {
      ans = std::max(ans, dfs(v));
    }
    return ans;
  }

  void calcDist(std::vector<int64_t>& dist, int other) {
    std::vector<uint8_t> flags(n);
    dist.assign(n, inf);
    std::priority_queue<std::pair<int64_t, int>> queue;
    dist[start] = 0;
    queue.push(std::pair<int64_t, int>(0, start));
    while (!queue.empty()) {
      int v = queue.top().second;
      queue.pop();
      if (v == other) continue;
      if (flags[v]) continue;
      flags[v] = true;
      for (std::pair<int, int>& edge : initGraph[v]) {
        if (dist[edge.first] > dist[v] + edge.second) {
          dist[edge.first] = dist[v] + edge.second;
          queue.push(std::pair<int64_t, int>(-dist[edge.first], edge.first));
        }
      }
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    int m;
    in >> m;
    in >> start;
    start--;
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
      int x, y, weight;
      in >> x >> y >> weight;
      x--;y--;
      graph[x].emplace_back(y, weight);
      graph[y].emplace_back(x, weight);
    }
    out << getAnswer(start, graph) << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
//  Solution().test();
  return 0;
}