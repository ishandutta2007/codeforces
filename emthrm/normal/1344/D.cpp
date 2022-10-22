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
  int n; ll k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  ll lb = -LINF, ub = LINF;
  while (ub - lb > 1) {
    ll mid = (lb + ub) >> 1, sum = 0;
    REP(i, n) {
      int mn = 0, mx = a[i] + 1;
      while (mx - mn > 1) {
        int x = (mn + mx) >> 1;
        (a[i] - 3LL * x * x + 3LL * x - 1 >= mid ? mn : mx) = x;
      }
      sum += mn;
    }
    (sum <= k ? ub : lb) = mid;
  }
  vector<int> b(n);
  REP(i, n) {
    int mn = 0, mx = a[i] + 1;
    while (mx - mn > 1) {
      int x = (mn + mx) >> 1;
      (a[i] - 3LL * x * x + 3LL * x - 1 >= ub ? mn : mx) = x;
    }
    b[i] = mn;
    k -= b[i];
  }
  // REP(i, n) cout << b[i] << " \n"[i + 1 == n];
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int l, int r) {
    ll p = b[l] == a[l] ? -LINF : a[l] - 3LL * (b[l] + 1) * (b[l] + 1) + 3LL * (b[l] + 1) - 1;
    ll q = b[r] == a[r] ? -LINF : a[r] - 3LL * (b[r] + 1) * (b[r] + 1) + 3LL * (b[r] + 1) - 1;
    return p > q;
  });
  REP(i, k) ++b[idx[i]];
  REP(i, n) cout << b[i] << " \n"[i + 1 == n];
  return 0;
}