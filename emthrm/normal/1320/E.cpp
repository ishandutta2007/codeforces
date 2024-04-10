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

int main() {
  int n; cin >> n;
  vector<vector<Edge>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(x, y, 1);
    graph[y].emplace_back(y, x, 1);
  }
  LCADoubling lca(graph);
  lca.build(0);
  vector<int> tra(n, -1);
  function<void(int, int&)> dfs = [&](int ver, int &t) {
    tra[ver] = t++;
    for (const Edge &e : graph[ver]) {
      if (tra[e.dst] == -1) dfs(e.dst, t);
    }
  };
  int t = 0;
  dfs(0, t);
  // REP(i, n) cout << tra[i] << " \n"[i + 1 == n];
  int q; cin >> q;
  while (q--) {
    int k, m; cin >> k >> m;
    vector<int> v(k), s(k), u(m), vers(k + m);
    REP(i, k) {
      cin >> v[i] >> s[i]; --v[i];
      vers[i] = v[i];
    }
    REP(i, m) {
      cin >> u[i]; --u[i];
      vers[k + i] = u[i];
    }
    sort(ALL(vers), [&](int a, int b) { return tra[a] < tra[b]; });
    vers.erase(unique(ALL(vers)), vers.end());
    for (int i = 1, sz = vers.size(); i < sz; ++i) vers.emplace_back(lca.query(vers[i - 1], vers[i]));
    sort(ALL(vers), [&](int a, int b) { return tra[a] < tra[b]; });
    vers.erase(unique(ALL(vers)), vers.end());
    int x = vers.size();
    map<int, int> mp;
    REP(i, x) mp[vers[i]] = i;
    vector<vector<Edge>> g(x);
    vector<int> sta{0};
    FOR(i, 1, x) {
      while (lca.query(vers[sta.back()], vers[i]) != vers[sta.back()]) sta.pop_back();
      g[sta.back()].emplace_back(sta.back(), i, lca.distance(vers[sta.back()], vers[i]));
      g[i].emplace_back(i, sta.back(), lca.distance(vers[sta.back()], vers[i]));
      sta.emplace_back(i);
    }
    // REP(i, x) for (const Edge &e : g[i]) {
    //   if (i < e.dst) cout << i << ' ' << e.dst << ' ' << e.cost << '\n';
    // }
    LCADoubling lca_g(g);
    lca_g.build(0);
    vector<pair<int, int>> dist(x, {n + 1, x});
    using P = pair<pair<int, int>, int>;
    priority_queue<P, vector<P>, greater<P>> que;
    REP(i, k) {
      dist[mp[v[i]]] = {0, i};
      que.emplace(dist[mp[v[i]]], mp[v[i]]);
    }
    while (!que.empty()) {
      auto [turn, type] = que.top().first;
      int ver = que.top().second;
      que.pop();
      if (dist[ver].first < turn) continue;
      if (dist[ver].second < type) continue;
      // cout << turn << ' ' << type << ' ' << ver << '\n';
      for (const Edge &e : g[ver]) {
        int tm = (lca_g.distance(mp[v[type]], e.dst) + s[type] - 1) / s[type];
        if (tm < dist[e.dst].first || (tm == dist[e.dst].first && type < dist[e.dst].second)) {
          dist[e.dst] = {tm, type};
          que.emplace(dist[e.dst], e.dst);
        }
      }
    }
    REP(i, m) cout << dist[mp[u[i]]].second + 1 << " \n"[i + 1 == m];
  }
  return 0;
}