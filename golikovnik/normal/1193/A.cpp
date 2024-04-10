//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

#ifndef MODMUL64_H
#define MODMUL64_H
ll modmul64(ll x, ll y, ll p) {
  ull q = (long double) x * y / p;
  ll res = ll(ull(x) * y - q * p);
  if (res >= p) res -= p;
  if (res < 0) res += p;
  return res;
}
#endif

//  https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
  explicit operator bool() const { return bool(value); }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = modmul64(value, rhs.value, mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

  Modular inv() const {
    return 1 / *this;
  }

  template<typename U>
  Modular<T> power(const U& b) {
    if (b < 0) {
      return inv().power(-b);
    }
    Modular<T> x = *this, res = 1;
    U p = b;
    while (p > 0) {
      if (p & 1) res *= x;
      x *= x;
      p >>= 1;
    }
    return res;
  }
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
// using ModType = int;
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using mint = Modular<VarMod>;
// void setMod(ModType p) {
//   VarMod::value = p;
// }
 
constexpr auto MOD = (int) 998244353;
// constexpr auto MOD = (int) (1e9 + 7);
using mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

using combine_t = function<pair<mint, mint>(int, mint, mint)>;
void transform(vector<mint>& a, combine_t const& f) {
  int n = int(a.size());
  for (int k = 1, bit = 0; k < n; k *= 2, bit++) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        tie(a[i + j], a[i + j + k]) = f(bit, a[i + j], a[i + j + k]);
      }
    }
  }
}

vector<mint> multiply(vector<mint> a, vector<mint> b,
                      combine_t const& forward, combine_t const& inverse) {
  int n = 1;
  while (n < int(a.size()) && n < int(b.size())) {
    n *= 2;
  }
  a.resize(n);
  b.resize(n);
  transform(a, forward);
  transform(b, forward);
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  transform(a, inverse);
  return a;
}

static combine_t const XOR_DIRECT = [](int, mint x, mint y) {
  return make_pair(x + y, x - y);
};
static combine_t const XOR_INVERSE = [](int, mint x, mint y) {
  static mint const INV2 = mint(2).inv();
  return make_pair((x + y) * INV2, (x - y) * INV2);
};
static combine_t const OR_DIRECT = [](int, mint x, mint y) {
  return make_pair(x, x + y);
};
static combine_t const OR_INVERSE = [](int, mint x, mint y) {
  return make_pair(x, y - x);
};
static combine_t const AND_DIRECT = [](int, mint x, mint y) {
  return make_pair(x + y, y);
};
static combine_t const AND_INVERSE = [](int, mint x, mint y) {
  return make_pair(x - y, y);
};

vector<mint> multiply_xor(vector<mint> const& a, vector<mint> const& b) {
  return multiply(a, b, XOR_DIRECT, XOR_INVERSE);
}

vector<mint> multiply_or(vector<mint> const& a, vector<mint> const& b) {
  return multiply(a, b, OR_DIRECT, OR_INVERSE);
}

vector<mint> multiply_and(vector<mint> const& a, vector<mint> const& b) {
  return multiply(a, b, AND_DIRECT, AND_INVERSE);
}

//  f(A) = h(A) + \sum_{B \ssub A} f(B)g(A \ B)
template <class T>
vector<T> submask_recurrence(vector<T> h, vector<T> g) {
  int n = int(h.size());
  assert(n == int(g.size()));
  assert(n > 0 && (n & (n - 1)) == 0);
  int bits = __lg(n);
  vector pg(bits + 1, vector<T>(n));
  vector pf(bits + 1, vector<T>(n));
  for (int i = 0; i < n; ++i) {
    int ppc = __builtin_popcount(i);
    pg[ppc][i] = g[i];
    pf[ppc][i] = h[i];
  }
  for (int sz = 0; sz <= bits; ++sz) {
    for (int k = 1; k < n; k *= 2) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; ++j) {
          pg[sz][i + j + k] += pg[sz][i + j];
          pf[sz][i + j + k] += pf[sz][i + j];
        }
      }
    }
  }
  vector<ll> pgv(bits + 1), pfv(bits + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= bits; ++j) {
      pgv[j] = ll(pg[j][i]);
    }
    for (int j = 0; j <= bits; ++j) {
      auto cur = ll(pf[j][i]);
      for (int k = 1; k <= j; ++k) {
        cur += pfv[j - k] * pgv[k];
        if (k % 7 == 0) {
          cur %= T::mod();
        }
      }
      pf[j][i] = cur;
      pfv[j] = ll(pf[j][i]);
    }
  }
  for (int sz = 0; sz <= bits; ++sz) {
    for (int k = 1; k < n; k *= 2) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; ++j) {
          pf[sz][i + j + k] -= pf[sz][i + j];
        }
      }
    }
  }
  vector<T> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = pf[__builtin_popcount(i)][i];
  }
  return ans;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u] |= 1 << v;
    graph[v] |= 1 << u;
  }
  vector<mint> f(1 << n);
  vector<int> ppc(1 << n);
  f[0] = 1;
  for (int i = 1; i < (1 << n); ++i) {
    int bit = __builtin_ctz(i);
    f[i] = f[i ^ (1 << bit)] && ((graph[bit] & i) == 0);
    ppc[i] = 1 + ppc[i ^ (1 << bit)];
    if (ppc[i] % 2 == 0) {
      f[i] = -f[i];
    }
  }
  vector pg(n + 1, vector<mint>(1 << n));
  vector pf(n + 1, vector<mint>(1 << n));
  for (int i = 0; i < (1 << n); ++i) {
    pg[ppc[i]][i] = f[i];
  }
  fill(pf[0].begin(), pf[0].end(), 1);
  for (int sz = 0; sz <= n; ++sz) {
    for (int k = 1; k < (1 << n); k *= 2) {
      for (int i = 0; i < (1 << n); i += 2 * k) {
        for (int j = 0; j < k; ++j) {
          pg[sz][i + j + k] += pg[sz][i + j];
        }
      }
    }
  }
  vector<ll> pgv(n + 1), pfv(n + 1);
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j <= n; ++j) {
      pgv[j] = ll(pg[j][i]);
    }
    for (int j = 0; j <= n; ++j) {
      auto cur = ll(pf[j][i]);
      for (int k = 1; k <= j; ++k) {
        cur += pfv[j - k] * pgv[k];
        if (k % 7 == 0) {
          cur %= MOD;
        }
      }
      pf[j][i] = cur;
      pfv[j] = ll(pf[j][i]);
    }
  }
  for (int k = 1; k < (1 << n); k *= 2) {
    for (int i = 0; i < (1 << n); i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        pf[n][i + j + k] -= pf[n][i + j];
      }
    }
  }
  cout << pf[n].back() * m / 2 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}