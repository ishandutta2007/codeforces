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
#line 2 "E_Colorings_and_Dominoes.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<998244353>;

using Grid = std::vector<std::vector<char>>;

ModT solve(int n, int m, int w, const Grid &grid) {
  std::vector<ModT> pre(m + 1);
  for (int count = 3; count <= m; ++count) {
    if (count & 1) {
      pre[count] = pre[count - 2] + ModT(2).power(w - count);
    } else {
      pre[count] = pre[count - 2] + ModT(2).power(w - (count - 1));
      // for (int j = 1; j <= count / 2 - 1; ++ j) {
      //     pre[count] += ModT(2).power(w - (2 * j + 1));
      // }
      // pre[count] += ModT(2).power(w - count);
    }
  }
  for (int count = 2; count <= m; count += 2) {
    pre[count] += ModT(2).power(w - count);
  }
  ModT result(0);
  for (int i = 0; i < n; ++i) {
    int count = 0;
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'o') {
        count++;
      } else {
        count = 0;
      }
      result += pre[count];
    }
  }
  return result;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Grid grid(n, std::vector<char>(m));
  int w = 0;
  std::vector<char> buffer(m + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer.data());
    std::copy(buffer.begin(), buffer.begin() + m, grid[i].begin());
    w += std::count(grid[i].begin(), grid[i].end(), 'o');
  }
  ModT result = solve(n, m, w, grid);
  Grid tgrid(m, std::vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tgrid[j][i] = grid[i][j];
    }
  }
  printf("%d\n", (result + solve(m, n, w, tgrid)).get());
}