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
  int n; string s; cin >> n >> s;
  if (int two = count(ALL(s), '2'); two == 0) {
    cout << "YES\n";
    REP(i, n) {
      REP(j, n) cout << (i == j ? 'X' : '=');
      cout << '\n';
    }
  } else if (two <= 2) {
    cout << "NO\n";
  } else {
    vector<int> twos;
    REP(i, n) {
      if (s[i] == '2') twos.emplace_back(i);
    }
    vector ans(n, string(n, '='));
    REP(i, n) ans[i][i] = 'X';
    REP(i, twos.size()) {
      const int x = twos[i], y = twos[(i + 1) % twos.size()];
      ans[x][y] = '+';
      ans[y][x] = '-';
    }
    cout << "YES\n";
    REP(i, n) cout << ans[i] << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}