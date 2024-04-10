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

void solve() {
  int n, m; cin >> n >> m;
  vector<string> a(n); REP(i, n) cin >> a[i];
  int ans = n * m;
  for (int y1 = 0; y1 + 4 < n; ++y1) {
    vector<int> obsidian(m, 0);
    FOR(y2, y1 + 1, y1 + 4) {
      REP(j, m) obsidian[j] += a[y2][j] == '1';
    }
    // REP(j, m) cout << obsidian[j] << " \n"[j + 1 == m];
    FOR(y2, y1 + 4, n) {
      vector<int> r(m);
      int to_empty = 0;
      REP(j, m) {
        r[j] = (y2 - y1 - 1) - obsidian[j] + to_empty;
        to_empty += obsidian[j] + (a[y1][j] == '0') + (a[y2][j] == '0');
      }
      for (int j = m - 2; j >= 0; --j) chmin(r[j], r[j + 1]);
      int minus = 0;
      for (int j = 0; j + 3 < m; ++j) {
        minus += obsidian[j] + (a[y1][j] == '0') + (a[y2][j] == '0');
        chmin(ans, (y2 - y1 - 1) - obsidian[j] + r[j + 3] - minus);
      }
      REP(j, m) obsidian[j] += a[y2][j] == '1';
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}