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

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<int> c(n, 0);
  while (m--) {
    int x, y, w; cin >> x >> y >> w; --x; --y;
    graph[x].emplace_back(y);
    c[x] += w;
    c[y] -= w;
  }
  // REP(i, n) cout << c[i] << " \n"[i + 1 == n];
  vector<int> t = topological_sort(graph);
  // REP(i, n) cout << t[i] << " \n"[i + 1 == n];
  vector<int> r(n);
  REP(i, n) r[t[i]] = i;
  vector dp(n, vector(n + 1, vector(1 << n, INF)));
  vector prev(n, vector(n + 1, vector(1 << n, false)));
  dp[0][0][0] = 0;
  REP(a, n) {
    REP(j, 1 << n) REP(i, n) {
      if (dp[a][i + 1][j] > dp[a][i][j]) {
        dp[a][i + 1][j] = dp[a][i][j];
        prev[a][i + 1][j] = false;
      }
      if (j >> i & 1) continue;
      bool can_assign = true;
      for (int e : graph[t[i]]) can_assign &= j >> r[e] & 1;
      if (can_assign && dp[a][i + 1][j | (1 << i)] > dp[a][i][j] + a * c[t[i]]) {
        dp[a][i + 1][j | (1 << i)] = dp[a][i][j] + a * c[t[i]];
        prev[a][i + 1][j | (1 << i)] = true;
      }
    }
    if (a + 1 < n) dp[a + 1][0] = dp[a][n];
  }
  // cout << dp[n - 1][n][(1 << n) - 1] << '\n';
  vector<int> ans(n, -1);
  int b = (1 << n) - 1;
  for (int a = n - 1; a >= 0; --a) {
    for (int i = n; i > 0; --i) {
      if (prev[a][i][b]) {
        b ^= 1 << (i - 1);
        ans[t[i - 1]] = a;
      }
    }
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}