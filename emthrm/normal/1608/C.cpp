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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct StronglyConnectedComponents {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, comp;

  StronglyConnectedComponents(const std::vector<std::vector<int>> &graph, bool heavy = false) : graph(graph), heavy(heavy) {
    n = graph.size();
    rev_graph.resize(n);
    for (int i = 0; i < n; ++i) for (int e : graph[i]) rev_graph[e].emplace_back(i);
    used.assign(n, false);
    id.assign(n, -1);
    for (int i = 0; i < n; ++i) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[order[i]] == -1) {
        if (heavy) vertices.emplace_back();
        rev_dfs(order[i], now++);
      }
    }
    comp.resize(now);
    for (int i = 0; i < n; ++i) for (int e : graph[i]) {
      if (id[i] != id[e]) comp[id[i]].emplace_back(id[e]);
    }
    // if (heavy) {
    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }

private:
  bool heavy;
  int n;
  std::vector<std::vector<int>> graph, rev_graph;
  std::vector<bool> used;
  std::vector<int> order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    if (heavy) vertices[now].emplace_back(ver);
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  const int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    const int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (const int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  vector<int> ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int l, int r) -> bool { return a[l] < a[r]; });
  vector<vector<int>> graph(n);
  REP(i, n - 1) graph[ord[i + 1]].emplace_back(ord[i]);
  sort(ALL(ord), [&](int l, int r) -> bool { return b[l] < b[r]; });
  REP(i, n - 1) graph[ord[i + 1]].emplace_back(ord[i]);
  StronglyConnectedComponents scc(graph);
  const int id = topological_sort(scc.comp).front();
  string ans(n, '0');
  REP(i, n) {
    if (scc.id[i] == id) ans[i] = '1';
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}