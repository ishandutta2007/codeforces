#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

using CostType = int;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};

struct LCADoubling {
  vector<int> depth;
  vector<CostType> dist;

  LCADoubling(const vector<vector<Edge> > &graph) : graph(graph) {
    n = graph.size();
    depth.resize(n);
    dist.resize(n);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, vector<int>(n));
  }

  void build(int root = 0) {
    dfs(-1, root, 0, 0);
    for (int i = 0; i + 1 < table_h; ++i) REP(ver, n) {
      parent[i + 1][ver] = (parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]]);
    }
  }

  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    REP(i, table_h) {
      if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];
    }
    if (u == v) return u;
    for (int i = table_h - 1; i >= 0; --i) {
      if (parent[i][u] != parent[i][v]) {
        u = parent[i][u];
        v = parent[i][v];
      }
    }
    return parent[0][u];
  }

  CostType distance(int u, int v) { return dist[u] + dist[v] - dist[query(u, v)] * 2; }

private:
  int n, table_h = 1;
  vector<vector<Edge> > graph;
  vector<vector<int> > parent;

  void dfs(int par, int ver, int now_depth, CostType now_dist) {
    depth[ver] = now_depth;
    dist[ver] = now_dist;
    parent[0][ver] = par;
    for (const Edge &e : graph[ver]) {
      if (e.dst != par) dfs(ver, e.dst, now_depth + 1, now_dist + e.cost);
    }
  }
};

int main() {
  int n; cin >> n;
  vector<vector<Edge> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(u, v, 1);
    graph[v].emplace_back(v, u, 1);
  }
  LCADoubling lca(graph);
  lca.build(0);
  int q; cin >> q;
  while (q--) {
    int x, y, a, b, k; cin >> x >> y >> a >> b >> k; --x; --y; --a; --b;
    int d = lca.distance(a, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    d = lca.distance(a, x) + 1 + lca.distance(y, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    d = lca.distance(a, y) + 1 + lca.distance(x, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    d = lca.distance(a, x) + lca.distance(x, y) + 1 + lca.distance(x, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    d = lca.distance(a, x) + lca.distance(x, y) + 2 + lca.distance(y, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    d = lca.distance(a, y) + lca.distance(x, y) + 1 + lca.distance(y, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    d = lca.distance(a, y) + lca.distance(x, y) + 2 + lca.distance(x, b);
    if (d <= k && (k - d) % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}