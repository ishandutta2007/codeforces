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
  vector<int> seg{0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
  int n, k; cin >> n >> k;
  vector<string> digits(n); REP(i, n) cin >> digits[i];
  vector memo(n, vector(10, -1));
  REP(i, n) {
    int val = bitset<7>(digits[i]).to_ulong();
    REP(j, 10) {
      if ((val & seg[j]) == val) memo[i][j] = __builtin_popcount(val ^ seg[j]);
    }
  }
  vector dp(n + 1, vector(k + 1, false));
  dp[n][0] = true;
  for (int i = n - 1; i >= 0; --i) REP(j, k + 1) {
    REP(l, 10) {
      // cout << j << ' ' << memo[i][l] << '\n';
      if (memo[i][l] != -1 && j - memo[i][l] >= 0 && dp[i + 1][j - memo[i][l]]) {
        // cout << i << ' ' << j << '\n';
        dp[i][j] = true;
        break;
      }
    }
  }
  // REP(i, n + 1) REP(j, k + 1) cout << dp[i][j] << " \n"[j == k];
  if (!dp[0][k]) {
    cout << "-1\n";
    return 0;
  }
  string ans = "";
  REP(i, n) {
    for (int j = 9; j >= 0; --j) {
      if (memo[i][j] != -1 && k - memo[i][j] >= 0 && dp[i + 1][k - memo[i][j]]) {
        ans += '0' + j;
        k -= memo[i][j];
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}