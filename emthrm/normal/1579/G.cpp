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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

constexpr int D = 2000;

void solve() {
  int n; cin >> n;
  int dp[D + 1]{};
  iota(dp, dp + (D + 1), 0);
  while (n--) {
    int a; cin >> a;
    int nx[D + 1]{};
    fill(nx, nx + (D + 1), D);
    REP(i, D + 1) {
      if (i - a >= 0) chmin(nx[i - a], dp[i]);
      if (i + a <= D) chmin(nx[i + a], max(dp[i], i + a));
    }
    swap(dp, nx);
  }
  cout << *min_element(dp, dp + (D + 1)) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}