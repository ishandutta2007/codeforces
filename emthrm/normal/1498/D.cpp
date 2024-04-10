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

constexpr int C = 100000;

int main() {
  int n, m; cin >> n >> m;
  vector<int> ans(m + 1, -1);
  ans[0] = 0;
  FOR(op, 1, n + 1) {
    int t, y; ll x; cin >> t >> x >> y;
    vector<int> dp(m + 1, -1);
    if (t == 1) {
      int cei = (x + C - 1) / C;
      REP(i, m + 1) {
        if (ans[i] != -1) dp[i] = y;
        if (dp[i] > 0 && i + cei <= m) chmax(dp[i + cei], dp[i] - 1);
      }
    } else if (t == 2) {
      REP(i, m + 1) {
        if (ans[i] != -1) dp[i] = y;
        if (dp[i] > 0 && (1LL * i * x + C - 1) / C <= m) chmax(dp[(1LL * i * x + C - 1) / C], dp[i] - 1);
      }
    }
    FOR(i, 1, m + 1) {
      if (ans[i] == -1 && dp[i] >= 0) ans[i] = op;
    }
  }
  FOR(i, 1, m + 1) cout << ans[i] << " \n"[i == m];
  return 0;
}