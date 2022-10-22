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

template <typename T>
std::vector<std::vector<T>> rot(const std::vector<std::vector<T>> &grid, int angle, T basis = ' ') {
  int h = grid.size(), w = grid.front().size();
  std::vector<std::vector<T>> rotated_grid;
  if (angle == 45) {
    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, basis));
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) rotated_grid[i + j][i - j + w - 1] = grid[i][j];
  } else if (angle == 90) {
    rotated_grid.assign(w, std::vector<T>(h));
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) rotated_grid[w - 1 - j][i] = grid[i][j];
  } else {
    assert(false);
  }
  return rotated_grid;
}

int f(char d, const vector<vector<char>> &s) {
  int n = s.size(), mn = n, mx = -1;
  REP(i, n) {
    if (count(ALL(s[i]), d) > 0) {
      chmin(mn, i);
      chmax(mx, i);
    }
  }
  int ans = 0;
  REP(i, n) {
    vector<int> pos;
    REP(j, n) {
      if (s[i][j] == d) pos.emplace_back(j);
    }
    if (pos.size() >= 2) {
      int b = pos.back() - pos.front();
      chmax(ans, b * i);
      chmax(ans, b * (n - 1 - i));
    }
    if (!pos.empty()) {
      int h = max(i - mn, mx - i);
      chmax(ans, pos.back() * h);
      chmax(ans, (n - 1 - pos.front()) * h);
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<vector<char>> s(n, vector<char>(n)); REP(i, n) REP(j, n) cin >> s[i][j];
  auto t = rot(s, 90);
  REP(d, 10) cout << max(f('0' + d, s), f('0' + d, t)) << " \n"[d + 1 == 10];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}