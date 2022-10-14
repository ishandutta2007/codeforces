#line 1 "/home/ftiasch/Documents/shoka/dsu.h"
#include <vector>

class DSU {
public:
  DSU(int n) : parent(n, -1) {}

  int find(int u) {
    if (!~parent[u]) {
      return u;
    }
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  bool merge(int a, int b) {
    if (find(a) == find(b)) {
      return false;
    }
    parent[find(a)] = find(b);
    return true;
  }

private:
  std::vector<int> parent;
};
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
#line 3 "D2_Mocha_and_Diana_Hard_Version.cpp"

#include <bits/stdc++.h>

struct MyDSU : public DSU {
  MyDSU(int n) : DSU(n) {}

  bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
  int n = STDIN.next_uint();
  int m[2];
  m[0] = STDIN.next_uint();
  m[1] = STDIN.next_uint();
  MyDSU t[]{MyDSU(n), MyDSU(n)};
  for (int id = 0; id < 2; ++id) {
    for (int i = 0; i < m[id]; ++i) {
      int a = STDIN.next_uint() - 1;
      int b = STDIN.next_uint() - 1;
      t[id].merge(a, b);
    }
  }
  std::vector<std::pair<int, int>> result;
  int side = 0;
  std::list<int> candidates{0};
  std::vector<int> timestamp(n, -1);
  for (int v = 1; v < n; ++v) {
    assert(!candidates.empty());
    if (t[side].same(candidates.front(), v)) {
      candidates.push_back(v);
      // may contain duplicates
    } else {
      auto iterator = candidates.begin();
      while (iterator != candidates.end() && t[side ^ 1].same(*iterator, v)) {
        auto backup = iterator++;
        int repr = t[side ^ 1].find(*backup);
        if (timestamp[repr] == v) {
          candidates.erase(backup);
        } else {
          timestamp[repr] = v;
        }
      }
      if (iterator != candidates.end()) {
        // found
        int u = *iterator;
        result.emplace_back(u, v);
        t[0].merge(u, v);
        t[1].merge(u, v);
      } else {
        side ^= 1;
        candidates.push_back(v);
      }
    }
  }
  STDOUT.println(result.size());
  for (auto &&[a, b] : result) {
    STDOUT.print(a + 1);
    STDOUT.putchar(' ');
    STDOUT.println(b + 1);
  }
}