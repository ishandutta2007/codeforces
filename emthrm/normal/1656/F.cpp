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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  if (a[0] * (n - 2LL) + accumulate(ALL(a), 0LL) > 0 ||
      a[n - 1] * (n - 2LL) + accumulate(ALL(a), 0LL) < 0) {
    cout << "INF\n";
    return;
  }
  if (n == 2) {
    cout << 1LL * a[0] * a[1] << '\n';
    return;
  }
  auto f = [&](int t) -> ll {
    vector<int> b(n);
    REP(i, n) b[i] = a[i] + t;
    ll cost = 1LL * b[0] * b[n - 1];
    FOR(i, 1, n - 1) cost += 1LL * b[i] * b[b[i] > 0 ? 0 : n - 1];
    return cost - (n - 1LL) * t * t;
  };
  int l = -a[n - 2], r = -a[1];
  while (r - l >= 3) {
    const int len = (r - l) / 3, m1 = l + len, m2 = m1 + len;
    if (f(m1) < f(m2)) {
      l = m1;
    } else {
      r = m2;
    }
  }
  ll ans = -LINF;
  FOR(i, l, r + 1) chmax(ans, f(i));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}