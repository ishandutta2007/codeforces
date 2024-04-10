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
#line 2 "/tmp/tmp-300543PwzEJUXSbEx7.cpp"

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

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-300543PwzEJUXSbEx7.cpp"

using Mod = mod::ModT<1'000'000'007>;

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<int> q(n);
    for (int i = 0; i < n; ++i) {
      q[io.read()] = i;
    }
    Mod result{1};
    int l = q[0], r = q[0];
    for (int i = 1; i < n; ++i) {
      if (q[i] < l) {
        l = q[i];
      } else if (r < q[i]) {
        r = q[i];
      } else {
        result *= Mod(r - l + 1 - i);
      }
    }
    std::cout << result << "\n";
  }
}