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
#line 2 "/tmp/tmp-88068apeQUiUOYEBE.cpp"

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 4 "/tmp/tmp-88068apeQUiUOYEBE.cpp"

const int INF = 1e9;

struct Matrix : std::array<std::array<int, 2>, 2> {
  Matrix() {
    for (auto &row : *this) {
      std::fill(ALL(row), INF);
    }
  }

  Matrix operator*(const Matrix &o) const {
    Matrix result;
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; i < 2; ++i) {
        result[i][j] =
            std::min((*this)[i][0] + o[0][j], (*this)[i][1] + o[1][j]);
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

Matrix make_matrix(int l, int r) {
  Matrix m;
  if (l) {
    m[0][0] = m[1][0] = 1;
  } else {
    m[0][0] = 0;
  }
  if (r) {
    m[0][1] = m[1][1] = 1;
  } else {
    m[1][1] = 0;
  }
  return m;
}

struct Update {
  void update(int l, int r, Matrix &n) {
    if (l == r) {
      n = make_matrix(lcount[l], rcount[l]);
    }
  }

  const std::vector<int> &lcount, &rcount;
};

struct Query {
  void update(int l, int r, const Matrix &n) {
    dp = {std::min(dp[0] + n[0][0], dp[1] + n[1][0]),
          std::min(dp[0] + n[0][1], dp[1] + n[1][1])};
  }

  std::array<int, 2> dp;
};

int main() {
  IO io;
  int n = io.read();
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    a[i] = io.read();
  }
  std::vector<int> lcount(n + 1), rcount(n + 1);
  lcount[0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    rcount[a[i]]++;
  }
  SegmentTree sgt(n + 1);
  sgt.traverse_all(Update{lcount, rcount});
  Long result = 0;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    rcount[x]--;
    sgt.traverse(Update{lcount, rcount}, x, x);
    if (x > 0) {
      auto dp = sgt.traverse(Query{}, 1, x - 1).dp;
      result += std::min(dp[0] + 1, dp[1] + 1);
    }
    lcount[x]++;
    sgt.traverse(Update{lcount, rcount}, x, x);
  }
  std::cout << result << "\n";
}