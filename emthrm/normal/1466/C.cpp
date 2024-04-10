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

constexpr int C = 26;
void solve() {
  string s; cin >> s;
  if (s.length() == 1) {
    cout << 0 << '\n';
    return;
  }
  vector dp(C + 1, vector(C + 1, INF));
  dp[C][C] = 0;
  for (char c : s) {
    int v = c - 'a';
    vector nx(C + 1, vector(C + 1, INF));
    vector<int> m1(C + 1), m2(C + 1);
    REP(j, C + 1) {
      if (dp[0][j] < dp[1][j]) {
        m1[j] = 0;
        m2[j] = 1;
      } else {
        m1[j] = 1;
        m2[j] = 0;
      }
      FOR(i, 2, C + 1) {
        if (dp[i][j] < dp[m1[j]][j]) {
          swap(m1[j], m2[j]);
          m1[j] = i;
        } else if (dp[i][j] < dp[m2[j]][j]) {
          m2[j] = i;
        }
      }
    }
    REP(j, C + 1) REP(k, C) {
      if (j != k) chmin(nx[j][k], (m1[j] == k ? dp[m2[j]][j] : dp[m1[j]][j]) + (k != v));
    }
    dp.swap(nx);
  }
  int ans = INF;
  REP(i, C + 1) chmin(ans, *min_element(ALL(dp[i])));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}