#line 1 "sol.cpp"
#include <bits/stdc++.h>

class MaxCostFlow {
public:
  struct Result {
    int flow, cost;
  };

  MaxCostFlow(int n, int m = 0) : visited(n), head(n, -1), dist(n), prev(n) {
    edges.reserve(m << 1);
  }

  void add_edge(int u, int v, int capacity, int cost) {
    // printf("%d->%d [label=\"cap=%d cost=%d\"]\n", u, v, capacity, cost);
    internal_add_edge(u, v, capacity, cost);
    internal_add_edge(v, u, 0, -cost);
  }

  Result augment(int src, int dst) {
    const int infdist = std::numeric_limits<int>::min();
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
        if (e.rest && dist[u] + e.cost > dist[v]) {
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

const int C = 26;

int main() {
  int len;
  scanf("%d", &len);
  std::vector<char> s(len + 1);
  scanf("%s", s.data());
  std::vector<int> b(len);
  for (int i = 0; i < len; ++i) {
    scanf("%d", &b[i]);
  }
  std::array<int, C> count{};
  for (int i = 0; i < len; ++i) {
    count[s[i] - 'a']++;
  }
  int offset = C + 3 * (len / 2);
  int source = offset + len;
  int sink = source + 1;
  int n = sink + 1;
  MaxCostFlow net(n);
  for (int c = 0; c < C; ++c) {
    net.add_edge(source, c, count[c], 0);
    for (int i = 0; i < (len >> 1); ++i) {
      int hub = C + 3 * i;
      int j = len - 1 - i;
      if (s[i] - 'a' == c) {
        net.add_edge(c, hub, 1, 0);
      } else if (s[j] - 'a' == c) {
        net.add_edge(c, hub + 1, 1, 0);
      } else {
        net.add_edge(c, hub + 2, 1, 0);
      }
    }
  }
  for (int i = 0; i < (len >> 1); ++i) {
    int hub = C + 3 * i;
    int j = len - 1 - i;
    if (s[i] != s[j]) {
      net.add_edge(hub, offset + i, 1, b[i]);
      net.add_edge(hub, offset + j, 1, 0);

      net.add_edge(hub + 1, offset + i, 1, 0);
      net.add_edge(hub + 1, offset + j, 1, b[j]);
    } else {
      net.add_edge(hub, offset + i, 1, b[i]);
      net.add_edge(hub, offset + j, 1, b[j]);
    }
    net.add_edge(hub + 2, offset + i, 1, 0);
    net.add_edge(hub + 2, offset + j, 1, 0);
  }
  for (int i = 0; i < len; ++i) {
    net.add_edge(offset + i, sink, 1, 0);
  }
  int result = 0;
  for (int i = 0; i < len; ++i) {
    result += net.augment(source, sink).cost;
  }
  printf("%d\n", result);
}