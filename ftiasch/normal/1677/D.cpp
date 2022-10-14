#line 1 "mod_details.h"



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


#line 2 "mod.h"

#line 4 "mod.h"
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
#line 1 "util.h"
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
#line 3 "/tmp/tmp-6960318e152ZQwM5dc.cpp"

#line 5 "/tmp/tmp-6960318e152ZQwM5dc.cpp"

using Mod = mod::ModT<998'244'353>;

Mod solve(int n, int k, const std::vector<int> &a) {
  for (int i = n - k; i < n; ++i) {
    if (a[i] > 0) {
      return Mod{0};
    }
  }
  Mod result{1};
  for (int i = 0; i < k; ++i) {
    result *= Mod(i + 1);
  }
  for (int i = k; i < n; ++i) {
    // 0 .. i
    if (!~a[i - k]) {
      result *= Mod(i + 1);
    } else if (!a[i - k]) {
      result *= Mod(std::min(i, k) + 1);
    } else if (a[i - k] + k > i) {
      return Mod{0};
    }
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int k = read();
    auto a = read_vector(n);
    std::cout << solve(n, k, a) << "\n";
  }
}