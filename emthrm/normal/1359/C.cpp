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
  int h, c, t; cin >> h >> c >> t;
  if (t * 2 <= h + c) {
    cout << "2\n";
    return;
  }
  ll lb = 0, ub = 1000001;
  while (ub - lb > 1) {
    ll mid = (lb + ub) / 2;
    (mid * (h + c) + h >= (mid * 2 + 1) * t ? lb : ub) = mid;
  }
  if ((lb * 2 + 3) * (lb * (h + c) + h) > ((lb * 2 + 3) * 2 * t - (lb + 1) * (h + c) - h) * (lb * 2 + 1)) ++lb;
  cout << lb * 2 + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}