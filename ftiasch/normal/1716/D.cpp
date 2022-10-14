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
#line 2 "/tmp/tmp-21838wWj7hqzspnMP.cpp"

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

template <typename T> using MinPQ = PQ<T, std::greater<T>>;
#line 4 "/tmp/tmp-21838wWj7hqzspnMP.cpp"

using Mod = mod::ModT<998'244'353>;

int main() {
  IO io;
  int n = io.read();
  int k = io.read();
  std::vector<Mod> dp(n + 1), buffer(n + 1), result(n + 1);
  dp[0] = Mod{1};
  int m = 0;
  while (m < n) {
    dp.swap(buffer);
    for (int i = 0; i < k; ++i) {
      dp[i] = Mod{0};
    }
    for (int i = k; i <= n; ++i) {
      dp[i] = dp[i - k] + buffer[i - k];
      result[i] += dp[i];
    }
    m += k;
    k++;
  }
  for (int i = 1; i <= n; ++i) {
    std::cout << result[i] << " \n"[i == n];
  }
}