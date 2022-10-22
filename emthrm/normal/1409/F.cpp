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
  int n, k; cin >> n >> k;
  string s, t; cin >> s >> t;
  vector dp(1, vector(1, -INF));
  dp[0][0] = 0;
  REP(x, n) {
    vector nx(x + 2, vector(x + 2, -INF));
    REP(y, x + 1) REP(z, x + 1) {
      chmax(nx[y][z + (s[x] == t[0])], dp[y][z] + (s[x] == t[1]) * z);
      chmax(nx[y + 1][z + 1], dp[y][z] + (t[0] == t[1]) * z);
      chmax(nx[y + 1][z + (t[1] == t[0])], dp[y][z] + z);
    }
    dp.swap(nx);
  }
  cout << *max_element(ALL(dp[k])) << '\n';
  return 0;
}