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

const int N = 1'000'001;

int n, a[N], parent[N], dfn[N], size[N];
std::vector<int> children[N];

void prepare(int &&clock, int u) {
  dfn[u] = clock++;
  size[u] = 1;
  for (int v : children[u]) {
    prepare(std::move(clock), v);
    size[u] += size[v];
  }
}

struct Node {
  void add(int d) {
    delta += d;
    max += d;
  }

  int delta, max;
};

struct Add {
  void update(int l, int r, Node &n) { n.add(delta); }

  int delta;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n) {}

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.delta != 0) {
      ln.add(n.delta);
      rn.add(n.delta);
      n.delta = 0;
    }
  }

  static void collect(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    n.max = std::max(ln.max, rn.max);
  }
};

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i--;) {
    auto &p = parent[i] = i + 1;
    while (p < n && a[i] >= a[p]) {
      p = parent[p];
    }
    children[p].push_back(i);
  }
  prepare(0, n);
  SGT sgt(n + 1);
  for (int i = 0; i < n; ++i) {
    sgt.traverse(Add{1}, dfn[i], dfn[i] + size[i] - 1);
    if (i >= m - 1) {
      printf("%d%c", sgt.root().max, " \n"[i + 1 == n]);
      int j = i - (m - 1);
      sgt.traverse(Add{-n}, dfn[j], dfn[j]);
    }
  }
}