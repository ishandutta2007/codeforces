//  Copyright 2020 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

template <typename A, typename B, typename Cmp>
bool set_min(A &x, B const &y, Cmp &&cmp) {
  if (cmp(y, x)) {
    x = y;
    return true;
  }
  return false;
}

template <typename A, typename B>
bool set_min(A &x, B const &y) {
  return set_min(x, y, less<typename common_type<A, B>::type>{});
}

template <typename A, typename B>
bool set_max(A &x, B const &y) {
  return set_min(x, y, greater<typename common_type<A, B>::type>{});
}

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

template <typename K, typename V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag,
                         tree_order_statistics_node_update>;

//  https://codeforces.com/blog/entry/62393
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t
        FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return static_cast<size_t>(splitmix64(x + FIXED_RANDOM));
  }
};

#ifdef __cpp_deduction_guides
template <typename F>
struct rec_fun {
  F fun;

  rec_fun(F &&fun_) : fun(std::forward<F>(fun_)) {}

  template <typename... Args>
  decltype(auto) operator()(Args &&... args) const {
    return fun(*this, std::forward<Args>(args)...);
  }
};
#endif

#ifdef __cpp_inline_variables
template <typename T>
inline constexpr auto type_min = numeric_limits<T>::min();

template <typename T>
inline constexpr auto type_max = numeric_limits<T>::max();
#endif

//  fast alloc
#if 0
int const MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void* operator new(size_t n) {
  mpos += n;
  return (void*)(mem + mpos - n);
}
void operator delete (void*) noexcept {}
#endif

//  pragmas
#if 0
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
#endif

template <int MOD>
struct modular {
  int val{};

  modular() = default;
  modular(int x) : val(x < 0 ? ((x % MOD) + MOD) % MOD : x) {}
  modular(i64 x) : val(((x % MOD) + MOD) % MOD) {}

  int to_int() const {
    return val;
  }
  modular& operator+=(modular other) {
    val += other.val;
    if (val >= MOD) {
      val -= MOD;
    }
    return *this;
  }
  friend modular operator+(modular x, modular y) {
    return x += y;
  }
  modular& operator-=(modular other) {
    val -= other.val;
    if (val < 0) {
      val += MOD;
    }
    return *this;
  }
  friend modular operator-(modular x, modular y) {
    return x -= y;
  }
  modular& operator++() {
    if (++val == MOD) {
      val = 0;
    }
    return *this;
  }
  modular& operator--() {
    if (--val < 0) {
      val = MOD - 1;
    }
    return *this;
  }
  friend modular operator*(modular x, modular y) {
    return modular{(i64) x.val * y.val};
  }
  modular operator*=(modular other) {
    return *this = *this * other;
  }
  friend bool operator==(modular x, modular y) {
    return x.to_int() == y.to_int();
  }
  friend bool operator!=(modular x, modular y) {
    return x.to_int() != y.to_int();
  }
  friend modular pw(modular x, i64 deg) {
    modular res = 1;
    while (deg) {
      if (deg & 1) {
        res *= x;
      }
      x *= x;
      deg /= 2;
    }
    return res;
  }
  friend modular inv(modular x) {
    return pw(x, MOD - 2);
  }
  friend modular operator/(modular x, modular y) {
    return x * inv(y);
  }
  modular operator/=(modular other) {
    return *this = *this / other;
  }
  modular operator-() const {
    return 0 - *this;
  }
  friend istream& operator>>(istream& in, modular& x) {
    return in >> x.val;
  }
  friend ostream& operator<<(ostream& out, modular x) {
    return out << x.val;
  }
};

int const MOD = (int) 1e9 + 7;
using mint = modular<MOD>;
mint const HALF = (MOD + 1) / 2;

enum op {
  XOR, OR, AND
};

void transform(vector<mint>& a, op operation, bool inv = false) {
  int n = (int) a.size();
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        auto x = a[i + j];
        auto y = a[i + j + k];
        if (operation == XOR) {
          if (inv) {
            a[i + j] = (x + y) * HALF;
            a[i + j + k] = (x - y) * HALF;
          } else {
            a[i + j] = x + y;
            a[i + j + k] = x - y;
          }
        } else if (operation == OR) {
          if (inv) {
            a[i + j + k] -= a[i + j];
          } else {
            a[i + j + k] += a[i + j];
          }
        } else {
          if (inv) {
            a[i + j] -= a[i + j + k];
          } else {
            a[i + j] += a[i + j + k];
          }
        }
      }
    }
  }
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int B = 17;
  int N = 1 << B;
  vector<mint> a(N);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[x];
  }
  vector<mint> fib(N);
  fib[1] = 1;
  for (int i = 2; i < N; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  vector<vector<mint>> sa(B + 1, vector<mint>(N));
  for (int i = 0; i < N; ++i) {
    sa[__builtin_popcount(i)][i] = a[i];
  }
  for (int i = 0; i <= B; ++i) {
    transform(sa[i], OR);
  }
  vector<vector<mint>> s_or(B + 1, vector<mint>(N));
  for (int x = 0; x <= B; ++x) {
    for (int y = 0; x + y <= B; ++y) {
      for (int i = 0; i < N; ++i) {
        s_or[x + y][i] += sa[x][i] * sa[y][i];
      }
    }
  }
  for (int i = 0; i <= B; ++i) {
    transform(s_or[i], OR, true);
  }
  vector<mint> or_conv(N);
  for (int i = 0; i < N; ++i) {
    or_conv[i] = s_or[__builtin_popcount(i)][i];
  }
  auto xor_conv = a;
  transform(xor_conv, XOR);
  for (int i = 0; i < N; ++i) {
    xor_conv[i] *= xor_conv[i];
  }
  transform(xor_conv, XOR, true);
  for (int i = 0; i < N; ++i) {
    a[i] *= fib[i];
    or_conv[i] *= fib[i];
    xor_conv[i] *= fib[i];
  }
  transform(a, AND);
  transform(or_conv, AND);
  transform(xor_conv, AND);
  for (int i = 0; i < N; ++i) {
    a[i] *= or_conv[i] * xor_conv[i];
  }
  transform(a, AND, true);
  mint ans = 0;
  for (int i = 0; i < B; ++i) {
    ans += a[1 << i];
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}