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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; cin >> n >> m;
  vector a(n, vector(m, 0)); REP(i, n) REP(j, m) cin >> a[i][j];
  if ((n + m - 1) % 2 == 1) {
    cout << "NO\n";
    return;
  }
  vector dp1(n, vector(m, INF)), dp2(n, vector(m, -INF));
  dp1[0][0] = dp2[0][0] = a[0][0];
  REP(i, n) REP(j, m) {
    if (i > 0) {
      chmin(dp1[i][j], dp1[i - 1][j] + a[i][j]);
      chmax(dp2[i][j], dp2[i - 1][j] + a[i][j]);
    }
    if (j > 0) {
      chmin(dp1[i][j], dp1[i][j - 1] + a[i][j]);
      chmax(dp2[i][j], dp2[i][j - 1] + a[i][j]);
    }
  }
  cout << (dp1[n - 1][m - 1] <= 0 && 0 <= dp2[n - 1][m - 1] ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}