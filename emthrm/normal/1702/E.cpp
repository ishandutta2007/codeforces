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

void solve() {
  int n; cin >> n;
  vector<vector<int>> idx(n);
  REP(i, n) {
    int a, b; cin >> a >> b; --a; --b;
    idx[a].emplace_back(i);
    idx[b].emplace_back(i);
  }
  vector<vector<int>> graph(n);
  REP(i, n) {
    if (idx[i].size() != 2) {
      cout << "NO\n";
      return;
    }
    const int u = idx[i][0], v = idx[i][1];
    if (u == v) {
      cout << "NO\n";
      return;
    }
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> color;
  cout << (is_bipartite(graph, &color) ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}