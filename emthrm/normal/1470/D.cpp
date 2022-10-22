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

bool is_bipartite(const std::vector<std::vector<int>> &graph, std::vector<int> &color) {
  int n = graph.size();
  color.assign(n, 0);
  std::function<bool(int, int)> dfs = [&graph, &color, &dfs](int ver, int now) -> bool {
    color[ver] = now;
    for (int e : graph[ver]) {
      if (color[e] == now || (color[e] == 0 && !dfs(e, -now))) return false;
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0 && !dfs(i, 1)) return false;
  }
  return true;
}

void solve() {
  int n, m; cin >> n >> m;
  UnionFind uf(n);
  vector<vector<int>> graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    uf.unite(u, v);
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  if (uf.size(0) < n) {
    cout << "NO\n";
    return;
  }
  vector<int> is_tea(n, -1);
  is_tea[0] = 1;
  queue<int> que1({0}), que2;
  map<int, int> vis;
  while (!que1.empty() || !que2.empty()) {
    if (!que1.empty()) {
      int v = que1.front(); que1.pop();
      assert(is_tea[v] == 1);
      for (int e : graph[v]) {
        assert(is_tea[e] != 1);
        if (is_tea[e] == -1) {
          is_tea[e] = 0;
          que2.emplace(e);
        }
      }
    } else {
      int v = que2.front();
      if (vis.count(v) == 0) vis[v] = 0;
      while (vis[v] < graph[v].size()) {
        int e = graph[v][vis[v]++];
        if (is_tea[e] == -1) {
          is_tea[e] = 1;
          que1.emplace(e);
          break;
        }
      }
      if (vis[v] == graph[v].size()) que2.pop();
    }
  }
  vector<int> ans;
  REP(i, n) {
    if (is_tea[i] == 1) ans.emplace_back(i);
  }
  int tea = ans.size();
  cout << "YES\n" << tea << '\n';
  REP(i, tea) cout << ans[i] + 1 << " \n"[i + 1 == tea];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}