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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<ll> a(n); REP(i, n) cin >> a[i];
  for (int i = n - 2; i >= 0; --i) a[i] += a[i + 1];
  int k = 1;
  while ((k + 1) * (k + 2) / 2 <= n) ++k;
  vector<ll> m(k + 1, -LINF);
  m[0] = LINF;
  vector can(n, vector(k + 1, 0LL));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= k && i + j - 1 < n; ++j) {
      if (ll seg = a[i] - (i + j == n ? 0 : a[i + j]); m[j - 1] > seg) {
        can[i][j] = seg;
      }
    }
    for (int j = 1; j <= k && i + j < n; ++j) {
      if (can[i + j][j] > 0) chmax(m[j], can[i + j][j]);
    }
  }
  for (int ans = k; ans > 0; --ans) {
    REP(i, n) {
      if (can[i][ans] > 0) {
        cout << ans << '\n';
        return;
      }
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}