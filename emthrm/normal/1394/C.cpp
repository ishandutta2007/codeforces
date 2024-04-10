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
  const int X = 500000;
  int n; cin >> n;
  vector a(n, 0), b(n, 0);
  REP(i, n) {
    string s; cin >> s;
    for (char c : s) ++(c == 'B' ? a[i] : b[i]);
  }
  function<string(int)> solve = [&](int d) -> string {
    int la = 0, ra = X, lb = 0, rb = X, l_intercept = -X, r_intercept = X;
    REP(i, n) {
      chmax(la, a[i] - d);
      chmin(ra, a[i] + d);
      chmax(lb, b[i] - d);
      chmin(rb, b[i] + d);
      chmax(l_intercept, b[i] - a[i] - d);
      chmin(r_intercept, b[i] - a[i] + d);
    }
    for (int x = la; x <= ra; ++x) {
      int ly = max({lb, x + l_intercept, int(x == 0)}), ry = min(rb, x + r_intercept);
      if (ly <= ry) {
        string s = "";
        while (x--) s += 'B';
        while (ly--) s += 'N';
        return s;
      }
    }
    return "";
  };
  int lb = -1, ub = X * 2;
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    (solve(mid).empty() ? lb : ub) = mid;
  }
  cout << ub << '\n' << solve(ub) << '\n';
  return 0;
}