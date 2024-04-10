#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/number/mod_int.h"

// START #include "../math/extended_gcd.h"

template <typename T>
tuple<T, T, T> extended_gcd(T a, T b) {
  if (b == 0) return tuple(a, 1, 0);
  auto [g, y, x] = extended_gcd(b, a % b);
  return tuple(g, x, y - x * (a / b));
}

// END #include "../math/extended_gcd.h"

template <long long mod_value, bool is_prime = true>
struct mod_int {
  static_assert(mod_value > 0);
  using mod_t = conditional_t < mod_value < 1LL << 31, int, long long>;
  using larger_t = conditional_t < mod_value < 1LL << 31, long long, __int128>;
  static constexpr mod_t mod = mod_value;
  mod_t v;
  mod_int() = default;
  mod_int(const mod_t& c): v(c) {
    if (abs(v) >= mod) v %= mod;
    if (v < 0) v += mod;
  }
  mod_int(const larger_t& c) {
    v = (mod_t) (abs(c) >= mod ? c % mod : c);
    if (v < 0) v += mod;
  }
  friend istream& operator >> (istream& is, mod_int& num) {
    is >> num.v;
    if (abs(num.v) >= mod) num.v %= mod;
    if (num.v < 0) num.v += mod;
    return is;
  }
  friend ostream& operator << (ostream& os, const mod_int& num) { return os << num.v; }
  int value() const { return v; }
  bool operator == (const mod_int& o) const { return v == o.v; }
  bool operator != (const mod_int& o) const { return v != o.v; }
  mod_int operator + (const mod_int& o) const { return mod_int(*this) += o; }
  mod_int operator - (const mod_int& o) const { return mod_int(*this) -= o; }
  mod_int operator * (const mod_int& o) const { return mod_int(*this) *= o; }
  mod_int operator / (const mod_int& o) const { return mod_int(*this) /= o; }
  mod_int operator - () const { return mod_int(*this).negate(); }
  mod_int& negate() {
    if (v != 0) v = mod - v;
    return *this;
  }
  mod_int& operator += (const mod_int& o) {
    v += o.v;
    if (v >= mod) v -= mod;
    return *this;
  }
  mod_int& operator -= (const mod_int& o) {
    v -= o.v;
    if (v < 0) v += mod;
    return *this;
  }
  mod_int& operator *= (const mod_int& o) {
    v = (mod_t)((larger_t)v * o.v % mod);
    return *this;
  }
  mod_int& operator /= (const mod_int& o) {
    return operator *= (o.inverse());
  }
  mod_int pow(long long exponent) const {
    if (exponent == 0) return mod_int(1);
    if (v == 0) {
      if (exponent < 0) throw invalid_argument("raising zero to a negative power");
      return mod_int(0);
    }
    if constexpr (is_prime) {
      if (abs(exponent) >= mod - 1) exponent %= mod - 1;
      if (exponent < 0) exponent += mod - 1;
      mod_int res(1), base(*this);
      for (; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    } else {
      mod_int res(1), base(exponent < 0 ? inverse() : *this);
      for (; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    }
  }
  mod_int inverse() const {
    auto [g, x, y] = extended_gcd(mod, v);
    if (g != 1) throw invalid_argument("taking the inverse of a non-coprime number");
    assert(operator*(mod_int(y)) == 1);
    return mod_int(y < 0 ? y + mod : y);
  }
};

// END #include "../../../lca/number/mod_int.h"

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9 + 7;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using Int = mod_int<MOD>;

const int N = 3e6 + 2;
Int fact[N], invf[N];
Int ncr(int n, int r) {
  if(r<0 || n<r) return 0;
  return fact[n] * invf[r] * invf[n-r];
}

Int dp[N]; // top mod 3

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  fact[0] = 1;
  for(int i=1; i<N; i++) {
    fact[i] = fact[i-1] * i;
  }
  invf[N-1] = fact[N-1].inverse();
  for(int i=N-1; i>0; i--) {
    invf[i-1] = invf[i] * i;
  }
  assert(invf[0] == 1);

  int n, q;
  cin >> n >> q;
  int m = 3 * n;
  Int inv3 = Int(3).inverse();

  dp[0] = n + 1; // sum 3k choose 0
  for(int i=1; i<=3*n; i++) {
    Int val = ncr(m+1, i+1) + ncr(m, i) * 2;
    val -= (dp[i-1] - ncr(m, i-1)) * 3;
    if(i-2 >= 0) val -= dp[i-2] - ncr(m, i-2);
    //cerr << "got " << val << nl;
    dp[i] = val * inv3;
  }

  while(q--) {
    int x;
    cin >> x;
    cout << dp[x] << nl;
  }

  return 0;
}