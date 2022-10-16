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

int const MOD = 998244353;
using mint = modular<MOD>;
mint const HALF = (MOD + 1) / 2;

namespace ntt {
  int const DEPTH = 19;
  mint roots[DEPTH + 1][1 << DEPTH];
  int rev[DEPTH + 1][1 << DEPTH];
  mint gen;

  void init() {
    for (gen = 2; ; ++gen) {
      if (pw(gen, (MOD - 1) / 2) == MOD - 1) {
        break;
      }
    }
    for (int dep = 1; dep <= DEPTH; ++dep) {
      roots[dep][0] = 1;
      auto const root = pw(gen, (MOD - 1) >> dep);
      int const n = 1 << dep;
      for (int i = 1; i < n; ++i) {
        roots[dep][i] = roots[dep][i - 1] * root;
        rev[dep][i] = (i & 1) << (dep - 1) | rev[dep - 1][i >> 1];
      }
    }
  }

  void fft(mint* a, int const n) {
    int const lg = __builtin_ctz(n);
    for (int i = 0; i < n; ++i) {
      int j = rev[lg][i];
      if (i < j) {
        swap(a[i], a[j]);
      }
    }
    for (int len = 2, half = 1, bits = 1; len <= n; len <<= 1, half <<= 1,
        ++bits) {
      for (int st = 0; st < n; st += len) {
        for (int i = 0; i < half; ++i) {
          int const L = st + i;
          int const R = L + half;
          auto const v = a[R] * roots[bits][i];
          a[R] = a[L] - v;
          a[L] += v;
        }
      }
    }
  }

  vector<mint> multiply(vector<mint> a, vector<mint> b) {
    int sz = 1;
    while (sz < (int) a.size() + (int) b.size() - 1) {
      sz *= 2;
    }
    a.resize(sz);
    b.resize(sz);
    bool const eq = a == b;
    fft(a.data(), sz);
    if (eq) {
      b = a;
    } else {
      fft(b.data(), sz);
    }
    for (int i = 0; i < sz; ++i) {
      a[i] *= b[i];
    }
    fft(a.data(), sz);
    reverse(a.begin() + 1, a.end());
    auto inv_sz = inv((mint) sz);
    for (auto& x : a) {
      x *= inv_sz;
    }
    return a;
  }
}

struct poly : vector<mint> {
  using vector<mint>::vector;

  poly(vector<mint> const& vec) : vector<mint>(vec) {}

  poly& operator*=(mint c) {
    for (auto& x : *this) {
      x *= c;
    }
    return *this;
  }

  poly operator*(mint c) const {
    auto copy = *this;
    copy *= c;
    return copy;
  }

  poly operator-() const {
    return *this * (-1);
  }

  mint get(int at) const {
    if (at < (int) size()) {
      return (*this)[at];
    }
    return 0;
  }

  friend poly operator+(poly const& a, poly const& b) {
    poly ans(max(a.size(), b.size()));
    for (int i = 0; i < (int) ans.size(); ++i) {
      ans[i] = a.get(i) + b.get(i);
    }
    return ans;
  }

  friend poly operator-(poly const& a, poly const& b) {
    poly ans(max(a.size(), b.size()));
    for (int i = 0; i < (int) ans.size(); ++i) {
      ans[i] = a.get(i) - b.get(i);
    }
    return ans;
  }

  friend poly operator*(poly const& a, poly const& b) {
    return poly(ntt::multiply(a, b));
  }

  static poly newton(mint init,
      int m, function<poly(poly const&, int)> const& nxt) {
    poly cur{init};
    for (int sz = 1; sz < m; sz *= 2) {
      cur = nxt(cur, 2 * sz);
      cur.resize(min({(int) cur.size(), m, 2 * sz}));
    }
    return cur;
  }

  friend poly inv(poly const& a, int m) {
    return newton(inv(a[0]), m, [&](poly const& p, int sz) {
      static poly const TWO{2};
      int sz_a = min(sz, (int) a.size());
      poly fa(a.begin(), a.begin() + sz_a);
      auto fp = p;
      int poly_sz = 1;
      while (poly_sz < (int) fa.size() + (int) fp.size() - 1 + (int) fp.size() - 1) {
        poly_sz <<= 1;
      }
      fa.resize(poly_sz);
      fp.resize(poly_sz);
      ntt::fft(fa.data(), poly_sz);
      ntt::fft(fp.data(), poly_sz);
      for (int i = 0; i < poly_sz; ++i) {
        fa[i] = fp[i] * (2 - fa[i] * fp[i]);
      }
      ntt::fft(fa.data(), poly_sz);
      reverse(fa.begin() + 1, fa.end());
      auto const inv_sz = inv((mint) poly_sz);
      for (auto& x : fa) {
        x *= inv_sz;
      }
      return fa;
    });
  }

  friend poly sqrt(poly const& a, int m) {
    return newton(1, m, [&](poly const& p, int sz) {
      return (p + a * inv(p, sz)) * HALF;
    });
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ntt::init();
  poly const ONE{1};
  int n, m;
  cin >> n >> m;
  ++m;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  poly base(*max_element(a.begin(), a.end()) + 1);
  for (int w : a) ++base[w];
  auto sq = sqrt(base * (-4) + ONE, m) + ONE;
  auto res = inv(sq, m) * 2;
  for (int i = 1; i < m; ++i) {
    cout << res.get(i) << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}