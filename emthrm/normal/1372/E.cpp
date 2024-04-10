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
  int n, m; cin >> n >> m;
  vector<vector<int>> left(n, vector<int>(m)), right(n, vector<int>(m));
  REP(i, n) {
    int k; cin >> k;
    while (k--) {
      int l, r; cin >> l >> r; --l; --r;
      FOR(j, l, r + 1) {
        left[i][j] = l;
        right[i][j] = r;
      }
    }
  }
  vector dp(m, vector(m, 0));
  FOR(len, 1, m + 1) for (int i = 0; i + len <= m; ++i) {
    int j = i + len - 1;
    FOR(k, i, j + 1) {
      int q = 0;
      REP(row, n) q += i <= left[row][k] && right[row][k] <= j;
      chmax(dp[i][j], (k - 1 < i ? 0 : dp[i][k - 1]) + q * q + (j < k + 1 ? 0 : dp[k + 1][j]));
    }
  }
  cout << dp[0][m - 1] << '\n';
  return 0;
}