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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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
  int m; cin >> m;
  vector<int> p(m); REP(i, m) cin >> p[i], --p[i];
  if (m == 1) {
    cout << 0 << '\n';
    return;
  }
  int ans = 0;
  const auto f = [&](auto&& f, const int l, const int r) -> pair<int, int> {
    if (l + 2 == r) {
      if (abs(p[l] - p[l + 1]) > 1) ans = INF;
      ans += p[l] > p[l + 1];
      return minmax(p[l], p[l + 1]);
    }
    const int m = (l + r) / 2;
    const auto [l1, r1] = f(f, l, m);
    const auto [l2, r2] = f(f, m, r);
    if (r1 + 1 != l2 && r2 + 1 != l1) ans = INF;
    ans += l1 > l2;
    return {min(l1, l2), max(r1, r2)};
  };
  f(f, 0, m);
  cout << (ans >= INF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}