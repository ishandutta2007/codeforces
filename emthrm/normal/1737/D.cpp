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

void solve() {
  int n, m; cin >> n >> m;
  vector graph(n, vector(n, INF));
  while (m--) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    chmin(graph[u][v], w);
    chmin(graph[v][u], w);
  }
  vector dp(n, vector(n, -1));
  dp[0][n - 1] = 0;
  for (queue<pair<int, int>> que({{0, n - 1}}); !que.empty();) {
    const auto [i, j] = que.front(); que.pop();
    if (i == j) {
      REP(k, i) {
        if (dp[k][i] == -1) {
          dp[k][i] = dp[i][i] + 1;
          que.emplace(k, i);
        }
      }
      FOR(k, i + 1, n) {
        if (dp[i][k] == -1) {
          dp[i][k] = dp[i][i] + 1;
          que.emplace(i, k);
        }
      }
      continue;
    }
    REP(k, n) {
      if (graph[i][k] != INF) {
        const auto [ni, nj] = minmax(k, j);
        if (dp[ni][nj] == -1) {
          dp[ni][nj] = dp[i][j] + 1;
          que.emplace(ni, nj);
        }
      }
    }
    REP(k, n) {
      if (graph[j][k] != INF) {
        const auto [ni, nj] = minmax(k, i);
        if (dp[ni][nj] == -1) {
          dp[ni][nj] = dp[i][j] + 1;
          que.emplace(ni, nj);
        }
      }
    }
  }
  ll ans = LINF;
  REP(i, n) FOR(j, i + 1, n) {
    if (graph[i][j] != INF) chmin(ans, graph[i][j] * (dp[i][j] + 1LL));
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}