#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
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
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
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
  int n, m; cin >> n >> m;
  vector<vector<int> > graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  const int x = ceil(sqrt(n));
  vector<int> par(n, -1), u, v;
  vector<vector<Edge> > tree(n);
  function<void(int)> dfs = [&](int ver) {
    for (int e : graph[ver]) {
      if (e == par[ver]) continue;
      if (par[e] == -1 && e != 0) {
        par[e] = ver;
        tree[ver].emplace_back(ver, e, 1);
        dfs(e);
      } else {
        u.emplace_back(ver);
        v.emplace_back(e);
      }
    }
  };
  dfs(0);
  LCADoubling lca(tree);
  lca.build(0);
  REP(i, u.size()) {
    // cout << u[i] << ' ' << v[i] << '\n';
    if (lca.distance(u[i], v[i]) >= x - 1) {
      int l = lca.query(u[i], v[i]);
      vector<int> ans;
      int now = u[i];
      while (now != l) {
        ans.emplace_back(now);
        now = par[now];
      }
      reverse(ALL(ans));
      now = v[i];
      while (now != l) {
        ans.emplace_back(now);
        now = par[now];
      }
      ans.emplace_back(l);
      cout << "2\n" << ans.size() << '\n';
      REP(j, ans.size()) cout << ans[j] + 1 << " \n"[j + 1 == ans.size()];
      return 0;
    }
  }
  int y = floor(sqrt(n));
  vector<vector<int> > vers(y);
  REP(i, n) vers[lca.dist[i] % y].emplace_back(i);
  REP(i, y) {
    // REP(j, vers[i].size()) cout << vers[i][j] << " \n"[j + 1 == vers[i].size()];
    if (vers[i].size() >= x) {
      cout << "1\n";
      sort(ALL(vers[i]));
      REP(j, x) cout << vers[i][j] + 1 << " \n"[j + 1 == x];
      return 0;
    }
  }
}