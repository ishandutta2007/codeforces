#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename CostType>
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
};

template <typename CostType>
struct NoshiGraph {
  std::vector<std::vector<Edge<CostType>>> graph;

  NoshiGraph(int n) {
    while (p2 < n) p2 <<= 1;
    int doub = p2 << 1, half = p2 >> 1;
    graph.resize(doub + p2);
    for (int i = 1; i < half; ++i) {
      graph[i + p2].emplace_back(i + p2, (i << 1) + p2, 0);
      graph[i + p2].emplace_back(i + p2, (i << 1) + p2 + 1, 0);
      graph[(i << 1) + doub].emplace_back((i << 1) + doub, i + doub, 0);
      graph[(i << 1) + doub + 1].emplace_back((i << 1) + doub + 1, i + doub, 0);
    }
    for (int src = p2 + half, dst = 0; dst < p2; ++src, dst += 2) {
      graph[src].emplace_back(src, dst, 0);
      graph[src].emplace_back(src, dst + 1, 0);
    }
    for (int src = doub + half, dst = 0; dst < p2; ++src, dst += 2) {
      graph[dst].emplace_back(dst, src, 0);
      graph[dst + 1].emplace_back(dst + 1, src, 0);
    }
  }

  void add_edge(int src, int dst, CostType cost) {
    graph[src].emplace_back(src, dst, cost);
  }

  void add_edge(int src_l, int src_r, int dst_l, int dst_r, CostType cost) {
    if (src_r <= src_l || dst_r <= dst_l) return;
    int src_id = graph.size(), dst_id = src_id + 1;
    graph.resize(graph.size() + 2);
    if ((dst_l += p2) & 1) graph[dst_id].emplace_back(dst_id, dst_l++ - p2, 0);
    if ((dst_r += p2) & 1) graph[dst_id].emplace_back(dst_id, --dst_r - p2, 0);
    for (dst_l >>= 1, dst_r >>= 1; dst_l < dst_r; dst_l >>= 1, dst_r >>= 1) {
      if (dst_l & 1) graph[dst_id].emplace_back(dst_id, dst_l++ + p2, 0);
      if (dst_r & 1) graph[dst_id].emplace_back(dst_id, --dst_r + p2, 0);
    }
    graph[src_id].emplace_back(src_id, dst_id, cost);
    if ((src_l += p2) & 1) {
      int src = src_l++ - p2;
      graph[src].emplace_back(src, src_id, 0);
    }
    if ((src_r += p2) & 1) {
      int src = --src_r - p2;
      graph[src].emplace_back(src, src_id, 0);
    }
    for (src_l >>= 1, src_r >>= 1; src_l < src_r; src_l >>= 1, src_r >>= 1) {
      if (src_l & 1) {
        int src = src_l++ + (p2 << 1);
        graph[src].emplace_back(src, src_id, 0);
      }
      if (src_r & 1) {
        int src = --src_r + (p2 << 1);
        graph[src].emplace_back(src, src_id, 0);
      }
    }
  }

private:
  int p2 = 1;
};

template <typename CostType>
struct Dijkstra {
  Dijkstra(const std::vector<std::vector<Edge<CostType>>> &graph, const CostType CINF) : graph(graph), CINF(CINF) {}

  std::vector<CostType> build(int s) {
    is_built = true;
    int n = graph.size();
    std::vector<CostType> dist(n, CINF);
    dist[s] = 0;
    prev.assign(n, -1);
    using Pci = std::pair<CostType, int>;
    std::priority_queue<Pci, std::vector<Pci>, std::greater<Pci>> que;
    que.emplace(0, s);
    while (!que.empty()) {
      CostType cost; int ver; std::tie(cost, ver) = que.top(); que.pop();
      if (dist[ver] < cost) continue;
      for (const Edge<CostType> &e : graph[ver]) {
        if (dist[e.dst] > dist[ver] + e.cost) {
          dist[e.dst] = dist[ver] + e.cost;
          prev[e.dst] = ver;
          que.emplace(dist[e.dst], e.dst);
        }
      }
    }
    return dist;
  }

  std::vector<int> build_path(int t) const {
    assert(is_built);
    std::vector<int> res;
    for (; t != -1; t = prev[t]) res.emplace_back(t);
    std::reverse(res.begin(), res.end());
    return res;
  }

private:
  bool is_built = false;
  std::vector<std::vector<Edge<CostType>>> graph;
  const CostType CINF;
  std::vector<int> prev;
};

int main() {
  int n, q, s; cin >> n >> q >> s; --s;
  NoshiGraph<ll> graph(n);
  while (q--) {
    int t, v; cin >> t >> v; --v;
    if (t == 1) {
      int u, w; cin >> u >> w; --u;
      graph.add_edge(v, u, w);
    } else {
      int l, r, w; cin >> l >> r >> w; --l; --r;
      if (t == 2) {
        graph.add_edge(v, v + 1, l, r + 1, w);
      } else if (t == 3) {
        graph.add_edge(l, r + 1, v, v + 1, w);
      }
    }
  }
  vector<ll> ans = Dijkstra(graph.graph, LINF).build(s);
  REP(i, n) cout << (ans[i] == LINF ? -1 : ans[i]) << " \n"[i + 1 == n];
  return 0;
}