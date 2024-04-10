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

  Node &get_node(int l, int r) { return nodes[l + r | (l != r)]; }

protected:
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
#line 2 "/tmp/tmp-898297ED46DK2o8070.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-898297ED46DK2o8070.cpp"

struct Node {
  void apply(int d) {
    sum2 += sum1 * d + sum0 * static_cast<Long>(d) * (d - 1) / 2;
    sum1 += sum0 * d;
  }

  int sum0, delta;
  Long sum1, sum2;
};

struct SegmentTree : public SegmentTreeBase<Node, SegmentTree> {
  using SegmentTreeBase::SegmentTreeBase;

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {}

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.sum0 = ln.sum0 + rn.sum0;
    n.sum1 = ln.sum1 + rn.sum1;
    n.sum2 = ln.sum2 + rn.sum2;
    n.apply(n.delta);
  }
};

template <int d> struct Add {
  void update(int l, int r, Node &n) {
    n.delta += d;
    n.apply(d);
  }
};

struct Flip {
  void update(int l, int r, Node &n) {
    n.sum0 ^= 1;
    n.sum1 = n.sum2 = 0;
    n.apply(n.delta);
  }
};

int main() {
  IO io;
  int n = io.read();
  int d = io.read();
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = io.read() - 1;
  }
  int m = *std::max_element(ALL(a)) + 1;
  std::vector<bool> present(m);
  SegmentTree sgt(m);
  for (int a : a) {
    sgt.traverse(Flip{}, a, a);
    if (present[a]) {
      sgt.traverse(Add<-1>{}, a - d, a - 1);
    } else {
      sgt.traverse(Add<1>{}, a - d, a - 1);
    }
    present[a] = !present[a];
    std::cout << sgt.root().sum2 << "\n";
  }
}