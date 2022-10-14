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

template <uint32_t MOD_> struct ModT {
  static const uint32_t MOD = MOD_;

  static_assert(MOD <= (std::numeric_limits<uint32_t>::max() >> 1));

  static constexpr ModT normalize(uint64_t x) { return ModT(x % MOD); }

  explicit constexpr ModT(uint32_t x_ = 0) : x(x_) {}

  constexpr uint32_t get() const { return x; }

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
    x = static_cast<uint64_t>(x) * static_cast<uint64_t>(other.x) % MOD;
    return *this;
  }

  constexpr ModT operator*(const ModT &other) const {
    ModT copy = *this;
    return copy *= other;
  }

  constexpr ModT power(uint64_t n) const {
    return details::power<ModT>(*this, n);
  }

  constexpr ModT inverse() const { return details::inverse<ModT>(*this); }

  uint32_t x;
};

} // namespace mod

template <uint32_t MOD>
std::ostream &operator<<(std::ostream &out, const mod::ModT<MOD> &mod) {
  return out << mod.get();
}
#line 2 "/home/ftiasch/Documents/shoka/ntt.h"

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
#line 4 "/home/ftiasch/Documents/shoka/ntt.h"

#include <algorithm>
#include <array>
#include <cassert>
#line 11 "/home/ftiasch/Documents/shoka/ntt.h"
#include <string>
#include <vector>

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
#line 2 "/home/ftiasch/Documents/shoka/poly.h"

#include <cstdlib>
#include <memory>
#line 7 "/home/ftiasch/Documents/shoka/poly.h"

template <typename Factory>
struct PolyT : public std::vector<typename Factory::Mod> {
  using Mod = typename Factory::Mod;
  using NTT = typename Factory::NTT;

  PolyT() = default;

  template <typename... Args>
  PolyT(std::shared_ptr<Factory> &&factory_, Args &&...args)
      : std::vector<Mod>(std::forward<Args>(args)...),
        factory(std::move(factory_)) {}

  int deg() const { return static_cast<int>(std::vector<Mod>::size()) - 1; }

  PolyT operator+(const PolyT &o) const {
    if (deg() < o.deg()) {
      return o + *this;
    }
    PolyT r = factory->make(*this);
    for (int i = 0; i <= o.deg(); ++i) {
      r[i] += o[i];
    }
    return r;
  }

  PolyT &operator+=(PolyT &o) { return *this = *this += o; }

  PolyT operator-(const PolyT &o) const {
    int max_deg = std::max(deg(), o.deg());
    PolyT r = factory->make(max_deg + 1);
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

  PolyT &operator-=(PolyT &o) { return *this = *this -= o; }

  PolyT operator*(const PolyT &o) const {
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

    int n = Factory::min_power_of_two(deg_plus_1);
    factory->reserve(n);
    Mod *b0 = factory->template raw_buffer<0>();
    Mod *b1 = factory->template raw_buffer<1>();
    Factory::copy_and_fill0(n, b0, *this);
    NTT::dif(n, b0);
    Factory::copy_and_fill0(n, b1, o);
    NTT::dif(n, b1);
    Factory::dot_product_and_dit(n, Mod(n).inverse(), b0, b0, b1);
    return factory->make(std::vector<Mod>(b0, b0 + deg_plus_1));
  }

  PolyT &operator*=(const PolyT &o) { return *this = *this * o; }

  std::shared_ptr<Factory> factory;
};

template <typename NTT_>
struct PolyFactory : std::enable_shared_from_this<PolyFactory<NTT_>> {
  static const size_t NUMBER_OF_BUFFER = 5;

  using NTT = NTT_;
  using Mod = typename NTT::Mod;
  using Poly = PolyT<PolyFactory>;

  static std::shared_ptr<PolyFactory> create() {
    return std::shared_ptr<PolyFactory>(new PolyFactory());
  }

  template <typename... Args> Poly make(Args &&...args) {
    PolyT p{std::enable_shared_from_this<PolyFactory>::shared_from_this(),
            std::forward<Args>(args)...};
    return p;
  }

  static void assert_power_of_two(int n) {
    if (n & (n - 1)) {
      throw std::invalid_argument(std::to_string(n) + " is not a power of two");
    }
  }

  static int min_power_of_two(int n) {
    return n == 1 ? 1 : 1 << (32 - __builtin_clz(n - 1));
  }

  void reserve(int n) {
    if (buffer[0].size() < n) {
      for (int i = 0; i < NUMBER_OF_BUFFER; ++i) {
        buffer[i].resize(n);
      }
    }
  }

  template <int index> Mod *raw_buffer() {
    static_assert(0 <= index && index < NUMBER_OF_BUFFER);
    return buffer[index].data();
  }

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

protected:
  PolyFactory() = default;

private:
  std::array<std::vector<Mod>, NUMBER_OF_BUFFER> buffer;
};
#line 4 "/tmp/tmp-1173430GBUuMuIk5cBJ.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

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

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T, typename Compare = std::less<T>>
struct PQ : public std::priority_queue<T, std::vector<T>, Compare> {
  T pop() {
    using Base = std::priority_queue<T, std::vector<T>, Compare>;
    auto t = Base::top();
    Base::pop();
    return t;
  }
};
#line 6 "/tmp/tmp-1173430GBUuMuIk5cBJ.cpp"

using Mod = mod::ModT<998'244'353>;
using NTT = ntt::NTT<Mod>;
using Factory = PolyFactory<NTT>;
using Poly = Factory::Poly;

int main() {
  IO io;
  int n = io.read();
  int m = io.read();
  int f = io.read();
  auto factory = Factory::create();
  auto dp = factory->make(f + 2);
  // [0, m]
  for (int i = 0; i <= f; ++i) {
    dp[i] = i <= m ? Mod{1} : Mod{0};
  }
  dp[f + 1] = Mod(std::max(m - f, 0));
  for (int _ = 1; _ < n; ++_) {
    auto dp2 = dp * dp;
    dp = factory->make(f + 2);
    Mod sufsum{0};
    for (int i = f + 1; i < dp2.size(); ++i) {
      sufsum += dp2[i];
    }
    dp[f + 1] = sufsum * Mod(std::max(m - f, 0));
    for (int i = f; i >= 0; --i) {
      if (i <= m) {
        dp[i] += dp2[i] * Mod(m - i + 1) + sufsum;
      }
      sufsum += dp2[i];
    }
  }
  auto dp2 = dp * dp;
  std::cout << dp2[f] << "\n";
}