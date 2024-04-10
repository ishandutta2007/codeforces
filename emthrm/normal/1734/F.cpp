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

constexpr int B = 61;

void solve() {
  ll n, m; cin >> n >> m;
  ll dp[2][2][2]{};  // dp[not more than m][popcount % 2][carry]
  dp[true][0][false] = 1;
  REP(b, B) {
    const int nv = (n >> b & 1), mv = ((m - 1) >> b & 1);
    ll nxt[2][2][2]{};
    REP(i, 2) REP(j, 2) REP(k, 2) {
      REP(digit, 2) nxt[digit < mv || (i && digit == mv)][(j + digit + ((k + nv + digit) & 1)) & 1][k + nv + digit >= 2] += dp[i][j][k];
    }
    swap(dp, nxt);
  }
  cout << dp[true][1][false] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}