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

struct LCADoubling {
  vector<int> depth;

  LCADoubling(const vector<vector<int>> &graph) {
    int n = graph.size();
    depth.assign(n, 0);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, vector<int>(n));
    function<void(int, int)> dfs = [&](int par, int ver) {
      parent[0][ver] = par;
      for (int e : graph[ver]) {
        if (e == par) continue;
        depth[e] = depth[ver] + 1;
        dfs(ver, e);
      }
    };
    dfs(-1, 0);
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

private:
  int table_h = 1;
  vector<vector<int>> parent;
};

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> depth(n, 0), par(n, -1);
  function<void(int)> dfs = [&](int ver) {
    for (int e : graph[ver]) {
      if (e == par[ver]) continue;
      depth[e] = depth[ver] + 1;
      par[e] = ver;
      dfs(e);
    }
  };
  dfs(0);
  LCADoubling lca(graph);
  function<void()> solve = [&]() {
    int k; cin >> k;
    vector<int> v(k);
    REP(i, k) {
      cin >> v[i], --v[i];
      if (v[i] > 0) v[i] = par[v[i]];
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)), v.end());
    sort(ALL(v), [&](int a, int b) { return depth[a] < depth[b]; });
    k = v.size();
    FOR(i, 1, k) {
      if (depth[v[i - 1]] == depth[v[i]]) {
        cout << "NO\n";
        return;
      }
    }
    for (int i = k - 1; i > 0; --i) {
      if (lca.query(v[i - 1], v[i]) != v[i - 1]) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  };
  while (m--) solve();
  return 0;
}