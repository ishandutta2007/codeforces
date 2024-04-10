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
  int n, m; string s; cin >> n >> m >> s;
  int y = 0, x = 0, min_y = 0, max_y = 0, min_x = 0, max_x = 0;
  for (char c : s) {
    int dy = 0, dx = 0;
    if (c == 'L') {
      dx = -1;
    } else if (c == 'R') {
      dx = 1;
    } else if (c == 'D') {
      dy = 1;
    } else if (c == 'U') {
      dy = -1;
    }
    if (max(y + dy, max_y) - min(y + dy, min_y) >= n ||
        max(x + dx, max_x) - min(x + dx, min_x) >= m) {
      cout << -min_y + 1 << ' ' << -min_x + 1 << '\n';
      return;
    }
    y += dy;
    x += dx;
    chmax(max_y, y);
    chmin(min_y, y);
    chmax(max_x, x);
    chmin(min_x, x);
  }
  cout << -min_y + 1 << ' ' << -min_x + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}