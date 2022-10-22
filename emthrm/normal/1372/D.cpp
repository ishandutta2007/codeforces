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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  ll l1 = 0, l2 = 0, r1 = 0, r2 = 0;
  for (int i = n - 1; i >= 0; i -= 2) r2 += a[i];
  for (int i = n - 2; i >= 0; i -= 2) r1 += a[i];
  ll ans = r2;
  REP(i, n) {
    if (i % 2 == 0) {
      l1 += a[i];
      r2 -= a[i];
      chmax(ans, l1 + r1);
    } else {
      l2 += a[i];
      r1 -= a[i];
      chmax(ans, l2 + r2);
    }
    // cout << l1 << ' ' << l2 << ' ' << r1 << ' ' << r2 << '\n';
  }
  cout << ans << '\n';
}