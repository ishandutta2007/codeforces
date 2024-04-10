#line 1 "sol.cpp"
// #include "debug.h"

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
      Impl::propagate(l, m, r, n, ln, rn);
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
#line 4 "sol.cpp"

#include <bits/stdc++.h>

struct Node {
  void add(long long d) {
    delta += d;
    minimum += d;
  }

  long long delta, minimum;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n) {}

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.delta) {
      ln.add(n.delta);
      rn.add(n.delta);
      n.delta = 0;
    }
  }

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                     const Node &rn) {
    n.minimum = std::min(ln.minimum, rn.minimum);
  }
};

struct Add {
  void update(int l, int r, Node &n) { n.add(d); }

  long long d;
};

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  std::vector<int> a(n), b(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d", &a[i], &b[i]);
  }
  std::vector<std::tuple<int, int, int>> arcs(m);
  for (int i = 0, x, y, z; i < m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    arcs[i] = std::make_tuple(x - 1, y - 1, z);
  }
  std::sort(arcs.begin(), arcs.end());
  std::vector<long long> extra(n);
  {
    SGT sgt(n);
    for (int i = 0; i < n - 1; ++i) {
      sgt.traverse(Add{b[i]}, i + 1, i + 1);
    }
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < m && std::get<0>(arcs[j]) == i) {
        auto [_, y, z] = arcs[j++];
        sgt.traverse(Add{z}, 0, y);
      }
      extra[i] = sgt.root().minimum;
    }
  }
//   std::cout << extra << std::endl;
  SGT sgt(n);
  for (int i = 0; i < n; ++i) {
    sgt.traverse(Add{extra[i] + a[i]}, i, i);
  }
  printf("%lld\n", sgt.root().minimum);
  while (q--) {
    int v, w;
    scanf("%d%d", &v, &w);
    v--;
    sgt.traverse(Add{w - a[v]}, v, v);
    a[v] = w;
    printf("%lld\n", sgt.root().minimum);
  }
}