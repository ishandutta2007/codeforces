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
  int n, k, z; cin >> n >> k >> z;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector dp(n + 1, vector(z + 1, 0));
  REP(i, n) REP(j, z + 1) {
    if (i + j * 2 + 1 <= k + 1) chmax(dp[i + 1][j], dp[i][j] + a[i]);
    if (i > 0 && j + 1 <= z && i + (j + 1) * 2 <= k + 1) chmax(dp[i][j + 1], dp[i][j] + a[i - 1] + a[i]);
  }
  int ans = 0;
  REP(i, n + 1) chmax(ans, *max_element(ALL(dp[i])));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}