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
  int n, m, x, y; cin >> n >> m >> x >> y;
  vector<string> a(n); REP(i, n) cin >> a[i];
  int one = 0, two = 0;
  REP(i, n) for (int j = 0; j < m; ++j) {
    if (a[i][j] == '.') {
      if (j + 1 < m && a[i][j + 1] == '.') {
        ++two;
        ++j;
      } else {
        ++one;
      }
    }
  }
  cout << min(x * one + y * two, x * (one + two * 2)) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}