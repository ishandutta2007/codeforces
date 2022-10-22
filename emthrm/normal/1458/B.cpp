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

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  int water = accumulate(ALL(b), 0), m = 0;
  REP(i, n) m += a[i] - b[i];
  chmin(m, (water + 1) / 2);
  vector dp(1, vector(m + 1, -INF));
  dp[0][0] = 0;
  REP(i, n) {
    vector nx(i + 2, vector(m + 1, -INF));
    REP(j, i + 1) REP(k, m + 1) {
      chmax(nx[j][k], dp[j][k]);
      chmax(nx[j + 1][min(k + a[i] - b[i], m)], dp[j][k] + b[i]);
    }
    dp.swap(nx);
  }
  FOR(k, 1, n + 1) {
    double ans = 0;
    REP(x, m + 1) {
      if (water - dp[k][x] < x * 2) {
        chmax(ans, dp[k][x] + (water - dp[k][x]) * 0.5);
      } else {
        chmax(ans, dp[k][x] + x);
      }
    }
    cout << ans << " \n"[k == n];
  }
  return 0;
}