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

const long long INF = 1e18;
const int N = 200000;

int first[N], next[N], value[N];
struct DP {
  int v, valuev;
  long long dpp, dpv;
} level[N];

int main() {
  IO io;
  int T = io.next_int();
  while (T--) {
    int n = io.next_int();
    memset(first, -1, sizeof(*first) * n);
    for (int i = 1; i < n; ++i) {
      int p = io.next_int() - 1;
      next[i] = first[p];
      first[p] = i;
    }
    for (int i = 1; i < n; ++i) {
      value[i] = io.next_int();
    }
    int head = 0;
    int tail = 1;
    while (true) {
      int new_tail = tail;
      int min_b = INT_MAX, max_b = INT_MIN;
      long long max_neg = -INF, max_pos = -INF;
      for (int i = head; i < tail; ++i) {
        int r = level[i].v;
        long long dpr = level[i].dpv;
        for (int v = first[r]; ~v; v = next[v]) {
          int valuev = value[v];
          min_b = std::min(min_b, valuev);
          max_b = std::max(max_b, valuev);
          max_neg = std::max(max_neg, dpr - valuev);
          max_pos = std::max(max_pos, dpr + valuev);
          level[new_tail++] = {v, valuev, dpr, 0};
        }
      }
      if (tail == new_tail) {
        long long result = 0;
        for (int i = head; i < tail; ++i) {
          result = std::max(result, level[i].dpv);
        }
        printf("%lld\n", result);
        break;
      }
      for (int i = tail; i < new_tail; ++i) {
        auto &info = level[i];
        info.dpv =
            std::max(info.dpp + std::max(std::abs(info.valuev - min_b),
                                         std::abs(info.valuev - max_b)),
                     std::max(info.valuev + max_neg, max_pos - info.valuev));
      }
      head = tail;
      tail = new_tail;
    }
  }
}