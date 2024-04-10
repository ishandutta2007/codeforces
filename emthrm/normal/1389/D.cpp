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
  ll n, k, l1, r1, l2, r2; cin >> n >> k >> l1 >> r1 >> l2 >> r2;
  if (l1 > l2) {
    swap(l1, l2);
    swap(r1, r2);
  }
  if (l2 <= r1) {
    if (r2 <= r1) {
      ll len = (r2 - l2) * n;
      if (len >= k) {
        cout << 0 << '\n';
        return;
      }
      ll add = ((r1 - l1) - (r2 - l2)) * n;
      cout << (len + add >= k ? k - len : add + (k - len - add) * 2) << '\n';
    } else {
      ll len = (r1 - l2) * n;
      if (len >= k) {
        cout << 0 << '\n';
        return;
      }
      ll add = ((r2 - l1) - (r1 - l2)) * n;
      cout << (len + add >= k ? k - len : add + (k - len - add) * 2) << '\n';
    }
  } else {
    ll len = 0, cost = 0;
    REP(i, n) {
      cost += l2 - r1;
      if (len + r2 - l1 >= k) {
        cout << cost + k - len << '\n';
        return;
      }
      len += r2 - l1;
      cost += r2 - l1;
      if (i + 1 < n && l2 - r1 + min(r2 - l1, k - len) < min(r2 - l1, k - len) * 2) continue;
      cout << cost + (k - len) * 2 << '\n';
      return;
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}