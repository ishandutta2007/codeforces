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

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  vector dp(n + 1, vector(k, make_pair(-LINF, -LINF)));
  dp[0][0] = {0, 0};
  ll red = 0, blue = 0;
  REP(i, n) {
    REP(j, k) {
      if (dp[i][j].first < 0) continue;
      ll r = blue - (dp[i][j].first * k - (red + dp[i][j].second - j));
      assert(r < k);
      for (int x = 0; x <= a[i] && x < k; ++x) {
        ll nx = dp[i][j].first + (j + x >= k);
        int a_rem = a[i] - x;
        nx += a_rem / k;
        a_rem %= k;
        int b_rem = b[i];
        if (a_rem > 0 && b_rem >= k - a_rem) {
          b_rem -= k - a_rem;
          a_rem = 0;
          ++nx;
        }
        nx += (r + b_rem) / k;
        chmax(dp[i + 1][(j + x) % k], make_pair(nx, dp[i][j].second - a_rem));
      }
    }
    red += a[i];
    blue += b[i];
  }
  ll ans = 0;
  REP(j, k) chmax(ans, dp[n][j].first);
  cout << ans << '\n';
  return 0;
}