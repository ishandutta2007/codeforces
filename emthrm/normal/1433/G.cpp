#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
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
  int n, m, k; cin >> n >> m >> k;
  vector<int> x(m), y(m), w(m);
  vector<vector<Edge<int>>> graph(n);
  REP(i, m) {
    cin >> x[i] >> y[i] >> w[i]; --x[i]; --y[i];
    graph[x[i]].emplace_back(x[i], y[i], w[i]);
    graph[y[i]].emplace_back(y[i], x[i], w[i]);
  }
  vector<int> a(k), b(k);
  REP(i, k) cin >> a[i] >> b[i], --a[i], --b[i];
  Dijkstra dij(graph, INF);
  vector<vector<int>> dist(n);
  REP(i, n) dist[i] = dij.build(i);
  vector<int> route(k);
  REP(i, k) route[i] = dist[a[i]][b[i]];
  // REP(i, k) cout << route[i] << " \n"[i + 1 == k];
  int ans = INF;
  REP(i, m) {
    int sum = 0;
    REP(j, k) {
      sum += min({dist[x[i]][a[j]] + dist[y[i]][b[j]], dist[y[i]][a[j]] + dist[x[i]][b[j]], route[j]});
    }
    chmin(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}