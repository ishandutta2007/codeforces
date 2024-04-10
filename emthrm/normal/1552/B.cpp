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

constexpr int M = 5;

void solve() {
  int n; cin >> n;
  vector<vector<int>> r(n, vector<int>(M)); REP(i, n) REP(j, M) cin >> r[i][j];
  int ans = 0;
  FOR(i, 1, n) {
    int win = 0;
    REP(j, M) win += r[i][j] < r[ans][j];
    if (win >= 3) ans = i;
  }
  REP(i, n) {
    if (i == ans) continue;
    int win = 0;
    REP(j, M) win += r[ans][j] < r[i][j];
    if (win < 3) {
      cout << "-1\n";
      return;
    }
  }
  cout << ans + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}