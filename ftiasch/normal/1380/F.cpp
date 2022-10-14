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

const int MOD = 998'244'353;

struct Matrix {
  Matrix() { memset(data, 0, sizeof(data)); }

  int *operator[](int i) { return data[i]; }

  const int *operator[](int i) const { return data[i]; }

  int data[2][2];
};

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      c[i][j] = (1LL * a[i][0] * b[0][j] + 1LL * a[i][1] * b[1][j]) % MOD;
    }
  }
  return c;
}

int sum_ways(int s) {
  return std::max(std::min(s, 9) - std::max(s - 9, 0) + 1, 0);
}

Matrix atom[10];

struct Build {
  void update(int l, int r, Matrix &n) {
    if (l == r) {
      n = atom[s[l] - '0'];
    }
  }

  const std::vector<char> &s;
};

struct SGT : public SegmentTreeBase<Matrix, SGT> {
  SGT(int n, const std::vector<char> &s) : SegmentTreeBase(n) {
    traverse_all(Build{s});
  }

  static void propagate(int l, int m, int r, Matrix &n, const Matrix &ln,
                        const Matrix &rn) {
    n = ln * rn;
  }

  static void collect(int l, int m, int r, Matrix &n, const Matrix &ln,
                      const Matrix &rn) {
    n = ln * rn;
  }
};

int main() {
  for (int d = 0; d < 10; ++d) {
    atom[d][0][0] = sum_ways(d);
    atom[d][0][1] = d == 1;
    atom[d][1][0] = sum_ways(10 + d);
  }
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  SGT sgt(n, s);
  while (m--) {
    int x, d;
    scanf("%d%d", &x, &d);
    x--;
    s[x] = '0' + d;
    sgt.traverse(Build{s}, x, x);
    printf("%d\n", sgt.root()[0][0]);
  }
}