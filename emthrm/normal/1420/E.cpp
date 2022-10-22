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
  const int M = 1560;
  int n; cin >> n;
  int x = min(n * (n - 1) / 2, M);
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> one;
  REP(i, n) {
    if (a[i] == 1) one.emplace_back(i);
  }
  int sields = count(ALL(a), 1);
  if (sields == 0) {
    REP(i, n * (n - 1) / 2 + 1) cout << 0 << " \n"[i == n * (n - 1) / 2];
    return 0;
  }
  vector dp(n, vector(x + 1, -INF));
  REP(i, n) dp[i][abs(one[0] - i)] = 0;
  FOR(sield, 1, sields) {
    vector nx(n, vector(x + 1, -INF));
    FOR(i, sield - 1, n) REP(j, x + 1) {
      FOR(k, i + 1, n) {
        int diff = abs(k - one[sield]);
        if (j + diff <= x) chmax(nx[k][j + diff], dp[i][j] + (k - i - 1) * (i + 1 - sield));
      }
    }
    dp.swap(nx);
  }
  vector<int> ans(x + 1, 0);
  REP(t, x + 1) {
    REP(i, n) chmax(ans[t], dp[i][t] + (n - i - 1) * (i + 1 - sields));
    if (t > 0) chmax(ans[t], ans[t - 1]);
  }
  REP(i, x) cout << ans[i] << ' ';
  FOR(i, x, n * (n - 1) / 2 + 1) cout << ans[x] << " \n"[i == n * (n - 1) / 2];
  return 0;
}