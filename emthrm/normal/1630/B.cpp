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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<int> b(n, 0);
  REP(i, n) ++b[a[i]];
  const int need = k - 1 + ((n - (k - 1)) / 2 + 1);
  int ans = n - 1, ans_l = 0, ans_r = n - 1, s = 0, r = 0;
  REP(l, n) {
    while (r < n && s < need) s += b[r++];
    if (s >= need && chmin(ans, r - 1 - l)) {
      ans_l = l;
      ans_r = r - 1;
    }
    s -= b[l];
  }
  cout << ans_l + 1 << ' ' << ans_r + 1 << '\n';
  int i = 0;
  REP(seg, k - 1) {
    int x = 0, j = i;
    while (x <= 0) {
      x += (ans_l <= a[j] && a[j] <= ans_r ? 1 : -1);
      ++j;
    }
    cout << i + 1 << ' ' << j << '\n';
    i = j;
  }
  cout << i + 1 << ' ' << n << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}