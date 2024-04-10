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
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> add(n, 0), sub(n, 0);
  FOR(i, 1, n - 1) {
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
      ++add[i + 1];
      ++sub[i];
    }
  }
  // REP(i, n) cout << add[i] << " \n"[i + 1 == n];
  // REP(i, n) cout << sub[i] << " \n"[i + 1 == n];
  int t = 0, l = 0, now = 0;
  REP(i, k - 1) now += add[i];
  FOR(i, k - 1, n) {
    now += add[i];
    now -= sub[i - (k - 1)];
    // cout << i << ' ' << now << '\n';
    if (now > t) {
      t = now;
      l = i - (k - 1);
    }
  }
  cout << t + 1 << ' ' << l + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}