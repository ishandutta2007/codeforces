#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n, m, k; cin >> n >> m >> k;
  vector<int> dp(k, -INF);
  dp[0] = 0;
  REP(i, n) {
    vector<int> a(m); REP(j, m) cin >> a[j];
    vector nx(m + 1, vector(k, vector(m / 2 + 1, -INF)));
    REP(x, k) nx[0][x][0] = dp[x];
    REP(j, m) {
      REP(x, k) for (int y = 0; y <= j && y <= m / 2; ++y) {
        chmax(nx[j + 1][x][y], nx[j][x][y]);
        if (y + 1 <= m) chmax(nx[j + 1][(x + a[j]) % k][y + 1], nx[j][x][y] + a[j]);
      }
    }
    REP(x, k) dp[x] = *max_element(ALL(nx[m][x]));
  }
  cout << dp[0] << '\n';
  return 0;
}