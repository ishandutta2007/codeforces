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
  int n, m; cin >> n >> m;
  vector<int> a(m), b(m); REP(i, m) cin >> a[i] >> b[i];
  vector<int> idx(m);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int l, int r) { return a[l] == a[r] ? b[l] > b[r] : a[l] > a[r]; });
  vector sum(m, 0LL);
  REP(i, m) sum[i] = (i > 0 ? sum[i - 1] : 0) + a[idx[i]];
  ll ans = 0;
  if (m >= n) ans = sum[n - 1];
  REP(i, m) {
    int lb = -1, ub = m;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (a[idx[mid]] > b[idx[i]] ? lb : ub) = mid;
    }
    if (i <= lb) {
      if (lb + 1 > n) continue;
      chmax(ans, sum[lb] + 1LL * b[idx[i]] * (n - (lb + 1)));
    } else {
      if (lb + 1 + 1 > n) continue;
      chmax(ans, (lb == -1 ? 0 : sum[lb]) + a[idx[i]] + 1LL * b[idx[i]] * (n - (lb + 2)));
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}