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

long long mod_inv(long long a, const int m) {
  if ((a %= m) < 0) a += m;
  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;
  long long x = 1;
  for (long long b = m, u = 0; b > 0;) {
    const long long q = a / b;
    std::swap(a -= q * b, b);
    std::swap(x -= q * u, u);
  }
  x %= m;
  return x < 0 ? x + m : x;
}

template <typename T>
std::pair<T, T> chinese_remainder_theorem(std::vector<T> b, std::vector<T> m) {
  const int n = b.size();
  T x = 0, md = 1;
  for (int i = 0; i < n; ++i) {
    if ((b[i] %= m[i]) < 0) b[i] += m[i];
    if (md < m[i]) {
      std::swap(x, b[i]);
      std::swap(md, m[i]);
    }
    if (md % m[i] == 0) {
      if (x % m[i] != b[i]) return {0, 0};
      continue;
    }
    const T g = std::__gcd(md, m[i]);
    if ((b[i] - x) % g != 0) return {0, 0};
    const T u_i = m[i] / g;
    x += (b[i] - x) / g % u_i * mod_inv(md / g, u_i) % u_i * md;
    md *= u_i;
    if (x < 0) x += md;
  }
  return {x, md};
}

const vector<ll> m{2, 3, 7, 11, 13, 17, 19, 23, 29};
constexpr int N = 9, Q = 30;
constexpr ll L = 1293938646;

void solve() {
  vector<ll> b(N, -1);
  ll l = L;
  for (int a = 1; a <= Q; ++a) {
    cout << "? " << a << ' ' << a + l << endl;
    int x; cin >> x;
    REP(i, N) {
      if (x % m[i] == 0) b[i] = (-a % m[i] + m[i]) % m[i];
    }
    if (b[0] != -1 && b[1] != -1 && l % 5 != 0) l = l / 6 * 5;
  }
  cout << "! " << chinese_remainder_theorem(b, m).first << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}