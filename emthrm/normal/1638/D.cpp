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
  const int dy[]{1, 0, 0, 1}, dx[]{0, 0, 1, 1};
  const int dy2[]{0, 0, -1, -1}, dx2[]{-1, 0, -1, 0};
  int n, m; cin >> n >> m;
  vector a(n, vector(m, 0)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector<tuple<int, int, int>> ans;
  vector sq(n - 1, vector(m - 1, vector<int>{}));
  queue<pair<int, int>> que;
  REP(i, n - 1) REP(j, m - 1) {
    REP(k, 4) {
      const int y = i + dy[k], x = j + dx[k];
      sq[i][j].emplace_back(a[y][x]);
    }
    sort(ALL(sq[i][j]));
    if (sq[i][j].front() == sq[i][j].back()) {
      sq[i][j].clear();
      que.emplace(i, j);
    }
  }
  vector is_painted(n, vector(m, 0));
  while (!que.empty()) {
    const auto [i, j] = que.front(); que.pop();
    int c = -1;
    REP(k, 4) {
      const int y = i + dy[k], x = j + dx[k];
      if (!is_painted[y][x]) {
        is_painted[y][x] = true;
        c = a[y][x];
        REP(l, 4) {
          const int r = y + dy2[l], c = x + dx2[l];
          if (0 <= r && r < n - 1 && 0 <= c && c < m - 1) {
            const auto it = find(ALL(sq[r][c]), a[y][x]);
            if (it != sq[r][c].end()) {
              sq[r][c].erase(it);
              if (!sq[r][c].empty() && sq[r][c].front() == sq[r][c].back()) {
                sq[r][c].clear();
                que.emplace(r, c);
              }
            }
          }
        }
      }
    }
    if (c != -1) ans.emplace_back(i, j, c);
  }
  REP(i, n) {
    if (count(ALL(is_painted[i]), false) > 0) {
      cout << "-1\n";
      return 0;
    }
  }
  reverse(ALL(ans));
  cout << ans.size() << '\n';
  for (const auto [i, j, c] : ans) cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';
  return 0;
}