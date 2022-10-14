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
#line 1 "/home/ftiasch/Documents/shoka/polynomial_interpolation.h"
#include <vector>

template <typename ModT> struct PolynomialInterpolation {
  PolynomialInterpolation(int maxd) : inverse(maxd) {
    inverse[1] = ModT{1};
    for (int i = 2; i < maxd; ++i) {
      inverse[i] = ModT(ModT::MOD - ModT::MOD / i) * inverse[ModT::MOD % i];
    }
  }

  ModT operator()(std::vector<ModT> values, ModT n) const {
    int d = static_cast<int>(values.size()) - 1;
    // d < maxd
    {
      ModT b{1};
      for (int i = 1; i <= d; ++i) {
        b = b * (n - ModT(i - 1)) * inverse[i];
        values[i] *= b;
      }
    }
    ModT result = values[d];
    {
      ModT b{1};
      for (int i = d - 1; i >= 0; --i) {
        b = (ModT{0} - b) * inverse[d - i] * (n - ModT(i + 1));
        result += values[i] * b;
      }
    }
    return result;
  }

  std::vector<ModT> inverse;
};
#line 3 "sol.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<1'000'003>;

const int D = 11;

int main() {
  std::vector<ModT> values(D);
  for (int x = 0; x < D; ++x) {
    printf("? %d\n", x);
    fflush(stdout);
    int fx;
    scanf("%d", &fx);
    if (fx == -1) {
      return 0;
    }
    values[x] = ModT(fx);
  }
  PolynomialInterpolation<ModT> inter(D);
  int n = 0;
  while (n < ModT::MOD && inter(values, ModT(n)).get() != 0) {
    n++;
  }
  printf("! %d\n", n < ModT::MOD ? n : -1);
  fflush(stdout);
}