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

constexpr int isqrt(int n) {
  int r = 0;
  while (r * r < n) {
    r++;
  }
  return r;
}

int sub(long long x, long long a) {
  return std::max(x - a, static_cast<long long>(-1));
}

const int N = 100000;
const int B = isqrt(N);

int n, q, b, a[N], in_count[B], in_indexes[B][B], pseudo_jump[N], marked[N];
long long blk_delta[B];
bool is_out[N];

int jump(int i) {
  if (i == -1) {
    return -1;
  }
  return is_out[i] ? sub(pseudo_jump[i], blk_delta[i / b]) : pseudo_jump[i];
}

int main() {
  IO io;
  n = io.next_int();
  q = io.next_int();
  for (int i = 0; i < n - 1; ++i) {
    a[i] = io.next_int() - 2;
  }
  b = isqrt(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int blk_idx = i / b;
    int bound = blk_idx * b;
    if (bound <= a[i]) {
      in_indexes[blk_idx][in_count[blk_idx]++] = i;
      pseudo_jump[i] = pseudo_jump[a[i]];
    } else {
      is_out[i] = true;
      pseudo_jump[i] = a[i];
    }
  }
  //   fprintf(stderr, "b=%d\n", b);
  //   for (int i = 0; i < n - 1; ++i) {
  //     fprintf(stderr, "%4d ", a[i] - blk_delta[i / b]);
  //   }
  //   fprintf(stderr, "\n");
  //   for (int i = 0; i < n - 1; ++i) {
  //     fprintf(stderr, "%4d ", jump(i));
  //   }
  //   fprintf(stderr, "\n");
  for (int time = 1; time <= q; ++time) {
    int t = io.next_int();
    int l = io.next_int() - 2;
    int r = io.next_int() - 2;
    if (t == 1) {
      int x = io.next_int();
      for (int blk_idx = l / b, bound = blk_idx * b; blk_idx <= r / b;
           ++blk_idx, bound += b) {
        if (l <= bound && bound + b - 1 <= r) {
          blk_delta[blk_idx] += x;
          int new_in_count = 0;
          for (int j = 0; j < in_count[blk_idx]; ++j) {
            int i = in_indexes[blk_idx][j];
            int cur_a = sub(a[i], blk_delta[blk_idx]);
            if (bound <= cur_a) {
              in_indexes[blk_idx][new_in_count++] = i;
              pseudo_jump[i] = jump(cur_a);
            } else {
              is_out[i] = true;
              pseudo_jump[i] = cur_a + blk_delta[blk_idx];
            }
          }
          in_count[blk_idx] = new_in_count;
        } else {
          in_count[blk_idx] = 0;
          for (int i = bound; i < bound + b && i < n; ++i) {
            a[i] = sub(a[i], blk_delta[blk_idx]);
            if (l <= i && i <= r) {
              a[i] = sub(a[i], x);
            }
            if (bound <= a[i]) {
              in_indexes[blk_idx][in_count[blk_idx]++] = i;
              pseudo_jump[i] = pseudo_jump[a[i]];
            } else {
              is_out[i] = true;
              pseudo_jump[i] = a[i];
            }
          }
          blk_delta[blk_idx] = 0;
        }
      }
      //   fprintf(stderr, "[%d, %d] -%d\n", l, r, x);
      //   for (int i = 0; i < n - 1; ++i) {
      //     fprintf(stderr, "%4d ", std::max(a[i] - blk_delta[i / b], -1));
      //   }
      //   fprintf(stderr, "\n");
      //   for (int i = 0; i < n - 1; ++i) {
      //     fprintf(stderr, "%4d ", jump(i));
      //   }
      //   fprintf(stderr, "\n");
      //   fprintf(stderr, "\n");
    } else {
      while (jump(l) != jump(r)) {
        int &v = jump(l) > jump(r) ? l : r;
        v = jump(v);
      }
      int l_blk_idx = l / b;
      for (int v = l; v != jump(l); v = sub(a[v], blk_delta[l_blk_idx])) {
        marked[v + 1] = time;
      }
      marked[jump(l) + 1] = time;
      int r_blk_idx = r / b;
      while (marked[r + 1] != time) {
        r = sub(a[r], blk_delta[r_blk_idx]);
      }
      printf("%d\n", r + 2);
    }
  }
}