#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  ll ans = -LINF;
  {
    vector dp(n + 1, vector(2, vector(2, -LINF)));
    dp[0][false][false] = 0;
    REP(i, n) REP(j, 2) REP(k, 2) {
      if (i % 2 == 0) {
        chmax(dp[i + 1][false][k], dp[i][j][k] + a[i]);
        if (j || !k) chmax(dp[i + 1][true][true], dp[i][j][k]);
      } else {
        if (j) {
          chmax(dp[i + 1][true][true], dp[i][j][k] + a[i]);
        } else {
          chmax(dp[i + 1][false][k], dp[i][j][k]);
        }
      }
    }
    REP(j, 2) REP(k, 2) chmax(ans, dp[n][j][k]);
  }
  {
    vector dp(n + 1, vector(2, vector(2, -LINF)));
    dp[0][false][false] = 0;
    REP(i, n) REP(j, 2) REP(k, 2) {
      if (i % 2 == 0) {
        if (j) {
          chmax(dp[i + 1][true][true], dp[i][j][k]);
        } else {
          chmax(dp[i + 1][false][k], dp[i][j][k] + a[i]);
        }
      } else {
        chmax(dp[i + 1][false][k], dp[i][j][k]);
        if (i + 1 < n && (j || !k)) chmax(dp[i + 1][true][true], dp[i][j][k] + a[i]);
      }
    }
    // REP(i, n + 1) REP(j, 2) REP(k, 2) cout << dp[i][j][k] << " \n"[j + 1 == 2 && k + 1 == 2];
    REP(j, 2) REP(k, 2) chmax(ans, dp[n][j][k]);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}