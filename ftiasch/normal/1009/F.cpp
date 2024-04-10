#line 1 "/home/ftiasch/Documents/shoka/io.h"
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
#line 2 "F_Dominant_Indices.cpp"

#include <bits/stdc++.h>

namespace {

const int N = 1'000'000;

std::vector<int> tree[N];

struct Summary {
  Summary() : best{0, -1} {}

  int size() const { return count.size(); }

  std::pair<int, int> best;
  std::vector<int> count;
};

Summary *merge(Summary *s, Summary *t) {
  if (s->size() < t->size()) {
    std::swap(s, t);
  }
  for (int i = s->size(), j = t->size(); i--, j--;) {
    s->count[i] += t->count[j];
    s->best = std::max(s->best, std::make_pair(s->count[i], i));
  }
  delete t;
  return s;
}

int result[N];

Summary *dfs(int p, int u) {
  Summary *s = new Summary();
  for (int v : tree[u]) {
    if (v != p) {
      s = merge(s, dfs(u, v));
    }
  }
  s->best = std::max(s->best, std::make_pair(1, s->size()));
  result[u] = s->size() - s->best.second;
  s->count.push_back(1);
  return s;
}

} // namespace

int main() {
  int n = STDIN.next_uint();
  for (int i = 0; i < n - 1; ++i) {
    int a = STDIN.next_uint() - 1;
    int b = STDIN.next_uint() - 1;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  delete dfs(-1, 0);
  for (int i = 0; i < n; ++i) {
    STDOUT.println(result[i]);
  }
}