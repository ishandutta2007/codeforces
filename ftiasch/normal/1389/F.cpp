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
#line 3 "sol.cpp"

#include <bits/stdc++.h>

struct Seg {
  int l, r, c;
};

bool operator<(const Seg &a, const Seg &b) { return a.r < b.r; }

struct Node {
  int dt, mx;
};

struct Add {
  void update(int l, int r, Node &n) {
    n.dt += dt;
    n.mx += dt;
  }

  int dt;
};

struct Ask {
  void update(int l, int r, Node &n) { mx = std::max(mx, n.mx); }

  int mx;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n), n(n) {}

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {}

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.mx = n.dt + std::max(ln.mx, rn.mx);
  }

  void add(int a, int b, int dt) { traverse(Add{dt}, a, b); }

  int ask() { return traverse(Ask{}, 0, n - 1).mx; }

  int n;
};

std::ostream& operator<<(std::ostream& out, const Seg& s) {
    return out << std::map<std::string, int>{
        {"l", s.l},
        {"r", s.r},
        {"c", s.c},
    };
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<Seg> segs(n);
  std::vector<int> rights;
  rights.reserve(n + 1);
  rights.push_back(0);
  for (int i = 0; i < n; ++i) {
    auto &s = segs[i];
    scanf("%d%d%d", &s.l, &s.r, &s.c);
    s.c--;
    rights.push_back(s.r);
  }
  std::sort(rights.begin(), rights.end());
  rights.erase(std::unique(rights.begin(), rights.end()), rights.end());
  int m = rights.size();
  SGT sgts[]{SGT(m), SGT(m)};
  std::sort(segs.begin(), segs.end());
//   std::cout << KV(rights) << std::endl;
//   std::cout << KV(segs) << std::endl;
  int result = 0;
  for (int i = 1, j = 0; i < m; ++i) {
    int r = rights[i];
    while (j < n && segs[j].r <= r) {
      auto &s = segs[j++];
      int l =
          static_cast<int>(std::lower_bound(rights.begin(), rights.end(), s.l) -
                           rights.begin()) -
          1;
      sgts[s.c ^ 1].add(0, l, 1);
    }
    for (int c = 0; c < 2; ++ c) {
        int dp = sgts[c ^ 1].ask();
        sgts[c].add(i, i, dp);
        result = std::max(result, dp);
        // std::cout << "dp[" << r << "][" << c << "]=" << dp << std::endl;
    }
  }
  printf("%d\n", result);
}