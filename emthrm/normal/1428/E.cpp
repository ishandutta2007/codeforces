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

ll calc(int a, int cut) {
  if (a < cut) return LINF;
  ll len = a / cut;
  return (len + 1) * (len + 1) * (a % cut) + len * len * (cut - a % cut);
}

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  priority_queue<pair<ll, int>> que;
  REP(i, n) que.emplace(calc(a[i], 1) - calc(a[i], 2), i);
  vector<int> cut(n, 1);
  REP(_, k - n) {
    int i = que.top().second; que.pop();
    ++cut[i];
    que.emplace(calc(a[i], cut[i]) - calc(a[i], cut[i] + 1), i);
  }
  // REP(i, n) cout << cut[i] << " \n"[i + 1 == n];
  ll ans = 0;
  REP(i, n) ans += calc(a[i], cut[i]);
  cout << ans << '\n';
  // vector dp(n + 1, vector(k + 1, LINF));
  // dp[0][0] = 0;
  // REP(i, n) REP(j, k) {
  //   for (int l = 1; l <= a[i] && j + l <= k; ++l) chmin(dp[i + 1][j + l], dp[i][j] + calc(a[i], l));
  // }
  // cout << dp[n][k] << '\n';
  return 0;
}