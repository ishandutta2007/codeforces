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
#line 2 "/tmp/tmp-218387btzQ8wsehfe.cpp"

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
#line 4 "/tmp/tmp-218387btzQ8wsehfe.cpp"

using Mod = mod::ModT<998'244'353>;

int main() {
  IO io;
  int T = io.read();
  std::vector<std::tuple<int, int, int>> tests(T);
  int max_k = 0;
  for (int i = 0; i < T; ++i) {
    int n = io.read();
    int m = io.read();
    int k = io.read();
    tests[i] = {n, m, k};
    max_k = std::max(max_k, k);
  }
  std::vector<std::vector<Mod>> stirling(max_k + 1,
                                         std::vector<Mod>(max_k + 1));
  stirling[0][0] = Mod{1};
  for (int i = 1; i <= max_k; ++i) {
    for (int j = 1; j <= i; ++j) {
      stirling[i][j] = stirling[i - 1][j - 1] + stirling[i - 1][j] * Mod(j);
    }
  }
  for (auto [n, m, k] : tests) {
    Mod result{0}, pow_o{1}, o = Mod((m + 1) / 2), binom{1},
                             mod_m = Mod::normalize(m);
    std::vector<Mod> pow_m(std::min(n, k) + 1);
    pow_m[std::min(n, k)] = mod_m.power(n - std::min(n, k));
    for (int i = std::min(n, k); i--;) {
      pow_m[i] = pow_m[i + 1] * mod_m;
    }
    for (int t = 0; t <= n && t <= k; ++t) {
      result += stirling[k][t] * binom * pow_o * pow_m[t];
      binom *= Mod::normalize(n - t);
      pow_o *= o;
    }
    std::cout << result << "\n";
  }
}