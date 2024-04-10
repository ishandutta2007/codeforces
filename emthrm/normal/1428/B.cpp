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

struct SCC {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, comp;

  SCC(const std::vector<std::vector<int>> &graph, bool heavy = false) : graph(graph), heavy(heavy) {
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

void solve() {
  int n; string s; cin >> n >> s;
  vector<vector<int>> graph(n);
  REP(i, n) {
    if (s[i] != '<') graph[i].emplace_back((i + 1) % n);
    if (s[(i - 1 + n) % n] != '>') graph[i].emplace_back((i - 1 + n) % n);
  }
  SCC scc(graph, true);
  int ans = 0;
  for (auto &v : scc.vertices) {
    if (v.size() > 1) ans += v.size();
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}