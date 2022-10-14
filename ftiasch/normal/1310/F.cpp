#include <bits/stdc++.h>

namespace nim {
using u64 = uint64_t;

template <int k, typename Out> struct Reducer {
  static_assert(k <= 6, "");

  u64 multiply(u64 a, u64 b) const {
    static const u64 P = 1ULL << (1 << k - 1);
    u64 a1 = a / P, a0 = a % P, b1 = b / P, b0 = b % P,
        c = out.multiply(a0, b0);
    return out.multiply(out.multiply(a1, b1), P / 2) ^
           (out.multiply(a0 ^ a1, b0 ^ b1) ^ c) * P ^ c;
  }

private:
  Out out;
};

template <int k> struct QuadraticMemorizedNim {
  static_assert(k <= 3, "");

  static const int N = 1 << (1 << k);

  QuadraticMemorizedNim() : table() {
    static Reducer<k, QuadraticMemorizedNim<k - 1>> out;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        table[i][j] = out.multiply(i, j);
      }
    }
  }

  u64 multiply(u64 a, u64 b) const { return table[a][b]; }

  u64 table[N][N];
};

template <> struct QuadraticMemorizedNim<0> {
  static const int N = 2;

  QuadraticMemorizedNim() {}

  u64 multiply(u64 a, u64 b) const { return a && b; }
};

// k == 4
template <u64 G> struct LinearMemorizedNim {
  static const int N = 1 << 16;

  LinearMemorizedNim() : exp(), log() {
    static Reducer<4, Reducer<3, QuadraticMemorizedNim<3>>> reduced;
    log[exp[0] = 1] = 0;
    for (int i = 1; i < N - 1; ++i) {
      log[exp[i] = reduced.multiply(exp[i - 1], G)] = i;
    }
  }

  u64 multiply(u64 a, u64 b) const {
    assert(a < N && b < N);
    return a == 0 || b == 0 ? 0 : exp[(log[a] + log[b]) % (N - 1)];
  }

private:
  int exp[N], log[N];
};

u64 multiply(u64 a, u64 b) {
  static Reducer<6, Reducer<5, Reducer<4, LinearMemorizedNim<258>>>> reduced;
  return reduced.multiply(a, b);
}
} // namespace nim

using u64 = uint64_t;

u64 power(u64 a, u64 n) {
  u64 result = 1;
  while (n) {
    if (n & 1) {
      result = nim::multiply(result, a);
    }
    a = nim::multiply(a, a);
    n >>= 1;
  }
  return result;
}

const int N = 7;
const u64 M = -1;
const u64 FACTORS[N]{3, 5, 17, 257, 641, 65537, 6700417};
const u64 CRTS[] = {
    12297829382473034410ULL, 7378697629483820646ULL,  1085102592571150095ULL,
    2296870857426870240ULL,  16979062407938588850ULL, 4611615650756935680ULL,
    10691053700478254925ULL,
};

int solve(int k, u64 a, u64 b) {
  std::map<u64, int> map;
  int sqrt = 0;
  while (sqrt * sqrt < FACTORS[k]) {
    map[b = nim::multiply(b, a)] = ++sqrt;
  }
  a = power(a, sqrt), b = 1;
  for (int i = 1; i <= sqrt; ++i) {
    b = nim::multiply(b, a);
    if (map.count(b)) {
      return (i * sqrt - map[b]) % FACTORS[k];
    }
  }
  return -1;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    u64 a, b;
    std::cin >> a >> b;
    bool ok = true;
    u64 result = 0;
#pragma GCC unroll 7
    for (int k = 0; k < N && ok; ++k) {
      u64 m = M / FACTORS[k];
      int e = solve(k, power(a, m), power(b, m));
      if (~e) {
        while (e--) {
          result += result >= M - CRTS[k] ? CRTS[k] + 1 : CRTS[k];
        }
      } else {
        ok = false;
      }
    }
    if (ok) {
      std::cout << result << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
  }
}