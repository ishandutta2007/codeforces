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

struct StronglyConnectedComponents {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, comp;

  StronglyConnectedComponents(const std::vector<std::vector<int>> &graph, bool heavy = false) : graph(graph), heavy(heavy) {
    n = graph.size();
    rev_graph.resize(n);
    for (int i = 0; i < n; ++i) for (int e : graph[i]) rev_graph[e].emplace_back(i);
    used.assign(n, false);
    id.assign(n, -1);
    for (int i = 0; i < n; ++i) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[order[i]] == -1) {
        if (heavy) vertices.emplace_back();
        rev_dfs(order[i], now++);
      }
    }
    comp.resize(now);
    for (int i = 0; i < n; ++i) for (int e : graph[i]) {
      if (id[i] != id[e]) comp[id[i]].emplace_back(id[e]);
    }
    // if (heavy) {
    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }

private:
  bool heavy;
  int n;
  std::vector<std::vector<int>> graph, rev_graph;
  std::vector<bool> used;
  std::vector<int> order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    if (heavy) vertices[now].emplace_back(ver);
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(m), b(m), l(m);
  vector<vector<int>> graph(n);
  REP(i, m) {
    cin >> a[i] >> b[i] >> l[i]; --a[i]; --b[i];
    graph[a[i]].emplace_back(b[i]);
  }
  StronglyConnectedComponents scc(graph);
  vector<vector<Edge<int>>> graph2(n);
  REP(i, m) {
    if (scc.id[a[i]] == scc.id[b[i]]) graph2[a[i]].emplace_back(a[i], b[i], l[i]);
  }
  vector<ll> g(scc.comp.size(), 0), dist(n, -1);
  REP(i, n) {
    auto f = [&](auto &&f, int ver) -> void {
      for (const Edge<int> &e : graph2[ver]) {
        if (dist[e.dst] == -1) {
          dist[e.dst] = dist[ver] + e.cost;
          f(f, e.dst);
        } else {
          g[scc.id[ver]] = gcd(g[scc.id[ver]], abs(dist[e.dst] - (dist[ver] + e.cost)));
        }
      }
    };
    if (dist[i] == -1) {
      dist[i] = 0;
      f(f, i);
    }
  }
  // REP(i, scc.comp.size()) cout << g[i] << " \n"[i + 1 == scc.comp.size()];
  int q; cin >> q;
  while (q--) {
    int v, s, t; cin >> v >> s >> t; --v;
    cout << (s == 0 || (g[scc.id[v]] > 0 && (t - s) % gcd(g[scc.id[v]], t) == 0) ? "YES\n" : "NO\n");
  }
  return 0;
}