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
  int n; cin >> n;
  vector<int> r(3); REP(i, 3) cin >> r[i];
  chmin(r[0], min(r[1], r[2]));
  int d; cin >> d;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector dp(n + 1, vector(2, LINF));
  dp[0][false] = -d;
  REP(i, n) {
    ll once = 1LL * r[0] * a[i] + r[2], twice = min(1LL * r[0] * (a[i] + 2), 1LL * r[0] + r[1]);
    chmin(dp[i + 1][false], dp[i][false] + d + once);
    chmin(dp[i + 1][false], dp[i][true] + d + min(once, twice));
    chmin(dp[i + 1][true], dp[i][false] + 3LL * d + min(once, twice));
  }
  // REP(j, 2) REP(i, n + 1) cout << dp[i][j] << " \n"[i == n];
  cout << min(*min_element(ALL(dp[n])), dp[n - 1][true] + 1LL * r[0] * a[n - 1] + r[2]) << '\n';
  return 0;
}