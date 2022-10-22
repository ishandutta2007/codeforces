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

struct LCADoubling {
  std::vector<int> depth, dist;
  int table_h = 1;
  std::vector<std::vector<int>> parent;

  LCADoubling(const std::vector<std::vector<int>> &graph) : graph(graph) {
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
  int n;
  std::vector<std::vector<int>> graph;

  void dfs(int par, int ver, int now_depth, int now_dist) {
    depth[ver] = now_depth;
    dist[ver] = now_dist;
    parent[0][ver] = par;
    for (int e : graph[ver]) {
      if (e != par) dfs(ver, e, now_depth + 1, now_dist + 1);
    }
  }
};

struct HLD {
  std::vector<int> parent, subtree, id, inv, head;

  HLD(const std::vector<std::vector<int>> &graph, int root = 0) : graph(graph) {
    int n = graph.size();
    parent.assign(n, -1);
    subtree.assign(n, 1);
    id.resize(n);
    inv.resize(n);
    head.resize(n);
    dfs1(root);
    head[root] = root;
    int now_id = 0;
    dfs2(root, now_id);
  }

  template <typename Fn>
  void v_update(int u, int v, Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      f(std::max(id[head[v]], id[u]), id[v] + 1);
      if (head[u] == head[v]) return;
      v = parent[head[v]];
    }
  }

  template <typename T, typename F, typename G>
  T v_query(int u, int v, F f, G g, const T ID) const {
    T left = ID, right = ID;
    while (true) {
      if (id[u] > id[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      left = g(left, f(std::max(id[head[v]], id[u]), id[v] + 1));
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
    return g(left, right);
  }

  template <typename Fn>
  void subtree_v_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]); }

  template <typename T, typename Fn>
  T subtree_v_query(int ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver]); }

  template <typename Fn>
  void e_update(int u, int v, Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) {
        f(id[u], id[v]);
        break;
      } else {
        f(id[head[v]] - 1, id[v]);
        v = parent[head[v]];
      }
    }
  }

  template <typename T, typename F, typename G>
  T e_query(int u, int v, F f, G g, const T ID) const {
    T left = ID, right = ID;
    while (true) {
      if (id[u] > id[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      if (head[u] == head[v]) {
        left = g(left, f(id[u], id[v]));
        break;
      } else {
        left = g(left, f(id[head[v]] - 1, id[v]));
        v = parent[head[v]];
      }
    }
    return g(left, right);
  }

  template <typename Fn>
  void subtree_e_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver] - 1); }

  template <typename T, typename Fn>
  T subtree_e_query(int ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver] - 1); }

  int lca(int u, int v) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = parent[head[v]];
    }
  }

private:
  std::vector<std::vector<int>> graph;

  void dfs1(int ver) {
    for (int &e : graph[ver]) {
      if (e != parent[ver]) {
        parent[e] = ver;
        dfs1(e);
        subtree[ver] += subtree[e];
        if (subtree[e] > subtree[graph[ver].front()]) std::swap(e, graph[ver].front());
      }
    }
  }

  void dfs2(int ver, int &now_id) {
    id[ver] = now_id++;
    inv[id[ver]] = ver;
    for (int e : graph[ver]) {
      if (e != parent[ver]) {
        head[e] = (e == graph[ver].front() ? head[ver] : e);
        dfs2(e, now_id);
      }
    }
  }
};

template <typename Abelian>
struct BIT {
  BIT(int n, const Abelian ID = 0) : n(n), ID(ID), dat(n, ID) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat;
};

int main() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  LCADoubling lca(graph);
  lca.build(0);
  auto f = [&](int v, int l) {
    assert(lca.depth[v] > lca.depth[l]);
    int d = lca.depth[v] - lca.depth[l] - 1, sub = v;
    REP(i, lca.table_h) {
      if (d >> i & 1) sub = lca.parent[i][sub];
    }
    return sub;
  };
  vector<int> cnt(n, 0);
  vector<map<int, int>> mp1(n);
  vector<map<pair<int, int>, int>> mp2(n);
  vector<vector<pair<int, int>>> vs(n);
  vector<vector<int>> sub(n);
  int m; cin >> m;
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    int l = lca.query(u, v);
    ++cnt[l];
    if (l == u && l == v) {
      // do nothing
    } else if (l == u || l == v) {
      int a = f(l == u ? v : u, l);
      ++mp1[l][a];
      vs[l].emplace_back(a, l == u ? v : u);
      sub[l].emplace_back(a);
    } else {
      int a = f(u, l), b = f(v, l);
      vs[l].emplace_back(a, u);
      vs[l].emplace_back(b, v);
      if (a > b) swap(a, b);
      ++mp1[l][a];
      ++mp1[l][b];
      ++mp2[l][{a, b}];
      sub[l].emplace_back(a);
      sub[l].emplace_back(b);
    }
  }
  // REP(i, n) cout << cnt[i] << " \n"[i + 1 == n];
  // REP(i, n) {
  //   cout << i << ": ";
  //   for (auto [k, v] : mp1[i]) cout << '{' << k << ',' << v << "} ";
  //   cout << '\n';
  // }
  ll ans = 0;
  REP(i, n) {
    ans += cnt[i] * (cnt[i] - 1LL) / 2;
    for (auto [_, v] : mp1[i]) ans -= v * (v - 1LL) / 2;
    for (auto [_, v] : mp2[i]) ans += v * (v - 1LL) / 2;
  }
  vector<int> ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int l, int r) { return lca.depth[l] > lca.depth[r]; });
  HLD hld(graph, 0);
  BIT<ll> bit(n);
  for (int ver : ord) {
    // cout << ver << ": ";
    for (auto [a, v] : vs[ver]) {
      // cout << '{' << a << ',' << v << "} ";
      ans += hld.v_query(a, v,
                         [&](int l, int r) { return bit.sum(l, r); },
                         [](ll l, ll r) { return l + r; }, 0LL);
    }
    // cout << '\n';
    bit.add(hld.id[ver], cnt[ver]);
    for (int child : sub[ver]) bit.add(hld.id[child], -1);
    // REP(i, n) cout << bit[i] << " \n"[i + 1 == n];
  }
  cout << ans << '\n';
  return 0;
}