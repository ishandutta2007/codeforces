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
 
// using ModType = int;
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using mint = Modular<VarMod>;
// void setMod(ModType p) {
//   VarMod::value = p;
// }
 
// constexpr auto MOD = (int) 998244353;
constexpr auto MOD = (int) (1e9 + 7);
using mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

template <typename T>
vector<T> berlekamp(vector<T> const& a) {
  vector<T> b{1};
  vector<T> c{1};
  T prev_d = 1;
  int len = 0;
  int deg = 1;
  for (int n = 1; n <= (int) a.size(); ++n, ++deg) {
    T d = 0;
    for (int i = 0; i <= len; ++i) {
      d += a[n - i - 1] * c[i];
    }
    if (!d) continue;
    auto new_c = c;
    auto coef = d / prev_d;
    new_c.resize(max(c.size(), b.size() + deg));
    for (int i = 0; i < (int) b.size(); ++i) {
      new_c[i + deg] -= coef * b[i];
    }
    if (n - len <= len) {
      c = move(new_c);
      continue;
    }
    len = n - len;
    b = move(c);
    c = move(new_c);
    prev_d = d;
    deg = 0;
  }
  vector<T> ans(c.begin() + 1, c.begin() + 1 + len);
  for (auto& x : ans) {
    x = -x;
  }
  return ans;
}

bool good(string s, char ch) {
  if (s.empty()) {
    return true;
  }
  char lst = s.back();
  if (ch == lst) {
    return false;
  }
  string s2 = string(1, lst) + ch;
  if (s2 == "WY" || s2 == "YW" || s2 == "RB" || s2 == "BR") {
    return false;
  }
  if (s.size() == 1) {
    return true;
  }
  string s3 = string(1, s.end()[-2]) + lst + ch;
  return s3 != "BWR" && s3 != "RWB";
}

string mkend(string s, char ch) {
  s += ch;
  int len = min(2, int(s.size()));
  return s.substr(int(s.size()) - len, len);
}

//  init satisfies c
template <typename T>
T nth_linear(vector<T> const& init, vector<T> const& c, ll n) {
  int k = (int) c.size();
  int m = (int) init.size();
  if (!k || !m) return 0;
  vector<T> p(k), q(k + 1);
  auto multiply = [](auto const& a, auto const& b) {
    int need = max(0, (int) (a.size() + b.size()) - 1);
    vector<T> ans(need);
    for (int i = 0; i < (int) a.size(); ++i) {
      for (int j = 0; j < (int) b.size(); ++j) {
        ans[i + j] += a[i] * b[j];
      }
    }
    return ans;
  };
  auto prod = multiply(init, c);
  p[0] = init[0];
  for (int i = 1; i < min(k, m); ++i) {
    p[i] = init[i] - prod[i - 1];
  }
  q[0] = 1;
  for (int i = 0; i < k; ++i) q[i + 1] = -c[i];
  auto select_terms = [](auto const& vec, int par) {
    vector<T> res;
    res.reserve((vec.size() + 1) / 2);
    for (int i = par; i < (int) vec.size(); i += 2) {
        res.push_back(vec[i]);
    }
    return res;
  };
  while (n) {
    auto q_neg = q;
    for (int i = 1; i < (int) q.size(); i += 2) {
        q_neg[i] = -q_neg[i];
    }
    auto new_q = multiply(q, q_neg);
    auto new_p = multiply(p, q_neg);
    p = select_terms(new_p, n % 2);
    q = select_terms(new_q, 0);
    n /= 2;
  }
  return p.empty() ? 0 : p[0];
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string ALL = "BRWY";
  int const N = 100;
  vector<map<string, mint>> dp(N);
  dp[0][""] = 1;
  for (int i = 1; i < N; ++i) {
    for (auto[end, val] : dp[i - 1]) {
      for (char add : ALL) {
        if (good(end, add)) {
          dp[i][mkend(end, add)] += val;
        }
      }
    }
  }

  vector<mint> vals(N);
  for (int i = 0; i < N; ++i) {
    mint v = 0;
    for (auto it : dp[i]) {
      v += it.second;
    }
    vals[i] = v;
  }

  vector<mint> pali(N);
  for (int i = 1; i < N; i += 2) {
    int len = (i - 1) / 2;
    for (char add : ALL) {
      for (auto[end, val] : dp[len]) {
        if (good(end, add)) {
          pali[i] += val;
        }
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    vals[i] += pali[i];
    vals[i] /= 2;
  }

  for (int i = 1; i < N; ++i) {
    vals[i] += vals[i - 1];
  }

  auto b = berlekamp(vals);

  auto solve = [&](int x) -> mint {
    return nth_linear(vals, b, x);
  };

  int L, R;
  cin >> L >> R;
  cout << solve(R) - solve(L - 1) << '\n'; 

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}