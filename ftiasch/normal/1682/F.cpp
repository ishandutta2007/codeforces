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
#line 2 "F_MCMF.cpp"

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
#line 4 "F_MCMF.cpp"

using Mod = mod::ModT<1'000'000'007>;

struct Fenwick : std::vector<Mod> {
  Fenwick(int n) : n(n), std::vector<Mod>(n) {}

  void add(int i, Mod v) {
    for (; ~i; i -= ~i & i + 1) {
      (*this)[i] += v;
    }
  }

  Mod ask(int i) {
    Mod result{0};
    for (; i < n; i += ~i & i + 1) {
      result += (*this)[i];
    }
    return result;
  }

  Mod ask(int l, int r) { return ask(l) - ask(r); }

  int n;
};

int main() {
  IO io;
  int n = io.read();
  int q = io.read();
  auto a = io.read_vector(n);
  std::vector<Mod> d(n - 1);
  for (int i = 0; i + 1 < n; ++i) {
    d[i] = Mod(a[i + 1] - a[i]);
  }
  auto b = io.read_vector(n);
  std::vector<Long> s_int(n);
  std::vector<Mod> s(n);
  s_int[0] = 1'000'000'000LL * n;
  s[0] = Mod::normalize(s_int[0]);
  for (int i = 1; i < n; ++i) {
    s_int[i] = s_int[i - 1] + b[i - 1];
    s[i] = Mod::normalize(s_int[i]);
  }
  std::vector<Mod> sum_d(n), sum_ds(n);
  for (int i = n - 2; i >= 0; --i) {
    sum_d[i] = d[i] + sum_d[i + 1];
    sum_ds[i] = d[i] * s[i + 1] + sum_ds[i + 1];
  }
  std::vector<Mod> result(q);
  std::vector<std::tuple<Long, int, int, int>> queries(q);
  for (int i = 0; i < q; ++i) {
    int l = io.read() - 1;
    int r = io.read() - 1;
    queries[i] = {s_int[l], l, r, i};
    result[i] = (sum_ds[l] - sum_ds[r]) - (sum_d[l] - sum_d[r]) * s[l];
  }
  std::sort(ALL(queries));
  std::vector<std::pair<Long, int>> events(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    events[i] = {s_int[i + 1], i};
  }
  std::sort(ALL(events));
  auto iterator = events.begin();
  Fenwick f_d(n), f_ds(n);
  for (auto [query_s, l, r, id] : queries) {
    while (iterator != events.end() && iterator->first <= query_s) {
      int i = iterator->second;
      f_d.add(i, d[i]);
      f_ds.add(i, d[i] * s[i + 1]);
      iterator++;
    }
    result[id] += Mod{2} * (f_d.ask(l, r) * s[l] - f_ds.ask(l, r));
  }
  for (int i = 0; i < q; ++i) {
    std::cout << result[i] << "\n";
  }
}