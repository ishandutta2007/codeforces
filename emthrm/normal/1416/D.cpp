#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) { return root(u) == root(v); }

  int size(int ver) { return -data[root(ver)]; }

private:
  std::vector<int> data;
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
  T v_query(int u, int v, F f, G g, const T UNITY) const {
    T left = UNITY, right = UNITY;
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
  T e_query(int u, int v, F f, G g, const T UNITY) const {
    T left = UNITY, right = UNITY;
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
    for (int &e : graph[ver]) {
      if (e != parent[ver]) {
        head[e] = (e == graph[ver].front() ? head[ver] : e);
        dfs2(e, now_id);
      }
    }
  }
};

template <typename Monoid>
struct RMQ {
  RMQ(int sz, const Monoid UNITY) : UNITY(UNITY) {
    init(sz);
    dat.assign((n << 1) - 1, UNITY);
  }

  RMQ(const std::vector<Monoid> &a, const Monoid UNITY) : UNITY(UNITY) {
    int a_sz = a.size();
    init(a_sz);
    dat.resize((n << 1) - 1);
    for (int i = 0; i < a_sz; ++i) dat[n - 1 + i] = a[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = std::min(dat[(i << 1) + 1], dat[(i << 1) + 2]);
  }

  void update(int node, Monoid val) {
    node += n - 1;
    dat[node] = val;
    while (node > 0) {
      node = (node - 1) >> 1;
      dat[node] = std::min(dat[(node << 1) + 1], dat[(node << 1) + 2]);
    }
  }

  Monoid query(int a, int b) const { return query(a, b, 0, 0, n); }

  int find(int a, int b, Monoid val) const { return find(a, b, val, 0, 0, n); }

  Monoid operator[](const int idx) const { return dat[idx + n - 1]; }

private:
  int n = 1;
  const Monoid UNITY;
  std::vector<Monoid> dat;

  void init(int sz) { while (n < sz) n <<= 1; }

  Monoid query(int a, int b, int node, int left, int right) const {
    if (right <= a || b <= left) return UNITY;
    if (a <= left && right <= b) return dat[node];
    return std::min(query(a, b, (node << 1) + 1, left, (left + right) >> 1), query(a, b, (node << 1) + 2, (left + right) >> 1, right));
  }

  int find(int a, int b, Monoid val, int node, int left, int right) const {
    if (dat[node] > val || right <= a || b <= left) return -1;
    if (right - left == 1) return node - (n - 1);
    int res_l = find(a, b, val, (node << 1) + 1, left, (left + right) >> 1);
    return res_l == -1 ? find(a, b, val, (node << 1) + 2, (left + right) >> 1, right) : res_l;
    // int res_r = find(a, b, val, (node << 1) + 2, (left + right) >> 1, right);
    // return res_r == -1 ? find(a, b, val, (node << 1) + 1, left, (left + right) >> 1) : res_r;
  }
};

int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<int> p(n); REP(i, n) cin >> p[i], --p[i];
  vector<int> a(m), b(m);
  REP(i, m) {
    cin >> a[i] >> b[i]; --a[i]; --b[i];
    a[i] = p[a[i]];
    b[i] = p[b[i]];
  }
  vector<bool> rem(m, true);
  vector<int> query(q), v(q);
  REP(i, q) {
    cin >> query[i] >> v[i]; --v[i];
    if (query[i] == 1) {
      v[i] = p[v[i]];
    } else if (query[i] == 2) {
      rem[v[i]] = false;
    }
  }
  UnionFind uf(n);
  REP(i, m) {
    if (rem[i]) uf.unite(a[i], b[i]);
  }
  vector<vector<int>> graph(n);
  vector<int> idx(n, INF);
  map<int, int> mp;
  REP(i, n) {
    int rt = uf.root(i);
    if (mp.count(rt) == 0) {
      int sz = graph.size();
      graph.emplace_back();
      idx.emplace_back(INF);
      mp[rt] = sz;
    }
    graph[mp[rt]].emplace_back(i);
    graph[i].emplace_back(mp[rt]);
  }
  vector<int> cor(q, -1);
  for (int i = q - 1; i >= 0; --i) {
    int sz = graph.size();
    if (query[i] == 1) {
      graph.emplace_back();
      int rt = uf.root(v[i]);
      idx.emplace_back(i);
      cor[i] = sz;
      graph[sz].emplace_back(mp[rt]);
      mp[rt] = sz;
    } else if (query[i] == 2) {
      int rt1 = uf.root(a[v[i]]), rt2 = uf.root(b[v[i]]);
      if (rt1 == rt2) continue;
      graph.emplace_back();
      idx.emplace_back(INF);
      graph[sz].emplace_back(mp[rt1]);
      graph[sz].emplace_back(mp[rt2]);
      uf.unite(rt1, rt2);
      int ne = uf.root(rt1);
      if (rt1 != ne) swap(rt1, rt2);
      mp[ne] = sz;
      mp.erase(rt2);
    }
  }
  int sz = graph.size();
  graph.emplace_back();
  idx.emplace_back(INF);
  for (auto pr : mp) graph[sz].emplace_back(pr.second);
  int x = graph.size();
  HLD hld(graph, x - 1);
  RMQ<int> rmq(x, INF);
  REP(i, x) rmq.update(hld.id[i], idx[i]);
  auto f = [&](int a, int b) { return rmq.query(a, b); };
  auto g = [](int a, int b) { return min(a, b); };
  vector<int> ans(q, -1);
  for (int i = n - 1; i >= 0; --i) {
    int pos = hld.v_query(i, x - 1, f, g, INF);
    if (pos != INF) {
      ans[pos] = i + 1;
      rmq.update(hld.id[cor[pos]], INF);
    }
  }
  REP(i, q) {
    if (query[i] == 1) cout << (ans[i] == -1 ? 0 : ans[i]) << '\n';
  }
  return 0;
}