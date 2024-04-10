#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/math/linear_sieve.h"

template <class Func, typename = void>
struct linear_sieve_base {
  linear_sieve_base(int) {}
};

template <class Func>
struct linear_sieve_base<Func, enable_if_t<!is_same_v<Func, void>>> {
  using T = typename Func::T;
  vector<T> f;
  vector<int> cnt;
  linear_sieve_base(int n): f(n), cnt(n) {}
  T operator [] (int i) const { return f[i]; }
};

template <class Func = void, bool store_powers = false>
struct linear_sieve : linear_sieve_base<Func> {
  using base = linear_sieve_base<Func>;
  static constexpr bool has_function = !is_same_v<Func, void>;
  using prime_t = conditional_t<store_powers, vector<int>, int>;
  vector<bool> composite;
  vector<prime_t> prime;
  linear_sieve(int n): linear_sieve_base<Func>(n), composite(n) {
    prime.reserve(n);
    if constexpr (has_function) base::f[1] = Func::one();
    for (int i = 2; i < n; i++) {
      if (!composite[i]) {
        if constexpr (store_powers) prime.emplace_back(1, i);
        else prime.push_back(i);
        if constexpr (has_function) {
          base::f[i] = Func::prime(i);
          base::cnt[i] = 1;
        }
      }
      if constexpr (store_powers) {
        for (auto& p : prime) {
          int ip = i * p.front();
          if (ip >= n) break;
          composite[ip] = true;
          if (i % p.front() == 0) {
            if constexpr (has_function) base::cnt[ip] = base::cnt[i] + 1;
            if (i == p.back()) {
              p.push_back(ip);
              if constexpr (has_function) {
                base::f[ip] = Func::prime_power(base::f[i], p.front(), base::cnt[ip]);
              }
            } else {
              if constexpr (has_function) {
                base::f[ip] = Func::coprime(
                  base::f[i / p[base::cnt[i] - 1]], base::f[p[base::cnt[i]]]);
              }
            }
            break;
          } else if constexpr (has_function) {
            base::cnt[ip] = 1;
            base::f[ip] = Func::coprime(base::f[i], base::f[p.front()]);
          }
        }
      } else {
        for (int p : prime) {
          int ip = i * p;
          if (ip >= n) break;
          composite[ip] = true;
          if constexpr (has_function) {
            if (i % p == 0) {
              base::cnt[ip] = base::cnt[i] + 1;
              base::f[ip] = Func::noncoprime(base::f[i], p, base::cnt[ip]);
              break;
            } else {
              base::cnt[ip] = 1;
              base::f[ip] = Func::coprime(base::f[i], base::f[p]);
            }
          }
        }
      }
    }
  }
};

namespace multiplicative_functions {
  struct totient {
    using T = int;
    static constexpr bool store_powers = false;
    static T one() { return 1; }
    static T coprime(T fv, T fp) { return fv * fp; }
    static T prime(int p) { return p - 1; }
    static T noncoprime(int fp, int p, int) { return fp * p; }
  };

  struct mobius {
    using T = int;
    static constexpr bool store_powers = false;
    static T one() { return 1; }
    static T coprime(T fv, T fp) { return fv * fp; }
    static T prime(int) { return -1; }
    static T noncoprime(int, int, int) { return 0; }
  };

  struct divisor_num {
    using T = int;
    static constexpr bool store_powers = false;
    static T one() { return 1; }
    static T coprime(T fv, T fp) { return fv * fp; }
    static T prime(int) { return 2; }
    static T noncoprime(int fp, int, int k) { return fp / k * (k + 1); }
  };

  template <int power = 1, typename sum_t = int>
  struct divisor {
    using T = sum_t;
    static constexpr bool store_powers = true;
    static T one() { return 1; }
    static T coprime(T fv, T fp) { return fv * fp; }
    static T prime(int p) { return 1 + (T)powl(p, power); }
    static T prime_power(int fp, int p, int k) { return fp + (T)powl(p, k * power); }
  };
}
// END #include "../../../lca/math/linear_sieve.h"

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

int add(int a, int b) {
  return a + b < MOD ? a + b : a + b - MOD;
}

int modpow(ll n, int e) {
  ll r = 1;
  for(;e;e/=2, n = n*n % MOD) {
    if(e&1) r = r*n % MOD;
  }
  return r;
}

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

  int n;
  cin >> n;
  linear_sieve<multiplicative_functions::divisor_num> div(n+1);

  vector<int> dp(n+1), sum(n+1);
  dp[0] = 1;
  sum[0] = 1;
  for(int i=1; i<=n; i++) {
    dp[i] = add(sum[i-1], div[i] - 1);
    sum[i] = add(dp[i], sum[i-1]);
  }
  cout << dp[n] << nl;

  return 0;
}