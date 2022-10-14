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
#line 3 "/tmp/tmp-4448Z7p99pmJeyMH.cpp"

#line 5 "/tmp/tmp-4448Z7p99pmJeyMH.cpp"

using Pair = std::pair<int, int>;

struct FwdTree : public SegmentTreeBase<Pair, FwdTree> {
  struct Build {
    void update(int l, int r, Pair &n) {
      if (l == r) {
        n = {p[l], l};
      }
    }

    const std::vector<int> &p;
  };

  struct Query {
    void update(int l, int r, const Pair &n) { result = std::max(result, n); }

    std::pair<int, int> result{-1, -1};
  };

  struct Remove {
    void update(int l, int r, Pair &n) { n = {-1, -1}; }
  };

  FwdTree(const std::vector<int> &p) : SegmentTreeBase(p.size()) {
    traverse_all(Build{p});
  }

  static void collect(int l, int m, int r, Pair &n, const Pair &ln,
                      const Pair &rn) {
    n = std::max(ln, rn);
  }

  static void propagate(int l, int m, int r, Pair &n, Pair &ln, Pair &rn) {}
};

using BwdNode = std::vector<Pair>;

struct BwdTree : public SegmentTreeBase<BwdNode, BwdTree> {
  struct Cover {
    void update(int l, int r, BwdNode &n) { n.push_back(p); }

    Pair p;
  };

  BwdTree(int n) : SegmentTreeBase(n) {}

  static void collect(int l, int m, int r, BwdNode &n, const BwdNode &ln,
                      const BwdNode &rn) {}

  static void propagate(int l, int m, int r, BwdNode &n, BwdNode &ln,
                        BwdNode &rn) {}
};

int main() {
  std::ios::sync_with_stdio(false);
  int T = read();
  while (T--) {
    int n = read();
    int a = read() - 1;
    int b = read() - 1;
    auto p = read_vector(n);
    std::vector<Pair> sorted_p(n);
    for (int i = 0; i < n; ++i) {
      sorted_p[i] = {p[i], i};
    }
    std::ranges::sort(sorted_p, std::greater<Pair>());
    FwdTree fwd(p);
    BwdTree bwd(n);
    for (auto [pi, i] : sorted_p) {
      bwd.traverse(BwdTree::Cover{Pair{pi, i}}, i - pi, i + pi);
    }
    std::vector<int> d(n, -1);
    std::queue<int> queue;
    d[a] = 0;
    queue.push(a);
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      while (true) {
        auto [pv, v] =
            fwd.traverse(FwdTree::Query{}, u - p[u], u + p[u]).result;
        if (!~v || (!~d[v] && pv < p[u])) {
          break;
        }
        fwd.traverse(FwdTree::Remove{}, v, v);
        if (!~d[v]) {
          //   std::cerr << "fwd: " << KV(pv) << KV(v) << std::endl;
          d[v] = d[u] + 1;
          queue.push(v);
        }
      }
      int l = 0;
      int r = n - 1;
      while (true) {
        auto &n = bwd.get_node(l, r);
        while (!n.empty()) {
          auto [pv, v] = n.back();
          if (!~d[v] && p[u] < pv) {
            break;
          }
          n.pop_back();
          if (!~d[v]) {
            //   std::cerr << "bwd! " << KV(pv) << KV(v) << std::endl;
            d[v] = d[u] + 1;
            queue.push(v);
          }
        }
        if (l == r) {
          break;
        }
        int m = (l + r) >> 1;
        if (u <= m) {
          r = m;
        } else {
          l = m + 1;
        }
      }
    }
    std::cout << d[b] << "\n";
  }
}