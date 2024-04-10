#line 1 "/home/ftiasch/Documents/shoka/fixed_size_matrix.h"
#include <array>
#include <cstring>
#include <vector>

template <typename T, size_t N> struct FixedSizeMatrixT {
  FixedSizeMatrixT() { memset(data, 0, sizeof(data)); }

  T *operator[](int i) { return data[i]; }

  const T *operator[](int i) const { return data[i]; }

  FixedSizeMatrixT &operator+=(const FixedSizeMatrixT &o) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        data[i][j] += o[i][j];
      }
    }
    return *this;
  }

  FixedSizeMatrixT operator+(const FixedSizeMatrixT &o) {
    return FixedSizeMatrixT(*this) += o;
  }

  FixedSizeMatrixT &operator-=(const FixedSizeMatrixT &o) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        data[i][j] -= o[i][j];
      }
    }
    return *this;
  }

  FixedSizeMatrixT operator-(const FixedSizeMatrixT &o) {
    return FixedSizeMatrixT(*this) -= o;
  }

  FixedSizeMatrixT operator*(const FixedSizeMatrixT &o) {
    static T buffer[N];
    FixedSizeMatrixT result;
    for (int j = 0; j < N; ++j) {
      for (int i = 0; i < N; ++i) {
        buffer[i] = o[i][j];
      }
      for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
          result[i][j] += data[i][k] * buffer[k];
        }
      }
    }
    return result;
  }

private:
  T data[N][N];
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
  return out << mod.x;
}
#line 3 "sol.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<1'000'000'007>;
using Matrix = FixedSizeMatrixT<ModT, 3>;

using Long = long long;

int main() {
  int n;
  Long m;
  scanf("%d%lld", &n, &m);
  std::vector<std::tuple<Long, int, int>> events;
  events.emplace_back(1, 0, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    Long l, r;
    scanf("%d%lld%lld", &a, &l, &r);
    events.emplace_back(l - 1, a - 1, 1);
    events.emplace_back(r, a - 1, -1);
  }
  events.emplace_back(m, 0, 0);
  std::sort(events.begin(), events.end());
  std::array<int, 3> count{};
  Matrix result{};
  result[0][1] = ModT{1};
  for (size_t i = 0; i + 1 < events.size(); ++i) {
    auto [_, a, delta] = events[i];
    count[a] += delta;
    Matrix t{};
    for (int x = 0; x < 3; ++x) {
      for (int y = std::max(x - 1, 0); y <= std::min(x + 1, 2); ++y) {
        if (!count[y]) {
          t[x][y] = ModT{1};
        }
      }
    }
    Long length = std::get<0>(events[i + 1]) - std::get<0>(events[i]);
    while (length) {
      if (length & 1) {
        result = result * t;
      }
      length >>= 1;
      t = t * t;
    }
  }
  printf("%d\n", result[0][1].get());
}