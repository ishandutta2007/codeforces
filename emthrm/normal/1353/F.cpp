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
  int n, m; cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) REP(j, m) {
    if (i > 0 || j > 0) a[i][j] -= a[0][0];
  }
  a[0][0] = 0;
  function<ll(ll s)> solve = [&](ll s) {
    if (s > 0) return LINF;
    s = -s;
    vector dp(n, vector(m, LINF));
    dp[0][0] = s;
    REP(i, n) REP(j, m) {
      ll height = i + j - s;
      if (a[i][j] >= height) {
        if (i > 0) chmin(dp[i][j], dp[i - 1][j] + a[i][j] - height);
        if (j > 0) chmin(dp[i][j], dp[i][j - 1] + a[i][j] - height);
      }
    }
    // REP(i, n) REP(j, m) cout << dp[i][j] << " \n"[j + 1 == m];
    // cout << '\n';
    return dp[n - 1][m - 1];
  };
  ll ans = LINF;
  REP(i, n) REP(j, m) chmin(ans, solve(a[i][j] - (i + j)));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}