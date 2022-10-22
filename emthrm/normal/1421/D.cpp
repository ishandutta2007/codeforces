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

void solve() {
  ll x, y; cin >> y >> x;
  vector<ll> c(6); REP(i, 6) cin >> c[i];
  auto f = [&](ll dy, ll dx) {
    ll cost = 0;
    cost += dy > 0 ? c[5] * dy : c[2] * -dy;
    cost += dx > 0 ? c[1] * dx : c[4] * -dx;
    return cost;
  };
  ll ans = LINF;
  // c_0
  {
    ll lb = 0, ub = 1000000000;
    while (ub - lb > 3) {
      ll m1 = (lb + lb + ub) / 3, m2 = (lb + ub + ub) / 3;
      ll cost1 = f(y - m1, x - m1) + c[0] * m1, cost2 = f(y - m2, x - m2) + c[0] * m2;
      if (cost1 < cost2) {
        ub = m2;
      } else {
        lb = m1;
      }
    }
    FOR(i, lb, ub + 1) chmin(ans, f(y - i, x - i) + c[0] * i);
  }
  // c_3
  {
    ll lb = 0, ub = 1000000000;
    while (ub - lb > 3) {
      ll m1 = (lb + lb + ub) / 3, m2 = (lb + ub + ub) / 3;
      ll cost1 = f(y + m1, x + m1) + c[3] * m1, cost2 = f(y + m2, x + m2) + c[3] * m2;
      if (cost1 < cost2) {
        ub = m2;
      } else {
        lb = m1;
      }
    }
    FOR(i, lb, ub + 1) chmin(ans, f(y + i, x + i) + c[3] * i);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}