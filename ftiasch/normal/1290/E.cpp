#include <bits/stdc++.h>

const int N = 150000;

int n, position[N];
long long result;

struct Fenwirk {
  void add(int k) {
    for (; ~k; k -= ~k & k + 1) {
      count[k]++;
    }
  }

  int ask(int k) {
    int result = 0;
    for (; k < n; k += ~k & k + 1) {
      result += count[k];
    }
    return result;
  }

  int count[N];
} fenwick;

enum class Side { L, R };

template <Side side> struct SegmentTree {
  static int ask(int i) {
    return side == Side::R ? -fenwick.ask(i + 1) : fenwick.ask(n - 1 - i);
  }

  static int get_id(int l, int r) { return l + r | l != r; }

  void init() {
    for (int i = 0; i < n << 1; ++i) {
      trees[i] = Entry{n - 1, -1, 0};
    }
  }

  void pass_down(int l, int r) {
    int m = l + r >> 1;
    int m0 = trees[get_id(l, r)].m0;
    trees[get_id(l, m)].m0 = std::min(trees[get_id(l, m)].m0, m0);
    trees[get_id(m + 1, r)].m0 = std::min(trees[get_id(m + 1, r)].m0, m0);
    trees[get_id(l, m)].check();
    trees[get_id(m + 1, r)].check();
  }

  void pass_up(int l, int r) {
    int m = l + r >> 1;
    Entry &e = trees[get_id(l, r)] = trees[get_id(m + 1, r)];
    const Entry &f = trees[get_id(l, m)];
    if (e.m0 > f.m0) {
      e.update(f.m0);
    } else if (e.m0 == f.m0) {
      e.count += f.count;
      e.update(f.m1);
    } else {
      e.m1 = e.m0, e.m0 = f.m0, e.count = f.count;
      e.update(f.m1);
    }
  }

  void bound(int l, int r, int a, int b, int v) { // update min
    if (b < l || r < a) {
      return;
    }
    int m = l + r >> 1;
    int id = get_id(l, r);
    Entry &e = trees[id];
    if (a <= l && r <= b) {
      if (v <= e.m1) {
        pass_down(l, r);
        bound(l, m, a, b, v);
        bound(m + 1, r, a, b, v);
        pass_up(l, r);
      } else if (v < e.m0) {
        result -= static_cast<long long>(e.count) * (ask(e.m0) - ask(v));
        e.m0 = v;
      }
    } else {
      pass_down(l, r);
      bound(l, m, a, b, v);
      bound(m + 1, r, a, b, v);
      pass_up(l, r);
    }
  }

  void reset(int l, int r, int k, int v) {
    if (k < l || r < k) {
      return;
    }
    if (l == r) {
      trees[get_id(l, r)] = Entry{v, -1, 1};
    } else {
      pass_down(l, r);
      int m = l + r >> 1;
      reset(l, m, k, v);
      reset(m + 1, r, k, v);
      pass_up(l, r);
    }
  }

  void dump(int l, int r) {
    const auto &e = trees[get_id(l, r)];
    if (side == Side::R) {
      printf("[%d, %d] = {m1: %d, m0: %d, cnt: %d}, ", l, r, e.m1, e.m0,
             e.count);
    } else {
      int n1 = n - 1;
      printf("[%d, %d] = {m1: %d, m0: %d, cnt: %d}, ", n1 - l, n1 - r,
             n1 - e.m1, n1 - e.m0, e.count);
    }
    if (l < r) {
      int m = l + r >> 1;
      dump(l, m);
      dump(m + 1, r);
    }
  }

  struct Entry {
    void update(int m) { m1 = std::max(m1, m); }

    void check() const { assert(m0 > m1); }

    int m0, m1, count;
  } trees[N << 1];
};

SegmentTree<Side::R> rtree;
SegmentTree<Side::L> ltree;

int main() {
  scanf("%d", &n);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    position[a - 1] = i;
  }
  ltree.init();
  rtree.init();
  int n1 = n - 1;
  for (int _ = 0; _ < n; ++_) {
    int i = position[_];
    rtree.bound(0, n1, 0, i - 1, i - 1);
    ltree.bound(0, n1, 0, n1 - (i + 1), n1 - (i + 1));
    rtree.reset(0, n1, i, n1);
    ltree.reset(0, n1, n1 - i, n1);
    fenwick.add(i);
    result += _ + 1;
    printf("%lld\n", result);
  }
}