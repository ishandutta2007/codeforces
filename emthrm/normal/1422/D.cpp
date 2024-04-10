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
  int n, m, sx, sy, fx, fy; cin >> n >> m >> sx >> sy >> fx >> fy;
  vector<int> x, y;
  {
    set<pair<int, int>> ps;
    while (m--) {
      int xi, yi; cin >> xi >> yi;
      if (ps.count({xi, yi}) == 0) {
        x.emplace_back(xi);
        y.emplace_back(yi);
        ps.emplace(xi, yi);
      }
    }
  }
  m = x.size();
  map<int, vector<int>> xs, ys;
  REP(i, m) {
    xs[x[i]].emplace_back(i);
    ys[y[i]].emplace_back(i);
  }
  vector<vector<Edge<ll>>> graph(m + 2);
  const int S = m, T = m + 1;
  REP(i, m) {
    graph[S].emplace_back(S, i, min(abs(sx - x[i]), abs(sy - y[i])));
    graph[i].emplace_back(i, T, abs(x[i] - fx) + abs(y[i] - fy));
  }
  graph[S].emplace_back(S, T, abs(fx - sx) + abs(fy - sy));
  if (m > 0) {
    for (auto it = xs.begin(); next(it) != xs.end(); ++it) {
      int dst = next(it)->second[0], dist = next(it)->first - it->first;
      for (int e : it->second) {
        graph[e].emplace_back(e, dst, dist);
        graph[dst].emplace_back(dst, e, dist);
      }
    }
    for (auto it = xs.begin(); it != xs.end(); ++it) {
      FOR(i, 1, it->second.size()) {
        int src = it->second[i - 1], dst = it->second[i];
        graph[src].emplace_back(src, dst, 0);
        graph[dst].emplace_back(dst, src, 0);
      }
    }
    for (auto it = ys.begin(); next(it) != ys.end(); ++it) {
      int dst = next(it)->second[0], dist = next(it)->first - it->first;
      for (int e : it->second) {
        graph[e].emplace_back(e, dst, dist);
        graph[dst].emplace_back(dst, e, dist);
      }
    }
    for (auto it = ys.begin(); it != ys.end(); ++it) {
      FOR(i, 1, it->second.size()) {
        int src = it->second[i - 1], dst = it->second[i];
        graph[src].emplace_back(src, dst, 0);
        graph[dst].emplace_back(dst, src, 0);
      }
    }
  }
  cout << Dijkstra(graph, LINF).build(S)[T] << '\n';
  return 0;
}