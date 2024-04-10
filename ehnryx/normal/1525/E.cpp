#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/number/mod_int.h"

// START #include "extended_gcd.h"

template <typename T>
tuple<T, T, T> extended_gcd(T a, T b) {
  if (b == 0) return tuple(a, 1, 0);
  auto [g, y, x] = extended_gcd(b, a % b);
  return tuple(g, x, y - x * (a / b));
}

// END #include "extended_gcd.h"

template <long long mod_value, int num_bits = 32, bool is_prime = true>
struct mod_int {
  static_assert(num_bits == 32 || num_bits == 64);
  using mod_t = conditional_t<num_bits == 32, int, long long>;
  using larger_t = conditional_t<num_bits == 32, long long, __int128>;
  static const mod_t mod = mod_value;
  mod_t v;
  mod_int() = default;
  mod_int(const mod_t& c): v(c) {
    if(v < 0) v = v % mod + mod;
    else if(v >= mod) v = v % mod;
  }
  friend istream& operator >> (istream& is, mod_int& num) {
    is >> num.v;
    if(num.v < 0) num.v = num.v % mod + mod;
    else if(num.v >= mod) num.v = num.v % mod;
    return is;
  }
  friend ostream& operator << (ostream& os, const mod_int& num) { return os << num.v; }
  bool operator == (const mod_int& o) const { return v == o.v; }
  mod_int operator + (const mod_int& o) const { return mod_int(*this) += o; }
  mod_int operator - (const mod_int& o) const { return mod_int(*this) -= o; }
  mod_int operator * (const mod_int& o) const { return mod_int(*this) *= o; }
  mod_int operator / (const mod_int& o) const { return mod_int(*this) /= o; }
  mod_int operator - () const { return mod_int(v ? mod - v : v); }
  mod_int& operator += (const mod_int& o) {
    v += o.v;
    if(v >= mod) v -= mod;
    return *this;
  }
  mod_int& operator -= (const mod_int& o) {
    v -= o.v;
    if(v < 0) v += mod;
    return *this;
  }
  mod_int& operator *= (const mod_int& o) {
    v = (mod_t)((larger_t)v * o.v % mod);
    return *this;
  }
  mod_int& operator /= (const mod_int& o) {
    return operator *= (o.inverse());
  }
  template <typename T, typename = enable_if_t<is_integral_v<T>>>
  mod_int pow(T exponent) const {
    if constexpr (is_prime) {
      if (exponent < 0) {
        assert(v != 0);
        exponent = mod - 1 + exponent % (mod - 1);
      }
      mod_int res(1), base(*this);
      for ( ; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    } else {
      mod_int res(1), base(exponent < 0 ? inverse() : *this);
      for ( ; exponent != 0; exponent /= 2) {
        if (exponent % 2) res *= base;
        base *= base;
      }
      return res;
    }
  }
  mod_int inverse() const {
    auto [g, x, y] = extended_gcd(mod, v);
    assert(g == 1);
    mod_int res(*this);
    res.v = (y < 0 ? y + mod : y);
    return res;
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

using Int = mod_int<998244353>;
//using Int = long double;

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

  int n, m;
  cin >> n >> m;
  vector dist(m, vector<int>(n));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> dist[j][i];
    }
  }

  Int ans(0);
  for(int i=0; i<m; i++) {
    sort(begin(dist[i]), end(dist[i]), greater<>());
    Int alive(1);
    for(int j=0, s=0; j<n; j++) {
      while(s < n && dist[i][s] > n-j) s++;
      Int cur = Int(n-s) / (n-j) * alive;
      ans += cur;
      alive -= cur;
    }
  }
  cout << ans << nl;

  return 0;
}