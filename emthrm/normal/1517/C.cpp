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
  vector ans(n, vector(n, -1));
  REP(i, n) REP(j, i + 1) ans[i][j] = i + 1;
  vector<int> not_fix(n);
  iota(ALL(not_fix), 1);
  REP(pi, n) {
    int p; cin >> p;
    FOR(i, pi, n) {
      if (ans[i][i] == p) {
        int len = p;
        for (int j = i - 1; j >= pi; --j) {
          assert(len >= not_fix[j]);
          not_fix[j + 1] -= len - not_fix[j];
          len = not_fix[j];
          REP(k, not_fix[j]) swap(ans[j][j - k], ans[j + 1][j + 1 - k]);
        }
        break;
      }
    }
  }
  REP(i, n) REP(j, i + 1) cout << ans[i][j] << " \n"[j == i];
  return 0;
}