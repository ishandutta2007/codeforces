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

void solve() {
  constexpr int M = 500;
  int n, x; cin >> n >> x;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector dp(n + 1, vector(M + 1, vector(M + 1, INF)));
  dp[0][0][x] = 0;
  REP(i, n) REP(j, M + 1) REP(k, M + 1) {
    if (j <= a[i]) chmin(dp[i + 1][a[i]][k], dp[i][j][k]);
    if (a[i] > k && j <= k) chmin(dp[i + 1][k][a[i]], dp[i][j][k] + 1);
  }
  int ans = INF;
  REP(j, M + 1) REP(k, M + 1) chmin(ans, dp[n][j][k]);
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}