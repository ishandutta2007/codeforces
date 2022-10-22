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

struct LowestCommonAncestorByDoubling {
  std::vector<int> depth, dist;

  LowestCommonAncestorByDoubling(const std::vector<std::vector<int>> &graph) : graph(graph) {
    n = graph.size();
    depth.resize(n);
    dist.resize(n);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, std::vector<int>(n));
  }

  void build(int root = 0) {
    is_built = true;
    dfs(-1, root, 0, 0);
    for (int i = 0; i + 1 < table_h; ++i) for (int ver = 0; ver < n; ++ver) {
      parent[i + 1][ver] = parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]];
    }
  }

  int query(int u, int v) const {
    assert(is_built);
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int i = 0; i < table_h; ++i) {
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

  int distance(int u, int v) const {
    assert(is_built);
    return dist[u] + dist[v] - dist[query(u, v)] * 2;
  }

private:
  bool is_built = false;
  int n, table_h = 1;
  std::vector<std::vector<int>> graph, parent;

  void dfs(int par, int ver, int now_depth, int now_dist) {
    depth[ver] = now_depth;
    dist[ver] = now_dist;
    parent[0][ver] = par;
    for (int e : graph[ver]) {
      if (e != par) dfs(ver, e, now_depth + 1, now_dist + 1);
    }
  }
};

void solve() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> child(n, 1);
  auto f = [&](auto &&f, int par, int ver) -> void {
    for (int e : graph[ver]) {
      if (e != par) {
        f(f, ver, e);
        child[ver] += child[e];
      }
    }
  };
  f(f, -1, 0);
  assert(child[0] == n);
  LowestCommonAncestorByDoubling lca(graph);
  lca.build(0);
  vector<ll> ans(n + 1, 0);
  ans[0] = n * (n - 1LL) / 2;
  for (int e : graph[0]) ans[1] += 1LL * child[e] * (n - child[e]);
  ans[1] = (ans[1] + n - 1) / 2;
  int l = 0, r = 1, l_child = n;
  for (int e : graph[0]) {
    if (lca.query(e, 1) == e) {
      l_child -= child[e];
      break;
    }
  }
  ans[2] = 1LL * l_child * child[r];
  FOR(i, 2, n) {
    if (lca.query(l, i) == i || lca.query(i, r) == i) {
      ans[i + 1] = ans[i];
    } else {
      if (int lc = lca.query(r, i); lc == r) {
        r = i;
      } else if (lc != 0) {
        break;
      } else if (l == 0) {
        l = i;
      } else if (int lc = lca.query(i, l); lc == l) {
        l = i;
      } else {
        break;
      }
      if (l == i) l_child = child[l];
      ans[i + 1] = 1LL * l_child * child[r];
    }
  }
  REP(i, n) ans[i] -= ans[i + 1];
  REP(i, n + 1) cout << ans[i] << " \n"[i == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}