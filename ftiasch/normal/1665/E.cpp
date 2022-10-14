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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int K = 31;

using Node = std::array<int, K>;

Node merge(const Node &u, const Node &v) {
  Node w;
  for (int i = 0, j = 0, k = 0; i < K; ++i) {
    w[i] = u[j] < v[k] ? u[j++] : v[k++];
  }
  return w;
}

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      std::ranges::fill(n, 1 << 30);
      n[0] = a[l];
    }
  }

  const std::vector<int> &a;
};

struct SegmentTree : public SegmentTreeBase<Node, SegmentTree> {
  SegmentTree(const std::vector<int> &a) : SegmentTreeBase(a.size()) {
    traverse_all(Build{a});
  }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {}

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n = merge(ln, rn);
  }
};

struct Query {
  Query() { std::ranges::fill(result, 1 << 30); }

  void update(int l, int r, const Node &n) { result = merge(result, n); }

  Node result;
};

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    SegmentTree sgt{a};
    int q;
    scanf("%d", &q);
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      auto candidates = sgt.traverse(Query{}, l - 1, r - 1).result;
      int result = 1 << 30;
      for (int i = 0; i < K; ++i) {
        for (int j = i + 1; j < K; ++j) {
          result = std::min(result, candidates[i] | candidates[j]);
        }
      }
      printf("%d\n", result);
    }
  }
}