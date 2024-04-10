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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct UnionFind {
  explicit UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) { return root(u) == root(v); }

  int size(const int ver) { return -data[root(ver)]; }

 private:
  std::vector<int> data;
};

struct HeavyLightDecomposition {
  std::vector<int> parent, subtree, id, inv, head;

  explicit HeavyLightDecomposition(const std::vector<std::vector<int>>& graph,
                                   const int root = 0)
      : graph(graph) {
    const int n = graph.size();
    parent.assign(n, -1);
    subtree.assign(n, 1);
    dfs1(root);
    id.resize(n);
    inv.resize(n);
    head.assign(n, root);
    int cur_id = 0;
    dfs2(root, &cur_id);
  }

  template <typename Fn>
  void update_v(int u, int v, const Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      f(std::max(id[head[v]], id[u]), id[v] + 1);
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
  }

  template <typename F, typename G, typename T>
  T query_v(int u, int v, const F f, const G g, const T id_t) const {
    T left = id_t, right = id_t;
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
  void update_subtree_v(const int ver, const Fn f) const {
    f(id[ver], id[ver] + subtree[ver]);
  }

  template <typename T, typename Fn>
  T query_subtree_v(const int ver, const Fn f) const {
    return f(id[ver], id[ver] + subtree[ver]);
  }

  template <typename Fn>
  void update_e(int u, int v, const Fn f) const {
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

  template <typename F, typename G, typename T>
  T query_e(int u, int v, const F f, const G g, const T id_t) const {
    T left = id_t, right = id_t;
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
  void update_subtree_e(const int ver, const Fn f) const {
    f(id[ver], id[ver] + subtree[ver] - 1);
  }

  template <typename T, typename Fn>
  T query_subtree_e(const int ver, const Fn f) const {
    return f(id[ver], id[ver] + subtree[ver] - 1);
  }

  int lowest_common_ancestor(int u, int v) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
    return u;
  }

 private:
  std::vector<std::vector<int>> graph;

  void dfs1(const int ver) {
    for (int i = 0; i < graph[ver].size(); ++i) {
      if (graph[ver][i] != parent[ver]) {
        parent[graph[ver][i]] = ver;
        dfs1(graph[ver][i]);
        subtree[ver] += subtree[graph[ver][i]];
        if (subtree[graph[ver][i]] > subtree[graph[ver].front()]) {
          std::swap(graph[ver][i], graph[ver].front());
        }
      }
    }
  }

  void dfs2(const int ver, int* cur_id) {
    id[ver] = (*cur_id)++;
    inv[id[ver]] = ver;
    for (const int e : graph[ver]) {
      if (e != parent[ver]) {
        head[e] = (e == graph[ver].front() ? head[ver] : e);
        dfs2(e, cur_id);
      }
    }
  }
};

struct LowestCommonAncestorByDoubling {
  std::vector<int> depth, dist;

  explicit LowestCommonAncestorByDoubling(
      const std::vector<std::vector<int>>& graph)
      : is_built(false), n(graph.size()), table_h(1), graph(graph) {
    depth.resize(n);
    dist.resize(n);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, std::vector<int>(n));
  }

  void build(int root = 0) {
    is_built = true;
    dfs(-1, root, 0, 0);
    for (int i = 0; i + 1 < table_h; ++i) {
      for (int ver = 0; ver < n; ++ver) {
        parent[i + 1][ver] =
            (parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]]);
      }
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
    return parent.front()[u];
  }

  int distance(const int u, const int v) const {
    assert(is_built);
    return dist[u] + dist[v] - dist[query(u, v)] * 2;
  }

  std::vector<std::vector<int>> parent;
 private:
  bool is_built;
  const int n;
  int table_h;
  const std::vector<std::vector<int>> graph;

  void dfs(const int par, const int ver, const int cur_depth,
           const int cur_dist) {
    depth[ver] = cur_depth;
    dist[ver] = cur_dist;
    parent.front()[ver] = par;
    for (const int e : graph[ver]) {
      if (e != par) dfs(ver, e, cur_depth + 1, cur_dist + 1);
    }
  }
};

template <typename Abelian>
struct FenwickTreeSupportingRangeAddQuery {
  explicit FenwickTreeSupportingRangeAddQuery(
      const int n_, const Abelian ID = 0)
      : n(n_ + 1), ID(ID) {
    data_const.assign(n, ID);
    data_linear.assign(n, ID);
  }

  void add(int left, const int right, const Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      data_const[i] -= val * (left - 1);
      data_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      data_const[i] += val * right;
      data_linear[i] -= val;
    }
  }

  Abelian sum(const int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) {
      res += data_linear[i];
    }
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) {
      res += data_const[i];
    }
    return res;
  }

  Abelian sum(const int left, const int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

 private:
  const int n;
  const Abelian ID;
  std::vector<Abelian> data_const, data_linear;
};

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<pair<int, int>> backedge;
  backedge.reserve(m - (n - 1));
  UnionFind union_find(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    if (union_find.unite(u, v)) {
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    } else {
      backedge.emplace_back(u, v);
    }
  }
  const int root = 0;
  HeavyLightDecomposition hld(graph, root);
  LowestCommonAncestorByDoubling lca(graph);
  lca.build(root);
  FenwickTreeSupportingRangeAddQuery<ll> bit(n);
  const auto add = [&](int v, const int d = 1) -> void {
    hld.update_subtree_v(v, [&](const int l, const int r) -> void { bit.add(l, r, d); });
  };
  for (auto& [u, v] : backedge) {
    const int l = lca.query(u, v);
    if (l != u && l != v) {
      add(u);
      add(v);
      continue;
    }
    if (l == v) swap(u, v);
    int child = v;
    for (int bit = 0, d = lca.depth[v] - lca.depth[u] - 1; d > 0; ++bit, d >>= 1) {
      if (d & 1) child = lca.parent[bit][child];
    }
    add(0);
    add(child, -1);
    add(v);
  }
  REP(i, n) cout << (bit[hld.id[i]] == backedge.size() ? 1 : 0);
  cout << '\n';
  return 0;
}