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
  int h, w; cin >> h >> w;
  vector ans(h, string(w, '0'));
  ans[0][0] = '1';
  auto f = [&](int i, int j) -> void {
    REP(k, 8) {
      int y = i + dy8[k], x = j + dx8[k];
      if (0 <= y && y < h && 0 <= x && x < w && ans[y][x] == '1') return;
    }
    ans[i][j] = '1';
  };
  FOR(j, 1, w) f(0, j);
  FOR(i, 1, h) f(i, w - 1);
  for (int j = w - 2; j >= 0; --j) f(h - 1, j);
  for (int i = h - 2; i >= 1; --i) f(i, 0);
  REP(i, h) cout << ans[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}