#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <int MOD>
struct MInt {
  unsigned val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}
  static int get_mod() { return MOD; }
  static void set_mod(int divisor) { assert(divisor == MOD); }
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator-=(const MInt &x) { if((val += MOD - x.val) >= MOD) val -= MOD; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }
  MInt &operator/=(const MInt &x) {
    // assert(std::__gcd(static_cast<int>(x.val), MOD) == 1);
    unsigned a = x.val, b = MOD; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      std::swap(a -= tmp * b, b);
      std::swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == MOD) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? MOD : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? MOD - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x) { return x; } }
template <int MOD>
struct Combinatorics {
  using ModInt = MInt<MOD>;
  int val;  // "val!" and "mod" must be disjoint.
  std::vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : nCk(n + k - 1, k);
  }
};
using ModInt = MInt<MOD>;

int main() {
  int n, x, pos; cin >> n >> x >> pos;
  int not_gre = 0, gre = 0;
  int left = 0, right = n;
  while (left < right) {
    int middle = (left + right) / 2;
    if (middle <= pos) {
      if (middle < pos) ++not_gre;
      left = middle + 1;
    } else {
      ++gre;
      right = middle;
    }
  }
  if (not_gre > x - 1 || gre > n - x) {
    cout << 0 << '\n';
    return 0;
  }
  Combinatorics<MOD> com(n);
  cout << com.nCk(x - 1, not_gre) * com.fact[not_gre] * com.nCk(n - x, gre) * com.fact[gre] * com.fact[n - 1 - not_gre - gre] << '\n';
  return 0;
}