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
#line 3 "/home/ftiasch/Documents/shoka/util.h"

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::cin.sync_with_stdio(false); }

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
};
#line 4 "/tmp/tmp-453132L2aSc95YnsAx.cpp"

#include <bits/stdc++.h>

using Mod = mod::ModT<1'000'000'007>;

IO io;

struct Solve {
  Solve(int n) : parent(n), size(n), tree(n) {
    k = io.read();
    for (int i = 0; i < n - 1; ++i) {
      int a = io.read() - 1;
      int b = io.read() - 1;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    parent[0] = -1;
    prepare(0);
    Binom<Mod> binom(n + 1);
    for (int u = 0; u < n; ++u) {
      int p = parent[u];
      Mod csum{0};
      for (int v : tree[u]) {
        if (v != p) {
          csum += binom(size[v], k);
        }
      }
      for (int v : tree[u]) {
        if (v != p) {
          Mod up_ways = binom(n - size[v], k) - (csum - binom(size[v], k));
          if (~p) {
            up_ways -= binom(n - size[u], k);
          }
          result += Mod(size[v]) * Mod(n - size[v]) * up_ways;
        }
      }
      Mod down_ways = binom(size[u], k) - csum;
      result += Mod(n - size[u]) * Mod(size[u]) * down_ways;
      Mod all_ways = binom(n, k) - csum;
      if (~p) {
        all_ways -= binom(n - size[u], k);
      }
      result += Mod(n) * all_ways;
    }
  }

  void prepare(int u) {
    size[u] = 1;
    for (int v : tree[u]) {
      if (v != parent[u]) {
        parent[v] = u;
        prepare(v);
        size[u] += size[v];
      }
    }
  }

  int k;
  Mod result{0};
  std::vector<int> parent, size;
  std::vector<std::vector<int>> tree;
};

int main() {
  int n = io.read();
  std::cout << Solve(n).result << "\n";
}