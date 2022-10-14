#include <bits/stdc++.h>

template <typename CostT> struct DensePrimalDual {
  using Result = std::pair<int, CostT>;

  DensePrimalDual(int n_)
      : n(n_), phi(n), net(n, std::vector<Edge>(n)), visited(n), dist(n),
        pred(n) {}

  // NOTE: at most one of the (u->v) and (v->u) edges exists
  void add_edge(int u, int v, int cap, CostT cost) {
    if (cost < 0) {
      throw std::runtime_error("cost must > 0");
    }
    // std::cerr << u << "->" << v << " [label=\"" << cost << "\"]" << std::endl;
    net[u][v] = {cap, cost};
    net[v][u] = {0, -cost};
  }

  Result augment(int source, int target, int maxflow = INT_MAX) {
    std::fill(visited.begin(), visited.end(), false);
    std::fill(dist.begin(), dist.end(), MAX_COST);
    dist[source] = 0;
    while (true) {
      std::pair<CostT, int> candidate{MAX_COST, -1};
      for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
          candidate = std::min(candidate, {dist[u], u});
        }
      }
      int u = candidate.second;
      if (u == -1 || u == target) {
        break;
      }
      visited[u] = true;
      for (int v = 0; v < n; ++v) {
        auto [cap, cost] = net[u][v];
        if (cap > 0 && dist[v] > dist[u] + (phi[u] + cost - phi[v])) {
          dist[v] = dist[u] + (phi[u] + cost - phi[v]);
          pred[v] = u;
        }
      }
    }
    if (dist[target] == MAX_COST) {
      return {0, 0};
    }
    int flow = maxflow;
    for (int v = target; v != source;) {
      int u = pred[v];
      flow = std::min(flow, net[u][v].first);
      v = u;
    }
    for (int v = target; v != source;) {
      int u = pred[v];
      net[u][v].first -= flow;
      net[v][u].first += flow;
      v = u;
    }
    CostT cost = dist[target] + phi[target];
    for (int u = 0; u < n; ++u) {
      if (dist[u] < dist[target]) {
        phi[u] += dist[u];
      }
    }
    phi[target] += dist[target];
    return {flow, cost};
  }

private:
  static const CostT MAX_COST = std::numeric_limits<CostT>::max();

  using Edge = std::pair<int, CostT>;

  int n;
  std::vector<CostT> phi;
  std::vector<std::vector<Edge>> net;
  std::vector<bool> visited;
  std::vector<CostT> dist;
  std::vector<int> pred;
};

namespace {

const int N = 500;
const int V = N + N;

int n, m, a[N + 1][N + 1];

int row(int i) { return i; }

int col(int j) { return (n - 1) + j; }

} // namespace

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    static char buffer[N + 1];
    scanf("%s", buffer);
    for (int j = 0; j < m; ++j) {
      a[i][j] = buffer[j] == 'B';
    }
  }
  int cost0 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] ^= a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1];
      cost0 += a[i][j];
    }
  }
  int src = (n - 1) + (m - 1);
  int dst = src + 1;
  DensePrimalDual<int> net(dst + 1);
//   std::cerr << "digraph {\n";
  for (int i = 0; i < n - 1; ++i) {
    net.add_edge(src, row(i), 1, 0);
  }
  for (int j = 0; j < m - 1; ++j) {
    net.add_edge(col(j), dst, 1, 0);
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      net.add_edge(row(i), col(j), 1,
                   (a[i][j] == 0) + (a[i][m - 1] == 0) + (a[n - 1][j] == 0));
    }
  }
//   std::cerr << "}\n";
//   for (int i = 0; i < n; ++ i) {
//       std::cerr << std::vector<int>(a[i], a[i] + m) << std::endl;
//   }
  int result = cost0;
  cost0 -= a[n - 1][m - 1];
//   std::cerr << KV(cost0) << std::endl;
  for (int count = 1; count <= n - 1 && count <= m - 1; ++count) {
    auto [flow, cost] = net.augment(src, dst, 1);
    // std::cerr << KV(count) << " " << KV(flow) << " " << KV(cost) << std::endl;
    if (flow == 0) {
      break;
    }
    cost0 += 2 * cost - 1;
    result = std::min(result, cost0 + (a[n - 1][m - 1] ^ (count & 1)));
  }
  printf("%d\n", result);
}