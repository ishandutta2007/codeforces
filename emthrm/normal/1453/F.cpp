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
  vector dp1(n, vector(n, 0));
  REP(j, n) {
    for (int i = j - 1; i >= 0; --i) dp1[i][j] = dp1[i + 1][j] + (j <= i + a[i]);
  }
  vector dp2(n, vector(n, INF));
  dp2[0][0] = 0;
  REP(i, n - 1) {
    int d = *min_element(dp2[i].begin(), dp2[i].begin() + i + 1);
    for (int j = i + 1; j <= i + a[i]; ++j) {
      chmin(dp2[j][i + a[i]], d + dp1[i + 1][j]);
      chmin(d, dp2[i][j]);
    }
  }
  cout << *min_element(ALL(dp2[n - 1])) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}