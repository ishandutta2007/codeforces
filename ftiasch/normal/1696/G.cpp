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
#line 2 "/tmp/tmp-144689TL9e9mLw7nfw.cpp"

#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-144689TL9e9mLw7nfw.cpp"

const Long INF = 2e17;

struct Matrix : std::array<std::array<Long, 3>, 3> {
  Matrix() {
    for (auto &row : *this) {
      std::fill(ALL(row), -INF);
    }
  }

  Matrix operator*(const Matrix &o) const {
    static Long buffer[3];
    Matrix result;
    for (int j = 0; j < 3; ++j) {
      for (int i = 0; i < 3; ++i) {
        buffer[i] = o[i][j];
      }
      for (int i = 0; i < 3; ++i) {
        for (int k = 0; k < 3; ++k) {
          result[i][j] = std::max(result[i][j], (*this)[i][k] + buffer[k]);
        }
      }
    }
    return result;
  }
};

struct SegmentTree : public SegmentTreeBase<Matrix, SegmentTree> {
  using SegmentTreeBase::SegmentTreeBase;

  static void propagate(int l, int m, int r, Matrix &n, Matrix &ln,
                        Matrix &rn) {}

  static void collect(int l, int m, int r, Matrix &n, const Matrix &ln,
                      const Matrix &rn) {
    n = ln * rn;
  }
};

Matrix make_matrix(int a, int b, int c) {
  Matrix result;
  for (int i = 0; i < 3; ++i) {
    result[i][0] = 0;
  }
  for (int i = 0; i < 2; ++i) {
    result[i][1] = static_cast<Long>(b) * c;
  }
  result[0][2] = static_cast<Long>(a + b) * c;
  return result;
}

struct Update {
  void update(int l, int r, Matrix &n) {
    if (l == r) {
      n = make_matrix(a, b, c[l]);
    }
  }

  int a, b;
  const std::vector<int> &c;
};

struct Query {
  void update(int l, int r, const Matrix &n) {
    std::fill(ALL(buffer), -INF);
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        buffer[j] = std::max(result[i] + n[i][j], buffer[j]);
      }
    }
    result.swap(buffer);
  }

  Long get() const { return *std::max_element(ALL(result)); }

  std::array<Long, 3> result, buffer;
};

int main() {
  IO io;
  int n = io.read();
  int q = io.read();
  int a = io.read();
  int b = io.read();
  if (a > b) {
    std::swap(a, b);
  }
  // a <= b
  // 0, b/b(a+b), (a+b)/b(a+b)
  auto c = io.read_vector(n);
  SegmentTree sgt(n);
  sgt.traverse_all(Update{a, b, c});
  std::cout << std::setprecision(10);
  while (q--) {
    int op = io.read();
    if (op == 1) {
      int k = io.read() - 1;
      c[k] = io.read();
      sgt.traverse(Update{a, b, c}, k, k);
    } else {
      int l = io.read() - 1;
      int r = io.read() - 1;
      std::cout << 1.0 * sgt.traverse(Query{}, l, r).get() /
                       (static_cast<Long>(b) * (a + b))
                << "\n";
    }
  }
}