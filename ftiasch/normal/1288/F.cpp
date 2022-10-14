#include <bits/stdc++.h>

class MinCostFlow {
public:
  MinCostFlow(int n, int m = 0) : visited(n), head(n, -1), dist(n), prev(n) {
    edges.reserve(m);
  }

  void add_edge(int u, int v, int capacity, int cost) {
    internal_add_edge(u, v, capacity, cost);
    internal_add_edge(v, u, 0, -cost);
  }

  int solve(int src, int dst) {
    const int infdist = std::numeric_limits<int>::max();
    int cost = 0;
    while (true) {
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
      if (dist[dst] > 0) {
        break;
      }
      cost += dist[dst];
      for (int v = dst; v != src; v = edges[prev[v] ^ 1].v) {
        edges[prev[v]].rest--;
        edges[prev[v] ^ 1].rest++;
      }
    }
    return cost;
  }

  std::vector<char> ways(int m, int e) const {
    std::vector<char> res(m + 1, 'U');
    for (int i = 0; i < m; ++i, e += 4) {
      if (edges[e + 1].rest) {
        res[i] = 'R';
      }
      if (edges[e + 3].rest) {
        res[i] = 'B';
      }
    }
    res[m] = '\0';
    return res;
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

int main() {
  int n[2], m, rcost, bcost;
  while (scanf("%d%d%d%d%d", n, n + 1, &m, &rcost, &bcost) == 5) {
    std::vector<char> buf(std::max(n[0], n[1]) + 1);
    int src = n[0] + n[1];
    int dst = src + 1;
    int infcost = std::max(rcost, bcost) * m + 1;
    MinCostFlow net(dst + 1);
    int cons = 0;
    for (int t = 0; t < 2; ++t) {
      scanf("%s", buf.data());
      for (int i = 0; i < n[t]; ++i) {
        int v = t ? n[0] + i : i;
        if (buf[i] == 'U') {
          net.add_edge(src, v, m, 0);
          net.add_edge(v, dst, m, 0);
        } else {
          cons++;
          if ((buf[i] == 'R') ^ t) {
            net.add_edge(src, v, 1, -infcost);
            net.add_edge(src, v, m, 0);
          } else {
            net.add_edge(v, dst, 1, -infcost);
            net.add_edge(v, dst, m, 0);
          }
        }
      }
    }
    std::vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      a[i]--, b[i]--;
      b[i] += n[0];
      net.add_edge(a[i], b[i], 1, rcost);
      net.add_edge(b[i], a[i], 1, bcost);
    }
    int cost = net.solve(src, dst);
    auto ways = net.ways(m, n[0] + n[1] << 2);
    int res = 0;
    for (int i = 0; i < m; ++i) {
      if (ways[i] == 'R') {
        res += rcost;
      }
      if (ways[i] == 'B') {
        res += bcost;
      }
    }
    if (cost != res - cons * infcost) {
      puts("-1");
    } else {
      printf("%d\n", res);
      puts(ways.data());
    }
  }
}