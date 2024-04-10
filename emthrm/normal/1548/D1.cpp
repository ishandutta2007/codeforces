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

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  ll ans = 0;
  REP(s, n) {
    int p[1 << 3]{};
    REP(i, n) {
      if (i == s) continue;
      int a = abs(x[i] - x[s]) / 2, b = abs(y[i] - y[s]) / 2;
      ++p[(a & 1) | ((b & 1) << 1) | ((gcd(a, b) & 1) << 2)];
    }
    REP(i, 1 << 3) FOR(j, i, 1 << 3) {
      int g = (((i & 1) == (j & 1)) && ((i >> 1 & 1) == (j >> 1 & 1))) ^ 1;
      if ((g + (i >> 2 & 1) + (j >> 2 & 1)) % 2 == 0) {
        ans += (j == i ? p[i] * (p[i] - 1LL) / 2 : 1LL * p[i] * p[j]);
      }
    }
  }
  cout << ans / 3 << '\n';
  return 0;
}