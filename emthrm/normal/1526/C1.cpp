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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<ll> dp(n + 1, -LINF);
  dp[0] = 0;
  for (int ai : a) {
    vector<ll> nx(n + 1, -LINF);
    REP(i, n + 1) {
      chmax(nx[i], dp[i]);
      if (dp[i] + ai >= 0) chmax(nx[i + 1], dp[i] + ai);
    }
    dp.swap(nx);
    // REP(i, n + 1) cout << dp[i] << " \n"[i == n];
  }
  for (int i = n; i >= 0; --i) {
    if (dp[i] >= 0) {
      cout << i << '\n';
      return 0;
    }
  }
  assert(false);
}