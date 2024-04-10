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
    return k < 0 || k > n ? ModT(1) : fact[n] * inv_fact[n - k] * inv_fact[k];
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
#line 4 "sol.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<998'244'353>;

const int N = 300'001;
const int M = 20;

int n, m, lower_bound[N], upper_bound[N], a[M], b[M], count[N], sum[N];
ModT csum[N][(M << 1) + 1];

void dfs(int i, int l, int r, int parity, int number) {
  if (i < m) {
    dfs(i + 1, l, r, parity, number);
    count[a[i]]++;
    count[b[i]]++;
    dfs(i + 1, std::max({l, lower_bound[a[i]], lower_bound[b[i]]}),
        std::min({r, upper_bound[a[i]], upper_bound[b[i]]}), parity ^ 1,
        number + (count[a[i]] == 1) + (count[b[i]] == 1));
    count[a[i]]--;
    count[b[i]]--;
  } else if (l <= r) {
    ModT mu = parity ? ModT(ModT::MOD - 1) : ModT(1);
    // std::cout << KV(l) << KV(r) << KV(number) << KV(parity) << std::endl;
    csum[r][number] += mu;
    csum[l - 1][number] -= mu;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", lower_bound + i, upper_bound + i);
    sum[upper_bound[i]]++;
    sum[lower_bound[i] - 1]--;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", a + i, b + i);
  }
  dfs(0, 1, n, 0, 0);
  for (int i = n; i--;) {
    sum[i] += sum[i + 1];
    for (int j = 0; j <= m << 1; ++j) {
      csum[i][j] += csum[i + 1][j];
    }
  }
  Binom<ModT> binom(n + 1);
  ModT result{0};
  for (int k = 1; k <= n; ++k) {
    if (k <= sum[k]) {
      for (int c = 0; c <= (m << 1) && c <= k && c <= sum[k]; ++c) {
        if (csum[k][c].get()) {
          //   std::cout << KV(k) << KV(c) << KV(sum[k]) << csum[k][c].get()
          //             << std::endl;
        }
        result += csum[k][c] * binom(sum[k] - c, k - c);
      }
    }
  }
  printf("%d\n", result.get());
}