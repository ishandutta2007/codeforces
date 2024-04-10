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
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  const int m = n * 100;
  vector<int> dp(m + 1, false);
  dp[0] = true;
  REP(i, n) {
    vector<int> nxt(m + 1, false);
    for (int j = m; j >= 0; --j) {
      if (!dp[j]) continue;
      if (j + a[i] <= m) nxt[j + a[i]] = true;
      if (j + b[i] <= m) nxt[j + b[i]] = true;
    }
    dp.swap(nxt);
  }
  const int s = accumulate(ALL(a), 0) + accumulate(ALL(b), 0);
  ll ans = LINF;
  REP(i, m + 1) {
    if (dp[i]) chmin(ans, 1LL * i * i + 1LL * (s - i) * (s - i));
  }
  REP(i, n) {
    ans -= a[i] * a[i];
    ans -= b[i] * b[i];
  }
  // ans = ans / 2 * 2;
  REP(i, n) {
    ans += (n - 1) * a[i] * a[i];
    ans += (n - 1) * b[i] * b[i];
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}