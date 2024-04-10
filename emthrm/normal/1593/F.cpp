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

void solve() {
  int n, a, b; string x; cin >> n >> a >> b >> x;
  vector dp(a, vector(b, vector(n * 2 + 1, 0)));
  vector prev(n + 1, vector(a, vector(b, vector(n * 2 + 1, make_pair(-1, -1)))));
  dp[0][0][n] = true;
  REP(c, n) {
    const int v = x[c] - '0';
    vector nx(a, vector(b, vector(n * 2 + 1, 0)));
    REP(i, a) REP(j, b) REP(k, n * 2 + 1) {
      if (!dp[i][j][k]) continue;
      if (k + 1 <= n * 2) {
        nx[(i * 10 + v) % a][j][k + 1] = true;
        prev[c + 1][(i * 10 + v) % a][j][k + 1] = {0, i};
      }
      if (k > 0) {
        nx[i][(j * 10 + v) % b][k - 1] = true;
        prev[c + 1][i][(j * 10 + v) % b][k - 1] = {1, j};
      }
    }
    dp.swap(nx);
  }
  REP(abso, n) {
    if (dp[0][0][n + abso] || dp[0][0][n - abso]) {
      int i = 0, j = 0, k = (dp[0][0][n + abso] ? n + abso : n - abso);
      string ans = "";
      for (int c = n; c > 0; --c) {
        if (prev[c][i][j][k].first == 0) {
          ans += 'R';
          i = prev[c][i][j][k].second;
          --k;
        } else {
          ans += 'B';
          j = prev[c][i][j][k].second;
          ++k;
        }
      }
      reverse(ALL(ans));
      cout << ans << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}