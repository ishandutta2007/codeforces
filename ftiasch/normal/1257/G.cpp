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


#line 2 "/home/ftiasch/Documents/shoka/montgomery.h"

#line 4 "/home/ftiasch/Documents/shoka/montgomery.h"
#include <limits>

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
struct MontgomeryBaseT {
  static const Digit MOD = M;

  static_assert(MOD <= std::numeric_limits<Digit>::max() >> 2,
                "4 * MOD <= MAX");

  explicit constexpr MontgomeryBaseT(Digit x = 0)
      : x(Derived::mont_multiply(x, R2)) {}

  constexpr Digit get() const {
    Digit y = Derived::reduce(x);
    if (y >= MOD) {
      y -= MOD;
    }
    return y;
  }

  constexpr MontgomeryBaseT &operator+=(const MontgomeryBaseT &other) {
    x += other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr MontgomeryBaseT operator+(const MontgomeryBaseT &other) const {
    MontgomeryBaseT copy = *this;
    return copy += other;
  }

  constexpr MontgomeryBaseT &operator-=(const MontgomeryBaseT &other) {
    x += MOD2 - other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr MontgomeryBaseT operator-(const MontgomeryBaseT &other) const {
    MontgomeryBaseT copy = *this;
    return copy -= other;
  }

  constexpr MontgomeryBaseT operator*=(const MontgomeryBaseT &other) {
    x = Derived::mont_multiply(x, other.x);
    return *this;
  }

  constexpr MontgomeryBaseT operator*(const MontgomeryBaseT &other) const {
    MontgomeryBaseT copy = *this;
    return copy *= other;
  }

  constexpr MontgomeryBaseT power(u64 n) const {
    return details::power<MontgomeryBaseT>(*this, n);
  }

  constexpr MontgomeryBaseT inverse() const {
    return details::inverse<MontgomeryBaseT>(*this);
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

template <u32 MOD> struct Montgomery32Impl {
  static constexpr u32 mont_multiply(u32 x, u32 y) {
    return reduce(static_cast<u64>(x) * y);
  }

  static constexpr u32 reduce(u32 x) { return reduce(static_cast<u64>(x)); }

  static constexpr u64 reduce(u64 x) {
    u64 y = (((x & UINT32_MAX) * INV) & UINT32_MAX) * MOD;
    return (x + y) >> 32U;
  }

  static const u32 INV = details::mont_modinv<u32>(MOD, 5);
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

  static const u64 INV = details::mont_modinv<u64>(MOD, 6);
};

template <u32 MOD>
using Montgomery32T = MontgomeryBaseT<32, u32, MOD, Montgomery32Impl<MOD>>;

template <u64 MOD>
using Montgomery64T = MontgomeryBaseT<64, u64, MOD, Montgomery64Impl<MOD>>;

} // namespace montgomery
#line 1 "/home/ftiasch/Documents/shoka/ntt.h"
#include <algorithm>
#include <array>
#include <cassert>
#line 5 "/home/ftiasch/Documents/shoka/ntt.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace ntt {

static void assert_power_of_two(int n) {
  if (n & (n - 1)) {
    throw std::invalid_argument(std::to_string(n) + " is not a power of two");
  }
}

template <typename ModT_> struct NTT {
  using ModT = ModT_;

  static void dit(int n, ModT *a) {
    assert_power_of_two(n);
    for (int m = 1; m < n; m <<= 1) {
      const ModT root = G.power((ModT::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        ModT twiddle(1);
        for (int r = i; r < i + m; ++r) {
          ModT tmp = twiddle * a[r + m];
          a[r + m] = a[r];
          a[r + m] -= tmp;
          a[r] += tmp;
          twiddle *= root;
        }
      }
    }
  }

  static void dif(int n, ModT *a) {
    assert_power_of_two(n);
    for (int m = n; m >>= 1;) {
      const ModT root = G.power(ModT::MOD - 1 - (ModT::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        ModT twiddle(1);
        for (int r = i; r < i + m; ++r) {
          ModT tmp = a[r];
          tmp -= a[r + m];
          a[r] += a[r + m];
          a[r + m] = twiddle * tmp;
          twiddle *= root;
        }
      }
    }
  }

private:
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
      for (int d = 2; d * d <= ModT::MOD - 1; ++d) {
        if ((ModT::MOD - 1) % d == 0 &&
            (g.power(d).get() == 1 ||
             g.power((ModT::MOD - 1) / d).get() == 1)) {
          return false;
        }
      }
      return true;
    }
  };

  static constexpr ModT G = ModT(FiniteField::primitive_root());
};

static int min_power_of_two(int n) { return 1 << (32 - __builtin_clz(n - 1)); }

template <typename NTT> class Poly {
private:
  using ModT = typename NTT::ModT;

public:
  Poly(int max_n_) : max_n(max_n_), inv(max_n) {
    inv[1] = ModT(1);
    for (int i = 2; i < max_n; ++i) {
      inv[i] = ModT(ModT::MOD - ModT::MOD / i) * inv[ModT::MOD % i];
    }
    for (int i = 0; i < 4; ++i) {
      buffer[i].resize(max_n);
    }
  }

  void multiply(std::vector<ModT> &out, const std::vector<ModT> &f,
                const std::vector<ModT> &g) {
    ModT *b0 = buffer[0].data();
    ModT *b1 = buffer[1].data();

    int deg_plus_1 = f.size() + g.size() - 1;
    int n = min_power_of_two(deg_plus_1);
    assert_max_n(n);

    copy_and_fill0(n, b0, f.size(), f.data());
    NTT::dif(n, b0);
    copy_and_fill0(n, b1, g.size(), g.data());
    NTT::dif(n, b1);
    dot_product_and_dit(n, ModT(n).inverse(), b0, b0, b1);
    out.resize(deg_plus_1);
    for (int i = 0; i < deg_plus_1; ++i) {
      out[i] = b0[i];
    }
  }

  void inverse(int n, ModT *out, const ModT *f) {
    assert_power_of_two(n);
    assert_max_n(n);

    ModT *const b0 = buffer[0].data();
    ModT *const b1 = buffer[1].data();

    std::fill(out, out + n, ModT(0));
    out[0] = f[0].inverse();
    ModT inv_m(1);
    for (int m = 2; m <= n; m <<= 1) {
      copy_and_fill0(m, b0, n, f);
      NTT::dif(m, b0);
      std::copy(out, out + m, b1);
      NTT::dif(m, b1);
      inv_m *= ModT(2).inverse();
      dot_product_and_dit(m, inv_m, b0, b0, b1);
      std::fill(b0, b0 + (m >> 1), ModT(0));
      NTT::dif(m, b0);
      dot_product_and_dit(m, inv_m, b0, b0, b1);
      for (int i = m >> 1; i < m; ++i) {
        out[i] = ModT(0) - b0[i];
      }
    }
  }

  // f / g
  void divide(int n, ModT *out, const ModT *f, const ModT *g) {
    if (n == 1) {
      out[0] = f[0] * g[0].inverse();
    } else {
      assert_power_of_two(n);
      assert_max_n(n);

      ModT *const b0 = buffer[0].data();
      ModT *const b1 = buffer[1].data();
      ModT *const inv_g = buffer[2].data();

      int m = n >> 1;
      inverse(m, inv_g, g);
      std::fill(inv_g + m, inv_g + n, ModT(0));
      NTT::dif(n, inv_g);
      copy_and_fill0(n, b0, m, f);
      NTT::dif(n, b0);
      const ModT inv_n = ModT(n).inverse();
      dot_product_and_dit(n, inv_n, b0, b0, inv_g);

      std::copy(b0, b0 + m, out);

      std::fill(b0 + m, b0 + n, ModT(0));
      NTT::dif(n, b0);
      std::copy(g, g + n, b1);
      NTT::dif(n, b1);
      dot_product_and_dit(n, inv_n, b0, b0, b1);
      std::fill(b0, b0 + m, ModT(0));
      for (int i = m; i < n; ++i) {
        b0[i] -= f[i];
      }
      NTT::dif(n, b0);
      dot_product_and_dit(n, inv_n, b0, b0, inv_g);
      for (int i = m; i < n; ++i) {
        out[i] = ModT(0) - b0[i];
      }
    }
  }

  void log(int n, ModT *out, const ModT *f) {
    if (f[0].get() != 1) {
      throw std::invalid_argument("[x^0] f != 1");
    }
    assert_power_of_two(n);
    assert_max_n(n);
    // log f = \int f' / f
    ModT *const d_f = buffer[3].data();
    d_f[n - 1] = ModT(0);
    for (int i = 1; i < n; ++i) {
      d_f[i - 1] = ModT(i) * f[i];
    }
    divide(n, out, d_f, f);
    for (int i = n; i-- > 1;) {
      out[i] = out[i - 1] * inv[i];
    }
    out[0] = ModT(0);
  }

  void exp(int n, ModT *out, const ModT *f) {
    if (f[0].get() != 0) {
      throw std::invalid_argument("[x^0] f != 0");
    }
    if (n == 1) {
      out[0] = ModT(1);
    } else {
      assert_power_of_two(n);
      assert_max_n(n);

      ModT *const b0 = buffer[0].data();
      ModT *const b1 = buffer[1].data();
      ModT *const b2 = buffer[2].data();
      ModT *const b3 = buffer[3].data();

      out[0] = b1[0] = b1[1] = b2[0] = ModT(1);
      ModT inv_m(1);
      for (int m = 1; m < (n >> 1); m <<= 1) {
        const ModT inv_2m = inv_m * ModT(2).inverse();
        for (int i = 0; i < m; ++i) {
          b0[i] = ModT(i) * f[i];
        }
        NTT::dif(m, b0);
        dot_product_and_dit(m, inv_m, b0, b0, b1);
        for (int i = 0; i < m; ++i) {
          b0[i] -= ModT(i) * out[i];
        }
        std::fill(b0 + m, b0 + (m << 1), ModT(0));
        NTT::dif(m << 1, b0);
        copy_and_fill0(m << 1, b3, m, b2);
        NTT::dif(m << 1, b3);
        dot_product_and_dit(m << 1, inv_2m, b0, b0, b3);
        for (int i = 0; i < m; ++i) {
          b0[i] = b0[i] * inv[m + i] + f[m + i];
        }
        std::fill(b0 + m, b0 + (m << 1), ModT(0));
        NTT::dif(m << 1, b0);
        dot_product_and_dit(m << 1, inv_2m, b0, b0, b1);
        std::copy(b0, b0 + m, out + m);
        copy_and_fill0(m << 2, b1, m << 1, out);
        NTT::dif(m << 2, b1);
        dot_product_and_dit(m << 1, inv_2m, b0, b1, b3);
        std::fill(b0, b0 + m, ModT(0));
        NTT::dif(m << 1, b0);
        dot_product_and_dit(m << 1, inv_2m, b0, b0, b3);
        for (int i = m; i < m << 1; ++i) {
          b2[i] = ModT(0) - b0[i];
        }
        inv_m = inv_2m;
      }
      const int m = n >> 1;
      for (int i = 0; i < m; ++i) {
        b0[i] = ModT(i) * f[i];
      }
      NTT::dif(m, b0);
      dot_product_and_dit(m, inv_m, b0, b0, b1);
      for (int i = 0; i < m; ++i) {
        b0[i] -= ModT(i) * out[i];
      }
      copy_and_fill0(m, b0 + m, m >> 1, b0 + (m >> 1));
      std::fill(b0 + (m >> 1), b0 + m, ModT(0));
      NTT::dif(m, b0);
      NTT::dif(m, b0 + m);
      copy_and_fill0(m, b3 + m, m >> 1, b2 + (m >> 1));
      NTT::dif(m, b3 + m);
      for (int i = 0; i < m; ++i) {
        b0[m + i] = inv_m * (b0[i] * b3[m + i] + b0[m + i] * b3[i]);
      }
      dot_product_and_dit(m, inv_m, b0, b0, b3);
      NTT::dit(m, b0 + m);
      for (int i = 0; i < m >> 1; ++i) {
        b0[(m >> 1) + i] += b0[m + i];
      }
      for (int i = 0; i < m; ++i) {
        b0[i] = b0[i] * inv[m + i] + f[m + i];
      }
      std::fill(b0 + m, b0 + (m << 1), ModT(0));
      NTT::dif(m << 1, b0);
      const ModT inv_2m = inv_m * ModT(2).inverse();
      dot_product_and_dit(m << 1, inv_2m, b0, b0, b1);
      std::copy(b0, b0 + m, out + m);
    }
  }

private:
  static void copy_and_fill0(int n, ModT *dst, int m, const ModT *src) {
    m = std::min(n, m);
    std::copy(src, src + m, dst);
    std::fill(dst + m, dst + n, ModT(0));
  }

  static void dot_product_and_dit(int n, ModT inv_n, ModT *out, const ModT *a,
                                  const ModT *b) {
    for (int i = 0; i < n; ++i) {
      out[i] = inv_n * a[i] * b[i];
    }
    NTT::dit(n, out);
  }

  void assert_max_n(int n) const {
    if (n > max_n) {
      throw std::invalid_argument("insufficient buffer");
    }
  }

  int max_n;
  std::vector<ModT> inv;
  std::array<std::vector<ModT>, 4> buffer;
};

} // namespace ntt
#line 3 "sol.cpp"

#include <bits/stdc++.h>

using ModT = montgomery::Montgomery32T<998'244'353>;

using NTT = ntt::NTT<ModT>;
using Poly = ntt::Poly<NTT>;

Poly poly(1 << 18);
std::vector<int> cnt;

std::vector<ModT> solve(int l, int r, int sum) {
  if (l + 1 == r) {
    int c = cnt[l];
    return std::vector<ModT>(c + 1, ModT{1});
  }
  int lsum = cnt[l];
  int m = l + 1;
  while (lsum + lsum <= sum && m + 1 < r) {
    lsum += cnt[m];
    m++;
  }
  std::vector<ModT> out;
  poly.multiply(out, solve(l, m, lsum), solve(m, r, sum - lsum));
  return out;
}

int main() {
  int n;
  scanf("%d", &n);
  std::map<int, int> cntmap;
  for (int i = 0, p; i < n; ++i) {
    scanf("%d", &p);
    cntmap[p]++;
  }
  for (auto [k, v] : cntmap) {
    cnt.push_back(v);
  }
  std::sort(cnt.begin(), cnt.end(), std::greater<int>());
  auto result = solve(0, cnt.size(), n);
  printf("%d\n", result[n / 2].get());
}