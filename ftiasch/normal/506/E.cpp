#include <bits/stdc++.h>

namespace mod {

using u64 = uint64_t;
using u32 = uint32_t;

template <u32 M> struct ModT {
  static const u32 MOD = M;

  explicit constexpr ModT(u32 x = 0) : x(x) {}

  const u32 get() const { return x; }

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
    x = static_cast<u64>(x) * other.x % MOD;
    return *this;
  }

  constexpr ModT operator*(const ModT &other) const {
    ModT copy = *this;
    return copy *= other;
  }

private:
  u32 x;
};

template <int RBIT, typename Digit, Digit M, typename Derived>
struct MontgomeryT {
  static const Digit MOD = M;

  static_assert(MOD <= std::numeric_limits<Digit>::max() >> 2,
                "4 * MOD <= MAX");

  explicit constexpr MontgomeryT(Digit x = 0)
      : x(Derived::mont_multiply(x, R2)) {}

  constexpr Digit get() const {
    Digit y = Derived::reduce(x);
    if (y >= MOD) {
      y -= MOD;
    }
    return y;
  }

  constexpr MontgomeryT &operator+=(const MontgomeryT &other) {
    x += other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr MontgomeryT operator+(const MontgomeryT &other) const {
    MontgomeryT copy = *this;
    return copy += other;
  }

  constexpr MontgomeryT &operator-=(const MontgomeryT &other) {
    x += MOD2 - other.x;
    if (x >= MOD2) {
      x -= MOD2;
    }
    return *this;
  }

  constexpr MontgomeryT operator-(const MontgomeryT &other) const {
    MontgomeryT copy = *this;
    return copy -= other;
  }

  constexpr MontgomeryT operator*=(const MontgomeryT &other) {
    x = Derived::mont_multiply(x, other.x);
    return *this;
  }

  constexpr MontgomeryT operator*(const MontgomeryT &other) const {
    MontgomeryT copy = *this;
    return copy *= other;
  }

private:
  static constexpr Digit rpower(int n) {
    Digit result = 1;
    for (int i = 0; i < n; ++i) {
      result += result;
      if (result >= MOD) {
        result -= MOD;
      }
    }
    return result;
  }

  static const Digit MOD2 = MOD << 1;
  static const Digit R = rpower(RBIT);
  static const Digit R2 = rpower(RBIT << 1);

public:
  Digit x;
};

template <typename Digit> static constexpr Digit modinv(Digit MOD, int n) {
  Digit result = 1;
  for (int i = 0; i < n; ++i) {
    result *= 2 - MOD * result;
  }
  return -result;
}

template <u32 MOD> struct Montgomery32Impl {
  static constexpr u32 mont_multiply(u32 x, u32 y) {
    return reduce(static_cast<u64>(x) * y);
  }

  static constexpr u32 reduce(u32 x) { return reduce(static_cast<u64>(x)); }

  static constexpr u64 reduce(u64 x) {
    u64 y = (((x & UINT32_MAX) * INV) & UINT32_MAX) * MOD;
    return (x + y) >> 32U;
  }

  static const u32 INV = modinv<u32>(MOD, 5);
};

template <u32 MOD>
using Montgomery32T = MontgomeryT<32, u32, MOD, Montgomery32Impl<MOD>>;

template <typename Mod> static Mod pow(Mod a, u64 n) {
  Mod result{1};
  while (n) {
    if (n & 1) {
      result *= a;
    }
    a *= a;
    n >>= 1;
  }
  return result;
}

template <typename Mod> static Mod inv(Mod a) { return pow(a, Mod::MOD - 2); }

} // namespace mod

// using Mod = mod::Montgomery32T<10007>;
using Mod = mod::ModT<10007>;

using Matrix = std::vector<std::vector<Mod>>;

Matrix matrix(int m, int n) { return Matrix(m, std::vector<Mod>(n)); }

Matrix mat_mul(int n, const Matrix &a, const Matrix &b) {
  Matrix result = matrix(n, n);
  std::vector<Mod> column(n);
  for (int j = 0; j < n; ++j) {
    for (int k = 0; k <= j; ++k) {
      column[k] = b[k][j];
    }
    for (int i = 0; i <= j; ++i) {
      uint64_t sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += a[i][k].get() * column[k].get();
      }
      result[i][j] = Mod(sum % Mod::MOD);
    }
  }
  return result;
}

Matrix mat_pow(int dim, Matrix a, uint64_t n) {
  Matrix result = matrix(dim, dim);
  for (int i = 0; i < dim; ++i) {
    result[i][i] = Mod{1};
  }
  while (n) {
    if (n & 1) {
      result = mat_mul(dim, result, a);
    }
    a = mat_mul(dim, a, a);
    n >>= 1;
  }
  return result;
}

struct Pair {
  int a, b;
  Mod count;
};

int main() {
  std::string s;
  int n;
  std::cin >> s >> n;
  const int m = s.length();
  n += m;

  const int mb = (m + 1) >> 1;
  const int half = (n + 1) >> 1;
  Matrix n_count = matrix(m + 1, mb + 1);
  Matrix n_minus_1_count = matrix(m + 1, mb + 1);
  std::vector<Pair> n_pairs, n_minus_1_pairs;
  {
    std::vector<std::vector<std::vector<Mod>>> dp(
        m + 1, std::vector<std::vector<Mod>>(m + 1, std::vector<Mod>(mb + 2)));
    dp[0][m][0] = Mod{1}; // [l, r)
    for (int i = 0; i < m; ++i) {
      for (int j = m; j > i; --j) {
        for (int b = 0; b <= (m - (j - i)) >> 1; ++b) {
          const Mod count = dp[i][j][b];
          int a = m - (j - i) - 2 * b;
          if (s[i] == s[j - 1]) {
            dp[i + 1][j - 1][b + 1] += dp[i][j][b];
            n_count[a][b + 1] += count;
            if ((n & 1) && i + 2 == j) {
              n_minus_1_count[a][b + 1] += count;
            }
          } else {
            dp[i + 1][j][b] += dp[i][j][b];
            dp[i][j - 1][b] += dp[i][j][b];
            n_count[a + 1][b] += count;
          }
        }
      }
    }
  }
  const int dim = m + mb;
  Matrix digraph = matrix(dim, dim);
  for (int i = 0; i < m; ++i) {
    digraph[i][i] = Mod{24};
    if (i + 1 < m) {
      digraph[i][i + 1] = Mod{1};
    }
  }
  digraph[m - 1][m] = Mod{1};
  for (int i = 0; i < mb; ++i) {
    digraph[m + i][m + i] = Mod{25};
    if (i + 1 < mb) {
      digraph[m + i][m + i + 1] = Mod{1};
    }
  }
  Matrix pow_n_minus_1 = mat_pow(dim, digraph, half - 1);
  Matrix pow_n = mat_mul(dim, digraph, pow_n_minus_1);
  Mod result = mod::pow(Mod{26}, half);
  for (int a = 0; a <= m; ++ a) {
    for (int b = 0; b <= mb; ++ b) {
      result -= n_minus_1_count[a][b] * pow_n_minus_1[m - a][m - 1 + b];
      result -= n_count[a][b] * pow_n[m - a][m - 1 + b];
    }
  }
  std::cout << result.get() << std::endl;
}