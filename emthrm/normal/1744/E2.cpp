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
std::vector<T> divisor(const T n) {
  std::vector<T> res;
  T i = 1;
  for (; i * i < n; ++i) {
    if (n % i == 0) {
      res.emplace_back(i);
      res.emplace_back(n / i);
    }
  }
  if (i * i == n && n % i == 0) res.emplace_back(i);
  std::sort(res.begin(), res.end());
  return res;
}

void solve() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  const vector<int> b_divs = divisor(b);
  for (const int a_div : divisor(a)) {
    for (const int b_div: b_divs) {
      const ll x_mul = 1LL * a_div * b_div;
      if (x_mul > c) break;
      const ll x = c / x_mul * x_mul;
      if (x <= a) continue;
      const ll y_mul = 1LL * a / a_div * b / b_div;
      if (y_mul > d) continue;
      const ll y = d / y_mul * y_mul;
      if (b < y) {
        cout << x << ' ' << y << '\n';
        return;
      }
    }
  }
  cout << "-1 -1\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}