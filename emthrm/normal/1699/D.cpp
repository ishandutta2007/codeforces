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

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<int> num(n, 0);
  vector can_erase(n, vector(n, false));
  REP(i, n) {
    int most = 0;
    FOR(j, i, n) {
      chmax(most, ++num[a[j]]);
      can_erase[i][j] = (j - i + 1) % 2 == 0 && most <= (j - i + 1) / 2;
    }
    FOR(j, i, n) --num[a[j]];
  }
  vector<vector<int>> pos(n);
  REP(i, n) pos[a[i]].emplace_back(i);
  int ans = 0;
  for (vector<int>& p : pos) {
    if (p.empty()) continue;
    p.emplace(p.begin(), -1);
    p.emplace_back(n);
    const int m = p.size();
    vector<int> dp(m, -INF);
    dp[0] = 0;
    FOR(i, 1, m) REP(j, i) {
      if (p[j] + 1 == p[i] || can_erase[p[j] + 1][p[i] - 1]) chmax(dp[i], dp[j] + 1);
    }
    chmax(ans, dp[m - 1] - 1);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}