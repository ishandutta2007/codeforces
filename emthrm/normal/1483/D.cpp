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

template <typename T>
struct WarshallFloyd {
  std::vector<std::vector<T>> graph, dist;

  WarshallFloyd(const std::vector<std::vector<T>> &graph, const T inf) : graph(graph), dist(graph), inf(inf) {
    n = graph.size();
    internal.assign(n, std::vector<int>(n, -1));
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      if (dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
        internal[i][j] = k;
      }
    }
  }

  void add(int src, int dst, T cost) {
    srcs.emplace_back(src);
    dsts.emplace_back(dst);
    costs.emplace_back(cost);
  }

  void calc() {
    std::set<int> vers;
    int sz = srcs.size();
    for (int i = 0; i < sz; ++i) {
      int s = srcs[i], t = dsts[i];
      T cost = costs[i];
      if (cost < graph[s][t]) graph[s][t] = cost;
      if (dist[s][t] >= cost) {
        dist[s][t] = cost;
        internal[s][t] = -1;
      }
      vers.emplace(s);
      vers.emplace(t);
    }
    for (int v : vers) {
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (dist[i][j] > dist[i][v] + dist[v][j]) {
          dist[i][j] = dist[i][v] + dist[v][j];
          internal[i][j] = v;
        }
      }
    }
    srcs.clear();
    dsts.clear();
    costs.clear();
  }

  bool has_negative_cycle() const {
    for (int i = 0; i < n; ++i) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }

  std::vector<int> build_path(int s, int t) const {
    std::vector<int> res;
    if (dist[s][t] != inf) {
      build_path(s, t, res);
      res.emplace_back(t);
    }
    return res;
  }

private:
  const T inf;
  int n;
  std::vector<std::vector<int>> internal;
  std::vector<int> srcs, dsts;
  std::vector<T> costs;

  void build_path(int s, int t, std::vector<int> &path) const {
    int k = internal[s][t];
    if (k == -1) {
      path.emplace_back(s);
    } else {
      build_path(s, k, path);
      build_path(k, t, path);
    }
  }
};

int main() {
  int n, m; cin >> n >> m;
  vector<Edge<int>> edge;
  edge.reserve(m);
  vector graph(n, vector(n, LINF));
  REP(i, n) graph[i][i] = 0;
  REP(_, m) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    edge.emplace_back(u, v, w);
    graph[u][v] = graph[v][u] = w;
  }
  WarshallFloyd wf(graph, LINF);
  vector longest(n, vector(n, -LINF));
  int q; cin >> q;
  while (q--) {
    int u, v, l; cin >> u >> v >> l; --u; --v;
    REP(i, n) {
      chmax(longest[u][i], l - wf.dist[v][i]);
      chmax(longest[v][i], l - wf.dist[u][i]);
    }
  }
  int ans = 0;
  for (auto [u, v, w] : edge) {
    bool is_useful = false;
    REP(i, n) {
      is_useful |= wf.dist[i][u] + w <= longest[i][v];
      is_useful |= wf.dist[i][v] + w <= longest[i][u];
    }
    ans += is_useful;
  }
  cout << ans << '\n';
  return 0;
}