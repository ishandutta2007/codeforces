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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  map<pair<int, int>, int> points;
  REP(i, n) {
    int x, y; cin >> x >> y;
    points[{x, y}] = i;
  }
  queue<pair<int, int>> que;
  for (const auto [xy, _] : points) {
    const auto [x, y] = xy;
    REP(k, 4) {
      const int nx = x + DX4[k], ny = y + DY4[k];
      if (!points.count({nx, ny})) que.emplace(nx, ny);
    }
  }
  vector<int> ans_x(n, -1), ans_y(n, -1);
  while (!que.empty()) {
    const auto [x, y] = que.front(); que.pop();
    REP(k, 4) {
      const int nx = x + DX4[k], ny = y + DY4[k];
      if (points.count({nx, ny}) && ans_x[points[{nx, ny}]] == -1) {
        const int id = points[{nx, ny}];
        if (points.count({x, y})) {
          const int frm = points[{x, y}];
          ans_x[id] = ans_x[frm];
          ans_y[id] = ans_y[frm];
        } else {
          ans_x[id] = x;
          ans_y[id] = y;
        }
        que.emplace(nx, ny);
      }
    }
  }
  REP(i, n) cout << ans_x[i] << ' ' << ans_y[i] << '\n';
}