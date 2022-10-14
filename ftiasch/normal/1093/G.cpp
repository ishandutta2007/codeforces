#line 1 "/home/ftiasch/Documents/shoka/debug.h"
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace {

template <typename Tuple, size_t... Index>
std::ostream &serialize_tuple(std::ostream &out, const Tuple &t,
                              std::index_sequence<Index...>) {
  out << "(";
  (..., (out << (Index == 0 ? "" : ", ") << std::get<Index>(t)));
  return out << ")";
}

} // namespace

template <typename A, typename B>
std::ostream &operator<<(std::ostream &out, const std::pair<A, B> &v) {
  return out << "(" << v.first << ", " << v.second << ")";
}

template <typename... T>
std::ostream &operator<<(std::ostream &out, const std::tuple<T...> &t) {
  return serialize_tuple(out, t, std::make_index_sequence<sizeof...(T)>());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename T, size_t N>
std::ostream &operator<<(std::ostream &out, const std::array<T, N> &v) {
  return out << std::vector<T>(v.begin(), v.end());
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::list<T> &v) {
  out << "[";
  bool first = true;
  for (auto &&e : v) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << e;
  }
  return out << "]";
}

template <typename K>
std::ostream &operator<<(std::ostream &out, const std::set<K> &s) {
  out << "{";
  bool first = true;
  for (auto &&k : s) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k;
  }
  return out << "}";
}

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &m) {
  out << "{";
  bool first = true;
  for (auto &&[k, v] : m) {
    if (first) {
      first = false;
    } else {
      out << ", ";
    }
    out << k << ": " << v;
  }
  return out << "}";
}

#define KV(x) #x << "=" << x << ";"
#line 1 "/home/ftiasch/Documents/shoka/segment_tree.h"
#include <memory>
#line 3 "/home/ftiasch/Documents/shoka/segment_tree.h"

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
      Impl::propagate(l, m, r, n, ln, rn);
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
#line 3 "sol.cpp"

#include <bits/stdc++.h>

using Vector = std::array<int, 5>;
using Node = std::array<int, 32>;

Node from_vector(const Vector &v) {
  Node result;
  for (int mask = 0; mask < 1 << 5; ++mask) {
    result[mask] = 0;
    for (int i = 0; i < 5; ++i) {
      if (mask >> i & 1) {
        result[mask] -= v[i];
      } else {
        result[mask] += v[i];
      }
    }
  }
  //   std::cout << result << std::endl;
  return result;
}

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      n = from_vector(vs[l]);
    }
  }

  const std::vector<Vector> &vs;
};

struct Modify {
  void update(int l, int r, Node &n) { n = from_vector(v); }

  const Vector &v;
};

struct Query {
  Query() {
    for (int i = 0; i < 32; ++i) {
      result[i] = INT_MAX;
    }
  }

  void update(int l, int r, const Node &n) {
    for (int i = 0; i < 32; ++i) {
      result[i] = std::min(result[i], n[i]);
    }
  }

  Node result;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(const std::vector<Vector> &vs) : SegmentTreeBase(vs.size()) {
    traverse_all(Build{vs});
  }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {}

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    for (int i = 0; i < 32; ++i) {
      n[i] = std::min(ln[i], rn[i]);
    }
  }
};

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<Vector> vs(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", &vs[i][j]);
    }
    for (int j = k; j < 5; ++j) {
      vs[i][j] = 0;
    }
  }
  SGT sgt(vs);
  int q;
  scanf("%d", &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int idx;
      scanf("%d", &idx);
      idx--;
      Vector v;
      std::fill(v.begin(), v.end(), 0);
      for (int j = 0; j < k; ++j) {
        scanf("%d", &v[j]);
      }
      sgt.traverse(Modify{v}, idx, idx);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      r--;
      auto result = sgt.traverse(Query{}, l, r).result;
      int best = 0;
      for (int mask = 0; mask < 1 << 4; ++mask) {
        best = std::max(best, std::abs(result[mask] + result[31 ^ mask]));
      }
      printf("%d\n", best);
    }
  }
}