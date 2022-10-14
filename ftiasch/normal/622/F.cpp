#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

namespace {

template <typename Tuple, size_t... Index>
std::ostream &serialize_tuple(std::ostream &out, const Tuple &t,
                              std::index_sequence<Index...>) {
  out << "(";
  (..., (out << (Index == 0 ? "" : ", ") << std::get<Index>(t)));
  return out << ")";
}

} // namespace

template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}

template <typename... T>
std::ostream &operator<<(std::ostream &out, const std::tuple<T...> &t) {
  return serialize_tuple(out, t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<T, N> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T, typename S, typename C>
std::ostream &operator<<(std::ostream &out, std::priority_queue<T, S, C> pq) {
  std::vector<T> v;
  while (!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  return out << v;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}

#define KV(x) #x << "=" << x << ";"
#line 2 "sol.cpp"

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

#line 5 "/home/ftiasch/Documents/shoka/mod.h"
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
  return out << mod.get();
}
#line 2 "/home/ftiasch/Documents/shoka/polynomial_interpolation.h"

template <typename ModT> struct PolynomialInterpolation {
  PolynomialInterpolation(int maxd) : inverse(maxd) {
    inverse[1] = ModT{1};
    for (int i = 2; i < maxd; ++i) {
      inverse[i] = ModT(ModT::MOD - ModT::MOD / i) * inverse[ModT::MOD % i];
    }
  }

  ModT operator()(std::vector<ModT> values, ModT n) const {
    int d = static_cast<int>(values.size()) - 1;
    // d < maxd
    {
      ModT b{1};
      for (int i = 1; i <= d; ++i) {
        b = b * (n - ModT(i - 1)) * inverse[i];
        values[i] *= b;
      }
    }
    ModT result = values[d];
    {
      ModT b{1};
      for (int i = d - 1; i >= 0; --i) {
        b = (ModT{0} - b) * inverse[d - i] * (n - ModT(i + 1));
        result += values[i] * b;
      }
    }
    return result;
  }

  std::vector<ModT> inverse;
};
#line 5 "sol.cpp"

#include <bits/stdc++.h>

using ModT = mod::ModT<1'000'000'007>;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  // compute S(0), S(1), ..., S(k)
  std::vector<ModT> s(k + 2);
  for (int i = 1; i <= k + 1; ++i) {
    s[i] = s[i - 1] + ModT(i).power(k);
  }
  PolynomialInterpolation<ModT> interpolate(k + 2);
  printf("%d\n", interpolate(s, ModT(n)).get());
}