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

struct Query {
  int l, r, k, v, i;

  auto rank(int bs) const {
    int ll = l / bs;
    int rr = r / bs;
    int vv = rr & 1 ? v : -v;
    return std::tuple<int, int, int>{ll, rr, vv};
  }
};

struct Change {
  int p, px, x;
};

struct State {
  State(int n) : n(n), cnt(n + 1), sorted_cnt(n), begin(n + 1, n) {
    // begin[c] = std::lower_bound(ALL(sorted_cnt), c)
    std::iota(sorted_cnt.begin(), sorted_cnt.end(), 0);
    begin[0] = 0;
  }

  void inc(int a) {
    int c = ++cnt[a];
    sorted_cnt[--begin[c]] = cnt[a];
  }

  void dec(int a) {
    int c = cnt[a]--;
    sorted_cnt[begin[c]++] = cnt[a];
  }

  int solve(int k) {
    int result = INT_MAX;
    for (int i = begin[1]; i + k <= n;) {
      int c = sorted_cnt[i];
      result = std::min(result, sorted_cnt[i + k - 1] - c);
      i = begin[c + 1];
    }
    return result == INT_MAX ? -1 : result;
  }

  int n;
  std::vector<int> cnt, sorted_cnt, begin;
};

int main() {
  IO io;
  int n = io.next_int();
  int m = io.next_int();
  int bs = 0;
  while (1LL * bs * bs * bs < 1LL * n * n) {
    bs++;
  }
  // bs^3 >= n^2
  // bs >= n^{2/3}
  // n / bs <= n^{1/3}
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = io.next_int();
  }
  std::vector<Query> queries;
  queries.reserve(m);
  std::vector<Change> changes;
  changes.reserve(m);
  for (int i = 0; i < m; ++i) {
    int op = io.next_int();
    if (op == 1) {
      Query q;
      q.l = io.next_int();
      q.r = io.next_int();
      q.k = io.next_int();
      q.v = changes.size();
      q.i = queries.size();
      queries.push_back(q);
    } else {
      Change c;
      c.p = io.next_int();
      c.x = io.next_int();
      c.px = a[c.p];
      a[c.p] = c.x;
      changes.push_back(c);
    }
  }
  std::sort(queries.begin(), queries.end(),
            [&bs](const Query &p, const Query &q) {
              return p.rank(bs) < q.rank(bs);
            });
  std::vector<int> result(queries.size());
  int l = 1;
  int r = 0;
  int v = changes.size();
  State state(100000);
  for (const Query &q : queries) {
    while (v < q.v) {
      Change c = changes[v++];
      if (l <= c.p && c.p <= r) {
        state.dec(c.px);
        state.inc(c.x);
      }
      a[c.p] = c.x;
    }
    while (q.v < v) {
      Change c = changes[--v];
      if (l <= c.p && c.p <= r) {
        state.dec(c.x);
        state.inc(c.px);
      }
      a[c.p] = c.px;
    }
    while (q.l < l) {
      state.inc(a[--l]);
    }
    while (q.r < r) {
      state.dec(a[r--]);
    }
    while (r < q.r) {
      state.inc(a[++r]);
    }
    while (l < q.l) {
      state.dec(a[l++]);
    }
    result[q.i] = state.solve(q.k);
  }
  for (int r : result) {
    printf("%d\n", r);
  }
}