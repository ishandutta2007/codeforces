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

void solve() {
  int n, m; string s; cin >> n >> m >> s;
  vector ans1(n, vector(m, 0));
  int serious = 0;
  REP(i, n * m) {
    serious += (s[i] == '1');
    if (serious > 0) ++ans1[i / m][i % m];
    if (i >= m - 1) serious -= (s[i - (m - 1)] == '1');
  }
  FOR(i, 1, n) REP(j, m) ans1[i][j] += ans1[i - 1][j];
  vector<int> exists(m, false), ans2(n * m, 0);
  REP(i, n * m) {
    if (s[i] == '1' && !exists[i % m]) {
      exists[i % m] = true;
      ++ans2[i];
    }
  }
  FOR(i, 1, n * m) ans2[i] += ans2[i - 1];
  REP(i, n * m) cout << ans1[i / m][i % m] + ans2[i] << " \n"[i + 1 == n * m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}