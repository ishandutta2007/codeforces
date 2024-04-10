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

  LCADoubling(const vector<vector<Edge>> &graph) : graph(graph) {
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
  vector<vector<Edge>> graph;
  vector<vector<int>> parent;

  void dfs(int par, int ver, int now_depth, CostType now_dist) {
    depth[ver] = now_depth;
    dist[ver] = now_dist;
    parent[0][ver] = par;
    for (const Edge &e : graph[ver]) {
      if (e.dst != par) dfs(ver, e.dst, now_depth + 1, now_dist + e.cost);
    }
  }
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
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> g(n);
  vector<int> u(m), v(m);
  REP(i, m) {
    cin >> u[i] >> v[i]; --u[i]; --v[i];
    g[u[i]].emplace_back(v[i]);
    g[v[i]].emplace_back(u[i]);
  }
  vector<int> rev(k);
  {
    map<int, int> mp;
    mp[0] = 0;
    rev[0] = 0;
    queue<int> que;
    que.emplace(0);
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (int e : g[ver]) {
        if (mp.size() < k && mp.count(e) == 0) {
          int sz = mp.size();
          mp[e] = sz;
          rev[sz] = e;
          que.emplace(e);
        }
      }
    }
    g.clear();
    g.resize(k);
    REP(i, m) {
      if (mp.count(u[i]) == 1 && mp.count(v[i]) == 1) {
        g[mp[u[i]]].emplace_back(mp[v[i]]);
        g[mp[v[i]]].emplace_back(mp[u[i]]);
      }
    }
  }
  vector<vector<Edge>> graph(k);
  vector<pair<int, int>> uv;
  vector<int> par(n, -1);
  queue<int> que;
  que.emplace(0);
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : g[ver]) {
      if (par[e] == -1 && e != 0) {
        graph[ver].emplace_back(ver, e, 1);
        par[e] = ver;
        que.emplace(e);
      } else {
        uv.emplace_back(ver, e);
      }
    }
  }
  LCADoubling lca(graph);
  lca.build(0);
  for (auto [u, v] : uv) {
    if (lca.distance(u, v) >= 2) {
      int l = lca.query(u, v);
      vector<int> ans;
      int ver = u;
      while (ver != l) {
        ans.emplace_back(ver);
        ver = par[ver];
      }
      reverse(ALL(ans));
      ver = v;
      while (ver != l) {
        ans.emplace_back(ver);
        ver = par[ver];
      }
      ans.emplace_back(l);
      cout << "2\n" << ans.size() << '\n';
      REP(i, ans.size()) cout << rev[ans[i]] + 1 << " \n"[i + 1 == ans.size()];
      return 0;
    }
  }
  vector<int> color;
  assert(is_bipartite(graph, color));
  vector<vector<int>> group(2);
  REP(i, k) group[max(color[i], 0)].emplace_back(i);
  if (group[0].size() < group[1].size()) swap(group[0], group[1]);
  group[0].resize((k + 1) / 2);
  cout << "1\n";
  REP(i, (k + 1) / 2) cout << rev[group[0][i]] + 1 << " \n"[i + 1 == (k + 1) / 2];
  return 0;
}