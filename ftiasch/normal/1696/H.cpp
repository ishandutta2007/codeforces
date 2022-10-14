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
#line 2 "/tmp/tmp-262300emXyJ83V0GSv.cpp"

#include <bits/stdc++.h>

using Mod = mod::ModT<1'000'000'007>;

const int N = 600;

bool by_abs(int x, int y) { return std::abs(x) > std::abs(y); }

int n, l, a[N];

Mod to_mod(int i) {
  if (~i) {
    return a[i] < 0 ? Mod(a[i] + Mod::MOD) : Mod(a[i]);
  }
  return Mod{1};
}

namespace prefix {

Mod dp[N][N + 1][2], dsum[2][N][2], ssum[2][N + 1][2];

void prepare() {
  for (int i = 0; i < n; ++i) {
    dp[i][0][a[i] < 0] = Mod{1};
  }
  // dp[k][i][j][nc]
  // --> dp[k + 1][i'][j][nc ^ (a[i' - 1] < 0)] if a[i - 1] * a[i' - 1] > 0
  // --> dp[k + 1][i'][i][nc ^ (a[i' - 1] < 0)] otherwise
  std::vector<int> indices[]{{-1}, {-1}};
  for (int i = 0; i < n; ++i) {
    indices[a[i] < 0].push_back(i);
  }
  for (int _ = 1; _ < l; ++_) {
    memset(dsum, 0, sizeof(dsum));
    for (int i = 0; i < n; ++i) {
      int t = a[i] < 0;
      for (int j : indices[t ^ 1]) {
        if (j >= i) {
          break;
        }
        dsum[t][i][0] += dp[i][j + 1][0] * to_mod(j);
        dsum[t][i][1] += dp[i][j + 1][1] * to_mod(j);
      }
    }
    memset(ssum, 0, sizeof(ssum));
    for (int i = 0; i < n; ++i) {
      int t = a[i] < 0;
      for (int j : indices[t ^ 1]) {
        if (j >= i) {
          break;
        }
        Mod old_dp_0 = dp[i][j + 1][0];
        Mod old_dp_1 = dp[i][j + 1][1];
        dp[i][j + 1][0] = ssum[t][j + 1][t];
        dp[i][j + 1][1] = ssum[t][j + 1][1 ^ t];
        if (~j) {
          dp[i][j + 1][0] += dsum[t ^ 1][j][t];
          dp[i][j + 1][1] += dsum[t ^ 1][j][1 ^ t];
        }
        ssum[t][j + 1][0] += old_dp_0 * to_mod(i);
        ssum[t][j + 1][1] += old_dp_1 * to_mod(i);
      }
    }
  }
}

} // namespace prefix

namespace all_negatives {

Mod dp[N + 1];

Mod count() {
  dp[0] = Mod{1};
  for (int i = n; i--;) {
    if (a[i] < 0) {
      for (int j = n; j >= 1; --j) {
        dp[j] += dp[j - 1] * (j <= l ? to_mod(i) : Mod{1});
      }
    }
  }
  Mod result{0};
  for (int j = l; j <= n; ++j) {
    result += dp[j];
  }
  return result;
}

} // namespace all_negatives

Mod dp[2][N + 1][N + 1], power_of_two[N];

int main() {
  scanf("%d%d", &n, &l);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n, by_abs);
  prefix::prepare();
  power_of_two[0] = Mod{1};
  for (int i = 1; i < n; ++i) {
    power_of_two[i] = power_of_two[i - 1] * Mod{2};
  }
  Mod result{0};
  dp[n & 1][n][n] = Mod{1};
  for (int i = n; i--;) {
    for (int j = -1; j < i; ++j) {
      result += prefix::dp[i][j + 1][0] * to_mod(i) * to_mod(j) *
                power_of_two[n - 1 - i];
    }
    // j == -1
    if (a[i] < 0) {
      // only negatives
      Mod prefix_dp = prefix::dp[i][0][1];
      for (int p = i + 1; p < n; ++p) {
        Mod subtotal{0};
        for (int q = i + 1; q <= n; ++q) {
          subtotal += dp[(i + 1) & 1][p][q];
        }
        result += prefix::dp[i][0][1] * to_mod(p) * subtotal;
      }
    }
    for (int j = 0; j < i; ++j) {
      int prefix_p = a[i] >= 0 ? i : j;
      int prefix_q = a[i] >= 0 ? j : i;
      Mod prefix_dp = prefix::dp[i][j + 1][1];
      Mod subtotal{0};
      // a[j] < 0
      result += prefix_dp * to_mod(prefix_p) * to_mod(prefix_q);
      // only positives
      {
        Mod subtotal{0};
        for (int p = i + 1; p < n; ++p) {
          // dp[(i + 1) & 1][p][n]
          subtotal += to_mod(p) * dp[(i + 1) & 1][p][n];
        }
        result += prefix_dp * to_mod(prefix_p) * subtotal;
      }
      // only negatives
      {
        Mod subtotal{0};
        for (int q = i + 1; q < n; ++q) {
          // dp[(i + 1) & 1][n][q]
          subtotal += to_mod(q) * dp[(i + 1) & 1][n][q];
        }
        result += prefix_dp * to_mod(prefix_q) * subtotal;
      }
    }
    if (a[i] >= 0) {
      // for (int j = 0; j < i; ++j) {
      //   for (int p = i + 1; p < n; ++p) {
      //     for (int q = i + 1; q < n; ++q) {
      //       if (static_cast<long long>(a[i]) * a[p] >=
      //           static_cast<long long>(a[j]) * a[q]) {
      //         result += prefix::dp[i][j + 1][1] * to_mod(i) * to_mod(p) *
      //                   dp[(i + 1) & 1][p][q];
      //       } else {
      //         result += prefix::dp[i][j + 1][1] * to_mod(j) * to_mod(q) *
      //                   dp[(i + 1) & 1][p][q];
      //       }
      //     }
      //   }
      // }
      for (int p = i + 1; p < n; ++p) {
        Mod sum0{0}, sum1{0};
        for (int q = i + 1; q < n; ++q) {
          if (a[q] < 0) {
            sum1 += to_mod(q) * dp[(i + 1) & 1][p][q];
          }
        }
        int q = n;
        for (int j = 0; j < i; ++j) {
          if (a[j] < 0) {
            while (i < q - 1 && (a[q - 1] >= 0 ||
                                 static_cast<long long>(a[i]) * a[p] >=
                                     static_cast<long long>(a[j]) * a[q - 1])) {
              q--;
              if (a[q] < 0) {
                sum0 += dp[(i + 1) & 1][p][q];
                sum1 -= to_mod(q) * dp[(i + 1) & 1][p][q];
              }
            }
            result += prefix::dp[i][j + 1][1] *
                      (to_mod(i) * to_mod(p) * sum0 + to_mod(j) * sum1);
          }
        }
      }

    } else {
      // for (int j = 0; j < i; ++j) {
      //   for (int p = i + 1; p < n; ++p) {
      //     for (int q = i + 1; q < n; ++q) {
      //       if (static_cast<long long>(a[j]) * a[p] >=
      //           static_cast<long long>(a[i]) * a[q]) {
      //         result += prefix::dp[i][j + 1][1] * to_mod(j) * to_mod(p) *
      //                   dp[(i + 1) & 1][p][q];
      //       } else {
      //         result += prefix::dp[i][j + 1][1] * to_mod(i) * to_mod(q) *
      //                   dp[(i + 1) & 1][p][q];
      //       }
      //     }
      //   }
      // }
      for (int p = i + 1; p < n; ++p) {
        Mod sum0{0}, sum1{0};
        for (int q = i + 1; q < n; ++q) {
          if (a[q] < 0) {
            sum0 += dp[(i + 1) & 1][p][q];
          }
        }
        int q = i + 1;
        for (int j = 0; j < i; ++j) {
          if (a[j] > 0) {
            while (q < n &&
                   (a[q] >= 0 || static_cast<long long>(a[j]) * a[p] <
                                     static_cast<long long>(a[i]) * a[q])) {
              if (a[q] < 0) {
                sum0 -= dp[(i + 1) & 1][p][q];
                sum1 += to_mod(q) * dp[(i + 1) & 1][p][q];
              }
              q++;
            }
            result += prefix::dp[i][j + 1][1] *
                      (to_mod(j) * to_mod(p) * sum0 + to_mod(i) * sum1);
          }
        }
      }
    }
    memset(dp[i & 1], 0, sizeof(dp[i & 1]));
    for (int p = i + 1; p <= n; ++p) {
      for (int q = i + 1; q <= n; ++q) {
        Mod old = dp[(i + 1) & 1][p][q];
        if (old.get()) {
          dp[i & 1][p][q] += old;
          if (a[i] >= 0) {
            dp[i & 1][i][q] += old;
          } else {
            dp[i & 1][p][i] += old;
          }
        }
      }
    }
  }
  if (l & 1) {
    result += all_negatives::count();
  }
  printf("%d\n", result.get());
}