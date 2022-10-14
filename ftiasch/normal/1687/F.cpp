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
#line 2 "/home/ftiasch/Documents/shoka/ntt_util.h"

#include <stdexcept>

namespace ntt {

static void assert_power_of_two(int n) {
  if (n & (n - 1)) {
    throw std::invalid_argument(std::to_string(n) + " is not a power of two");
  }
}

static int min_power_of_two(int n) {
  return n == 1 ? 1 : 1 << (32 - __builtin_clz(n - 1));
}

} // namespace ntt
#line 2 "/home/ftiasch/Documents/shoka/finite_poly.h"

#include <cstdlib>
#include <memory>
#line 6 "/home/ftiasch/Documents/shoka/finite_poly.h"

namespace ntt {

/*
 * Operation in Finite Polynomial Ring
 * e.g. 1 / f(z) is not finite and should be computed as 1 / f(z) mod z^n
 */
template <typename NTT>
struct FinitePolyFactoryT
    : std::enable_shared_from_this<FinitePolyFactoryT<NTT>> {
private:
  using Mod = typename NTT::Mod;
  using Factory = FinitePolyFactoryT<NTT>;

public:
  using Ptr = std::shared_ptr<Factory>;

  static Ptr create(int max_deg) { return Ptr(new Factory(max_deg)); }

  struct Poly : public std::vector<Mod> {
    Poly() : std::vector<Mod>(), factory(LocalSharedPtr<Factory>(nullptr)) {}

    int deg() const { return static_cast<int>(std::vector<Mod>::size()) - 1; }

    Poly operator+(const Poly &o) const {
      if (deg() < o.deg()) {
        return o + *this;
      }
      Poly r = factory->make(*this);
      for (int i = 0; i <= o.deg(); ++i) {
        r[i] += o[i];
      }
      return r;
    }

    Poly &operator+=(Poly &o) { return *this = *this += o; }

    Poly operator-(const Poly &o) const {
      int max_deg = std::max(deg(), o.deg());
      Poly r = factory->make(max_deg + 1);
      int min_deg = std::min(deg(), o.deg());
      for (int i = 0; i <= min_deg; ++i) {
        r[i] = (*this)[i] - o[i];
      }
      for (int i = min_deg + 1; i <= deg(); ++i) {
        r[i] = (*this)[i];
      }
      for (int i = min_deg + 1; i <= o.deg(); ++i) {
        r[i] = -o[i];
      }
      return r;
    }

    Poly &operator-=(Poly &o) { return *this = *this -= o; }

    Poly operator*(const Poly &o) const {
      int deg_plus_1 = deg() + o.deg() + 1;
      if (deg_plus_1 <= 16) {
        std::vector<Mod> result(deg_plus_1);
        for (int i = 0; i <= deg(); ++i) {
          for (int j = 0; j <= o.deg(); ++j) {
            result[i + j] += (*this)[i] * o[j];
          }
        }
        return factory->make(std::move(result));
      }

      Mod *b0 = factory->template raw_buffer<0>();
      Mod *b1 = factory->template raw_buffer<1>();

      int n = min_power_of_two(deg_plus_1);
      factory->assert_max_n(n);
      copy_and_fill0(n, b0, *this);
      NTT::dif(n, b0);
      copy_and_fill0(n, b1, o);
      NTT::dif(n, b1);
      dot_product_and_dit(n, Mod(n).inverse(), b0, b0, b1);
      return factory->make(std::vector<Mod>(b0, b0 + deg_plus_1));
    }

    Poly &operator*=(const Poly &o) { return *this = *this * o; }

  private:
    friend struct FinitePolyFactoryT;

    template <typename... Args>
    Poly(Ptr &&factory_, Args &&...args)
        : std::vector<Mod>(std::forward<Args>(args)...),
          factory(std::move(factory_)) {}

    Ptr factory;
  };

  template <typename... Args> Poly make(Args &&...args) {
    Poly p{std::enable_shared_from_this<Factory>::shared_from_this(),
           std::forward<Args>(args)...};
    return p;
  }

private:
  friend struct Poly;

  FinitePolyFactoryT(int max_deg)
      : max_n{min_power_of_two(max_deg + 1)}, buffer{std::vector<Mod>(max_n),
                                                     std::vector<Mod>(max_n)} {}

  static void copy_and_fill0(int n, Mod *dst, int m, const Mod *src) {
    m = std::min(n, m);
    std::copy(src, src + m, dst);
    std::fill(dst + m, dst + n, Mod(0));
  }

  static void copy_and_fill0(int n, Mod *dst, const std::vector<Mod> &src) {
    copy_and_fill0(n, dst, src.size(), src.data());
  }

  static void dot_product_and_dit(int n, Mod inv_n, Mod *out, const Mod *a,
                                  const Mod *b) {
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

  template <int index> Mod *raw_buffer() { return buffer[index].data(); }

  int max_n;
  std::array<std::vector<Mod>, 2> buffer;
};

} // namespace ntt
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

namespace mod {

using u32 = uint32_t;
using u64 = uint64_t;

template <u32 MOD_> struct ModT {
  static const u32 MOD = MOD_;

  static_assert(MOD <= (std::numeric_limits<u32>::max() >> 1));

  static constexpr ModT normalize(u64 x) { return ModT(x % MOD); }

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

  constexpr ModT operator-() const {
    ModT copy{0};
    copy -= *this;
    return copy;
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

} // namespace mod

template <mod::u32 MOD>
std::ostream &operator<<(std::ostream &out, const mod::ModT<MOD> &mod) {
  return out << mod.get();
}
#line 2 "/home/ftiasch/Documents/shoka/ntt.h"

#line 4 "/home/ftiasch/Documents/shoka/ntt.h"

#include <algorithm>
#include <array>
#include <cassert>
#line 11 "/home/ftiasch/Documents/shoka/ntt.h"
#include <string>
#line 13 "/home/ftiasch/Documents/shoka/ntt.h"

namespace ntt {

template <typename ModT_> struct NTT {
  using Mod = ModT_;

  static void dit(int n, Mod *a) {
    assert_power_of_two(n);
    for (int m = 1; m < n; m <<= 1) {
      const Mod root = G.power((Mod::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        Mod twiddle(1);
        for (int r = i; r < i + m; ++r) {
          Mod tmp = twiddle * a[r + m];
          a[r + m] = a[r];
          a[r + m] -= tmp;
          a[r] += tmp;
          twiddle *= root;
        }
      }
    }
  }

  static void dif(int n, Mod *a) {
    assert_power_of_two(n);
    for (int m = n; m >>= 1;) {
      const Mod root = G.power(Mod::MOD - 1 - (Mod::MOD - 1) / (m << 1));
      for (int i = 0; i < n; i += m << 1) {
        Mod twiddle(1);
        for (int r = i; r < i + m; ++r) {
          Mod tmp = a[r];
          tmp -= a[r + m];
          a[r] += a[r + m];
          a[r + m] = twiddle * tmp;
          twiddle *= root;
        }
      }
    }
  }

  static Mod get_primitive_root() { return G; }

private:
  struct FiniteField {
    static constexpr Mod primitive_root() {
      int g = 2;
      while (!is_primitive_root(Mod(g))) {
        g++;
      }
      return Mod(g);
    }

  private:
    static constexpr bool is_primitive_root(Mod g) {
      for (int d = 2; d * d <= Mod::MOD - 1; ++d) {
        if ((Mod::MOD - 1) % d == 0 &&
            (g.power(d).get() == 1 || g.power((Mod::MOD - 1) / d).get() == 1)) {
          return false;
        }
      }
      return true;
    }
  };

  static constexpr Mod G = FiniteField::primitive_root();
};

} // namespace ntt
#line 5 "/tmp/tmp-56992X3GYfqrMfNT6.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 7 "/tmp/tmp-56992X3GYfqrMfNT6.cpp"

using Mod = mod::ModT<998'244'353>;
using PolyFactory = ntt::FinitePolyFactoryT<ntt::NTT<Mod>>;
using Poly = PolyFactory::Poly;

struct Node {
  Poly product, sum_Q, sum_C, result;
};

struct Solver {
  Solver(int max_n_, int s)
      : max_n(max_n_), factory(PolyFactory::create(max_n + max_n)),
        binom(max_n + std::max(s, 1)),
        tree(max_n + max_n + 1, Node{make(0), make(0), make(0), make(0)}) {
    prepare(0, max_n);
  }

  Node &prepare(int l, int r_minus_1) {
    Node &n = get_node(l, r_minus_1);
    int r = r_minus_1 + 1;
    if (l == r_minus_1) {
      // (-tau - i + 1) / i
      Poly q_l = l ? make(std::vector<Mod>{Mod(l).inverse() - Mod(1),
                                           -Mod(l).inverse()})
                   : make(std::vector<Mod>{Mod{1}});
      n.product = q_l;
      n.sum_Q = shift(q_l, 1);
    } else {
      int m_minus_1 = (l + r_minus_1) >> 1;
      const Node &ln = prepare(l, m_minus_1);
      const Node &rn = prepare(m_minus_1 + 1, r_minus_1);
      int m = m_minus_1 + 1;
      n.product = ln.product * rn.product;
      n.sum_Q = shift(ln.sum_Q, r - m) + ln.product * rn.sum_Q;
    }
    return n;
  }

  Node &recur(const std::vector<Mod> &c, int l, int r_minus_1) {
    Node &n = get_node(l, r_minus_1);
    int r = r_minus_1 + 1;
    if (l == r_minus_1) {
      n.sum_C = make(std::vector<Mod>{c[l]});
      n.result = n.product * n.sum_C;
    } else {
      int m_minus_1 = (l + r_minus_1) >> 1;
      const Node &ln = recur(c, l, m_minus_1);
      const Node &rn = recur(c, m_minus_1 + 1, r_minus_1);
      int m = m_minus_1 + 1;
      n.sum_C = ln.sum_C + shift(rn.sum_C, m - l);
      n.result = ln.result + ln.sum_Q * rn.sum_C + ln.product * rn.result;
    }
    return n;
  }

  // change of value tau = t / (1 - t)
  Poly taylor(int n, const Poly &f) {
    std::vector<Mod> g(n + 1), h(n + 1);
    for (int i = 0; i <= n; ++i) {
      g[i] = binom.fact[n - i] * f[i];
      h[i] = minus_one(i) * binom.inv_fact[i];
    }
    auto gh = make(g) * make(h);
    gh.resize(n + 1);
    for (int k = 0; k <= n; ++k) {
      gh[k] *= binom.inv_fact[n - k];
    }
    return gh;
  }

  // n! (1-t) [z^n] exp(-tz) / (1 - t exp((1-t)z))
  Poly solve(int n) {
    std::vector<Mod> c = stirling(n);
    for (int i = 0; i <= n; ++i) {
      c[i] *= binom.fact[i];
    }
    c.resize(max_n + 1);
    Poly result = recur(c, 0, max_n).result;
    return taylor(n, result);
  }

  Poly solve() { return solve(max_n) + solve(max_n - 1); }

  // sum_k Stirling(n, k) t^k
  std::vector<Mod> stirling(int n) const {
    std::vector<Mod> g(n + 1), h(n + 1);
    for (int i = 0; i <= n; ++i) {
      g[i] = minus_one(i) * binom.inv_fact[i];
      h[i] = Mod(i).power(n) * binom.inv_fact[i];
    }
    auto gh = make(g) * make(h);
    gh.resize(n + 1);
    return gh;
  }

  Node &get_node(int l, int r) { return tree[(l + r) | (l != r)]; }

  template <typename... Args> Poly make(Args &&...args) const {
    return factory->make(std::forward<Args...>(args...));
  }

  static Mod minus_one(int n) { return Mod((n & 1) ? Mod::MOD - 1 : 1); }

  // = p * z^k
  Poly shift(const Poly &p, int k) {
    Poly np = make(p.deg() + k + 1);
    for (int i = 0; i <= p.deg(); ++i) {
      np[i + k] = p[i];
    }
    return np;
  }

  int max_n;
  PolyFactory::Ptr factory;
  Binom<Mod> binom;
  std::vector<Node> tree;
};

int main() {
  IO io;
  int n = io.read();
  int s = io.read();
  n -= s;
  Solver solver{n, s};
  Poly result_prime = solver.solve();
  Mod b = solver.binom(n + s - 1, s);
  for (int k = 0; k < n + s; ++k) {
    auto result = k < s ? Mod{0} : b * result_prime[n - 1 - (k - s)];
    std::cout << result << " \n"[k + 1 == n + s];
  }
}