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
  int game = 1;
  if (n % 2 == 0) {
    vector ans(n, vector(n, 0));
    REP(i, n) FOR(j, i + 1, n - 1 - i) {
      ans[i][j] = game;
      ans[n - 1 - j][n - 1 - i] = -game;
      game *= -1;
    }
    REP(i, n) FOR(j, i + 1, n) cout << ans[i][j] << " \n"[i == n - 2 && j + 1 == n];
  } else {
    REP(i, n) FOR(j, i + 1, n) {
      cout << game << " \n"[i == n - 2 && j + 1 == n];
      game *= -1;
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}