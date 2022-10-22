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

int main() {
  constexpr int M = 5000000;
  int n; cin >> n;
  int a[M + 1]{};
  while (n--) {
    int ai; cin >> ai;
    ++a[ai];
  }
  FOR(i, 1, M + 1) for (int j = i << 1; j <= M; j += i) a[i] += a[j];
  ll dp[M + 1]{};
  FOR(i, 1, M + 1) {
    chmax(dp[i], 1LL * a[i] * i);
    for (int j = i << 1; j <= M; j += i) {
      chmax(dp[j], dp[i] + 1LL * (j - i) * a[j]);
    }
  }
  cout << *max_element(dp, dp + (M + 1)) << '\n';
  return 0;
}