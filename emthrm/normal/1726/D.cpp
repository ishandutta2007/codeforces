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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

std::vector<int> detect_path(const std::vector<std::vector<int>>& graph,
                             const int s, const int t) {
  std::vector<bool> is_visited(graph.size(), false);
  std::vector<int> path{s};
  const std::function<bool(const int)> dfs =
      [&graph, t, &is_visited, &path, &dfs](const int ver) -> bool {
        if (ver == t) return true;
        is_visited[ver] = true;
        for (const int e : graph[ver]) {
          if (!is_visited[e]) {
            path.emplace_back(e);
            if (dfs(e)) return true;
            path.pop_back();
          }
        }
        return false;
      };
  return dfs(s) ? path : std::vector<int>{};
}

bool is_triangle(vector<pair<int, int>> edges) {
  if (edges.size() != 3) return false;
  sort(ALL(edges));
  const auto [u0, v0] = edges[0];
  const auto [u1, v1] = edges[1];
  const auto [u2, v2] = edges[2];
  return u0 == u1 && v0 == u2 && v1 == v2;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> tree(n);
  map<pair<int, int>, int> ids;
  vector<pair<int, int>> bad_edges;
  string ans(m, '0');
  UnionFind union_find(n);
  REP(i, m) {
    int u, v; cin >> u >> v; --u; --v;
    ids[minmax(u, v)] = i;
    if (union_find.unite(u, v)) {
      tree[u].emplace_back(v);
      tree[v].emplace_back(u);
    } else {
      bad_edges.emplace_back(minmax(u, v));
      ans[i] = '1';
    }
  }
  if (is_triangle(bad_edges)) {
    const auto [u, v] = bad_edges.front();
    const vector<int> path = detect_path(tree, u, v);
    swap(ans[ids[bad_edges.front()]], ans[ids[minmax(path[0], path[1])]]);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}