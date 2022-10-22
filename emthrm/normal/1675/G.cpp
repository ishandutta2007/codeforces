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
  int n, m; cin >> n >> m;
  if (n == 1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> a(n); REP(i, n) cin >> a[i];
  reverse(ALL(a));
  FOR(i, 1, n) a[i] += a[i - 1];
  assert(a.back() == m);
  vector dp(m + 1, vector(m + 1, INF));
  REP(j, m + 1) dp[j][j] = abs(a.front() - j);
  FOR(i, 1, n) {
    vector yumeya(m + 1, vector(m + 1, INF));
    REP(j, m + 1) for (int k = 0; j + k <= m; ++k) chmin(yumeya[j + k][k], dp[j][k]);
    FOR(j, 1, m + 1) FOR(k, 1, m + 1) chmin(yumeya[j][k], yumeya[j - 1][k - 1]);
    REP(j, m + 1) REP(k, m + 1) {
      if (yumeya[j][k] != INF) yumeya[j][k] += abs(j - a[i]);
    }
    dp.swap(yumeya);
  }
  cout << *min_element(ALL(dp[m])) << '\n';
  return 0;
}