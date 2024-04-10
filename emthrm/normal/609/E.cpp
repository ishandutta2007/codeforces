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

template <typename CostType>
struct HLD {
  std::vector<int> parent, subtree, id, inv, head;
  std::vector<CostType> cost;

  HLD(const std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) : graph(graph) {
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
  std::vector<std::vector<Edge<CostType>>> graph;

  void dfs1(int ver) {
    for (Edge<CostType> &e : graph[ver]) {
      if (e.dst != parent[ver]) {
        parent[e.dst] = ver;
        dfs1(e.dst);
        subtree[ver] += subtree[e.dst];
        if (subtree[e.dst] > subtree[graph[ver].front().dst]) std::swap(e, graph[ver].front());
      }
    }
  }

  void dfs2(int ver, int &now_id) {
    id[ver] = now_id++;
    inv[id[ver]] = ver;
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != parent[ver]) {
        head[e.dst] = (e.dst == graph[ver].front().dst ? head[ver] : e.dst);
        cost.emplace_back(e.cost);
        dfs2(e.dst, now_id);
      }
    }
  }
};

template <typename MeetSemilattice>
struct SparseTable {
  using Fn = std::function<MeetSemilattice(MeetSemilattice, MeetSemilattice)>;

  SparseTable() {}

  SparseTable(const std::vector<MeetSemilattice> &a, Fn fn) { init(a, fn); }

  void init(const std::vector<MeetSemilattice> &a, Fn fn_) {
    is_built = true;
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    while ((1 << table_h) <= n) ++table_h;
    dat.assign(table_h, std::vector<MeetSemilattice>(n));
    for (int j = 0; j < n; ++j) dat[0][j] = a[j];
    for (int i = 1; i < table_h; ++i) for (int j = 0; j + (1 << i) <= n; ++j) {
      dat[i][j] = fn(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
    }
  }

  MeetSemilattice query(int left, int right) const {
    assert(is_built && left < right);
    int h = lg[right - left];
    return fn(dat[h][left], dat[h][right - (1 << h)]);
  }

private:
  bool is_built = false;
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<MeetSemilattice>> dat;
};

int main() {
  int n, m; cin >> n >> m;
  vector<pair<Edge<int>, int>> edges;
  REP(i, m) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    edges.emplace_back(Edge(a, b, c), i);
  }
  sort(ALL(edges));
  UnionFind uf(n);
  vector<int> base;
  ll cost = 0;
  vector<vector<Edge<int>>> graph(n);
  vector<pair<Edge<int>, int>> query;
  for (auto [e, idx] : edges) {
    if (uf.unite(e.src, e.dst)) {
      base.emplace_back(idx);
      cost += e.cost;
      graph[e.src].emplace_back(e);
      graph[e.dst].emplace_back(e.dst, e.src, e.cost);
    } else {
      query.emplace_back(e, idx);
    }
  }
  vector<ll> ans(m, LINF);
  for (int idx : base) ans[idx] = cost;
  HLD hld(graph);
  SparseTable<int> st(hld.cost, [](int a, int b) { return max(a, b); });
  for (auto [e, idx] : query) {
    ans[idx] = cost - hld.e_query<int>(e.src, e.dst, [&](int a, int b) { return a == b ? 0 : st.query(a, b); }, [](int a, int b) { return max(a, b); }, 0) + e.cost;
  }
  REP(i, m) cout << ans[i] << '\n';
  return 0;
}