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
  int n, m; cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> b[i][j];
  vector<pair<int, int>> ord;
  REP(i, n) REP(j, m) ord.emplace_back(i, j);
  sort(ALL(ord), [&](const pair<int, int> &l, const pair<int, int> &r) -> bool {
    auto [li, lj] = l;
    auto [ri, rj] = r;
    return b[li][lj] < b[ri][rj];
  });
  vector ans(n, vector(m, -1));
  vector used(n, vector(m, false));
  REP(i, m) {
    auto [y, x] = ord[i];
    ans[y][i] = b[y][x];
    used[y][x] = true;
  }
  REP(i, n) {
    int pos = 0;
    REP(j, m) {
      if (ans[i][j] == -1) {
        while (used[i][pos]) ++pos;
        ans[i][j] = b[i][pos];
        used[i][pos] = true;
      }
    }
  }
  REP(i, n) REP(j, m) cout << ans[i][j] << " \n"[j + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}