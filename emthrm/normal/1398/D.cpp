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
  int R, G, B; cin >> R >> G >> B;
  vector<int> r(R), g(G), b(B);
  REP(i, R) cin >> r[i];
  sort(ALL(r), greater<int>());
  REP(i, G) cin >> g[i];
  sort(ALL(g), greater<int>());
  REP(i, B) cin >> b[i];
  sort(ALL(b), greater<int>());
  vector dp(R + 1, vector(G + 1, vector(B + 1, 0LL)));
  REP(i, R + 1) REP(j, G + 1) REP(k, B + 1) {
    if (i < R && j < G) chmax(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
    if (j < G && k < B) chmax(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
    if (k < B && i < R) chmax(dp[i + 1][j][k + 1], dp[i][j][k] + b[k] * r[i]);
  }
  ll ans = 0;
  REP(i, R + 1) REP(j, G + 1) REP(k, B + 1) chmax(ans, dp[i][j][k]);
  cout << ans << '\n';
  return 0;
}