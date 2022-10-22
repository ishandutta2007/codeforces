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
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<vector<pair<int, int>>> ans;
  auto flip = [&](int y1, int x1, int y2, int x2, int y3, int x3) {
    ans.emplace_back(vector<pair<int, int>>{{y1, x1}, {y2, x2}, {y3, x3}});
    s[y1][x1] = s[y1][x1] == '0' ? '1' : '0';
    s[y2][x2] = s[y2][x2] == '0' ? '1' : '0';
    s[y3][x3] = s[y3][x3] == '0' ? '1' : '0';
  };
  REP(i, n - 2) {
    REP(j, m - 2) {
      if (s[i][j] == '1') flip(i, j, i, j + 1, i + 1, j);
    }
    if (s[i][m - 2] == '1' && s[i][m - 1] == '1') {
      flip(i, m - 2, i, m - 1, i + 1, m - 2);
    } else if (s[i][m - 2] == '1') {
      flip(i, m - 2, i + 1, m - 2, i + 1, m - 1);
    } else if (s[i][m - 1] == '1') {
      flip(i, m - 1, i + 1, m - 2, i + 1, m - 1);
    }
  }
  REP(j, m - 2) {
    if (s[n - 2][j] == '1' && s[n - 1][j] == '1') {
      flip(n - 2, j, n - 2, j + 1, n - 1, j);
    } else if (s[n - 2][j] == '1') {
      flip(n - 2, j, n - 2, j + 1, n - 1, j + 1);
    } else if (s[n - 1][j] == '1') {
      flip(n - 1, j, n - 2, j + 1, n - 1, j + 1);
    }
  }
  int a = s[n - 2][m - 2] - '0', b = s[n - 2][m - 1] - '0', c = s[n - 1][m - 2] - '0', d = s[n - 1][m - 1] - '0';
  if (a + b + c + d == 4) flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
  a = s[n - 2][m - 2] - '0', b = s[n - 2][m - 1] - '0', c = s[n - 1][m - 2] - '0', d = s[n - 1][m - 1] - '0';
  if (a + b + c + d == 1) {
    if (d == 1) {
      flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
    } else {
      flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
    }
  }
  a = s[n - 2][m - 2] - '0', b = s[n - 2][m - 1] - '0', c = s[n - 1][m - 2] - '0', d = s[n - 1][m - 1] - '0';
  if (a + b + c + d == 2) {
    if (d == 1) {
      flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
    } else if (c == 1) {
      flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
    } else {
      flip(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
    }
  }
  a = s[n - 2][m - 2] - '0', b = s[n - 2][m - 1] - '0', c = s[n - 1][m - 2] - '0', d = s[n - 1][m - 1] - '0';
  if (a + b + c + d == 3) {
    if (a == 0) {
      flip(n - 2, m - 1, n - 1, m - 2, n - 1, m - 1);
    } else if (b == 0) {
      flip(n - 2, m - 2, n - 1, m - 2, n - 1, m - 1);
    } else if (c == 0) {
      flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 1);
    } else {
      flip(n - 2, m - 2, n - 2, m - 1, n - 1, m - 2);
    }
  }
  REP(i, n) assert(count(ALL(s[i]), '1') == 0);
  assert(ans.size() <= n * m);
  cout << ans.size() << '\n';
  for (const auto &v : ans) {
    REP(i, 3) cout << v[i].first + 1 << ' ' << v[i].second + 1 << " \n"[i + 1 == 3];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}