//  Copyright 2022 Nikita Golikov

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
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
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
  Modular<T> power(const U& b) const {
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
 
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using mint = Modular<VarMod>;
void setMod(ModType p) {
  VarMod::value = p;
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct chash {
  static auto const C = (ull) 7e18 + 23;
  static_assert(C % 2);

  ull const RANDOM = chrono::steady_clock::now().time_since_epoch().count();
  ull operator()(ull x) const {
    return __builtin_bswap64((x ^ RANDOM) * C);
  }

  template <class A, class B>
  ull operator()(pair<A, B> const& p) const {
    return (*this)(p.first) * 31 + (*this)(p.second);
  }

  ull operator()(mint x) const {
    return (*this)(int(x));
  }
};

template <class T> using hash_set = gp_hash_table<T, null_type, chash>;
template <class K, class V> using hash_map = gp_hash_table<K, V, chash>;

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, mod;
  cin >> n >> mod;
  setMod(mod);

  mint base, rem;
  cin >> base >> rem;
  vector<mint> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<mint> ipw(n + 1);
  ipw[0] = 1;
  mint ibase = base.inv();
  for (int i = 1; i <= n; ++i) {
    ipw[i] = ipw[i - 1] * ibase;
  }
  vector<ll> out(n), in(n);

  vector<int> sz(n);
  vector<int> level(n, -1);
  auto getSize = [&](auto&& self, int v, int p = -1) -> void {
    sz[v] = 1;
    for (int u : graph[v]) {
      if (u != p && level[u] < 0) {
        self(self, u, v);
        sz[v] += sz[u];
      }
    }
  };
  auto findCentroid = [&](int v) {
    int s = sz[v];
    int p = -1;
    while (true) {
      bool found = false;
      for (int u : graph[v]) {
        if (u != p && level[u] < 0 && 2 * sz[u] > s) {
          p = v;
          v = u;
          found = true;
          break;
        }
      }
      if (!found) {
        return v;
      }
    }
    assert(false);
  };
  hash_map<mint, int> hdown, fordown;
  vector<mint> pw(n);
  vector<mint> up(n), down(n);
  vector<int> dep(n);
  vector<vector<int>> children;
  function<void(int, int)> dfsBuild = [&](int shit, int par) {
    assert(level[shit] < 0);

    getSize(getSize, shit);
    int c = findCentroid(shit);
    auto Work = [&](int x) {
      if (up[x] == rem) {
        ++in[c];
        ++out[x];
      }
      if (x != c && down[x] == rem) {
        ++out[c];
        ++in[x];
      }
    };
    auto dfsSubtree = [&](auto&& self, int v, int p) -> void {
      dep[v] = dep[p] + 1;
      pw[v] = pw[p] * base;
      up[v] = up[p] * base + a[v];
      down[v] = down[p] + a[v] * pw[v];
      Work(v);
      ++hdown[down[v]];
      ++fordown[down[c] + (rem - up[v]) * ipw[dep[v]]];
      children.back().push_back(v);
      for (int u : graph[v]) {
        if (level[u] < 0 && u != p) {
          self(self, u, v);
        }
      }
    };

    level[c] = (par < 0 ? 0 : level[par] + 1);
    hdown.clear(); fordown.clear();
    children.clear();
    up[c] = down[c] = a[c];
    pw[c] = 1;
    dep[c] = 0;
    Work(c);

    for (int u : graph[c]) {
      if (level[u] < 0) {
        children.emplace_back();
        dfsSubtree(dfsSubtree, u, c);
      }      
    }

    int nch = int(children.size());
    for (int i = 0; i < nch; ++i) {
      auto& vec = children[i];
      for (int v : vec) {
        --hdown[down[v]];
        --fordown[down[c] + (rem - up[v]) * ipw[dep[v]]];
      }
      for (int v : vec) {
        out[v] += hdown[down[c] + (rem - up[v]) * ipw[dep[v]]];
        in[v] += fordown[down[v]];
      }
      for (int v : vec) {
        ++hdown[down[v]];
        ++fordown[down[c] + (rem - up[v]) * ipw[dep[v]]];
      }
    }

    for (int u : graph[c]) {
      if (level[u] < 0) {
        dfsBuild(u, c);
      }
    }
  };
  dfsBuild(0, -1);
  ll ans = 0;
  for (int v = 0; v < n; ++v) {
    ans += 2 * out[v] * (n - out[v]);
    ans += 2 * in[v] * (n - in[v]);
    ans += out[v] * (n - in[v]);
    ans += in[v] * (n - out[v]);
  }
  assert(ans % 2 == 0);
  cout << ll(n) * n * n - ans / 2 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}