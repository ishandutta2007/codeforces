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
#line 2 "main.cc"

#include <bits/stdc++.h>

namespace {

const int N = 200'000;
const int D = 30;

int n, a[N];
long long result;

struct Node {
  Node() : child{nullptr, nullptr} {}

  Node *child[2];
};

int search(int d, Node *u, Node *v) {
  assert(u != nullptr);
  if (d == 0) {
    return 0;
  }
  int result = INT_MAX;
  for (int c = 0; c < 2; ++c) {
    if (u->child[c]) {
      if (v->child[c]) {
        result = std::min(result, search(d - 1, u->child[c], v->child[c]));
      } else {
        result = std::min(result, search(d - 1, u->child[c], v->child[c ^ 1]) |
                                      (1 << (d - 1)));
      }
    }
  }
  return result;
}

Node *merge(Node *u, Node *v) {
  if (u == nullptr) {
    return v;
  }
  if (v == nullptr) {
    return u;
  }
  for (int c = 0; c < 2; ++c) {
    u->child[c] = merge(u->child[c], v->child[c]);
  }
  delete v;
  return u;
}

Node *solve(int low, int high, int l, int r) {
  if (l == r) {
    return nullptr;
  }
  if (low + 1 == high) {
    Node *root = new Node();
    Node *p = root;
    for (int i = D; i--;) {
      int c = a[l] >> i & 1;
      p->child[c] = new Node();
      p = p->child[c];
    }
    return root;
  }
  int middle = (low + high) >> 1;
  int m = std::lower_bound(a + l, a + r, middle) - a;
  auto u = solve(low, middle, l, m);
  auto v = solve(middle, high, m, r);
  if (m - l > r - m) {
    std::swap(u, v);
  }
  assert(v != nullptr);
  if (u == nullptr) {
    return v;
  }
  result += search(D, u, v);
  return merge(u, v);
}

} // namespace

int main() {
  n = STDIN.next_uint();
  for (int i = 0; i < n; ++i) {
    a[i] = STDIN.next_uint();
  }
  std::sort(a, a + n);
  solve(0, 1 << D, 0, n);
  std::cout << result << std::endl;
}