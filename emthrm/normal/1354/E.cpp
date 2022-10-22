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

struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) { return root(u) == root(v); }

  int size(int ver) { return -data[root(ver)]; }

private:
  vector<int> data;
};

using CostType = bool;
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

bool is_bipartite(const vector<vector<Edge>> &graph, vector<int> &color) {
  int n = graph.size();
  color.assign(n, 0);
  function<bool(int, int)> dfs = [&](int ver, int now) {
    color[ver] = now;
    for (const Edge &e : graph[ver]) {
      if (color[e.dst] == now || (color[e.dst] == 0 && !dfs(e.dst, -now))) return false;
    }
    return true;
  };
  REP(i, n) {
    if (color[i] == 0 && !dfs(i, 1)) return false;
  }
  return true;
}

int main() {
  int n, m, n1, n2, n3; cin >> n >> m >> n1 >> n2 >> n3;
  UnionFind uf(n);
  vector<vector<int>> g(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    uf.unite(u, v);
  }
  map<int, vector<int>> rt;
  REP(i, n) rt[uf.root(i)].emplace_back(i);
  vector dp(1, vector(n2 + 1, false));
  vector prev(1, vector(n2 + 1, -1));
  vector<vector<int>> white(1), black(1);
  dp[0][0] = true;
  for (auto [ignore, vers] : rt) {
    map<int, int> mp;
    vector<int> rev;
    for (int e : vers) {
      mp[e] = rev.size();
      rev.emplace_back(e);
    }
    int l = vers.size();
    vector<vector<Edge>> graph(l);
    for (int src : vers) for (int dst : g[src]) graph[mp[src]].emplace_back(mp[src], mp[dst]);
    vector<int> color;
    if (!is_bipartite(graph, color)) {
      cout << "NO\n";
      return 0;
    }
    int idx = white.size();
    white.emplace_back();
    black.emplace_back();
    REP(i, l) (color[i] == 1 ? white[idx] : black[idx]).emplace_back(rev[i]);
    int w = white.back().size(), b = black.back().size();
    dp.emplace_back(n2 + 1, false);
    prev.emplace_back(n2 + 1, -1);
    REP(i, n2 + 1) {
      if (i - w >= 0 && dp[idx - 1][i - w]) {
        dp[idx][i] = true;
        prev[idx][i] = 0;
      }
      if (i - b >= 0 && dp[idx - 1][i - b]) {
        dp[idx][i] = true;
        prev[idx][i] = 1;
      }
    }
  }
  int i = dp.size() - 1, j = n2;
  // for (int k = 1; k <= i; ++k) {
  //   cout << "W:";
  //   for (int e : white[k]) cout << ' ' << e;
  //   cout << "  B:";
  //   for (int e : black[k]) cout << ' ' << e;
  //   cout << '\n';
  // }
  if (!dp[i][j]) {
    cout << "NO\n";
    return 0;
  }
  vector<int> ans(n, 0);
  for (; i > 0; --i) {
    if (prev[i][j] == 0) {
      for (int e : white[i]) ans[e] = 2;
      for (int e : black[i]) ans[e] = 1;
      j -= white[i].size();
    } else if (prev[i][j] == 1) {
      for (int e : white[i]) ans[e] = 1;
      for (int e : black[i]) ans[e] = 2;
      j -= black[i].size();
    }
  }
  REP(i, n) {
    if (ans[i] == 1 && n3 > 0) {
      ans[i] = 3;
      --n3;
    }
  }
  cout << "YES\n";
  REP(i, n) cout << ans[i];
  cout << '\n';
  return 0;
}