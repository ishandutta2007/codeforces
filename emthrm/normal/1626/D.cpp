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

int f(int x) {
  if (x == 0) return 1;
  return __builtin_popcount(x) == 1 ? x : 1 << (32 - __builtin_clz(x));
}

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1, 0);
  REP(_, n) {
    int ai; cin >> ai; --ai;
    ++a[ai];
  }
  vector<int> s = a;
  REP(i, n) s[i + 1] += s[i];
  const auto sum = [&](int l, int r) -> int {
    return s[r] - (l == 0 ? 0 : s[l - 1]);
  };
  vector<int> heavy;
  for (int i = n - 1, x = 0, p2 = 0; i >= 0;) {
    while (i >= 0 && x + a[i] <= p2) x += a[i--];
    heavy.emplace_back(i);
    p2 = (p2 == 0 ? 1 : p2 << 1);
  }
  const int b = heavy.size();
  int light = 0, ans = f(n) + 2;
  REP(ml, n) {
    const int light_f = f(light);
    REP(i, b) {
      const int heavy_f = (i == 0 ? 1 : 1 << (i - 1));
      if (heavy[i] < ml) {
        if (i == 0 || heavy[i - 1] > ml) chmin(ans, light_f + 1 + heavy_f);
        break;
      }
      chmin(ans, light_f + f(sum(ml, heavy[i])) + heavy_f);
    }
    light += a[ml];
  }
  cout << ans - n << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}