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
  auto f = [&](int i, int j, int k) {
    ll xi = x[i] - x[j], yi = y[i] - y[j], xk = x[k] - x[j], yk = y[k] - y[j];
    return xi * xk + yi * yk > 0;
  };
  vector<int> ans{0};
  FOR(i, 1, n) {
    ans.emplace_back(i);
    for (int j = i; j >= 0; --j) {
      bool osu = true;
      for (int k = j - 2; k <= j; ++k) {
        if (0 <= k && k + 2 <= i) osu &= f(ans[k], ans[k + 1], ans[k + 2]);
      }
      if (osu) break;
      assert(j > 0);
      swap(ans[j - 1], ans[j]);
    }
  }
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}