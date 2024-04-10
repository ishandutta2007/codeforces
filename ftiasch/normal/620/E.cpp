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

struct Node {
  void cover(int c) {
    covered = c;
    cmask = 1LL << c;
  }

  int covered = 0;
  long long cmask;
};

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      n.cover(c[l]);
    }
  }

  const std::vector<int> &c;
};

struct Cover {
  void update(int l, int r, Node &n) { n.cover(c); }

  int c;
};

struct Query {
  void update(int l, int r, const Node &n) { cmask |= n.cmask; };

  long long cmask = 0;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n, const std::vector<int> &c) : SegmentTreeBase(n) {
    traverse_all(Build{c});
  }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.covered) {
      ln.cover(n.covered);
      rn.cover(n.covered);
      n.covered = 0;
    }
  }

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.cmask = ln.cmask | rn.cmask;
  }
};

using Tree = std::vector<std::vector<int>>;

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  Tree tree(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  std::vector<int> dfn(n), size(n);
  std::function<void(int &&, int, int)> dfs = [&](int &&clock, int p, int u) {
    dfn[u] = clock++;
    size[u] = 1;
    for (int v : tree[u]) {
      if (v != p) {
        dfs(std::move(clock), u, v);
        size[u] += size[v];
      }
    }
  };
  dfs(0, -1, 0);
  std::vector<int> reordered_c(n);
  for (int i = 0; i < n; ++i) {
    reordered_c[dfn[i]] = c[i];
  }
  SGT sgt(n, reordered_c);
  while (q--) {
    int op, v;
    scanf("%d%d", &op, &v);
    v--;
    if (op == 1) {
      int c;
      scanf("%d", &c);
      sgt.traverse(Cover{c}, dfn[v], dfn[v] + size[v] - 1);
    } else {
      printf("%d\n",
             __builtin_popcountll(
                 sgt.traverse(Query{}, dfn[v], dfn[v] + size[v] - 1).cmask));
    }
  }
}