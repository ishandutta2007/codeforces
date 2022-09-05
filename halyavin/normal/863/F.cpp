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

template<class E>
struct MinCostFlow2 {
  std::vector<std::vector<E*>>* pGraph = nullptr;
  int vFrom = 0;
  int vTo = 0;
  int n = 0;
  int64_t totalCost = 0;

  std::vector<E*> prev;
  std::vector<int64_t> potential;
  std::vector<int64_t> dist;

  static int capacity(int v, E* edge) {
      if (edge->from == v) {
          return edge->capacity - edge->flow;
      } else {
          return edge->flow;
      }
  }

  static decltype(std::declval<E>().cost) cost(int v, E* edge) {
      if (edge->from == v) {
          return edge->cost;
      } else {
          return -edge->cost;
      }
  }

  static void addCapacity(int v, E* edge, int flow) {
      if (edge->from == v) {
          edge->flow += flow;
      } else {
          edge->flow -= flow;
      }
  }

  void updateDist2() {
      dist.assign(n, int64_t(1) << 62);
      std::vector<bool> found(n);
      std::queue<int> queue;
      dist[vFrom] = 0;
      queue.push(vFrom);
      found[vFrom] = true;
      while (!queue.empty()) {
          int v = queue.front();
          queue.pop();
          if (v == vTo) {
              continue;
          }
          for (auto& edge : (*pGraph)[v]) {
              if (edge->from != v) {
                  continue;
              }
              int nv = edge->to;
              int64_t newDist = dist[v] + edge->cost;
              if (dist[nv] > newDist) {
                  dist[nv] = newDist;
                  if (!found[nv]) {
                      queue.push(nv);
                      found[nv] = true;
                  }
              }
          }
          found[v] = false;
      }
  }

  bool updateDist() {
      std::swap(potential, dist);
      prev.assign(n, nullptr);
      dist.assign(n, int64_t(1) << 62);
      dist[vFrom] = 0;
      std::priority_queue<std::pair<int64_t, int>> queue;
      queue.emplace(0, vFrom);
      while (!queue.empty()) {
          int64_t value = -queue.top().first;
          int v = queue.top().second;
          queue.pop();
          if (value + potential[v] != dist[v]) {
              continue;
          }
          value = dist[v];
          for (auto& edge : (*pGraph)[v]) {
              if (capacity(v, edge) == 0) {
                  continue;
              }
              int nv = edge->from ^edge->to ^v;
              int64_t newDist = value + cost(v, edge);
              if (dist[nv] > newDist) {
                  prev[nv] = edge;
                  dist[nv] = newDist;
                  queue.emplace(potential[nv] - newDist, nv);
              }
          }
      }
      return prev[vTo] != nullptr;
  }

  int dfs() {
      int node = prev[vTo]->to ^prev[vTo]->from ^vTo;
      int flow = capacity(node, prev[vTo]);
      while (node != vFrom) {
          int prevNode = prev[node]->to ^prev[node]->from ^node;
          flow = std::min(flow, capacity(prevNode, prev[node]));
          node = prevNode;
      }
      node = vTo;
      while (node != vFrom) {
          int prevNode = prev[node]->to ^prev[node]->from ^node;
          addCapacity(prevNode, prev[node], flow);
          node = prevNode;
      }
      return flow;
  }

  int64_t solve(std::vector<std::vector<E*>>& graph, int from, int to, bool clear = true) {
      totalCost = 0;
      pGraph = &graph;
      vFrom = from;
      vTo = to;
      if (clear) {
          for (auto& vArray : graph) {
              for (auto& edge : vArray) {
                  edge->flow = 0;
              }
          }
      }
      n = graph.size();
      updateDist2();
      while (updateDist()) {
          int flow = dfs();
          totalCost += dist[vTo] * flow;
      }

      return totalCost;
  }
};

struct Edge {
  int from;
  int to;
  int capacity;
  int flow;
  int cost;
};

void clearGraph(std::vector<std::vector<Edge*>>& graph) {
    for (size_t v = 0; v < graph.size(); v++) {
        auto& edges = graph[v];
        auto it = std::partition(edges.begin(), edges.end(), [v](Edge* e) { return e->from == v; });
        edges.erase(it, edges.end());
    }
    for (auto& v : graph) {
        for (Edge* edge : v) {
            delete edge;
        }
    }
    graph.clear();
}


struct Solution {
  void run(std::istream& in, std::ostream& out) {
      int n, q;
      in >> n >> q;
      std::vector<int> low(n, 0);
      std::vector<int> high(n, n - 1);
      for (int i = 0; i < q; i++) {
          int t, l, r, v;
          in >> t >> l >> r >> v;
          l--;
          v--;
          if (t == 1) {
              for (int i = l; i < r; i++) {
                  low[i] = std::max(low[i], v);
              }
          } else {
              for (int i = l; i < r; i++) {
                  high[i] = std::min(high[i], v);
              }
          }
      }
      for (int i = 0; i < n; i++) {
          if (high[i] < low[i]) {
              out << -1 << std::endl;
              return;
          }
      }
      std::vector<std::vector<Edge*>> graph(2 * n + 2);
      int from = 2 * n;
      int to = 2 * n + 1;
      for (int i = 0; i < n; i++) {
          Edge* edge = new Edge();
          edge->from = from;
          edge->to = i;
          edge->capacity = 1;
          edge->cost = 0;
          graph[from].push_back(edge);
          graph[i].push_back(edge);

          for (int j = low[i]; j <= high[i]; j++) {
              edge = new Edge();
              edge->from = i;
              edge->to = j + n;
              edge->capacity = 1;
              edge->cost = 0;
              graph[i].push_back(edge);
              graph[j + n].push_back(edge);
          }
          for (int j = 0; j < n; j++) {
              edge = new Edge();
              edge->from = i + n;
              edge->to = to;
              edge->capacity = 1;
              edge->cost = 2 * j + 1;
              graph[i + n].push_back(edge);
              graph[to].push_back(edge);
          }
      }
      int64_t answer = MinCostFlow2<Edge>().solve(graph, from, to, true);
      clearGraph(graph);
      out << answer << std::endl;
  }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}