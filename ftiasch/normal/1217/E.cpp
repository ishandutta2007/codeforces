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
      traverse_all(std::forward<H>(h), l, m);
      traverse_all(std::forward<H>(h), m + 1, r);
      Impl::collect(l, m, r, n, ln, rn);
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
      Impl::propagate(l, m, r, n, ln, rn);
      if (direction) {
        traverse<H, 1>(std::forward<H>(h), m + 1, r, a, b);
        traverse<H, 1>(std::forward<H>(h), l, m, a, b);
      } else {
        traverse<H, 0>(std::forward<H>(h), l, m, a, b);
        traverse<H, 0>(std::forward<H>(h), m + 1, r, a, b);
      }
      Impl::collect(l, m, r, n, ln, rn);
    }
  }

  int n;
  std::vector<Node> nodes;
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int INF = 1e9;

using A2 = std::array<int, 2>;

A2 merge(const A2 &a, const A2 &b) {
  if (a[0] > b[0]) {
    return merge(b, a);
  }
  return {a[0], std::min(a[1], b[0])};
}

const int D = 9;

using Node = std::array<A2, D>;

void merge(Node &out, const Node &a, const Node &b) {
  for (int i = 0; i < D; ++i) {
    out[i] = merge(a[i], b[i]);
  }
}

struct Change {
  void update(int l, int r, Node &n) {
    for (int i = 0, t = x; i < D; ++i, t /= 10) {
      n[i][0] = t % 10 ? x : INF;
      n[i][1] = INF;
    }
  }

  int x;
};

struct Query {
  Query() {
    for (int i = 0; i < D; ++i) {
      result[i][0] = result[i][1] = INF;
    }
  }

  void update(int l, int r, Node &n) { merge(result, result, n); }

  Node result;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n) {}

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    merge(n, ln, rn);
  }

  static void propagate(int l, int m, int r, Node &n, const Node &ln,
                        const Node &rn) {}
};

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  SGT sgt(n);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    sgt.traverse(Change{x}, i, i);
  }
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int i, x;
      scanf("%d%d", &i, &x);
      i--;
      sgt.traverse(Change{x}, i, i);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      r--;
      int result = INF + INF;
      auto q = sgt.traverse(Query{}, l, r).result;
      for (int i = 0; i < D; ++i) {
        if (q[i][1] < INF) {
          result = std::min(result, q[i][0] + q[i][1]);
        }
      }
      printf("%d\n", result < INF + INF ? result : -1);
    }
  }
}