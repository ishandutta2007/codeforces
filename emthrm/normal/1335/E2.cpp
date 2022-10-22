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
  vector<int> a(n), comp;
  REP(i, n) {
    cin >> a[i]; --a[i];
    comp.emplace_back(a[i]);
  }
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  int m = comp.size();
  REP(i, n) a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
  vector sum(m, vector(n + 1, 0));
  REP(j, n) REP(i, m) sum[i][j + 1] = sum[i][j] + (a[j] == i);
  // REP(i, m) REP(j, n + 1) cout << sum[i][j] << " \n"[j == n];
  vector<vector<int>> idx(m);
  REP(i, n) idx[a[i]].emplace_back(i);
  int ans = 0;
  REP(kind, m) {
    int sz = idx[kind].size();
    chmax(ans, sz);
    for (int i = 0; i < sz - 1 - i; ++i) {
      int l = idx[kind][i], r = idx[kind][sz - 1 - i];
      // cout << l << ' ' << r << '\n';
      int mx = 0;
      REP(j, m) chmax(mx, sum[j][r] - sum[j][l + 1]);
      chmax(ans, mx + (i + 1) * 2);
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}