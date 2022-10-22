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

bool is_bipartite(const std::vector<std::vector<int>>& graph,
                  std::vector<int>* color) {
  const int n = graph.size();
  color->assign(n, -1);
  const std::function<bool(int, int)> dfs = [&graph, &color, &dfs](
      const int ver, const int c) -> bool {
    (*color)[ver] = c;
    for (const int e : graph[ver]) {
      if ((*color)[e] == c || ((*color)[e] == -1 && !dfs(e, c ^ 1))) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if ((*color)[i] == -1 && !dfs(i, 0)) {
      color->clear();
      return false;
    }
  }
  return true;
}

std::vector<int> topological_sort(const std::vector<std::vector<int>>& graph) {
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
  res.reserve(n);
  while (!que.empty()) {
    const int ver = que.front();
    que.pop();
    res.emplace_back(ver);
    for (const int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>{};
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> type(m), is(m), js(m);
  vector<vector<int>> graph(n);
  REP(i, m) {
    cin >> type[i] >> is[i] >> js[i]; --is[i]; --js[i];
    graph[is[i]].emplace_back(js[i]);
    graph[js[i]].emplace_back(is[i]);
  }
  vector<int> color;
  if (!is_bipartite(graph, &color)) {
    cout << "NO\n";
    return 0;
  }
  REP(i, n) graph[i].clear();
  REP(i, m) {
    if (type[i] == 1) {
      if (color[is[i]] == 0) {
        graph[is[i]].emplace_back(js[i]);
      } else {
        graph[js[i]].emplace_back(is[i]);
      }
    } else if (type[i] == 2) {
      if (color[is[i]] == 1) {
        graph[is[i]].emplace_back(js[i]);
      } else {
        graph[js[i]].emplace_back(is[i]);
      }
    }
  }
  vector<int> order = topological_sort(graph);
  if (order.empty()) {
    cout << "NO\n";
    return 0;
  }
  vector<int> x(n);
  REP(i, n) x[order[i]] = i;
  cout << "YES\n";
  REP(i, n) cout << (color[i] ? 'R' : 'L') << ' ' << x[i] << '\n';
  return 0;
}