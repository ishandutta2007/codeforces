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

const int M = 7;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int source = (M + 2) * n;
  int target = source + 1;
  MinCostFlow net(target + 1);
  std::map<int, int> nxt;
  for (int i = n; i--;) {
    net.add_edge(source, i, 1, 0);
    net.add_edge(i, n + i, 1, -1);
    net.add_edge(n + i, target, 1, 0);
    if (nxt.count(a[i])) {
      net.add_edge(i, nxt[a[i]], 4, 0);
    }
    if (nxt.count(a[i] - 1)) {
      net.add_edge(n + i, nxt[a[i] - 1], 1, 0);
    }
    if (nxt.count(a[i] + 1)) {
      net.add_edge(n + i, nxt[a[i] + 1], 1, 0);
    }
    if (i + 1 < n) {
      for (int r = 0; r < M; ++r) {
        net.add_edge((2 + r) * n + i, (2 + r) * n + (i + 1), 4, 0);
      }
      net.add_edge(n + i, (2 + a[i] % M) * n + (i + 1), 1, 0);
    }
    net.add_edge((2 + a[i] % M) * n + i, i, 1, 0);
    nxt[a[i]] = i;
  }
  int result = 0;
  for (int _ = 0; _ < 4; ++_) {
    result -= net.augment(source, target).cost;
  }
  printf("%d\n", result);
}