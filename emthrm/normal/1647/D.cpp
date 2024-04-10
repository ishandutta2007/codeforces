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

bool is_prime(const long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  int x, d; cin >> x >> d;
  int p = 0;
  for (; x % d == 0; x /= d) ++p;
  if (p == 1) {
    cout << "NO\n";
    return;
  }
  const bool d_is_prime = is_prime(d);
  if (x == 1) {
    cout << (d_is_prime || p == 2 ? "NO\n" : "YES\n");
    return;
  }
  const bool x_is_prime = is_prime(x);
  if (!x_is_prime) {
    cout << "YES\n";
    return;
  }
  if (d_is_prime || p == 2) {
    cout << "NO\n";
    return;
  }
  if (p >= 4) {
    cout << "YES\n";
    return;
  }
  cout << (1LL * x * x == d ? "NO\n" : "YES\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}