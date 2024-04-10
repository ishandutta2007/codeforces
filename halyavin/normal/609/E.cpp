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
#include <queue>

struct Edge {
  int to;
  int weight;
  int num;

  Edge(int to, int weight, int num) :
      to(to), weight(weight), num(num) { }
};

using Graph = std::vector<std::vector<Edge>>;

struct Solution {

  Graph graph;
  std::vector<int> prev;
  std::vector<int> dist;
  std::vector<int64_t> answer;
  int64_t sum;

  void buildTree() {
    std::vector<bool> flags(graph.size());
    dist.assign(graph.size(), 2000000000);
    std::priority_queue<void, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
    queue.emplace(0, 0);
    prev[0] = 0;
    dist[0] = 0;
    while (!queue.empty()) {
      std::pair<int, int> node = queue.top();
      queue.pop();
      int v = node.second;
      if (flags[v]) {
        continue;
      }
      sum += node.first;
      flags[v] = true;
      for (size_t i = 0; i < graph[v].size(); i++) {
        int nv = graph[v][i].to;
        if (flags[nv]) continue;
        if (dist[nv] > graph[v][i].weight) {
          dist[nv] = graph[v][i].weight;
          prev[nv] = v;
          queue.emplace(graph[v][i].weight, nv);
        }
      }
    }
  }

  struct Up {
    int prev;
    int max;

    Up() : prev(0), max(0) { }

    Up(int prev, int max) : prev(prev), max(max) { }
  };

  int levels;
  std::vector<std::vector<Up>> up;

  void buildFastUp() {
    levels = 1;
    while ((size_t(1) << levels) < graph.size()) levels++;
    up.clear();
    up.resize(levels, std::vector<Up>(graph.size()));
    for (int i = 0; i < graph.size(); i++) {
      up[0][i].prev = prev[i];
      up[0][i].max = dist[i];
    }
    for (int level = 1; level < levels; level++) {
      for (int i = 0; i < graph.size(); i++) {
        int next = up[level - 1][i].prev;
        up[level][i].prev = up[level - 1][next].prev;
        up[level][i].max = std::max(up[level - 1][i].max, up[level - 1][next].max);
      }
    }
  }

  std::vector<bool> inDfs;
  std::vector<int> depth;

  std::pair<int, int> firstOnDfs(int nv) {
    if (inDfs[nv]) {
      return {nv, 0};
    }
    std::pair<int, int> result = {};
    for (int level = levels - 1; level >= 0; level--) {
      int prevNV = up[level][nv].prev;
      if (inDfs[prevNV]) {
        continue;
      }
      result.second = std::max(result.second, up[level][nv].max);
      nv = prevNV;
    }
    result.first = prev[nv];
    result.second = std::max(result.second, dist[nv]);
    return result;
  };

  void dfs(int v, int vprev) {
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i].to;
      if (nv == vprev) continue;
      if (prev[nv] == v) {
        inDfs[nv] = true;
        depth[nv] = depth[v] + 1;
        dfs(nv, v);
        answer[graph[v][i].num] = sum;
        continue;
      }
      std::pair<int, int> res = firstOnDfs(nv);
      int xv = res.first;
      int maxEdge = res.second;
      int dist = depth[v] - depth[xv];
      int curV = v;
      for (int level = levels - 1; level >= 0; level--) {
        if ((1 << level) > dist) continue;
        maxEdge = std::max(maxEdge, up[level][curV].max);
        curV = up[level][curV].prev;
        dist -= 1 << level;
      }
      answer[graph[v][i].num] = (sum + graph[v][i].weight) - maxEdge;
    }
    inDfs[v] = false;
  }

  void run(std::istream& in, std::ostream& out) {
    int n, m;
    in >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
      int from, to, weight;
      in >> from >> to >> weight;
      from--;
      to--;
      graph[from].emplace_back(to, weight, i);
      graph[to].emplace_back(from, weight, i);
    }
    prev.assign(n, -1);
    sum = 0;
    buildTree();
    answer.assign(m, 0);
    buildFastUp();
    inDfs.assign(n, false);
    depth.assign(n, false);
    inDfs[0] = true;
    depth[0] = 0;
    dfs(0, 0);
    for (int i = 0; i < m; i++) {
      out << answer[i] << "\n";
    }
    out.flush();
  }



};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}