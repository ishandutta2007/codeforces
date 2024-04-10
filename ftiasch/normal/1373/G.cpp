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

struct Node {
  void add(int d) {
    delta += d;
    minimum += d;
  }

  int delta, minimum;
};

struct Build {
  void update(int l, int r, Node &node) {
    if (l == r) {
      node.delta = node.minimum = -l;
    }
  }
};

template <int delta> struct Add {
  void update(int l, int r, Node &n) { n.add(delta); }
};

struct Min {
  void update(int l, int r, const Node &n) { min = std::min(min, n.minimum); }

  int min = INT_MAX;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n << 1) { traverse_all(Build{}); }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.delta) {
      ln.add(n.delta);
      rn.add(n.delta);
      n.delta = 0;
    }
  }

  static void collect(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    n.minimum = n.delta + std::min(ln.minimum, rn.minimum);
  }
};

int main() {
  int n, q, target;
  scanf("%d%d%d", &n, &target, &q);
  std::set<std::pair<int, int>> pawn;
  std::map<int, int> ys;
  SGT sgt(n);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    auto [pit, ok] = pawn.emplace(x, y);
    y += std::abs(x - target) - 1;
    if (ok) {
      ys[y]++;
      sgt.traverse(Add<-1>{}, 0, y);
      // std::cout << "+" << y << std::endl;
    } else {
      pawn.erase(pit);
      auto yit = ys.find(y);
      yit->second--;
      if (!yit->second) {
        ys.erase(yit);
      }
      sgt.traverse(Add<1>{}, 0, y);
      // std::cout << "-" << y << std::endl;
    }
    int y0 = ys.empty() ? n : std::max(ys.rbegin()->first + 1, n);
    int min = sgt.traverse(Min{}, 0, y0 - 1).min;
    // printf("=>y0=%d %d\n", y0, min);
    printf("%d\n", y0 - std::min(y0 + min, 0) - n);
  }
}