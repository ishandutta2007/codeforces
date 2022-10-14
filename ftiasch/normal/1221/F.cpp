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

using Pair = std::pair<long long, int>;

struct Node {
  void add(long long d) {
    delta += d;
    max.first += d;
  }

  long long delta = 0;
  Pair max;
};

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      int v = values[l];
      n = Node{v, {v, v}};
    }
  }

  const std::vector<int> &values;
};

struct Add {
  void update(int l, int r, Node &n) { n.add(d); }

  int d;
};

struct GetMax {
  void update(int l, int r, Node &n) { max = std::max(max, n.max); }

  Pair max = {0, -1};
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(const std::vector<int> &values) : SegmentTreeBase(values.size()) {
    traverse_all(Build{values});
  }

  void add(int l, int r, int d) { traverse(Add{d}, l, r); }

  Pair get_max(int l, int r) { return traverse(GetMax{}, l, r).max; }

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.max = std::max(ln.max, rn.max);
  }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.delta != 0) {
      ln.add(n.delta);
      rn.add(n.delta);
      n.delta = 0;
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> values;
  values.reserve(n << 1);
  std::vector<std::tuple<int, int, int>> p(n);
  for (int i = 0, x, y, c; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &c);
    // y <= x
    if (x < y) {
      std::swap(x, y);
    }
    p[i] = {x, c, y};
    values.push_back(x);
    values.push_back(y);
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  auto get_id = [&](int v) {
    return std::lower_bound(values.begin(), values.end(), v) - values.begin();
  };
  SGT sgt{values};
  std::pair<long long, std::pair<int, int>> result{0, {1e9 + 1, 1e9 + 1}};
  std::sort(p.begin(), p.end());
  for (auto [x, c, y] : p) {
    // std::cout << KV(x) << KV(y) << KV(c) << std::endl;
    sgt.add(0, get_id(y), c);
    auto sub = sgt.get_max(0, get_id(x));
    result = std::max(result, {sub.first - x, {sub.second, x}});
  }
  auto [y, yy] = result.second;
  printf("%lld\n%d %d %d %d\n", result.first, y, y, yy, yy);
}