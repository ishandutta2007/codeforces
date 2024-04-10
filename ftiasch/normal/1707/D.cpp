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
#line 2 "/home/ftiasch/Documents/shoka/nd_vector.h"

template <typename T, int N> struct NDVector {
  using Nested = NDVector<T, N - 1>;
  using Vector = std::vector<typename Nested::Vector>;

  template <typename... Args> static Vector create(int n, Args &&...args) {
    return Vector(n, Nested::create(std::forward<Args>(args)...));
  }
};

template <typename T> struct NDVector<T, 1> {
  using Vector = std::vector<T>;

  template <typename... Args> static Vector create(Args &&...args) {
    return Vector(std::forward<Args>(args)...);
  }
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
#line 2 "/home/ftiasch/Documents/shoka/non_const_mod.h"

#define DECLARE_NON_CONST_MODT(name)                                           \
  using name = mod::ModT<0>;                                                   \
  uint32_t name::MOD

namespace mod {

template <> struct ModT<0> {
  static uint32_t MOD;

  explicit ModT(uint32_t x_ = 0) : x(x_) {}

  uint32_t get() const { return x; }

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
    x = static_cast<uint64_t>(x) * static_cast<uint64_t>(other.x) % MOD;
    return *this;
  }

  ModT operator*(const ModT &other) const {
    ModT copy = *this;
    return copy *= other;
  }

  ModT<0> power(uint64_t n) const {
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

  uint32_t x;
};

} // namespace mod
#line 1 "/home/ftiasch/Documents/shoka/y_combinator.h"
#include <functional>

// Authored by ecnerwala

namespace details {

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

} // namespace details

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return details::y_combinator_result<std::decay_t<Fun>>(
      std::forward<Fun>(fun));
}
#line 5 "/tmp/tmp-1282031fqDRFozdcI5g.cpp"

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
#line 7 "/tmp/tmp-1282031fqDRFozdcI5g.cpp"

// #include "debug.h"

DECLARE_NON_CONST_MODT(Mod);

int main() {
  IO io;
  int n = io.read();
  Mod::MOD = io.read();
  std::vector<std::vector<int>> tree(n);
  for (int i = 0; i < n - 1; ++i) {
    int a = io.read() - 1;
    int b = io.read() - 1;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  std::vector<int> order;
  y_combinator([&](auto dfs, int p, int u) -> void {
    if (~p) {
      tree[u].erase(std::find(ALL(tree[u]), p));
    }
    for (int v : tree[u]) {
      dfs(u, v);
    }
    order.push_back(u);
  })(-1, 0);
  auto dp = NDVector<Mod, 2>::create(n, n - 1, Mod{0});
  auto prefix = NDVector<Mod, 2>::create(n, n - 1, Mod{1});
  auto suffix = NDVector<Mod, 2>::create(n, n - 1, Mod{1});
  std::vector<Mod> osum(n);
  for (int u : order) {
    if (u) {
      int deg = tree[u].size();
      for (int m = 0; m < n - 1; ++m) {
        prefix[0][m] = suffix[deg][m] = Mod{1};
      }
      for (int i = 0; i < deg; ++i) {
        int v = tree[u][i];
        for (int m = 0; m < n - 1; ++m) {
          prefix[i + 1][m] = prefix[i][m] * dp[v][m];
        }
      }
      for (int i = deg; i--;) {
        int v = tree[u][i];
        for (int m = 0; m < n - 1; ++m) {
          suffix[i][m] = dp[v][m] * suffix[i + 1][m];
        }
      }
      {
        Mod sum{0};
        for (int m = 0; m < n - 1; ++m) {
          sum += suffix[0][m];
          dp[u][m] += (Mod{1} - Mod(deg)) * sum;
        }
      }
      {
        for (int i = 0; i < deg; ++i) {
          osum[i] = Mod{0};
        }
        for (int m = 0; m < n - 1; ++m) {
          for (int i = 0; i < deg; ++i) {
            int v = tree[u][i];
            osum[i] += prefix[i][m] * suffix[i + 1][m];
            dp[u][m] += dp[v][m] * osum[i];
          }
        }
      }
    } else {
      std::fill(ALL(dp[0]), Mod{1});
      for (int v : tree[u]) {
        for (int m = 0; m < n - 1; ++m) {
          dp[0][m] *= dp[v][m];
        }
      }
    }
  }
  Binom<Mod> binom(n);
  std::vector<Mod> result(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    result[i] = dp[0][i];
    for (int j = 0; j < i; ++j) {
      result[i] -= binom(i + 1, j + 1) * result[j];
    }
    std::cout << result[i] << " \n"[i + 2 == n];
  }
}