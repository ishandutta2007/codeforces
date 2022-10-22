#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector dp(n, vector(2, LINF));
  dp[0][false] = 0;
  dp[0][true] = a[0] - 1;
  FOR(i, 1, n) {
    dp[i][false] = dp[i - 1][true];
    dp[i][true] = min(dp[i - 1][true], dp[i - 1][false]) + (a[i] - 1);
  }
  vector<int> b(n);
  int j = min_element(ALL(dp[n - 1])) - dp[n - 1].begin();
  for (int i = n - 1; i > 0; --i) {
    if (j == 0) {
      b[i] = a[i];
      j = 1;
    } else {
      b[i] = 1;
      j = min_element(ALL(dp[i - 1])) - dp[i - 1].begin();
    }
  }
  b[0] = j == 0 ? a[0] : 1;
  REP(i, n) cout << b[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}