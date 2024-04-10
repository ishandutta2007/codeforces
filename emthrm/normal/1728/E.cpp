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

template <typename T>
std::pair<T, T> ext_gcd(T a, T b) {
  T x = 1, y = 0;
  for (T u = 0, v = 1; b;) {
    const T q = a / b;
    std::swap(a -= q * b, b);
    std::swap(x -= q * u, u);
    std::swap(y -= q * v, v);
  }
  return a < 0 ? std::make_pair(-x, -y) : std::make_pair(x, y);
}

int main() {
  constexpr int S = 547;
  int n; cin >> n;
  vector<ll> ans(n + 1, 0);
  REP(i, n) {
    int a; cin >> a >> ans[i];
    ans.back() += a;
    ans[i] -= a;
  }
  sort(ans.begin(), ans.begin() + n);
  for (int i = n - 1; i >= 0; --i) {
    ans[i] += ans[i + 1];
  }
  // REP(i, n + 1) cout << ans[i] << " \n"[i == n];
  vector<ll> sqr[S]{};
  FOR(d, 1, S) {
    sqr[d].assign(d, -1);
    for (int i = 0, j = 0; i <= n; ++i, ++j) {
      if (j == d) j = 0;
      chmax(sqr[d][j], ans[i]);
    }
  }

  int m; cin >> m;
  while (m--) {
    int x, y; cin >> x >> y;
    const int g = gcd(x, y);
    if (n % g > 0) {
      cout << "-1\n";
      continue;
    }
    const int d = y / g;
    ll p = ext_gcd<ll>(x, y).first * n / g % d;
    if (p < 0) p += d;
    if (x * p > n) {
      cout << "-1\n";
    } else if (1LL * x * d < S) {
      cout << sqr[x * d][x * p] << '\n';
    } else {
      const ll add = 1LL * x * d;
      ll maxi = -1;
      for (ll i = x * p; i <= n; i += add) chmax(maxi, ans[i]);
      cout << maxi << '\n';
    }
  }
  return 0;
}