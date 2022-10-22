#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  int odd = 0, even = 0;
  vector<int> p(n); REP(i, n) cin >> p[i];
  FOR(i, 1, n + 1) {
    if (count(ALL(p), i) == 0) ++(i & 1 ? odd : even);
  }
  vector<vector<vector<vector<int> > > > dp(n + 1, vector<vector<vector<int> > >(odd + 1, vector<vector<int> >(even + 1, vector<int>(2, INF))));
  dp[0][0][0][0] = dp[0][0][0][1] = 0;
  REP(i, n) REP(j, odd + 1) REP(k, even + 1) REP(l, 2) {
    if (p[i] == 0) {
      if (j + 1 <= odd) {
        int plus = i - 1 >= 0 && l == 0;
        chmin(dp[i + 1][j + 1][k][1], dp[i][j][k][l] + plus);
      }
      if (k + 1 <= even) {
        int plus = i - 1 >= 0 && l == 1;
        chmin(dp[i + 1][j][k + 1][0], dp[i][j][k][l] + plus);
      }
    } else {
      int plus = i - 1 >= 0 && l != p[i] % 2;
      chmin(dp[i + 1][j][k][p[i] % 2], dp[i][j][k][l] + plus);
    }
  }
  cout << min(dp[n][odd][even][0], dp[n][odd][even][1]) << '\n';
  return 0;
}