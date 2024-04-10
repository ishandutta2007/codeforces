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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> mn_l(n, -1), mn_r(n, -1);
  mn_l[1] = 0;
  FOR(i, 2, n) {
    if (a[i - 1] < a[mn_l[i - 1]]) {
      mn_l[i] = i - 1;
    } else {
      mn_l[i] = mn_l[i - 1];
    }
  }
  mn_r[n - 2] = n - 1;
  for (int i = n - 3; i >= 0; --i) {
    if (a[i + 1] < a[mn_r[i + 1]]) {
      mn_r[i] = i + 1;
    } else {
      mn_r[i] = mn_r[i + 1];
    }
  }
  FOR(i, 1, n - 1) {
    if (a[mn_l[i]] < a[i] && a[mn_r[i]] < a[i]) {
      cout << "YES\n" << mn_l[i] + 1 << ' ' << i + 1 << ' ' << mn_r[i] + 1 << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}