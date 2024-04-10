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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

long long mod_inv(long long a, int m) {
  if ((a %= m) < 0) a += m;
  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;
  long long b = m, x = 1, u = 0;
  while (b > 0) {
    long long q = a / b;
    std::swap(a -= q * b, b);
    std::swap(x -= q * u, u);
  }
  x %= m;
  return x < 0 ? x + m : x;
}

int main() {
  int n, m; ll k; cin >> n >> m >> k;
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i], --a[i];
  REP(i, m) cin >> b[i], --b[i];
  if (n > m) {
    swap(n, m);
    swap(a, b);
  }
  int x = max(n, m) * 2;
  vector<int> pos(x, -1);
  REP(i, m) pos[b[i]] = i;
  ll g = gcd(n, m), l = n / g * m;
  int inv_n = mod_inv(n / g, m / g);
  assert(inv_n != -1);
  vector<int> small(n, -1);
  REP(i, n) {
    if (pos[a[i]] != -1 && abs(i - pos[a[i]]) % g == 0) small[i] = (((pos[a[i]] - i) % m + m) % m) / g * inv_n % (m / g);
  }
  ll lb = 0, ub = m * k;
  while (ub - lb > 1) {
    ll mid = (lb + ub) >> 1;
    ll diff = 0;
    REP(i, n) {
      diff += mid / n + (i < mid % n);
      if (pos[a[i]] != -1 && abs(i - pos[a[i]]) % g == 0) {
        diff -= mid / l;
        diff -= (i + 1 + 1LL * n * small[i] <= mid % l);
      }
      if (diff >= k) break;
    }
    (diff >= k ? ub : lb) = mid;
  }
  cout << ub << '\n';
  return 0;
}