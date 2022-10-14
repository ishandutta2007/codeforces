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
#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T> std::vector<int> discretize(const std::vector<T> &a) {
  auto values = a;
  std::sort(ALL(values));
  values.erase(std::unique(ALL(values)), values.end());
  std::vector<int> result(a.size());
  for (int i = 0; i < a.size(); ++i) {
    result[i] = std::lower_bound(ALL(values), a[i]) - values.begin();
  }
  return result;
}
#line 3 "/tmp/tmp-215011zK2hW2h0tnza.cpp"

#line 5 "/tmp/tmp-215011zK2hW2h0tnza.cpp"

using Matrix = std::array<std::array<Long, 2>, 2>;

Matrix mul(const Matrix &a, const Matrix &b) {
  Matrix c;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      c[i][j] = std::min(a[i][0] + b[0][j], a[i][1] + b[1][j]);
    }
  }
  return c;
}

struct SegmentTree : public SegmentTreeBase<Matrix, SegmentTree> {
  struct Build {
    void update(int l, int r, Matrix &n) {
      if (l == r) {
        n = ms[l];
      }
    }

    const std::vector<Matrix> &ms;
  };

  static Matrix identity(Long inf) {
    Matrix r;
    r[0][0] = r[1][1] = 0;
    r[0][1] = r[1][0] = inf;
    return r;
  }

  struct Query {
    Query(Long inf) { r = identity(inf); }

    void update(int l_, int r_, const Matrix &n) { r = mul(r, n); }

    Matrix r;
  };

  SegmentTree(const std::vector<Matrix> &ms) : SegmentTreeBase(ms.size()) {
    traverse_all(Build{ms});
  }

  static void propagate(int l, int m, int r, Matrix &n, Matrix &ln,
                        Matrix &rn) {}

  static void collect(int l, int m, int r, Matrix &n, const Matrix &ln,
                      const Matrix &rn) {
    n = mul(ln, rn);
  }

  Matrix query(int l, int r, Long inf) {
    if (l == r) {
      return identity(inf);
    }
    return traverse(Query{inf}, l, r - 1).r;
  }
};

using Tuple4 = std::tuple<int, int, int, int>;

int dist(int x0, int y0, int x1, int y1) {
  return std::abs(x0 - x1) + std::abs(y0 - y1);
}

int main() {
  std::ios::sync_with_stdio(false);
  int n = read();
  std::vector<int> top(n - 1), right(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    assert(read() == i + 1);
    top[i] = read() - 1;
    right[i] = read() - 1;
    assert(read() == i + 1);
  }
  std::vector<Matrix> ds(n - 1);
  for (int i = 0; i + 1 < n - 1; ++i) {
    auto &d = ds[i];
    d[0][0] = dist(i + 1, top[i], i + 1, top[i + 1]);
    d[0][1] = dist(i + 1, top[i], right[i + 1], i + 1);
    d[1][0] = dist(right[i], i + 1, i + 1, top[i + 1]);
    d[1][1] = dist(right[i], i + 1, right[i + 1], i + 1);
  }
  SegmentTree sgt(ds);
  Long inf = 1LL * n * n;
  int q = read();
  while (q--) {
    int x0 = read() - 1;
    int y0 = read() - 1;
    int x1 = read() - 1;
    int y1 = read() - 1;
    if (std::max(x0, y0) > std::max(x1, y1)) {
      std::swap(x0, x1);
      std::swap(y0, y1);
    }
    Long result;
    int l0 = std::max(x0, y0);
    int l1 = std::max(x1, y1);
    if (l0 == l1) {
      result = dist(x0, y0, x1, y1);
    } else {
      result = inf;
      auto d = sgt.query(l0, l1 - 1, inf);
      std::array<int, 2> d0 = {
          dist(x0, y0, l0, top[l0]),
          dist(x0, y0, right[l0], l0),
      };
      std::array<int, 2> d1 = {dist(l1, top[l1 - 1], x1, y1),
                               dist(right[l1 - 1], l1, x1, y1)};
      for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
          result = std::min(result, d0[x] + d[x][y] + d1[y]);
        }
      }
      result += l1 - l0;
    }
    std::cout << result << "\n";
  }
}