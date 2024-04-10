#include <bits/stdc++.h>

const int MOD = 998244353;

static void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

template <int N, int MOD> struct NTT {
  void dit(int n, int *a) {
    // revbin(n, a);
    for (int m = 1; m < n; m <<= 1) {
      int64_t root = power(G, (MOD - 1) / (m << 1));
      twiddles[0] = 1;
      for (int i = 1; i < m; ++i) {
        twiddles[i] = twiddles[i - 1] * root % MOD;
      }
      for (int i = 0; i < n; i += m << 1) {
        for (int r = i; r < i + m; ++r) {
          int tmp = static_cast<int64_t>(twiddles[r - i]) * a[r + m] % MOD;
          a[r + m] = a[r];
          add(a[r + m], MOD - tmp);
          add(a[r], tmp);
        }
      }
    }
  }

  void dif(int n, int *a) {
    for (int m = n; m >>= 1;) {
      int64_t root = power(G, MOD - 1 - (MOD - 1) / (m << 1));
      twiddles[0] = 1;
      for (int i = 1; i < m; ++i) {
        twiddles[i] = twiddles[i - 1] * root % MOD;
      }
      for (int i = 0; i < n; i += m << 1) {
        for (int r = i; r < i + m; ++r) {
          int tmp = a[r];
          add(tmp, MOD - a[r + m]);
          add(a[r], a[r + m]);
          a[r + m] = static_cast<int64_t>(twiddles[r - i]) * tmp % MOD;
        }
      }
    }
    // revbin(n, a);
  }

  void convolute(int n, int *a, int *b, int *out) {
    dif(n, a);
    dif(n, b);
    uint64_t inv_n = power(n, MOD - 2);
    for (int i = 0; i < n; ++i) {
      out[i] = inv_n * a[i] % MOD * b[i] % MOD;
    }
    dit(n, out);
  }

  static constexpr int power(int a, int n) {
    int res = 1;
    while (n) {
      if (n & 1) {
        res = 1ULL * res * a % MOD;
      }
      a = 1ULL * a * a % MOD;
      n >>= 1;
    }
    return res;
  }

private:
  void revbin(int n, int *a) {
    for (int i = 1, j = 0; i < n - 1; ++i) {
      for (int s = n; j ^= s >>= 1, ~j & s;)
        ;
      if (i < j) {
        std::swap(a[i], a[j]);
      }
    }
  }

  struct FiniteField {
    static constexpr int primitive_root() {
      int g = 2;
      while (!is_primitive_root(g)) {
        g++;
      }
      return g;
    }

  private:
    static constexpr bool is_primitive_root(int g) {
      for (int d = 2; d * d <= MOD - 1; ++d) {
        if ((MOD - 1) % d == 0 &&
            (power(g, d) == 1 || power(g, (MOD - 1) / d) == 1)) {
          return false;
        }
      }
      return true;
    }
  };

  static const int G = FiniteField::primitive_root();
  int twiddles[N];
};

const int N = 1 << 19;

int p[26], noise[26], a[N], b[N];
char s[N], t[N];
NTT<N, MOD> ntt;

int main() {
  for (int i = 0; i < 26; ++i) {
    scanf("%d", p + i);
    p[i]--;
  }
  std::mt19937 gen{static_cast<int>(time(nullptr))};
  for (int i = 0; i < 26; ++i) {
    noise[i] = std::uniform_int_distribution<int>(0, MOD - 1)(gen);
  }
  scanf("%s%s", s, t);
  int n = strlen(s);
  int m = strlen(t);
  int n2 = 1;
  while (n + m - 2 >= n2) {
    n2 <<= 1;
  }
  int sum_s = 0;
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    add(sum_s, 1LL * noise[c] * noise[p[c]] % MOD);
    a[n - 1 - i] = (noise[c] + noise[p[c]]) % MOD;
  }
  for (int i = 0; i < m; ++i) {
    b[i] = noise[t[i] - 'a'];
  }
  ntt.convolute(n2, a, b, a);
  int sum_t = 0;
  for (int i = 0; i < m; ++i) {
    add(sum_t, 1LL * noise[t[i] - 'a'] * noise[t[i] - 'a'] % MOD);
    if (i >= n - 1) {
      putchar("01"[(sum_s + sum_t) % MOD == a[i]]);
      add(sum_t, MOD - 1LL * noise[t[i - n + 1] - 'a'] *
                           noise[t[i - n + 1] - 'a'] % MOD);
    }
  }
  puts("");
}