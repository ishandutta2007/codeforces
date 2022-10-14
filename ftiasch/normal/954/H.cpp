#line 1 "/home/ftiasch/Documents/shoka/mod_details.h"



#include <cstdint>

namespace details {

template <typename ModT> static constexpr ModT power(ModT a, uint64_t n) {
  ModT result(1);
  n %= ModT::MOD - 1;
  while (n) {
    if (n & 1) {
      result *= a;
    }
    a *= a;
    n >>= 1;
  }
  return result;
}

template <typename ModT> static constexpr ModT inverse(ModT a) {
  return power<ModT>(a, ModT::MOD - 2);
}

template <typename Digit> static constexpr Digit mont_modinv(Digit MOD, int n) {
  Digit result = 1;
  for (int i = 0; i < n; ++i) {
    result *= 2 - MOD * result;
  }
  return -result;
}

} // namespace details


#line 2 "/home/ftiasch/Documents/shoka/mod.h"

#line 4 "/home/ftiasch/Documents/shoka/mod.h"
#include <iostream>
#include <limits>

#define DECLARE_NON_CONST_MODT(name)                                           \
  using name = mod::ModT<0>;                                                   \
  uint32_t name::MOD

namespace mod {

using u32 = uint32_t;
using u64 = uint64_t;

template <u32 MOD_> struct ModT {
  static const u32 MOD = MOD_;

  static_assert(MOD <= (std::numeric_limits<u32>::max() >> 1));

  explicit constexpr ModT(u32 x_ = 0) : x(x_) {}

  constexpr u32 get() const { return x; }

  constexpr ModT &operator+=(const ModT &other) {
    x += other.x;
    if (x >= MOD) {
      x -= MOD;
    }
    return *this;
  }

  constexpr ModT operator+(const ModT &other) const {
    ModT copy = *this;
    return copy += other;
  }

  constexpr ModT &operator-=(const ModT &other) {
    x += MOD - other.x;
    if (x >= MOD) {
      x -= MOD;
    }
    return *this;
  }

  constexpr ModT operator-(const ModT &other) const {
    ModT copy = *this;
    return copy -= other;
  }

  constexpr ModT operator*=(const ModT &other) {
    x = static_cast<u64>(x) * static_cast<u64>(other.x) % MOD;
    return *this;
  }

  constexpr ModT operator*(const ModT &other) const {
    ModT copy = *this;
    return copy *= other;
  }

  constexpr ModT power(u64 n) const { return details::power<ModT>(*this, n); }

  constexpr ModT inverse() const { return details::inverse<ModT>(*this); }

  u32 x;
};

template <> struct ModT<0> {
  static u32 MOD;

  explicit ModT(u32 x_ = 0) : x(x_) {}

  u32 get() const { return x; }

  ModT &operator+=(const ModT &other) {
    x += other.x;
    if (x >= MOD) {
      x -= MOD;
    }
    return *this;
  }

  ModT operator+(const ModT &other) const {
    ModT copy = *this;
    return copy += other;
  }

  ModT &operator-=(const ModT &other) {
    x += MOD - other.x;
    if (x >= MOD) {
      x -= MOD;
    }
    return *this;
  }

  ModT operator-(const ModT &other) const {
    ModT copy = *this;
    return copy -= other;
  }

  ModT operator*=(const ModT &other) {
    x = static_cast<u64>(x) * static_cast<u64>(other.x) % MOD;
    return *this;
  }

  ModT operator*(const ModT &other) const {
    ModT copy = *this;
    return copy *= other;
  }

  ModT<0> power(u64 n) const {
    ModT a = *this;
    ModT result(1);
    n %= MOD - 1;
    while (n) {
      if (n & 1) {
        result *= a;
      }
      a *= a;
      n >>= 1;
    }
    return result;
  }

  ModT<0> inverse() const { return power(MOD - 2); }

  u32 x;
};

} // namespace mod

template <mod::u32 MOD>
std::ostream &operator<<(std::ostream &out, const mod::ModT<MOD>& mod) {
  return out << mod.x;
}
#line 2 "sol.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<1'000'000'007>;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<ModT> a(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int _a;
    scanf("%d", &_a);
    a[i] = ModT(_a);
  }
  std::vector<ModT> p(n);
  p[0] = ModT{1};
  for (int i = 0; i < n - 1; ++i) {
    p[i + 1] = p[i] * ModT(a[i]);
  }
  std::vector<ModT> f(n), f2((n << 1) - 1), result((n << 1) - 1);
  f[0] = f2[0] = ModT{1};
  for (int i = n - 2, d = 1; i >= 0; --i, ++d) {
    // f' = 1 + a[i] * z * f
    // f'^2 = 1 + 2 * a[i] * z * f + a[i]^2 * z^2 * f^2
    ModT binom_a_2 = p[i] * (a[i] * (a[i] - ModT(1)) * ModT{2}.inverse());
    ModT a2 = a[i] * a[i];
    ModT two_a = a[i] + a[i];
    for (int j = d << 1; j >= 2; --j) {
      result[j] += binom_a_2 * f2[j - 2];
      f2[j] = a2 * f2[j - 2];
    }
    f2[0] = ModT{1};
    f2[1] = ModT{0};
    for (int j = d; j >= 1; --j) {
      f2[j] += two_a * f[j - 1];
      f[j] = a[i] * f[j - 1];
      result[j] += p[i] * f[j];
    }
    f[0] = ModT{1};
  }
  for (int i = 1; i <= (n - 1) << 1; ++i) {
    printf("%d%c", result[i].get(), " \n"[i == ((n - 1) << 1)]);
  }
}