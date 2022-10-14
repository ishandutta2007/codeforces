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

using Long = long long;

static const Long INF = 1'000'000'000'000'000'001;

// 0 - nothing
// 1 - flip
// 2 - set to 0
// 3 - set to 1

struct Node {
  void flip() {
    op ^= 1;
    std::swap(mex[0], mex[1]);
  }

  void set(Long l, int t) {
    op = 2 + t;
    mex[t] = l;
    mex[t ^ 1] = INF;
  }

  int op = 0;
  Long mex[2] = {INF, INF};
};

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      n.mex[0] = values[l];
    }
  }

  const std::vector<Long> &values;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(const std::vector<Long> &values_)
      : SegmentTreeBase{static_cast<int>(values_.size())}, values{values_} {
    traverse_all(Build{values});
  }

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.mex[0] = std::min(ln.mex[0], rn.mex[0]);
    n.mex[1] = std::min(ln.mex[1], rn.mex[1]);
  }

  void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.op == 1) {
      ln.flip();
      rn.flip();
    } else if (n.op >= 2) {
      ln.set(values[l], n.op - 2);
      rn.set(values[m + 1], n.op - 2);
    }
    n.op = 0;
  }

  const std::vector<Long> &values;
};

struct Flip {
  void update(int l, int r, Node &n) { n.flip(); }
};

struct Set {
  void update(int l, int r, Node &n) { n.set(values[l], t); }

  const std::vector<Long> &values;
  int t;
};

int main() {
  int q;
  scanf("%d", &q);
  std::vector<std::tuple<int, Long, Long>> ops(q);
  std::vector<Long> values{1LL};
  values.reserve(q * 2 + 1);
  for (int i = 0, t; i < q; ++i) {
    Long l, r;
    scanf("%d%lld%lld", &t, &l, &r);
    ops[i] = {t, l, r};
    values.push_back(l);
    values.push_back(r + 1);
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  int n = values.size();
  SGT sgt{values};
  for (auto [t, ll, rr] : ops) {
    int l = std::lower_bound(values.begin(), values.end(), ll) - values.begin();
    int r = static_cast<int>(
                std::lower_bound(values.begin(), values.end(), rr + 1) -
                values.begin()) -
            1;
    // std::cout << KV(l) << KV(r) << std::endl;
    if (t == 3) {
      sgt.traverse(Flip{}, l, r);
    } else {
      sgt.traverse(Set{values, 2 - t}, l, r);
    }
    printf("%lld\n", sgt.root().mex[0]);
  }
}