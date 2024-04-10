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

const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 200000;

int b[N], next[N + 1], delta[N + 2];

int main() {
  IO io;
  int T = io.next_int();
  while (T--) {
    int n = io.next_int();
    for (int i = 1; i <= n; ++i) {
      b[i] = io.next_int();
    }
    {
      std::map<long long, int> next_map;
      // next_map[0] = n + 1;
      long long sum = 0;
      for (int i = n; i >= 0; --i) {
        sum += b[i];
        next[i] = next_map.count(sum) ? next_map[sum] : n + 1;
        next_map[sum] = i;
      }
    }
    int dp = 1;
    memset(delta, 0, sizeof(*delta) * (n + 2));
    add(delta[1], MOD - 1);
    for (int i = 1; i <= n; ++i) {
      add(delta[next[i]], MOD - dp);
      add(dp, dp);
      add(dp, delta[i]);
    }
    printf("%d\n", dp);
  }
}