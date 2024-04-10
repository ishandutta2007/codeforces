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

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector dp(n + 1, vector(2, -LINF));
  dp[0][0] = 0;
  REP(i, n) REP(j, 2) {
    chmax(dp[i + 1][j], dp[i][j]);
    chmax(dp[i + 1][j ^ 1], dp[i][j] + a[i] * (j == 0 ? 1 : -1));
  }
  ll ans = *max_element(ALL(dp[n]));
  cout << ans << '\n';
  a.emplace(a.begin(), -INF);
  a.emplace_back(-INF);
  while (q--) {
    int l, r; cin >> l >> r;
    for (int idx : set<int>{l - 1, l, l + 1, r - 1, r, r + 1}) {
      if (1 <= idx && idx <= n) {
        if (a[idx - 1] < a[idx] && a[idx] > a[idx + 1]) ans -= a[idx];
        if (a[idx - 1] > a[idx] && a[idx] < a[idx + 1]) ans += a[idx];
      }
    }
    swap(a[l], a[r]);
    for (int idx : set<int>{l - 1, l, l + 1, r - 1, r, r + 1}) {
      if (1 <= idx && idx <= n) {
        if (a[idx - 1] < a[idx] && a[idx] > a[idx + 1]) ans += a[idx];
        if (a[idx - 1] > a[idx] && a[idx] < a[idx + 1]) ans -= a[idx];
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}