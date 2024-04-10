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
constexpr int MOD = 998244353;
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
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector can_move(n, vector(m, 0)), dir(n, vector(m, 0));
  queue<pair<int, int>> que;
  REP(i, n) REP(j, m) {
    if (s[i][j] == '#') continue;
    if (s[i][j] == 'L') que.emplace(i, j);
    REP(k, 4) {
      const int y = i + DY[k], x = j + DX[k];
      if (0 <= y && y < n && 0 <= x && x < m && s[y][x] != '#') {
        can_move[i][j] |= 1 << ((k + 2) % 4);
        ++dir[i][j];
      }
    }
    if (dir[i][j] > 2) can_move[i][j] = 0;
  }
  vector<string> ans = s;
  while (!que.empty()) {
    const auto [i, j] = que.front(); que.pop();
    REP(k, 4) {
      const int y = i + DY[k], x = j + DX[k];
      if (0 <= y && y < n && 0 <= x && x < m && ans[y][x] == '.') {
        --dir[y][x];
        if ((can_move[y][x] >> k & 1) || dir[y][x] <= 1) {
          ans[y][x] = '+';
          que.emplace(y, x);
        }
      }
    }
  }
  REP(i, n) cout << ans[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}