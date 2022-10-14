#line 2 "/home/ftiasch/Documents/shoka/sparse_table.h"

#include <algorithm>
#include <cstring>

template <typename T, int N> struct SparseTable {
  SparseTable() {
    log[0] = 0;
    for (int i = 1; i < N; ++i) {
      log[i] = log[i - 1] + (1 << (log[i - 1] + 1) < i + 1);
    }
  }

  void initialize(int n, const T *value) {
    l = log2n(n), memcpy(table[0], value, sizeof(T) * n);
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        table[i][j] =
            std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T operator()(int l, int r) const {
    const int lv = log[r - l];
    return std::min(table[lv][l], table[lv][r - (1 << lv) + 1]);
  }

private:
  static constexpr int log2n(int n) {
    return n > 1 ? 32 - __builtin_clz(n - 1) : 1;
  }

  static const int L = log2n(N);

  int l, log[N];
  T table[L][N];
};
#line 2 "/home/ftiasch/Documents/shoka/bit_rmq.h"

#include <cstdint>

template <typename T, int N> struct BitRMQ {
public:
  void initialize(int n, const T *a) {
    for (int i = 0, block_start = 0; block_start < n; ++i, block_start += 64) {
      buffer[i] =
          intra[i].compute(std::min(n - block_start, 64), a + block_start);
    }
    inter.initialize((n + 63) >> 6, buffer);
  }

  T operator()(int l, int r) const {
    int lblk = l >> 6;
    int rblk = r >> 6;
    if (lblk == rblk) {
      return intra[lblk].rmq(l & 63, r & 63);
    }
    T prefix = intra[lblk].suffix[l & 63];
    T suffix = intra[rblk].prefix[r & 63];
    if (lblk + 1 <= rblk - 1) {
      return std::min({prefix, inter(lblk + 1, rblk - 1), suffix});
    }
    return std::min({prefix, suffix});
  }

private:
  static const int M = (N + 63) >> 6;

  struct Intra {
    T compute(int n, const T *a_) {
      a = a_;
      uint64_t current_stack = 0;
      T minimum;
      for (int i = 0; i < n; ++i) {
        while (current_stack && a[highest_bit(current_stack)] > a[i]) {
          current_stack ^= 1ULL << highest_bit(current_stack);
        }
        current_stack |= 1ULL << i;
        stack[i] = current_stack;
        minimum = i ? std::min(minimum, a[i]) : a[i];
        prefix[i] = minimum;
      }
      suffix[n - 1] = a[n - 1];
      for (int i = n - 1; i--;) {
        suffix[i] = std::min(suffix[i + 1], a[i]);
      }
      return minimum;
    }

    T rmq(int l, int r) const {
      return a[__builtin_ctzll(stack[r] & ~((1ULL << l) - 1))];
    }

    T prefix[64], suffix[64];

  private:
    static int highest_bit(uint64_t mask) { return 63 - __builtin_clzll(mask); }

    const T *a;
    uint64_t stack[64];
  } intra[M];
  T buffer[M];
  SparseTable<T, M> inter;
};
#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>

#define DEBUG(expr)                                                            \
  do {                                                                         \
    std::cerr << "[L" << __LINE__ << "] " << expr << std::endl;                                            \
  } while (0)

#define KV(x) "|" << #x << "=" << x
#line 1 "/home/ftiasch/Documents/shoka/io.h"
#include <cctype>
#line 3 "/home/ftiasch/Documents/shoka/io.h"
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
#line 4 "main.cc"

#include <bits/stdc++.h>

const int N = 500'000;
const int C = 22;

namespace {

int n, first_child[N], next_child[N], mask_to_root[N], first_mask[1 << C],
    next_mask[N], dfn[N], depth[N];
std::pair<int, int> euler[N << 1];
char character[N];

void prepare(int &&clock, int u, int d) {
  euler[dfn[u] = clock++] = {d, u};
  depth[u] = d;
  int m = mask_to_root[u];
  next_mask[u] = first_mask[m];
  first_mask[m] = u;
  for (int v = first_child[u]; ~v; v = next_child[v]) {
    mask_to_root[v] = mask_to_root[u] ^ (1 << (character[v] - 'a'));
    prepare(std::move(clock), v, d + 1);
    euler[clock++] = {d, u};
  }
}

BitRMQ<std::pair<int, int>, N << 1> rmq;

std::pair<int, int> lca(int a, int b) {
  int u = dfn[a];
  int v = dfn[b];
  if (u > v) {
    std::swap(u, v);
  }
  return rmq(u, v);
}

int result[N];

struct Entry {
  int v, depth_v, depest;
};

void update_max(int &x, int a) { x = std::max(x, a); }

Entry stack[N];

int vertex_count, vertices[N];

void work() {
  int v0 = vertices[vertex_count - 1];
  int stack_sz = 0;
  stack[stack_sz++] = Entry{v0, depth[v0], depth[v0]};
  // DEBUG(KV(v0 + 1));
  for (int i = vertex_count - 2; i >= 0; --i) {
    int v = vertices[i];
    // DEBUG(KV(v + 1));
    auto [depth_w, w] = lca(stack[stack_sz - 1].v, v);
    int popped_depest = -1;
    while (stack_sz && stack[stack_sz - 1].depth_v > depth_w) {
      auto b = stack[stack_sz - 1];
      if (~b.depest && ~popped_depest) {
        update_max(result[b.v], b.depest + popped_depest - 2 * b.depth_v);
      }
      update_max(popped_depest, b.depest);
      stack_sz--;
    }
    if (!stack_sz || stack[stack_sz - 1].v != w) {
      stack[stack_sz++] = Entry{w, depth_w, popped_depest};
    } else {
      auto &b = stack[stack_sz - 1];
      if (~b.depest && ~popped_depest) {
        update_max(result[b.v], b.depest + popped_depest - 2 * b.depth_v);
      }
      update_max(b.depest, popped_depest);
    }
    int d0 = stack[stack_sz - 1].depest;
    if (~d0) {
      update_max(result[w], d0 + depth[v] - 2 * depth_w);
    }
    stack[stack_sz++] = Entry{v, depth[v], depth[v]};
  }
  int popped_depest = -1;
  while (stack_sz) {
    auto b = stack[stack_sz - 1];
    if (~b.depest && ~popped_depest) {
      update_max(result[b.v], b.depest + popped_depest - 2 * b.depth_v);
    }
    update_max(popped_depest, b.depest);
    stack_sz--;
  }
}

void propagate(int u) {
  for (int v = first_child[u]; ~v; v = next_child[v]) {
    propagate(v);
    result[u] = std::max(result[u], result[v]);
  }
}

} // namespace

int main() {
  n = STDIN.next_uint();
  memset(first_child, -1, sizeof(int) * n);
  for (int i = 1; i < n; ++i) {
    int p = STDIN.next_uint() - 1;
    do {
      character[i] = STDIN.next_char();
    } while (!std::islower(character[i]));
    next_child[i] = first_child[p];
    first_child[p] = i;
  }
  mask_to_root[0] = 0;
  memset(first_mask, -1, sizeof(int) << C);
  prepare(0, 0, 0);
  rmq.initialize((n << 1) - 1, euler);
  for (int i = 0; i < n; ++i) {
    int mask = mask_to_root[i];
    if (first_mask[mask] == i) {
      bool found = false;
      for (int c = 0; c < C; ++c) {
        int flip_mask = mask ^ (1 << c);
        if (~first_mask[flip_mask]) {
          found = true;
          if (mask < flip_mask) {
            vertex_count = 0;
            int u = first_mask[mask];
            int v = first_mask[flip_mask];
            while (~u || ~v) {
              if (v == -1 || ~u && dfn[u] > dfn[v]) {
                vertices[vertex_count++] = u;
                u = next_mask[u];
              } else {
                vertices[vertex_count++] = v;
                v = next_mask[v];
              }
            }
            work();
          }
        }
      }
      if (!found) {
        vertex_count = 0;
        for (int v = first_mask[mask]; ~v; v = next_mask[v]) {
          vertices[vertex_count++] = v;
        }
        work();
      }
    }
  }
  propagate(0);
  for (int i = 0; i < n; ++i) {
    STDOUT.print(result[i]);
    STDOUT.putchar(" \n"[i + 1 == n]);
  }
}