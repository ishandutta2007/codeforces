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
  vector<string> ans(n, string(n, '0'));
  REP(j, n) REP(i, n) {
    if (k > 0) {
      ans[i][(j + i) % n] = '1';
      --k;
    }
  }
  vector<int> r(n, 0), c(n, 0);
  REP(i, n) r[i] = count(ALL(ans[i]), '1');
  sort(ALL(r));
  REP(j, n) REP(i, n) c[j] += ans[i][j] == '1';
  sort(ALL(c));
  cout << (r[n - 1] - r[0]) * (r[n - 1] - r[0]) + (c[n - 1] - c[0]) * (c[n - 1] - c[0]) << '\n';
  REP(i, n) cout << ans[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}