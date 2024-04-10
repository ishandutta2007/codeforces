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

constexpr int L = 2000;
int to[L][L]{}, dist[L][L]{};

void solve() {
  int n, m; cin >> n >> m;
  queue<pair<int, int>> que;
  REP(i, n) REP(j, m) {
    char c; cin >> c;
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
    const int y = i + dy, x = j + dx;
    if (0 <= y && y < n && 0 <= x && x < m) {
      to[i][j] = y * m + x;
      dist[i][j] = 0;
    } else {
      to[i][j] = -1;
      dist[i][j] = 1;
      que.emplace(i, j);
    }
  }
  REP(i, n) REP(j, m) {
    bool is_goal = false;
    REP(k, 4) {
      const int y = i + DY[k], x = j + DX[k];
      is_goal |= y < 0 || n <= y || x < 0 || m <= x;
    }
  }
  while (!que.empty()) {
    const auto [i, j] = que.front(); que.pop();
    REP(k, 4) {
      const int y = i + DY[k], x = j + DX[k];
      if (0 <= y && y < n && 0 <= x && x < m && dist[y][x] == 0 && to[y][x] == i * m + j) {
        dist[y][x] = dist[i][j] + 1;
        que.emplace(y, x);
      }
    }
  }
  // REP(i, n) REP(j, m) cerr << dist[i][j] << " \n"[j + 1 == m];
  REP(sy, n) REP(sx, m) {
    if (dist[sy][sx] > 0) continue;
    int i = sy, j = sx;
    vector<pair<int, int>> stack;
    while (true) {
      if (dist[i][j] == -1) {
        for (int len = 1; ; ++len) {
          if (stack.end()[-len] == make_pair(i, j)) {
            REP(_, len) {
              auto [y, x] = stack.back(); stack.pop_back();
              dist[y][x] = len;
            }
            break;
          }
        }
      } else if (dist[i][j] == 0) {
        dist[i][j] = -1;
        stack.emplace_back(i, j);
        tie(i, j) = [](int to, int m) -> pair<int, int> {
          return {to / m, to % m};
        } (to[i][j], m);
        continue;
      }
      for (; !stack.empty(); stack.pop_back()) {
        auto [y, x] = stack.back();
        dist[y][x] = dist[i][j] + 1;
        tie(i, j) = stack.back();
      }
      break;
    }
  }
  int r = -1, c = -1, d = 0;
  REP(i, n) REP(j, m) {
    if (chmax(d, dist[i][j])) {
      r = i;
      c = j;
    }
  }
  cout << r + 1 << ' ' << c + 1 << ' ' << d << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}