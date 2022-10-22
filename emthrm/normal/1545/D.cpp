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
  int m, k; cin >> m >> k;
  vector<vector<int>> x(k, vector<int>(m)); REP(i, k) REP(j, m) cin >> x[i][j];
  ll sum_x = accumulate(ALL(x[0]), 0LL), sum_v = (accumulate(ALL(x[k - 1]), 0LL) - sum_x) / (k - 1);
  ll sum_x2 = 0;
  REP(j, m) sum_x2 += 1LL * x[0][j] * x[0][j];
  ll tmp1 = 0;
  REP(j, m) tmp1 += 1LL * x[k - 1][j] * x[k - 1][j];
  tmp1 = (tmp1 - sum_x2) / (k - 1);
  FOR(t, 1, k - 1) {
    ll d = accumulate(ALL(x[t]), 0LL) - (sum_v * t + sum_x);
    if (d == 0) continue;
    FOR(i, 1, k - 1) {
      if (i == t) continue;
      ll tmp2 = 0;
      REP(j, m) tmp2 += 1LL * x[i][j] * x[i][j];
      tmp2 = (tmp2 - sum_x2) / i;
      ll sum_v2 = (tmp1 - tmp2) / (k - 1 - i), sum_2xv = tmp1 - sum_v2 * (k - 1);
      ll p = 0;
      REP(j, m) p += 1LL * x[t][j] * x[t][j];
      p -= sum_x2 + sum_2xv * t + sum_v2 * t * t;
      cout << t << ' ' << (p - d * d) / (d * 2) << endl;
      return 0;
    }
  }
  assert(false);
}