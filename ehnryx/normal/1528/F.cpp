#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/math/number_theoretic_transform.h"

template <long long mod>
long long modpow(long long base, long long exponent) {
  long long res = 1;
  while (exponent != 0) {
    if (exponent & 1) {
      res = res * base % mod;
    }
    base = base * base % mod;
    exponent >>= 1;
  }
  return res;
}

template <long long mod, typename T>
void number_theoretic_transform(vector<T>& a, const T& p2_root) {
  int n = (int)size(a); // n should be a power of 2
  int L = 31 - __builtin_clz(n); // logn
  static vector<T> root(2, 1);
  for (static int k = 2; k < n; k *= 2) {
    root.resize(n, 1);
    if constexpr (is_integral_v<T>) {
      T w = modpow<mod>(p2_root, mod / 2 / k);
      for (int i = k; i < 2 * k; i++) {
        root[i] = (i % 2 ? root[i / 2] * w % mod : root[i / 2]);
      }
    } else {
      T w = p2_root.pow(mod / 2 / k);
      for (int i = k; i < 2 * k; i++) {
        root[i] = (i % 2 ? root[i / 2] * w : root[i / 2]);
      }
    }
  }
  vector<int> rev(n);
  for (int i = 0; i < n; i++) {
    rev[i] = (rev[i >> 1] | (i & 1) << L) >> 1;
    if (i < rev[i]) {
      swap(a[i], a[rev[i]]);
    }
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        if constexpr (is_integral_v<T>) {
          T z = root[j + k] * a[i + j + k] % mod;
          a[i + j + k] = a[i + j] - z < 0 ? a[i + j] - z + mod : a[i + j] - z;
          a[i + j] = a[i + j] + z < mod ? a[i + j] + z : a[i + j] + z - mod;
        } else {
          T z = root[j + k] * a[i + j + k];
          a[i + j + k] = a[i + j] - z;
          a[i + j] += z;
        }
      }
    }
  }
}

template <long long mod, typename T>
vector<T> convolve(vector<T> a, vector<T> b, size_t cut = -1) {
  static_assert(is_same_v<T, long long> || !is_integral_v<T>);
  if (empty(a) || empty(b)) return vector<T>();
  vector<T> res(size(a) + size(b) - 1, 0);
  int L = (size(res) == 1 ? 0 : 32 - __builtin_clz((int)size(res) - 1));
  int n = 1 << L;
  T inv, p2_root;
  if constexpr (is_integral_v<T>) {
    inv = modpow<mod>(n, mod - 2);
    p2_root = T(2);
    while (modpow<mod>(p2_root, mod / 2) == 1) {
      p2_root += 1;
    }
  } else {
    inv = T(n).inverse();
    p2_root = T(2);
    while (p2_root.pow(mod / 2) == 1) {
      p2_root += 1;
    }
  }
  a.resize(n);
  b.resize(n);
  number_theoretic_transform<mod>(a, p2_root);
  number_theoretic_transform<mod>(b, p2_root);
  for (int i = 0; i < n; i++) {
    if constexpr (is_integral_v<T>) {
      a[i] = a[i] * b[i] % mod * inv % mod;
    } else {
      a[i] *= b[i];
      a[i] *= inv;
    }
  }
  reverse(begin(a) + 1, end(a));
  number_theoretic_transform<mod>(a, p2_root);
  if (a.size() > cut) {
    a.resize(cut);
  }
  return a;
}

// END #include "../../../lca/math/number_theoretic_transform.h"
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
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using Int = mod_int<MOD>;

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

  int n, k;
  cin >> n >> k;

  vector<Int> a(k+1), b(k+1);
  vector<Int> f(k+1), invf(k+1);
  f[0] = 1;
  for(int i=0; i<=k; i++) {
    invf[i] = f[i].inverse();
    int s = i % 2 ? -1 : 1;
    a[i] = invf[i] * s;
    b[i] = Int(i).pow(k) * invf[i];
    if(i+1 <= k) {
      f[i+1] = f[i] * (i + 1);
    }
  }
  vector<Int> stirling = convolve<MOD>(a, b);

  Int ans = 0;
  Int prod = 1;
  for(int i=1; i<=k; i++) {
    prod = prod * (n - i + 1);
    ans += stirling[i] * prod * Int(n+1).pow(n-i);
  }
  cout << ans << nl;

  return 0;
}