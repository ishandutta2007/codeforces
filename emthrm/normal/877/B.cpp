#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;
 
int main() {
  string s; cin >> s;
  int n = s.length();
  vector dp(n + 1, vector(4, 0));
  REP(i, n) REP(j, 4) {
    chmax(dp[i + 1][j], dp[i][j]);
    if (s[i] == 'a') {
      chmax(dp[i + 1][j + (j == 1)], dp[i][j] + 1);
    } else {
      chmax(dp[i + 1][j + (j == 0 || j == 2)], dp[i][j] + 1);
    }
  }
  // REP(j, 4) REP(i, n + 1) cout << dp[i][j] << " \n"[i == n];
  cout << *max_element(dp[n].begin(), dp[n].begin() + 3) << '\n';
  return 0;
}