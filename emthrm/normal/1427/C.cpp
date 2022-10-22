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
  int r, n; cin >> r >> n;
  vector<int> dp(n + 1, -INF);
  dp[0] = 0;
  vector<int> t(n + 1, 0), x(n + 1, 1), y(n + 1, 1);
  FOR(i, 1, n + 1) cin >> t[i] >> x[i] >> y[i];
  int fr = 0, mx = -INF;
  FOR(i, 1, n + 1) {
    while (fr < i && t[i] - t[fr] >= (r - 1) * 2) chmax(mx, dp[fr++]);
    dp[i] = mx + 1;
    FOR(j, fr, i) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) chmax(dp[i], dp[j] + 1);
    }
  }
  cout << *max_element(ALL(dp)) << '\n';
  return 0;
}