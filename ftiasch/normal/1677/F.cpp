#line 1 "/home/ftiasch/Documents/shoka/binom.h"
#include <vector>

template <typename ModT> struct Binom {
  Binom(int n) : fact(n), inv_fact(n) {
    fact[0] = inv_fact[0] = inv_fact[1] = ModT(1);
    for (int i = 2; i < n; ++i) {
      inv_fact[i] = ModT(ModT::MOD - ModT::MOD / i) * inv_fact[ModT::MOD % i];
    }
    for (int i = 1; i < n; ++i) {
      fact[i] = ModT(i) * fact[i - 1];
      inv_fact[i] *= inv_fact[i - 1];
    }
  }

  ModT operator()(int n, int k) const {
    return k < 0 || k > n ? ModT(0) : fact[n] * inv_fact[n - k] * inv_fact[k];
  }

  std::vector<ModT> fact, inv_fact;
};
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
#include <iostream>
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

  constexpr MontgomeryBaseT operator-() const {
    MontgomeryBaseT copy{0};
    return copy -= *this;
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

template <int RBIT, typename Digit, Digit M, typename Derived>
std::ostream &
operator<<(std::ostream &out,
           const montgomery::MontgomeryBaseT<RBIT, Digit, M, Derived> &mod) {
  return out << mod.get();
}
#line 1 "/home/ftiasch/Documents/shoka/ntt.h"
#include <algorithm>
#include <array>
#include <cassert>
#line 6 "/home/ftiasch/Documents/shoka/ntt.h"
#include <stdexcept>
#include <string>
#line 9 "/home/ftiasch/Documents/shoka/ntt.h"

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

  static ModT get_primitive_root() {
    return G;
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

  static constexpr ModT G = FiniteField::primitive_root();
};

static int min_power_of_two(int n) {
  return n == 1 ? 1 : 1 << (32 - __builtin_clz(n - 1));
}

template <typename NTT> class Poly {
protected:
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

  std::vector<ModT> multiply(const std::vector<ModT> &f,
                             const std::vector<ModT> &g) {
    std::vector<ModT> out;
    multiply(out, f, g);
    return out;
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

protected:
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
#line 2 "/home/ftiasch/Documents/shoka/multi_eval.h"

#include <chrono>
#line 5 "/home/ftiasch/Documents/shoka/multi_eval.h"

namespace ntt {

template <typename NTT> struct MultiEval : public Poly<NTT> {
private:
  using ModT = typename Poly<NTT>::ModT;

public:
  MultiEval(int max_n_) : Poly<NTT>(max_n_ << 1) {}

  // input:  f(z) = sum c[i] * z^i
  // output: f(a_0) f(a_1) ...
  std::vector<ModT> eval(const std::vector<ModT> &c,
                         const std::vector<ModT> &a) {
    int m = min_power_of_two(std::max<size_t>({c.size(), a.size(), 2}));
    Poly<NTT>::assert_max_n(m);
    int log_m = (__builtin_ctz(m)) + 1;
    std::vector<std::vector<ModT>> dif_rev_q(log_m, std::vector<ModT>(m << 1));
    for (int i = 0; i < m; ++i) {
      dif_rev_q[0][i << 1] = i < a.size() ? -a[i] : ModT(0);
      dif_rev_q[0][i << 1 | 1] = ModT{1};
      NTT::dif(2, dif_rev_q[0].data() + (i << 1));
    }
    for (int l = 1; l < log_m; ++l) {
      ModT inv_n(ModT(1 << l).inverse());
      ModT G(NTT::get_primitive_root());
      ModT zeta(G.power(ModT::MOD - 1 - (ModT::MOD >> (l + 1))));
      for (int s = 0; s < (m << 1); s += (2 << l)) {
        if (l + 1 < log_m) {
          for (int i = s; i < s + (1 << l); ++i) {
            dif_rev_q[l][i] = dif_rev_q[l - 1][i] * dif_rev_q[l - 1][i + (1 << l)];
            dif_rev_q[l][i + (1 << l)] = inv_n * dif_rev_q[l][i];
          }
          NTT::dit(1 << l, dif_rev_q[l].data() + s + (1 << l));
          dif_rev_q[l][s + (1 << l)] -= ModT{2};
          ModT zeta_tmp{1};
          for (int i = s + (1 << l); i < s + (2 << l); ++i) {
            dif_rev_q[l][i] *= zeta_tmp;
            zeta_tmp *= zeta;
          }
          NTT::dif(1 << l, dif_rev_q[l].data() + s + (1 << l));
        } else {
          Poly<NTT>::dot_product_and_dit(1 << l, inv_n,
                                       dif_rev_q[l].data() + s,
                                       dif_rev_q[l - 1].data() + s,
                                       dif_rev_q[l - 1].data() + s + (1 << l));
          dif_rev_q[l][s] -= ModT{1};
          dif_rev_q[l][s + (1 << l)] = ModT{1};
        }
      }
    }
    auto &q1 = dif_rev_q[log_m - 1];
    std::reverse(q1.data(), q1.data() + (m + 1));
    ModT *const dif_rev_inv_q1 = Poly<NTT>::buffer[2].data();
    Poly<NTT>::inverse(m, dif_rev_inv_q1, q1.data());
    // mul_t(m, inv_q1, c)
    std::fill(dif_rev_inv_q1 + m, dif_rev_inv_q1 + (m << 1), ModT{0});
    std::reverse(dif_rev_inv_q1, dif_rev_inv_q1 + (m + 1));
    NTT::dif(m << 1, dif_rev_inv_q1);
    ModT *const dif_c = Poly<NTT>::buffer[3].data();
    Poly<NTT>::copy_and_fill0(m << 1, dif_c, c.size(), c.data());
    NTT::dif(m << 1, dif_c);
    ModT *pnow = Poly<NTT>::buffer[0].data();
    ModT *ppre = Poly<NTT>::buffer[1].data();
    mul_t(m << 1, pnow, dif_rev_inv_q1, dif_c);
    for (int l = log_m; l-- > 1;) {
      std::swap(pnow, ppre);
      for (int s = 0, s2 = 0; s < m; s += (1 << l), s2 += (2 << l)) {
        NTT::dif(1 << l, ppre + s);
        mul_t(1 << l, pnow + s, dif_rev_q[l - 1].data() + s2 + (1 << l),
              ppre + s);
        mul_t(1 << l, pnow + s + (1 << (l - 1)), dif_rev_q[l - 1].data() + s2,
              ppre + s);
      }
    }
    return std::vector<ModT>(pnow, pnow + a.size());
  }

private:
  void mul_t(int n, ModT *out, ModT *dif_rev_a, ModT *dif_c) {
    ModT *const b = Poly<NTT>::buffer[2].data();
    Poly<NTT>::dot_product_and_dit(n, ModT(n).inverse(), b, dif_rev_a, dif_c);
    std::copy(b + (n >> 1), b + n, out);
  }
};

} // namespace ntt
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m));
}

template <typename T = int>
std::vector<std::vector<T>> vector_2d(int n, int m, T d) {
  return std::vector<std::vector<T>>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 5 "/tmp/tmp-48330w7Kog4rO87K4.cpp"

#line 8 "/home/ftiasch/Documents/shoka/debug.h"

namespace {

template <typename Tuple, size_t... Index>
std::ostream &serialize_tuple(std::ostream &out, const Tuple &t,
                              std::index_sequence<Index...>) {
  out << "(";
  (..., (out << (Index == 0 ? "" : ", ") << std::get<Index>(t)));
  return out << ")";
}

} // namespace

template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}

template <typename... T>
std::ostream &operator<<(std::ostream &out, const std::tuple<T...> &t) {
  return serialize_tuple(out, t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<T, N> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::deque<T> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T, typename S, typename C>
std::ostream &operator<<(std::ostream &out, std::priority_queue<T, S, C> pq) {
  std::vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  return out << v;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}

#define KV(x) #x << "=" << x << ";"
#line 7 "/tmp/tmp-48330w7Kog4rO87K4.cpp"

#line 9 "/tmp/tmp-48330w7Kog4rO87K4.cpp"

using Mod = montgomery::Montgomery32T<998'244'353>;

using Poly = ntt::MultiEval<ntt::NTT<Mod>>;

// f_{p, k}(n) = sum_{i = 0}^{n - 1} p^i * i^k = p^n * G(n) + C_0

std::vector<Mod> precompute_G(Poly &poly, int k, Mod p) {
  Binom<Mod> binom(k + 1);
  int k2 = ntt::min_power_of_two(k + 1);
  std::vector<Mod> h(k2), inv_h(k2), g(k + 1);
  // G(z) = inv(p * exp(D) - 1) * (z^k)
  for (int i = 0; i <= k; ++i) {
    h[i] = p * binom.inv_fact[i];
  }
  h[0] -= Mod{1};
  poly.inverse(k2, inv_h.data(), h.data());
  Mod falling_fact{1};
  for (int i = 0; i <= k; ++i) {
    g[k - i] = inv_h[i] * falling_fact;
    falling_fact *= Mod(k - i);
  }
  return g;
}

using DP = std::array<Mod, 4>;

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  int k = read();
  Mod p = Mod(read());
  auto a = read_vector(n);
  Poly poly(ntt::min_power_of_two(std::max(k + 1, n)));
  auto g = precompute_G(poly, k, p);
  auto c0 = -g[0];
  std::vector<Mod> mod_a_plus_1(n);
  for (int i = 0; i < n; ++i) {
    mod_a_plus_1[i] = Mod(a[i] + 1);
  }
  auto ga = poly.eval(g, mod_a_plus_1);
  std::vector<Mod> sum(n);
  for (int i = 0; i < n; ++i) {
    sum[i] = ga[i] * p.power(a[i] + 1) + c0;
  }
  Mod result{0};
  DP dp;
  for (int i = 0; i < n; ++i) {
    dp[0] += Mod{1};
    DP new_dp;
    for (int mask = 0; mask < 4; ++mask) {
      new_dp[mask] += dp[mask] * mod_a_plus_1[i];
      if ((mask & 1) == 0) {
        new_dp[mask | 1] += dp[mask] * sum[i];
      }
      if ((mask & 2) == 0) {
        new_dp[mask | 2] += dp[mask] * Mod(a[i]);
      }
      if ((mask & 3) == 0) {
        new_dp[mask | 3] += dp[mask] * sum[i];
      }
    }
    dp.swap(new_dp);
    result += dp[3];
  }
  std::cout << result << "\n";
}