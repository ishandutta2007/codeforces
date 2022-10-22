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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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
  string s; cin >> s;
  const int n = s.length();
  vector dp(n, vector(n, -1));
  FOR(j, 1, n) {
    dp[j - 1][j] = (s[j - 1] != s[j]);
    for (int i = j - 3; i >= 0; i -= 2) {
      dp[i][j] = ((dp[i + 2][j] || (!dp[i + 2][j] && s[i] < s[i + 1])) && (dp[i + 1][j - 1] || (!dp[i + 1][j - 1] && s[i] < s[j]))) ||
                 ((dp[i][j - 2] || (!dp[i][j - 2] && s[j] < s[j - 1])) && (dp[i + 1][j - 1] || (!dp[i + 1][j - 1] && s[j] < s[i])));
    }
  }
  cout << (dp[0][n - 1] ? "Alice\n" : "Draw\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}