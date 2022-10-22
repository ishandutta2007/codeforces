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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int m, n; cin >> m >> n;
  vector p(m, vector(n, 0)); REP(i, m) REP(j, n) cin >> p[i][j];
  int lb = 1, ub = 1000000001;
  REP(j, n) {
    int max_p = 0;
    REP(i, m) chmax(max_p, p[i][j]);
    chmin(ub, max_p + 1);
  }
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    bool is_valid = false;
    REP(i, m) {
      int cnt = 0;
      REP(j, n) cnt += p[i][j] >= mid;
      is_valid |= cnt >= 2;
    }
    (is_valid ? lb : ub) = mid;
  }
  cout << lb << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}