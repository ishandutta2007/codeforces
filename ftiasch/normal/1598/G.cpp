#line 1 "/home/ftiasch/Documents/shoka/prefix_table.h"
#include <algorithm>

std::vector<int> prefix_table(int n, const char *s) {
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; ++i) {
    z[i] = i < j + z[j] ? std::min(z[i - j], j + z[j] - i) : 0;
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > j + z[j]) {
      j = i;
    }
  }
  z[0] = n;
  return z;
}
#line 2 "G_The_Sum_of_Good_Numbers.cpp"

#include <bits/stdc++.h>

using u32 = uint32_t;

// const u32 MOD = 1'000'000'009;

u32 MOD;

const int N = 500'000;
const int M = 200'000;

char buffer[N + M + 2];
char s[N + 1], x[M + 1];
u32 prefix[N + 1], power[M + 1];

u32 sum(u32 a, u32 b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}

// [l, r)
u32 get_hash(int l, int r) {
  u32 result = prefix[r];
  return sum(result, MOD - 1ULL * prefix[l] * power[r - l] % MOD);
}

bool is_prime(int m) {
  for (int i = 2; i * i <= m; ++i) {
    if (m % i == 0) {
      return false;
    }
  }
  return true;
}

std::tuple<int, int, int> solve() {
  scanf("%s%s", s, x);
  int n = strlen(s);
  int m = strlen(x);
  strcpy(buffer, x);
  strcpy(buffer + (m + 1), s);
  u32 seed = n + m;
  for (int i = 0; i < n + m + 1; ++i) {
    seed += buffer[i];
  }
  std::mt19937 gen{seed};
  MOD = 1'000'000'000 - gen() % 100'000'000;
  while (!is_prime(MOD)) {
    MOD++;
  }
  u32 x_hash = 0;
  for (int i = 0; i < m; ++i) {
    x_hash = (x_hash * 10ULL + (x[i] - '0')) % MOD;
  }
  power[0] = 1U;
  for (int i = 1; i <= m; ++i) {
    power[i] = (power[i - 1] * 10ULL) % MOD;
  }
  prefix[0] = 0;
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = (prefix[i] * 10ULL + (s[i] - '0')) % MOD;
  }
  // two strings of length (m - 1)
  for (int i = m - 1; i + (m - 1) <= n; ++i) {
    // [i - (m - 1), i)
    // [i, i + (m - 1))
    if (sum(get_hash(i - (m - 1), i), get_hash(i, i + (m - 1))) == x_hash) {
      return {i - (m - 1), i, i + (m - 1)};
    }
  }
  auto z = prefix_table(n + m + 1, buffer);
  for (int i = m; i <= n; ++i) {
    u32 h = get_hash(i - m, i);
    // [i - m, i)
    int lcp = z[(m + 1) + (i - m)];
    int maxlen = m - lcp;
    for (int offset = 0; offset <= 1 && maxlen - offset >= 1; ++offset) {
      int len = maxlen - offset;
      if (i - m >= len && sum(get_hash(i - m - len, i - m), h) == x_hash) {
        return {i - m - len, i - m, i};
      }
      if (i + len <= n && sum(h, get_hash(i, i + len)) == x_hash) {
        return {i - m, i, i + len};
      }
    }
  }
  return {-1, -1, -1};
}

int main() {
  auto [i, j, k] = solve();
  printf("%d %d\n", i + 1, j);
  printf("%d %d\n", j + 1, k);
}