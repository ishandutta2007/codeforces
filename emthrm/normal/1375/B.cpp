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

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  if (max({a[0][0], a[0][m - 1], a[n - 1][0], a[n - 1][m - 1]}) > 2) {
    cout << "NO\n";
    return;
  }
  REP(j, m) {
    if (a[0][j] > 3 || a[n - 1][j] > 3) {
      cout << "NO\n";
      return;
    }
  }
  REP(i, n) {
    if (a[i][0] > 3 || a[i][m - 1] > 3) {
      cout << "NO\n";
      return;
    }
  }
  REP(i, n) REP(j, m) {
    if (a[i][j] > 4) {
      cout << "NO\n";
      return;
    }
  }
  REP(i, n) REP(j, m) a[i][j] = 4;
  REP(i, n) a[i][0] = a[i][m - 1] = 3;
  REP(j, m) a[0][j] = a[n - 1][j] = 3;
  a[0][0] = a[0][m - 1] = a[n - 1][0] = a[n - 1][m - 1] = 2;
  cout << "YES\n";
  REP(i, n) REP(j, m) cout << a[i][j] << " \n"[j + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}