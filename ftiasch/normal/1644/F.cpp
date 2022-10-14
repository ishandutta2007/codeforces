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
#line 2 "sol.cpp"
// #include "debug.h"
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
  return out << mod.get();
}
#line 4 "sol.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<998'244'353>;

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  if (n == 1 || m == 1) {
    puts("1");
  } else {
    std::vector<ModT> derangement(m + 1);
    derangement[0] = ModT{1};
    derangement[1] = ModT{0};
    for (int i = 2; i <= m; ++i) {
      derangement[i] = ModT(i - 1) * (derangement[i - 2] + derangement[i - 1]);
    }
    Binom<ModT> binom(m + 1);
    std::vector<ModT> mu(n + 1);
    mu[1] = ModT{1};
    for (int i = 1; i <= n; ++i) {
      for (int j = i + i; j <= n; j += i) {
        mu[j] -= mu[i];
      }
    }
    ModT result{0};
    for (int d = 1; d <= n; ++d) {
      if (mu[d].get()) {
        ModT subtotal{0};
        int nn = (n + d - 1) / d;
        int mm = std::min(nn, m);
        for (int k = 1; k <= mm; ++k) {
          subtotal += binom(mm, k) * derangement[mm - k] * ModT(k).power(nn);
        }
        subtotal *= binom.inv_fact[mm];
        subtotal -= ModT{1};
        result += mu[d] * subtotal;
      }
    }
    printf("%d\n", result.get());
  }
}