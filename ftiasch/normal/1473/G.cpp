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

  constexpr MontgomeryT operator+(const MontgomeryT &other) {
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

  constexpr MontgomeryT operator-(const MontgomeryT &other) {
    MontgomeryT copy = *this;
    return copy -= other;
  }

  constexpr MontgomeryT operator*=(const MontgomeryT &other) {
    x = Derived::mont_multiply(x, other.x);
    return *this;
  }

  constexpr MontgomeryT operator*(const MontgomeryT &other) {
    MontgomeryT copy = *this;
    return copy *= other;
  }

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

using u32 = uint32_t;
using u64 = uint64_t;

template <typename ModT> struct NTT {
  static const u32 MOD = ModT::MOD;

  NTT(int n) : n(n), dit_twiddles(n), dif_twiddles(n) { resize(n); }

  void resize(int n) {
    this->n = n;
    inv_n = power(ModT(n), MOD - 2);
    dit_twiddles.resize(n);
    dif_twiddles.resize(n);
    ModT root = power(G, (MOD - 1) / n);
    for (int m = n; m >>= 1;) {
      dit_twiddles[m] = ModT(1);
      for (int i = 1; i < m; ++i) {
        dit_twiddles[m + i] = dit_twiddles[m + i - 1] * root;
      }
      root *= root;
    }
    root = power(G, MOD - 1 - (MOD - 1) / n);
    for (int m = n; m >>= 1;) {
      dif_twiddles[m] = ModT(1);
      for (int i = 1; i < m; ++i) {
        dif_twiddles[m + i] = dif_twiddles[m + i - 1] * root;
      }
      root *= root;
    }
  }

  void dit(ModT *a) {
    for (int m = 1; m < n; m <<= 1) {
      for (int i = 0; i < n; i += m << 1) {
        for (int r = i; r < i + m; ++r) {
          ModT tmp = dit_twiddles[m + r - i] * a[r + m];
          a[r + m] = a[r];
          a[r + m] -= tmp;
          a[r] += tmp;
        }
      }
    }
  }

  void dif(ModT *a) {
    for (int m = n; m >>= 1;) {
      for (int i = 0; i < n; i += m << 1) {
        for (int r = i; r < i + m; ++r) {
          ModT tmp = a[r];
          tmp -= a[r + m];
          a[r] += a[r + m];
          a[r + m] = dif_twiddles[m + r - i] * tmp;
        }
      }
    }
  }

  void convolute(ModT *a, ModT *b, ModT *out) {
    dif(a);
    dif(b);
    for (int i = 0; i < n; ++i) {
      out[i] = inv_n * a[i] * b[i];
    }
    dit(out);
  }

  void revbin(ModT *a) {
    for (int i = 1, j = 0; i < n - 1; ++i) {
      for (int s = n; j ^= s >>= 1, ~j & s;)
        ;
      if (i < j) {
        std::swap(a[i], a[j]);
      }
    }
  }

private:
  static constexpr ModT power(ModT a, int n) {
    ModT res(1);
    while (n) {
      if (n & 1) {
        res *= a;
      }
      a *= a;
      n >>= 1;
    }
    return res;
  }

  struct FiniteField {
    static constexpr ModT primitive_root() {
      int g = 2;
      while (!is_primitive_root(ModT(g))) {
        g++;
      }
      return ModT(g);
    }

  private:
    static constexpr bool is_primitive_root(ModT g) {
      for (int d = 2; d * d <= MOD - 1; ++d) {
        if ((MOD - 1) % d == 0 &&
            (power(g, d).get() == 1 || power(g, (MOD - 1) / d).get() == 1)) {
          return false;
        }
      }
      return true;
    }
  };

  int n;
  ModT inv_n;
  std::vector<ModT> dit_twiddles, dif_twiddles;

  static constexpr ModT G = ModT(FiniteField::primitive_root());
};

const int MOD = 998244353;
using ModT = montgomery::Montgomery32T<MOD>;

struct Binom {
  Binom(int m) : fact(m + 1), inv_fact(m + 1) {
    fact[0] = inv_fact[0] = inv_fact[1] = ModT(1);
    for (int i = 1; i <= m; ++i) {
      fact[i] = fact[i - 1] * ModT(i);
    }
    for (int i = 2; i <= m; ++i) {
      inv_fact[i] = ModT(MOD - MOD / i) * inv_fact[MOD % i];
    }
    for (int i = 2; i <= m; ++i) {
      inv_fact[i] = inv_fact[i - 1] * inv_fact[i];
    }
  }

  ModT get(int n, int k) {
    return 0 <= k && k <= n ? fact[n] * inv_fact[k] * inv_fact[n - k] : ModT(0);
  }

  std::vector<ModT> fact, inv_fact;
};

int min_power_of_two(int n) {
  int k = 0;
  while ((1 << k) <= n) {
    k++;
  }
  return 1 << k;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    std::vector<int> a(n), b(n), tiles(n + 1);
    tiles[0] = 1;
    int m = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i], &b[i]);
      m = std::max(m, a[i] + b[i]);
      tiles[i + 1] = tiles[i] + a[i] - b[i];
    }
    Binom binom(m);
    int size = 1;
    NTT<ModT> ntt(size);
    std::vector<ModT> dp{ModT(1)}, ways(0);
    for (int i = 0; i < n; ++i) {
      {
        int p = min_power_of_two(tiles[i] + tiles[i + 1]);
        if (size < p) {
          size = p;
          dp.resize(size);
          ways.resize(size);
          ntt.resize(size);
        }
      }
      for (int j = 0; j < size; ++j) {
        ways[j] = 0 < j && j < tiles[i] + tiles[i + 1]
                      ? binom.get(a[i] + b[i], b[i] + (j - tiles[i]))
                      : ModT(0);
      }
      ntt.convolute(dp.data(), ways.data(), dp.data());
      for (int j = 0; j < tiles[i + 1]; ++j) {
        dp[j] = dp[j + tiles[i]];
      }
      for (int j = tiles[i + 1]; j < size; ++j) {
        dp[j] = ModT(0);
      }
    }
    ModT result(0);
    for (int j = 0; j < tiles[n]; ++j) {
      result += dp[j];
    }
    printf("%u\n", result.get());
  }
}