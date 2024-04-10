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
  int n, l, k; cin >> n >> l >> k;
  vector<int> d(n + 1, l), a(n);
  REP(i, n) cin >> d[i];
  REP(i, n) cin >> a[i];
  vector dp(n + 1, vector(k + 1, INF));
  dp[0][0] = 0;
  FOR(i, 1, n + 1) for (int j = i - 1; j >= 0; --j) {
    for (int x = 0; x + i - j - 1 <= k; ++x) {
      chmin(dp[i][x + i - j - 1], dp[j][x] + a[j] * (d[i] - d[j]));
    }
  }
  cout << *min_element(ALL(dp[n])) << '\n';
  return 0;
}