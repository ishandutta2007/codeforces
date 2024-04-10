#pragma GCC optimize("Ofast", "unroll-loops")
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

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
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);
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
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}
template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
constexpr int md = 31607;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

template<bool inv>
void and_convolution(int n, Mint a[]) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (inv) {
            a[i] -= a[i + n / 2];
        } else {
            a[i] += a[i + n / 2];
        }
    }
    and_convolution<inv>(n / 2, a);
    and_convolution<inv>(n / 2, a + n / 2);
}

const int N = 21;

Mint b[2][2][1 << N];

Mint dp[2][2][1 << N];
Mint ndp[2][2][1 << N];
Mint pr[1 << N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <vector <Mint>> A(n, vector <Mint> (n));
  vector <vector <Mint>> B(n, vector <Mint> (n));

  vector <Mint> prod(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      A[i][j] = (Mint)x / 10000;
      B[i][j] = 1 / (1 - A[i][j]);
      prod[i] *= (1 - A[i][j]);
    }
  }
  
  auto get = [&] (int r) {
    pr[0] = 1;
    for (int mask = 1; mask < (1 << n); ++mask) {
      int x = __builtin_ctz(mask);
      pr[mask] = pr[mask ^ (1 << x)] * A[r][x] * B[r][x];
    } 
    for (int i = 0; i < (1 << n); ++i) {
      pr[i] *= prod[r];
    }
  };

  {
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (int f2 = 0; f2 <= 1; ++f2) {
        for (int i = 0; i < (1 << n); ++i) dp[f1][f2][i] = 0;
      }
    }
    get(0);
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (int f2 = 0; f2 <= 1; ++f2) {
        for (int mask = 0; mask < (1 << n); ++mask) {
          if (f1 == 1 && !((mask >> 0) & 1)) continue;
          if (f2 == 1 && !((mask >> (n - 1)) & 1)) continue;
          dp[f1][f2][mask] = pr[mask];
        }
        dp[f1][f2][(1 << n) - 1] = 0;
      }
    }
  }

  for (int r = 1; r < n; ++r) {
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (int f2 = 0; f2 <= 1; ++f2) {
        and_convolution <false> (1 << n, dp[f1][f2]);
      }
    }
    get(r);
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (int f2 = 0; f2 <= 1; ++f2) {
        for (int mask = 0; mask < (1 << n); ++mask) b[f1][f2][mask] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
          if (f1 == 1 && !((mask >> r) & 1)) continue;
          if (f2 == 1 && !((mask >> (n - r - 1)) & 1)) continue;
          b[f1][f2][mask] = pr[mask];
        }
        b[f1][f2][(1 << n) - 1] = 0;
        and_convolution <false> (1 << n, b[f1][f2]);
      }
    }
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (int f2 = 0; f2 <= 1; ++f2) {
        for (int i = 0; i < (1 << n); ++i) {
          ndp[f1][f2][i] = dp[f1][f2][i] * b[f1][f2][i];
        }
        and_convolution <true> (1 << n, ndp[f1][f2]);
      }
    }
    for (int f1 = 0; f1 <= 1; ++f1) {
      for (int f2 = 0; f2 <= 1; ++f2) {
        swap(dp[f1][f2], ndp[f1][f2]);
      }
    }
  }

  Mint ans = 0;
  for (int f1 = 0; f1 <= 1; ++f1) {
    for (int f2 = 0; f2 <= 1; ++f2) {
      if ((f1 + f2) % 2 == 0) {
        ans += dp[f1][f2][0];
      } else {
        ans -= dp[f1][f2][0];
      }
    }
  }
  cout << 1 - ans << '\n'; 
  //cout << (double)clock() / CLOCKS_PER_SEC << endl;
}