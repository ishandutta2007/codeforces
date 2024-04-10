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

constexpr int C = 26;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector ans(n, string(m, '.'));
  if (n & 1) {
    k -= m / 2;
    REP(j, m / 2) ans[n - 1][j * 2] = ans[n - 1][j * 2 + 1] = 'a' + (j % C);
  } else if (m & 1) {
    REP(i, n / 2) ans[i * 2][m - 1] = ans[i * 2 + 1][m - 1] = 'a' + (i % C);
  }
  auto f = [&](int y1, int x1, int y2, int x2) -> char {
    set<char> s;
    REP(k, 4) {
      int y = y1 + dy[k], x = x1 + dx[k];
      if (0 <= y && y < n && 0 <= x && x < m && ans[y][x] != '.') s.emplace(ans[y][x]);
    }
    REP(k, 4) {
      int y = y2 + dy[k], x = x2 + dx[k];
      if (0 <= y && y < n && 0 <= x && x < m && ans[y][x] != '.') s.emplace(ans[y][x]);
    }
    char res = 'a';
    while (s.count(res) == 1) ++res;
    return res;
  };
  if (0 <= k && k <= (n - (n & 1)) * (m - (m & 1)) / 2 && k % 2 == 0) {
    for (int i = 0; i + 1 < n; i += 2) for (int j = 0; j + 1 < m; j += 2) {
      if (k > 0) {
        ans[i][j] = ans[i][j + 1] = f(i, j, i, j + 1);
        ans[i + 1][j] = ans[i + 1][j + 1] = f(i + 1, j, i + 1, j + 1);
        k -= 2;
      } else {
        ans[i][j] = ans[i + 1][j] = f(i, j, i + 1, j);
        ans[i][j + 1] = ans[i + 1][j + 1] = f(i, j + 1, i + 1, j + 1);
      }
    }
    cout << "YES\n";
    REP(i, n) cout << ans[i] << '\n';
  } else {
    cout << "NO\n";
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}