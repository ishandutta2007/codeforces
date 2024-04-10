#line 1 "io.h"
#include <cctype>
#include <cstdint>
#include <cstdio>

struct FastIn {
  FastIn(FILE *in_ = stdin) : in(in_) {}

  char next_char() {
    if (head == length) {
      head = 0;
      length = fread(buffer, 1, LENGTH, in);
    }
    return buffer[head++];
  }

  uint64_t next_uint() {
    char c = next_char();
    while (!std::isdigit(c)) {
      c = next_char();
    }
    uint64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10U + c - '0';
    }
    return x;
  }

  int64_t next_int() {
    char c = next_char();
    while (!std::isdigit(c) && c != '-') {
      c = next_char();
    }
    int64_t sign = 1;
    if (c == '-') {
      sign = -1;
      c = next_char();
    }
    int64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10 + c - '0';
    }
    return sign * x;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  size_t head = 0;
  size_t length = 0;
  FILE *in;
};

struct FastOut {
  static const int BUFSIZE = 4096;

  void putchar(char c) {
    buf[len++] = c;
    if (len == BUFSIZE) {
      fwrite(buf, 1, BUFSIZE, stdout);
      len = 0;
    }
  }

  void puts(const char *s) {
    while (*s) {
      putchar(*(s++));
    }
    putchar('\n');
  }

  void print(int64_t n) {
    static char bufn[32];
    bool negative = false;
    if (n < 0) {
      n = -n;
      negative = true;
    }
    int top = 32;
    while (n >= 10) {
      bufn[--top] = '0' + n % 10;
      n /= 10;
    }
    bufn[--top] = '0' + n;
    if (negative) {
      bufn[--top] = '-';
    }
    for (; top < 32; ++top) {
      putchar(bufn[top]);
    }
  }

  void println(int64_t n) {
    print(n);
    putchar('\n');
  }

  ~FastOut() {
    if (len) {
      fwrite(buf, 1, len, stdout);
    }
    fflush(stdout);
  }

  char buf[BUFSIZE];
  int len = 0;
};

static FastIn STDIN;
static FastOut STDOUT;
#line 2 "/tmp/tmp-300543fTu0tBnDYnDy.cpp"

#include <bits/stdc++.h>

int main() {
  int T = STDIN.next_uint();
  while (T--) {
    int n = STDIN.next_uint();
    int m = STDIN.next_uint();
    std::vector<bool> present(m + 1);
    std::vector<int> count(m + 2);
    for (int i = 0; i < n; ++i) {
      int a = STDIN.next_uint();
      present[a] = true;
    }
    for (int i = 1; i <= m; ++i) {
      if (present[i]) {
        count[m + 1]++;
      }
    }
    std::vector<int> dp(m + 1, m + 1);
    int upper = m + 1;
    auto set_dp = [&](int i, int v) {
      if (dp[i] > v) {
        if (present[i]) {
          count[dp[i]]--;
          count[v]++;
          while (!count[upper]) {
            upper--;
          }
        }
        dp[i] = v;
      }
    };
    int result = m + 1;
    for (int i = m; i >= 1; --i) {
      set_dp(i, i);
      if (static_cast<long long>(i) * i <= m) {
        for (int j = i * i, q = i; j <= m; j += i, ++q) {
          set_dp(j, std::max(i, dp[q]));
        }
      }
      if (upper <= m) {
        result = std::min(result, upper - i);
      }
    }
    STDOUT.println(result);
  }
}