#include <bits/stdc++.h>

struct IO {
  IO(FILE *in = stdin) : in(in) {}

  int next_char() {
    if (position == length) {
      position = 0, length = fread(buffer, 1, LENGTH, in);
    }
    if (position == length) {
      eof = true;
      return -1;
    }
    return buffer[position++];
  }

  int next_uint() {
    int c = next_char(), x = 0;
    while (c <= 32) {
      c = next_char();
    }
    for (; '0' <= c && c <= '9'; c = next_char()) {
      x = x * 10 + c - '0';
    }
    return x;
  }

  int next_int() {
    int s = 1, c = next_char(), x = 0;
    while (c <= 32) {
      c = next_char();
    }
    if (c == '-') {
      s = -1, c = next_char();
    }
    for (; '0' <= c && c <= '9'; c = next_char()) {
      x = x * 10 + c - '0';
    }
    return x * s;
  }

  void next_string(char *s) {
    int c = next_char();
    while (c <= 32) {
      c = next_char();
    }
    for (; c > 32; c = next_char()) {
      *s++ = c;
    }
    *s = 0;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  int position = 0, length = 0;
  bool eof = false;
  FILE *in;
};

const int N = 500000;
const auto MAX = 500000000000001;

int n, m, a[N], p[N], rk[N + 1];
long long dp[N + 1];

int main() {
  IO io{stdin};
  n = io.next_uint();
  for (int i = 0; i < n; ++i) {
    a[i] = io.next_uint() - 1;
  }
  for (int i = 0; i < n; ++i) {
    p[i] = io.next_int();
  }
  m = io.next_uint();
  for (int i = 0; i < m; ++i) {
    rk[io.next_uint() - 1] = i << 1 | 1;
  }
  rk[n] = m << 1 | 1;
  for (int i = n; i--;) {
    rk[i] = rk[i] ? rk[i] : rk[i + 1] & ~1;
  }
  dp[0] = -(dp[m] = 2 * MAX);
  for (int i = 0; i < n; ++i) {
    int j = rk[a[i]] >> 1;
    if (j < m && (rk[a[i]] & 1) && dp[j] < std::min(p[i], 0)) {
      dp[j + 1] += dp[j];
      dp[j] = p[i];
      if (p[i] <= 0) {
        dp[m] += p[i], dp[j + 1] -= p[i];
      }
    } else {
      dp[p[i] > 0 ? j : m] += p[i];
    }
  }
  if (dp[m] < MAX) {
    printf("YES\n%lld\n", dp[m]);
  } else {
    puts("NO");
  }
}