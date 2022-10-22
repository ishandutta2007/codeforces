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

 private:
  bool is_built;
  const int n;
  int table_h;
  const std::vector<std::vector<int>> graph;
  std::vector<std::vector<int>> parent;

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

void solve() {
  int n; cin >> n;
  vector s(n, vector(n, string(0, '$'))); REP(i, n) FOR(j, i + 1, n) cin >> s[i][j];
  vector union_find(n, UnionFind(n));
  REP(root, n) REP(i, n) FOR(j, i + 1, n) {
    if (s[i][j][root] == '1') union_find[root].unite(i, j);
  }
  vector<map<int, vector<int>>> components(n);
  REP(root, n) {
    if (union_find[root].size(root) != 1) {
      cout << "No\n";
      return;
    }
    REP(i, n) components[root][union_find[root].root(i)].emplace_back(i);
  }
  vector<vector<int>> tree(n);
  vector<int> is_visited(n, false);
  for (const auto [_, children] : components[0]) {
    if (children.size() == 1 && children.front() == 0) continue;
    REP(i, n) tree[i].clear();
    fill(ALL(is_visited), false);
    is_visited[0] = true;
    auto f = [&](auto&& f, int par, int ver) -> bool {
      if (is_visited[ver]) return false;
      is_visited[ver] = true;
      for (int child : components[ver][union_find[ver].root(par)]) {
        if (child == par) continue;
        tree[ver].emplace_back(child);
        if (!f(f, ver, child)) return false;
      }
      return true;
    };
    bool is_valid = true;
    for (const int child : children) {
      tree[0].emplace_back(child);
      if (!f(f, 0, child)) {
        is_valid = false;
        break;
      }
    }
    if (is_valid && find(ALL(is_visited), false) == is_visited.end()) {
      LowestCommonAncestorByDoubling lca(tree);
      lca.build(0);
      if ([&]() -> bool {
            REP(i, n) FOR(j, i + 1, n) REP(k, n) {
              if ((lca.distance(i, k) == lca.distance(j, k)) != (s[i][j][k] == '1')) return false;
            }
            return true;
          } ()) {
        cout << "Yes\n";
        REP(i, n) for (int j : tree[i]) cout << i + 1 << ' ' << j + 1 << '\n';
        return;
      }
    }
  }
  cout << "No\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}