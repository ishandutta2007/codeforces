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

constexpr int block_size(int n) {
  return 1024;
  // int r = 0;
  // while (r * r < n) {
  //   r++;
  // }
  // return r;
}

const int N = 1000000;
const int Q = 500000;
const int M = 100002;

struct Query {
  int t, l, r, x, result;
};

int n, q, a[N];
Query query[Q];

int16_t repr[M];

struct {
  unsigned int parent : 21, count : 11;
} dsu[block_size(N)];

int value(int i) {
  int r = i;
  while (dsu[r].parent < n) {
    r = dsu[r].parent;
  }
  while (dsu[i].parent < n) {
    int backup = dsu[i].parent;
    dsu[i].parent = r;
    i = backup;
  }
  return dsu[r].parent - n;
}

void init_parent(int begin, int sz) {
  for (int i = 0; i < sz; ++i) {
    int ai = a[begin + i];
    auto &r = repr[ai];
    if (r == -1) {
      r = i;
      dsu[i].parent = n + ai;
      dsu[i].count = 1;
    } else {
      dsu[i].parent = r;
      dsu[r].count++;
    }
  }
}

void move(int a, int b) {
  int ra = repr[a];
  if (~ra) {
    int rb = repr[b];
    if (~rb) {
      dsu[ra].parent = rb;
      dsu[rb].count += dsu[ra].count;
    } else {
      dsu[ra].parent = n + b;
      repr[b] = ra;
    }
    repr[a] = -1;
  }
}

int main() {
  IO io;
  n = io.next_uint();
  q = io.next_uint();
  for (int i = 0; i < n; ++i) {
    a[i] = io.next_uint();
  }
  for (int i = 0; i < q; ++i) {
    auto &q = query[i];
    q.t = io.next_uint();
    q.l = io.next_uint() - 1;
    q.r = io.next_uint();
    // [l, r)
    q.x = io.next_uint();
  }
  int blk_sz = block_size(n);
  memset(repr, -1, sizeof(repr));
  for (int begin = 0, end; begin < n; begin = end) {
    end = std::min(begin + blk_sz, n);
    int sz = end - begin;
    int m = *std::max_element(a + begin, a + end) + 1;
    int mbegin = 0;
    int mend = m;
    init_parent(begin, sz);
    for (int i = 0; i < q; ++i) {
      auto &q = query[i];
      int x = q.x;
      if (q.l <= begin && end <= q.r) {
        if (q.t == 1) {
          if (x && mend - mbegin - 1 > x) {
            if (x + 1 <= (mend - mbegin) - x) {
              for (int j = mbegin + x; j >= mbegin; --j) {
                move(j, j + x);
              }
              mbegin += x;
            } else {
              for (int j = mbegin + x + 1; j < mend; ++j) {
                move(j, j - x);
              }
              mend = mbegin + x + 1;
            }
          }
        } else {
          if (mbegin + x < mend && ~repr[mbegin + x]) {
            q.result += dsu[repr[mbegin + x]].count;
          }
        }
      } else if (q.l < end && begin < q.r) {
        if (q.t == 1) {
          for (int i = 0; i < sz; ++i) {
            repr[a[begin + i] = value(i)] = -1;
          }
          for (int i = std::max(q.l, begin); i < std::min(q.r, end); ++i) {
            if (a[i] - mbegin > x) {
              a[i] -= x;
            }
          }
          init_parent(begin, sz);
        } else {
          for (int i = std::max(q.l, begin); i < std::min(q.r, end); ++i) {
            q.result += value(i - begin) - mbegin == x;
          }
        }
      }
    }
    for (int i = 0; i < sz; ++i) {
      repr[value(i)] = -1;
    }
  }
  for (int i = 0; i < q; ++i) {
    auto &q = query[i];
    if (q.t == 2) {
      printf("%d\n", q.result);
    }
  }
}