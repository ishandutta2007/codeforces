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
#line 2 "sol.cpp"
#include <bits/stdc++.h>

using ModT = mod::ModT<1'000'000'007>;

const int N = 200'000;

int n, l[N], r[N];
ModT prob[N], same[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", l + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", r + i);
    prob[i] = ModT(r[i] - l[i] + 1).inverse();
  }
  // X - number of same
  // (n - X)^2 = n^2 - 2 * n * X + X^2
  // X^2 = 2 * binom(X, 2) + X
  ModT exp_x{0};
  for (int i = 0; i + 1 < n; ++i) {
    same[i] = ModT(std::max(
                  std::min(r[i], r[i + 1]) - std::max(l[i], l[i + 1]) + 1, 0)) *
              prob[i] * prob[i + 1];
    exp_x += same[i];
  }
  ModT exp_x2{0};
  for (int i = 0; i + 2 < n; ++i) {
    // (x[i] == x[i + 1]) && (x[i + 1] == x[i + 2])
    // 1 - (x[i] == x[i + 1]) - (x[i + 1] == x[i + 2]) + (x[i] == x[i + 1] &&
    // x[i + 1][i + 2])
    ModT same3 = ModT(std::max(std::min({r[i], r[i + 1], r[i + 2]}) -
                                   std::max({l[i], l[i + 1], l[i + 2]}) + 1,
                               0)) *
                 prob[i] * prob[i + 1] * prob[i + 2];
    exp_x2 += same3;
    // for (int j = i + 2; j + 1 < n; ++j) {
    //   exp_x2 += same[i] * same[j];
    // }
  }
  ModT same_sum{0};
  for (int j = 2; j + 1 < n; ++j) {
    same_sum += same[j - 2];
    exp_x2 += same_sum * same[j];
  }
  ModT result =
      ModT(n) * ModT(n) + (ModT{1} - ModT(2 * n)) * exp_x + ModT{2} * exp_x2;
  printf("%d\n", result.get());
}