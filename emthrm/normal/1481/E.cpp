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

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<int> book(n, 0), l(n, n), r(n, n);
  REP(i, n) {
    ++book[a[i]];
    if (l[a[i]] == n) l[a[i]] = i;
    r[a[i]] = i;
  }
  vector<int> dp(n + 1, n);
  int ans = n;
  dp[0] = 0;
  REP(i, n) {
    chmin(dp[i + 1], dp[i] + 1);
    if (l[a[i]] < i) {
      chmin(ans, dp[i] + (n - i) - book[a[i]]);
      --book[a[i]];
      continue;
    }
    chmin(dp[r[a[i]] + 1], dp[i] + (r[a[i]] - i + 1) - book[a[i]]);
    --book[a[i]];
  }
  cout << min(ans, dp[n]) << '\n';
  return 0;
}