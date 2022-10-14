#include <bits/stdc++.h>

namespace montgomery {

using u64 = uint64_t;
using u32 = uint32_t;

struct u128 {
  static u128 multiply(u64 x, u64 y) {
#ifdef U128_ASM
    u64 high, low;
    __asm__("mulq %3\n\t" : "=d"(high), "=a"(low) : "%a"(x), "rm"(y) : "cc");
    return {high, low};
#else
    uint64_t a = x & UINT32_MAX, b = x >> 32u, c = y & UINT32_MAX, d = y >> 32u,
             ac = a * c, bc = b * c, ad = a * d,
             z = (bc & UINT32_MAX) + (ad & UINT32_MAX) + (ac >> 32u);
    return {b * d + (bc >> 32u) + (ad >> 32u) + (z >> 32u),
            (z & UINT32_MAX) << 32u | (ac & UINT32_MAX)};
#endif
  }

  u64 high, low;
};

template <int RBIT, typename Digit, Digit M, typename Derived>
struct MontgomeryT {
  static const Digit MOD = M;

  static_assert(MOD <= std::numeric_limits<Digit>::max() >> 2,
                "4 * MOD <= MAX");

  explicit constexpr MontgomeryT(Digit x = 0)
      : x(Derived::mont_multiply(x, R2)) {}

  constexpr Digit get() const {
    Digit y = Derived::reduce(x);
    if (y >= MOD) {
      y -= MOD;
    }
    return y;
  }

  constexpr MontgomeryT &operator+=(const MontgomeryT &other) {
    x += other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr MontgomeryT operator+(const MontgomeryT &other) const {
    MontgomeryT copy = *this;
    return copy += other;
  }

  constexpr MontgomeryT &operator-=(const MontgomeryT &other) {
    x += MOD2 - other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr MontgomeryT operator-(const MontgomeryT &other) const {
    MontgomeryT copy = *this;
    return copy -= other;
  }

  constexpr MontgomeryT operator*=(const MontgomeryT &other) {
    x = Derived::mont_multiply(x, other.x);
    return *this;
  }

  constexpr MontgomeryT operator*(const MontgomeryT &other) const {
    MontgomeryT copy = *this;
    return copy *= other;
  }

  constexpr MontgomeryT pow(u64 n) const {
    MontgomeryT base = *this;
    MontgomeryT result{1};
    while (n) {
      if (n & 1) {
        result *= base;
      }
      base *= base;
      n >>= 1;
    }
    return result;
  }

  constexpr MontgomeryT inv() const { return pow(MOD - 2); }

private:
  static constexpr Digit rpower(int n) {
    Digit result = 1;
    for (int i = 0; i < n; ++i) {
      result += result;
      if (result >= MOD) {
        result -= MOD;
      }
    }
    return result;
  }

  static const Digit MOD2 = MOD << 1;
  static const Digit R = rpower(RBIT);
  static const Digit R2 = rpower(RBIT << 1);

  Digit x;
};

template <typename Digit> static constexpr Digit modinv(Digit MOD, int n) {
  Digit result = 1;
  for (int i = 0; i < n; ++i) {
    result *= 2 - MOD * result;
  }
  return -result;
}

template <u32 MOD> struct Montgomery32Impl {
  static constexpr u32 mont_multiply(u32 x, u32 y) {
    return reduce(static_cast<u64>(x) * y);
  }

  static constexpr u32 reduce(u32 x) { return reduce(static_cast<u64>(x)); }

  static constexpr u64 reduce(u64 x) {
    u64 y = (((x & UINT32_MAX) * INV) & UINT32_MAX) * MOD;
    return (x + y) >> 32U;
  }

  static const u32 INV = modinv<u32>(MOD, 5);
};

template <u64 MOD> struct Montgomery64Impl {
  static constexpr u64 mont_multiply(u64 x, u64 y) {
    return reduce(u128::multiply(x, y));
  }

  static constexpr u64 reduce(u64 x) { return reduce(u128{0, x}); }

  static constexpr u64 reduce(u128 x) {
    u128 y = u128::multiply(u128::multiply(x.low, INV).low, MOD);
    return x.high + y.high + (x.low > ~y.low);
  }

  static const u64 INV = modinv<u64>(MOD, 6);
};

template <u32 MOD>
using Montgomery32T = MontgomeryT<32, u32, MOD, Montgomery32Impl<MOD>>;

template <u64 MOD>
using Montgomery64T = MontgomeryT<64, u64, MOD, Montgomery64Impl<MOD>>;

} // namespace montgomery

using ModT = montgomery::Montgomery32T<998244353>;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  n >>= 1;
  std::vector<int> digits(k);
  for (int i = 0, d; i < k; ++i) {
    scanf("%d", &digits[i]);
  }
  std::sort(digits.begin(), digits.end());
  for (int i = 1; i < k; ++i) {
    digits[i] -= digits[0];
  }
  digits.erase(digits.begin());
  int m = n * 9;
  std::vector<ModT> inv(m + 1);
  inv[1] = ModT{1};
  for (int i = 2; i <= m; ++i) {
    inv[i] = ModT(ModT::MOD - ModT::MOD / i) * inv[ModT::MOD % i];
  }
  std::vector<ModT> q(m + 1);
  q[0] = ModT{1};
  std::array<ModT, 10> mod_d;
  for (int i = 0; i < 10; ++i) {
    mod_d[i] = ModT(i);
  }
  ModT mod_n(n);
  ModT mod_k_plus_1(0);
  for (int k = 0; k < m; ++k) {
    mod_k_plus_1 += ModT{1};
    ModT result{0};
    for (auto &&d : digits) {
      if (d <= k + 1) {
        result += mod_d[d] * q[k - (d - 1)];
      }
    }
    result *= mod_n;
    for (auto &&d : digits) {
      if (d <= k) {
        result -= (mod_k_plus_1 - mod_d[d]) * q[k + 1 - d];
      }
    }
    q[k + 1] = result * inv[k + 1];
  }
  ModT result{0};
  for (int i = 0; i <= m; ++i) {
    result += q[i] * q[i];
  }
  printf("%d\n", result.get());
}