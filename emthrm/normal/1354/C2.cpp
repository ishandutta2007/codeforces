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
  int n; cin >> n;
  n *= 2;
  function<double(double)> f = [&](double d) {
    double now = d, r1 = 0;
    REP(_, n / 2) {
      r1 += sin(now / 180 * M_PI);
      now += 360.0 / n;
      while (now >= 180) now -= 180;
    }
    now = 90 - d;
    double r2 = 0;
    REP(_, n / 2) {
      r2 += sin(now / 180 * M_PI);
      now += 360.0 / n;
      while (now >= 180) now -= 180;
    }
    return max(r1, r2);
  };
  double lb = 0, ub = 360.0 / n;
  REP(_, 100) {
    double m1 = (lb + lb + ub) / 3, m2 = (lb + ub + ub) / 3;
    if (f(m1) < f(m2)) {
      ub = m2;
    } else {
      lb = m1;
    }
  }
  cout << f(lb) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}