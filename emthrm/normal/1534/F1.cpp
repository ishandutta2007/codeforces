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

int main() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<int> a(m); REP(i, m) cin >> a[i];
  int x = 0;
  vector id(n, vector(m, -1));
  REP(i, n) REP(j, m) {
    if (s[i][j] == '#') id[i][j] = x++;
  }
  // REP(i, n) REP(j, m) cout << id[i][j] << " \n"[j + 1 == m];
  vector<vector<int>> sand(m);
  REP(j, m) REP(i, n) {
    if (s[i][j] == '#') sand[j].emplace_back(i);
  }
  vector<vector<int>> graph(x);
  REP(j, m) {
    int l = 0, r = 0;
    for (auto it = sand[j].begin(); it != sand[j].end(); it = next(it)) {
      if (it != sand[j].begin() && *prev(it) + 1 == *it) graph[id[*it][j]].emplace_back(id[*prev(it)][j]);
      if (next(it) != sand[j].end()) graph[id[*it][j]].emplace_back(id[*next(it)][j]);
      if (j > 0) {
        while (l < sand[j - 1].size() && sand[j - 1][l] < *it) ++l;
        if (l < sand[j - 1].size()) graph[id[*it][j]].emplace_back(id[sand[j - 1][l]][j - 1]);
      }
      if (j + 1 < m) {
        while (r < sand[j + 1].size() && sand[j + 1][r] < *it) ++r;
        if (r < sand[j + 1].size()) graph[id[*it][j]].emplace_back(id[sand[j + 1][r]][j + 1]);
      }
    }
  }
  StronglyConnectedComponents scc(graph);
  const int y = scc.comp.size();
  vector<bool> need(y, true);
  REP(i, y) for (int e : scc.comp[i]) need[e] = false;
  cout << count(ALL(need), true) << '\n';
  return 0;
}