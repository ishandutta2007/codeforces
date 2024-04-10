#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<vector<ll>> a(n);
  REP(i, n) {
    int t; cin >> t;
    a[i].assign(t + 1, 0);
    FOR(j, 1, t + 1) cin >> a[i][j];
    if (t > k) {
      a[i].resize(k + 1);
      t = k;
    }
    REP(j, t) a[i][j + 1] += a[i][j];
  }
  ll ans = 0;
  function<void(int, int, const vector<ll>&)> solve = [&](int l, int r, const vector<ll> &dp) {
    if (l + 1 == r) {
      REP(j, a[l].size()) chmax(ans, dp[k - j] + a[l][j]);
      return;
    }
    int m = (l + r) >> 1;
    vector<ll> dpl(dp);
    FOR(i, l, m) {
      vector<ll> nx(k + 1, -LINF);
      REP(j, k + 1) {
        chmax(nx[j], dpl[j]);
        if (j + a[i].size() - 1 <= k) chmax(nx[j + a[i].size() - 1], dpl[j] + a[i].back());
      }
      dpl.swap(nx);
    }
    solve(m, r, dpl);
    vector<ll> dpr(dp);
    FOR(i, m, r) {
      vector<ll> nx(k + 1, -LINF);
      REP(j, k + 1) {
        chmax(nx[j], dpr[j]);
        if (j + a[i].size() - 1 <= k) chmax(nx[j + a[i].size() - 1], dpr[j] + a[i].back());
      }
      dpr.swap(nx);
    }
    solve(l, m, dpr);
  };
  vector<ll> dp(k + 1, -LINF);
  dp[0] = 0;
  solve(0, n, dp);
  cout << ans << '\n';
  return 0;
}