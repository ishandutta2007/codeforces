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

constexpr int N = 1000000;
int dp[N][2][2]{};
pair<int, int> prv[N][2][2]{};

void solve() {
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i];
  REP(i, n) REP(j, 2) fill(dp[i][j], dp[i][j] + 2, INF);
  REP(i, n) REP(j, 2) fill(prv[i][j], prv[i][j] + 2, make_pair(-1, -1));
  fill(dp[0][true], dp[0][true] + 2, -INF);
  REP(i, n - 1) REP(j, 2) REP(k, 2) {
    int x = dp[i][j][k];
    if (x == INF) continue;
    int y = (k ? -p[i] : p[i]);
    if (j) swap(x, y);
    assert(x > y);
    REP(sgn, 2) {
      const int z = (sgn ? -p[i + 1] : p[i + 1]);
      if (z > x) {
        if (chmin(dp[i + 1][true][sgn], y)) prv[i + 1][true][sgn] = {j, k};
      } else if (z > y) {
        if (chmin(dp[i + 1][false][sgn], x)) prv[i + 1][false][sgn] = {j, k};
      }
    }
  }
  vector<int> ans(n);
  int j = -1, k = -1;
  REP(j_, 2) REP(k_, 2) {
    if (dp[n - 1][j_][k_] != INF) {
      j = j_;
      k = k_;
    }
  }
  if (j == -1) {
    cout << "NO\n";
    return;
  }
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = (k ? -p[i] : p[i]);
    tie(j, k) = prv[i][j][k];
  }
  cout << "YES\n";
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}