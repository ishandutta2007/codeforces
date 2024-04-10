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
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int M = 5;

int m;

using State = std::array<int, M + 1>;

State singleton(int a) {
  State r;
  // P
  for (int i = 0; i < m; ++i) {
    r[i] = i + 1;
  }
  r[m] = a ? 0 : m;
  return r;
}

State merge(const State &p, const State &q) {
  State r;
  for (int i = 0; i <= m; ++i) {
    r[i] = p[q[i]];
  }
  return r;
}

struct Node {
  void flip() {
    flipped ^= 1;
    std::swap(s[0], s[1]);
  }

  bool flipped;
  State s[2];
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n) {}

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.flipped) {
      n.flipped = false;
      ln.flip();
      rn.flip();
    }
  }

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.s[0] = merge(ln.s[0], rn.s[0]);
    n.s[1] = merge(ln.s[1], rn.s[1]);
  }
};

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      n.s[0] = singleton(a[l]);
      n.s[1] = singleton(a[l] ^ 1);
    }
  }

  const std::vector<int> &a;
};

struct Flip {
  void update(int l, int r, Node &n) { n.flip(); }
};

struct Query {
  Query() {
    for (int i = 0; i <= m; ++i) {
      result[i] = i;
    }
  }

  void update(int l, int r, Node &n) { result = merge(result, n.s[0]); }

  State result;
};

int main() {
  int n, q;
  scanf("%d%d%d", &n, &m, &q);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    long long aa;
    scanf("%lld", &aa);
    a[i] = aa & 1;
  }
  SGT sgt(n);
  sgt.traverse_all(Build{a});
  while (q--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    l--;
    r--;
    if (op == 1) {
      long long d;
      scanf("%lld", &d);
      if (d & 1) {
        sgt.traverse(Flip{}, l, r);
      }
    } else {
      auto result = sgt.traverse(Query{}, l, r).result;
      printf("%d\n", result[m] > 0 ? 1 : 2);
    }
  }
}