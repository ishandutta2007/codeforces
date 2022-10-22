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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
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
  UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) {
      std::swap(u, v);
    }
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) {
    return root(u) == root(v);
  }

  int size(const int ver) {
    return -data[root(ver)];
  }

private:
  std::vector<int> data;
};

bool is_bipartite(const std::vector<std::vector<int>> &graph, std::vector<int> &color) {
  const int n = graph.size();
  color.assign(n, -1);
  std::function<bool(int, int)> dfs = [&graph, &color, &dfs](const int ver, const int c) -> bool {
    color[ver] = c;
    for (const int e : graph[ver]) {
      if (color[e] == c || (color[e] == -1 && !dfs(e, c ^ 1))) return false;
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1 && !dfs(i, 0)) return false;
  }
  return true;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> is(m), js(m);
  vector<string> c(m);
  UnionFind uf(n);
  REP(i, m) {
    cin >> is[i] >> js[i] >> c[i]; --is[i]; --js[i];
    if (c[i] == "crewmate") uf.unite(is[i], js[i]);
  }
  vector<int> root, w;
  REP(i, n) {
    if (uf.root(i) == i) {
      root.emplace_back(i);
      w.emplace_back(uf.size(i));
    }
  }
  const int l = root.size();
  vector<vector<int>> graph(l);
  UnionFind uf2(l);
  REP(i, m) {
    is[i] = lower_bound(ALL(root), uf.root(is[i])) - root.begin();
    js[i] = lower_bound(ALL(root), uf.root(js[i])) - root.begin();
    if (c[i] == "imposter") {
      graph[is[i]].emplace_back(js[i]);
      graph[js[i]].emplace_back(is[i]);
      uf2.unite(is[i], js[i]);
    }
  }
  vector<int> color;
  if (!is_bipartite(graph, color)) {
    cout << "-1\n";
    return;
  }
  map<int, pair<int, int>> mp;
  REP(i, l) {
    if (color[i]) {
      mp[uf2.root(i)].second += w[i];
    } else {
      mp[uf2.root(i)].first += w[i];
    }
  }
  int ans = 0;
  for (auto [_, bw] : mp) ans += max(bw.first, bw.second);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}