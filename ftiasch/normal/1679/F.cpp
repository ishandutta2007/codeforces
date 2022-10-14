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
std::ostream &operator<<(std::ostream &out, const mod::ModT<MOD> &mod) {
  return out << mod.get();
}
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
#line 3 "/tmp/tmp-63715lXol65MHb0DC.cpp"

#line 5 "/tmp/tmp-63715lXol65MHb0DC.cpp"

using Mod = mod::ModT<998'244'353>;

const int D = 10;

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  std::vector<int> graph(D), smaller(D);
  {
    int m = read();
    while (m--) {
      int a = read();
      int b = read();
      if (a > b) {
        std::swap(a, b);
      }
      // a < b
      graph[a] |= 1 << b;
      graph[b] |= 1 << a;
      smaller[b] |= 1 << a;
    }
  }
  std::vector<Mod> dp(1 << D), new_dp(1 << D);
  dp[0] = Mod{1};
  while (n--) {
    std::ranges::fill(new_dp, Mod{0});
    for (int mask = 0; mask < 1 << D; ++mask) {
      for (int d = 0; d < D; ++d) {
        if ((mask & smaller[d]) == 0) {
          new_dp[(mask & graph[d]) | 1 << d] += dp[mask];
        }
      }
    }
    dp.swap(new_dp);
  }
  auto result = std::accumulate(ALL(dp), Mod{0});
  std::cout << result << "\n";
}