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
  int n, p, k; cin >> n >> p >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int> > s(n, vector<int>(p)); REP(i, n) REP(j, p) cin >> s[i][j];
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int l, int r) { return a[l] > a[r]; });
  vector<vector<ll> > dp(n + 1, vector<ll>(1 << p, 0));
  REP(i, k) dp[0][0] += a[idx[i]];
  REP(i, n) {
    int now = idx[i];
    REP(j, 1 << p) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j == (1 << p) - 1) continue;
      ll tmp = dp[i][j];
      if (i < k + __builtin_popcount(j)) {
        tmp -= a[now];
        tmp += a[idx[k + __builtin_popcount(j)]];
      }
      REP(x, p) {
        if (!(j >> x & 1)) chmax(dp[i + 1][j | (1 << x)], tmp + s[now][x]);
      }
    }
  }
  cout << dp[n][(1 << p) - 1] << '\n';
  return 0;
}