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

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  vector<ll> c(n * 2 - 1, 0LL);
  REP(i, n) REP(j, n) c[i + j] += 1LL * a[i] * b[j];
  vector<ll> suf(n);
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = 1LL * a[i] * b[i];
    if (i + 1 < n) suf[i] += suf[i + 1];
  }
  ll ans = suf[0], pre = 0;
  REP(i, n) {
    FOR(j, i, n) chmax(ans, pre + c[i + j] + (j + 1 == n ? 0 : suf[j + 1]));
    FOR(j, i, n) c[i + j] -= 1LL * a[i] * b[j];
    FOR(j, i + 1, n) c[i + j] -= 1LL * a[j] * b[i];
    pre += 1LL * a[i] * b[i];
  }
  cout << ans << '\n';
  return 0;
}