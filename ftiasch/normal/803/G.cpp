#line 1 "/home/ftiasch/Documents/shoka/segment_tree.h"
#include <memory>
#include <vector>

template <typename Node, typename Impl> struct SegmentTreeBase {
  SegmentTreeBase(int n_) : n(n_), nodes(n << 1) {}

  Node &root() { return get_node(0, n - 1); }

  const Node &root() const { return get_node(0, n - 1); }

  template <typename H> H traverse_all(H &&h) {
    traverse_all(std::forward<H>(h), 0, n - 1);
    return h;
  }

  template <typename H> H traverse(H &&h, int a, int b) {
    traverse<H, 0>(std::forward<H>(h), 0, n - 1, a, b);
    return h;
  }

  template <typename H> H reverse_traverse(H &&h, int a, int b) {
    traverse<H, 1>(std::forward<H>(h), 0, n - 1, a, b);
    return h;
  }

private:
  Node &get_node(int l, int r) { return nodes[l + r | (l != r)]; }

  template <typename H> void traverse_all(H &&h, int l, int r) {
    Node &n = get_node(l, r);
    h.update(l, r, n);
    if (l < r) {
      int m = (l + r) >> 1;
      Node &ln = get_node(l, m);
      Node &rn = get_node(m + 1, r);
      static_cast<Impl *>(this)->propagate(l, m, r, n, ln, rn);
      traverse_all(std::forward<H>(h), l, m);
      traverse_all(std::forward<H>(h), m + 1, r);
      static_cast<Impl *>(this)->collect(l, m, r, n, ln, rn);
    }
  }

  template <typename H, int direction>
  void traverse(H &&h, int l, int r, int a, int b) {
    if (b < l || r < a) {
      return;
    }
    Node &n = get_node(l, r);
    if (a <= l && r <= b) {
      h.update(l, r, n);
    } else {
      int m = (l + r) >> 1;
      Node &ln = get_node(l, m);
      Node &rn = get_node(m + 1, r);
      static_cast<Impl *>(this)->propagate(l, m, r, n, ln, rn);
      if (direction) {
        traverse<H, 1>(std::forward<H>(h), m + 1, r, a, b);
        traverse<H, 1>(std::forward<H>(h), l, m, a, b);
      } else {
        traverse<H, 0>(std::forward<H>(h), l, m, a, b);
        traverse<H, 0>(std::forward<H>(h), m + 1, r, a, b);
      }
      static_cast<Impl *>(this)->collect(l, m, r, n, ln, rn);
    }
  }

  int n;
  std::vector<Node> nodes;
};
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
#line 3 "sol.cpp"

#include <bits/stdc++.h>

const int N = 100'000;

int n, k, b[N];
std::vector<int> values;
SparseTable<int, N> rmq;

int get_prmq(int l, int r) {
  if (l / n == r / n) {
    return rmq(l % n, r % n);
  }
  if (l / n + 1 < r / n) {
    return rmq(0, n - 1);
  }
  return std::min(rmq(l % n, n - 1), rmq(0, r % n));
}

struct Node {
  void set(int t) { tag = min = t; }

  int tag, min;
};

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      n.min = get_prmq(values[l], values[l + 1] - 1);
    }
  }
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n) { traverse_all(Build{}); }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.tag) {
      ln.set(n.tag);
      rn.set(n.tag);
      n.tag = 0;
    }
  }

  static void collect(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    n.min = std::min(ln.min, rn.min);
  }
};

struct Set {
  void update(int l, int r, Node &n) { n.set(x); }

  int x;
};

struct GetMin {
  void update(int l, int r, Node &n) { result = std::min(result, n.min); }

  int result = INT_MAX;
};

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  int q;
  scanf("%d", &q);
  std::vector<std::tuple<int, int, int>> ops(q);
  values.reserve(q << 1);
  for (int i = 0, op, l, r, x; i < q; ++i) {
    scanf("%d%d%d", &op, &l, &r);
    l--;
    if (op == 1) {
      scanf("%d", &x);
    } else {
      x = 0;
    }
    ops[i] = {l, r, x};
    values.push_back(l);
    values.push_back(r);
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  rmq.initialize(n, b);
  SGT sgt(values.size() - 1);
  for (auto [ll, rr, xx] : ops) {
    int l = std::lower_bound(values.begin(), values.end(), ll) - values.begin();
    int r =
        static_cast<int>(std::lower_bound(values.begin(), values.end(), rr) -
                         values.begin()) -
        1;
    if (xx) {
      sgt.traverse(Set{xx}, l, r);
    } else {
      printf("%d\n", sgt.traverse(GetMin{}, l, r).result);
    }
  }
}