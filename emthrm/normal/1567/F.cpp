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

int main() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector unmarked(n, vector(m, 0));
  FOR(i, 1, n - 1) FOR(j, 1, m - 1) {
    if (s[i][j] == 'X') {
      REP(k, 4) {
        const int y = i + DY[k], x = j + DX[k];
        unmarked[i][j] += s[y][x] == '.';
      }
      if (unmarked[i][j] & 1) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  vector ans(n, vector(m, 0));
  ans[0][0] = 1;
  queue<pair<int, int>> que({{0, 0}});
  while (!que.empty()) {
    const auto [i, j] = que.front(); que.pop();
    REP(k, 8) {
      const int y = i + DY8[k], x = j + DX8[k];
      if (y < 0 || n <= y || x < 0 || m <= x) continue;
      if (ans[y][x] != 0) continue;
      if (s[y][x] == 'X') {
        const int ny = y + DY8[k], nx = x + DX8[k];
        if (k % 2 == 0 && unmarked[y][x] == 2 && s[ny][nx] == '.' && ans[ny][nx] == 0) {
          ans[ny][nx] = 5 - ans[i][j];
          que.emplace(ny, nx);
        }
      } else {
        ans[y][x] = (k % 4 == 0 ? ans[i][j] : 5 - ans[i][j]);
        que.emplace(y, x);
      }
    }
  }
  cout << "YES\n";
  REP(i, n) REP(j, m) {
    if (s[i][j] == 'X') {
      REP(k, 4) {
        const int y = i + DY[k], x = j + DX[k];
        if (s[y][x] == '.') ans[i][j] += ans[y][x];
      }
    }
    cout << ans[i][j] << " \n"[j + 1 == m];
  }
  return 0;
}