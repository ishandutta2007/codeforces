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
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  auto get = [&](int idx) {
    return a[idx] <= b[idx] ? make_tuple(0, b[idx] - a[idx], b[idx]) : make_tuple(a[idx] - b[idx], 0, b[idx]);
  };
  auto [minx, mink, maxk] = get(0);
  FOR(i, 1, n) {
    auto [p, q, r] = get(i);
    if (p < mink) {
      maxk = min(q + maxk - p, r);
      mink = min(q + mink - p, r);
    } else if (mink <= p && p <= maxk) {
      minx += p - mink;
      mink = q;
      maxk = min(q + maxk - p, r);
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << (minx <= mink ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}