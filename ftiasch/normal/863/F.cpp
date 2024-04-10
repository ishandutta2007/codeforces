#line 1 "/home/ftiasch/Documents/shoka/min_cost_flow.h"
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

class MinCostFlow {
public:
  struct Result {
    int flow, cost;
  };

  MinCostFlow(int n, int m = 0) : visited(n), head(n, -1), dist(n), prev(n) {
    edges.reserve(m << 1);
  }

  void add_edge(int u, int v, int capacity, int cost) {
    internal_add_edge(u, v, capacity, cost);
    internal_add_edge(v, u, 0, -cost);
  }

  Result augment(int src, int dst) {
    const int infdist = std::numeric_limits<int>::max();
    std::fill(dist.begin(), dist.end(), infdist);
    dist[src] = 0;
    std::queue<int> queue;
    queue.push(src);
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      visited[u] = false;
      for (int iter = head[u]; ~iter;) {
        auto &e = edges[iter];
        int v = e.v;
        if (e.rest && dist[u] + e.cost < dist[v]) {
          dist[v] = dist[u] + e.cost;
          prev[v] = iter;
          if (!visited[v]) {
            visited[v] = true;
            queue.push(v);
          }
        }
        iter = e.next;
      }
    }
    if (dist[dst] == infdist) {
      return Result{0, 0};
    }
    for (int v = dst; v != src; v = edges[prev[v] ^ 1].v) {
      edges[prev[v]].rest--;
      edges[prev[v] ^ 1].rest++;
    }
    return Result{1, dist[dst]};
  }

private:
  struct Edge {
    int v, next, rest, cost;
  };

  void internal_add_edge(int u, int v, int capacity, int cost) {
    edges.push_back(Edge{v, head[u], capacity, cost});
    head[u] = edges.size() - 1;
  }

  std::vector<bool> visited;
  std::vector<int> head, dist, prev;
  std::vector<Edge> edges;
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> min(n, 0), max(n, n - 1);
  while (m--) {
    int t, l, r, v;
    scanf("%d%d%d%d", &t, &l, &r, &v);
    for (int i = l - 1; i < r; ++i) {
      if (t == 1) {
        min[i] = std::max(min[i], v - 1);
      } else {
        max[i] = std::min(max[i], v - 1);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (min[i] > max[i]) {
      puts("-1");
      return 0;
    }
  }
  MinCostFlow network(n + n + 2);
  int source = n + n;
  int target = source + 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n; ++j) {
      network.add_edge(source, i, 1, 2 * j - 1);
    }
    for (int j = 0; j < n; ++j) {
      if (min[j] <= i && i <= max[j]) {
        network.add_edge(i, n + j, 1, 0);
      }
    }
    network.add_edge(n + i, target, 1, 0);
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    result += network.augment(source, target).cost;
  }
  printf("%d\n", result);
}