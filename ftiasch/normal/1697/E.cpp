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
#line 3 "E_Coloring.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 5 "E_Coloring.cpp"

using Mod = mod::ModT<998'244'353>;

int main() {
  IO io;
  int n = io.read();
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    x[i] = io.read();
    y[i] = io.read();
  }
  std::vector<std::vector<int>> d(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    d[i][i] = INT_MAX;
    for (int j = i + 1; j < n; ++j) {
      d[i][j] = d[j][i] = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
    }
  }
  std::vector<int> min_d(n);
  std::vector<std::vector<int>> neighbors(n);
  for (int i = 0; i < n; ++i) {
    min_d[i] = *std::min_element(ALL(d[i]));
    for (int j = 0; j < n; ++j) {
      if (d[i][j] == min_d[i]) {
        neighbors[i].push_back(j);
      }
    }
  }
  std::vector<int> cliques;
  std::vector<bool> isolated(n, true);
  for (int u = 0; u < n; ++u) {
    if (isolated[u] && neighbors[u].size() < 4) {
      bool valid = true;
      for (int x : neighbors[u]) {
        valid &=
            min_d[x] == min_d[u] && neighbors[x].size() == neighbors[u].size();
        for (int y : neighbors[u]) {
          if (x == y) {
            break;
          }
          valid &= d[x][y] == min_d[u];
        }
      }
      if (valid) {
        cliques.push_back(neighbors[u].size() + 1);
        isolated[u] = false;
        for (int x : neighbors[u]) {
          isolated[x] = false;
        }
      }
    }
    if (isolated[u]) {
      cliques.push_back(1);
    }
  }
  Binom<Mod> binom(n + 1);
  std::vector<Mod> dp(n + 1);
  dp[0] = Mod{1};
  for (int c : cliques) {
    for (int i = n; i >= 0; --i) {
      Mod subtotal{0};
      if (i) {
        subtotal += dp[i - 1] * Mod(n - (i - 1));
      }
      if (c > 1 && i >= c) {
        subtotal += dp[i - c] * binom.fact[n - (i - c)] * binom.inv_fact[n - i];
      }
      dp[i] = subtotal;
    }
  }
  std::cout << std::accumulate(ALL(dp), Mod{0}) << std::endl;
}