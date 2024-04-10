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

std::vector<std::vector<int>> nx_init(const std::string &s, const char basis = 'a', const int char_sz = 26) {
  int n = s.size();
  std::vector<std::vector<int>> nx(n, std::vector<int>(char_sz, n));
  nx[n - 1][s[n - 1] - basis] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < char_sz; ++j) nx[i][j] = nx[i + 1][j];
    nx[i][s[i] - basis] = i;
  }
  return nx;
}

int main() {
  int n, m; string s, t; cin >> n >> m >> s >> t;
  auto nx = nx_init(s);
  reverse(ALL(s));
  auto xn = nx_init(s);
  vector<int> vec(m, n), cev(m, n);
  REP(i, m) vec[i] = nx[i > 0 ? vec[i - 1] + 1 : 0][t[i] - 'a'];
  // REP(i, m) cout << vec[i] << " \n"[i + 1 == m];
  reverse(ALL(t));
  REP(i, m) cev[i] = xn[i > 0 ? cev[i - 1] + 1 : 0][t[i] - 'a'];
  // REP(i, m) cout << n - 1 - cev[i] << " \n"[i + 1 == m];
  int ans = 1;
  REP(i, m - 1) chmax(ans, (n - 1 - cev[m - 2 - i]) - vec[i]);
  cout << ans << '\n';
  return 0;
}