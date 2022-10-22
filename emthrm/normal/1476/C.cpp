#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> c(n), a(n), b(n);
  REP(i, n) cin >> c[i];
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  REP(i, n) {
    if (a[i] > b[i]) swap(a[i], b[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n;) {
    if (i > 0) chmax(ans, c[i] + 1);
    int j = i + 1;
    ll l = i == 0 ? 0 : 2;
    while (j < n && a[j] != b[j]) {
      if (j > 1) l += a[j] + c[j - 1] - b[j] + 1;
      chmax(l, abs(b[j] - a[j]) + 2);
      chmax(ans, l + c[j] - 1);
      ++j;
    }
    i = j;
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}