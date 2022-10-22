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

constexpr int P = 100;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> t(m), p(m);
  vector<vector<int>> options(n);
  REP(i, m) {
    int e; cin >> e >> t[i] >> p[i]; --e;
    options[e].emplace_back(i);
  }
  ll tm = 0;
  vector<int> ans;
  REP(i, n) {
    const int l = options[i].size();
    vector dp(l + 1, vector(P + 1, LINF));
    vector prev(l + 1, vector(P + 1, -1));
    dp[0][0] = 0;
    REP(x, l) REP(y, P + 1) {
      if (chmin(dp[x + 1][y], dp[x][y])) prev[x + 1][y] = y;
      if (chmin(dp[x + 1][min(y + p[options[i][x]], P)], dp[x][y] + t[options[i][x]])) prev[x + 1][min(y + p[options[i][x]], P)] = y;
    }
    tm += dp[l][P];
    if (tm > a[i]) {
      cout << "-1\n";
      return;
    }
    int y = P;
    for (int x = l - 1; x >= 0; --x) {
      if (prev[x + 1][y] < y) {
        ans.emplace_back(options[i][x]);
        y = prev[x + 1][y];
      }
    }
  }
  const int k = ans.size();
  cout << k << '\n';
  REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}