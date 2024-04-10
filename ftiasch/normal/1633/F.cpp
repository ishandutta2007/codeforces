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
#line 2 "sol.cpp"

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
#line 4 "sol.cpp"

#include <bits/stdc++.h>

const int N = 200'001;

int n, to[N << 1], head[N], next[N << 1], parent[N], prefer[N], weight[N];

int prepare(int u) {
  int size_u = 1;
  std::pair<int, int> candidate{0, u};
  for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
    int v = to[iterator];
    if (v != parent[u]) {
      parent[v] = u;
      weight[v] = (iterator >> 1) + 1;
      int size_v = prepare(v);
      size_u += size_v;
      candidate = std::max(candidate, {size_v, v});
    }
  }
  prefer[u] = candidate.second;
  return size_u;
}

int dfn[N], top[N], order[N];

void prepare2(int &&clock, int u, int t) {
  order[dfn[u] = clock++] = u;
  top[u] = t;
  if (prefer[u] != u) {
    prepare2(std::move(clock), prefer[u], t);
    for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
      int v = to[iterator];
      if (v != parent[u] && v != prefer[u]) {
        prepare2(std::move(clock), v, v);
      }
    }
  }
}

using Pair = std::pair<int, long long>;

Pair operator+(const Pair &p, const Pair &q) {
  return {p.first + q.first, p.second + q.second};
}

struct Node {
  void flip() {
    flipped ^= 1;
    std::swap(sum[0], sum[1]);
  }

  bool flipped;
  Pair sum[2];
};

struct Build {
  void update(int l, int r, Node &n) {
    if (l == r) {
      n.sum[0] = {1, weight[order[l]]};
    }
  }
};

struct Flip {
  void update(int l, int r, Node &n) { n.flip(); }
};

struct Report {
  void update(int l, int r, const Node &n) {
    if (l == r && n.flipped) {
      result.push_back(n.sum[1].second);
    }
  }

  void write() {
    std::sort(result.begin(), result.end());
    printf("%d", static_cast<int>(result.size()));
    for (int w : result) {
      printf(" %d", w);
    }
    puts("");
  }

  std::vector<int> result;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(int n) : SegmentTreeBase(n) { traverse_all(Build{}); }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.flipped) {
      n.flipped = false;
      ln.flip();
      rn.flip();
    }
  }

  static void collect(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    n.sum[0] = ln.sum[0] + rn.sum[0];
    n.sum[1] = ln.sum[1] + rn.sum[1];
  }
};

int main() {
  scanf("%d", &n);
  for (int i = 0; i < (n - 1) << 1; ++i) {
    scanf("%d", to + i);
  }
  memset(head, -1, sizeof(*head) * (n + 1));
  for (int i = 0; i < (n - 1) << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  parent[1] = 0;
  prepare(1);
  prepare2(0, 1, 1);
  SGT sgt(n);
  int activated = 1;
  sgt.traverse(Flip{}, 0, 0);
  while (true) {
    int op;
    scanf("%d", &op);
    switch (op) {
    case 0:
    case 3: {
      return 0;
    }
    case 1: {
      int v;
      scanf("%d", &v);
      activated++;
      while (v) {
        int t = top[v];
        sgt.traverse(Flip{}, dfn[t], dfn[v]);
        v = parent[t];
      }
      auto [count1, sum1] = sgt.root().sum[1];
      printf("%lld\n", count1 + count1 == activated ? sum1 : 0);
      fflush(stdout);
      break;
    }
    case 2: {
      auto [count1, sum1] = sgt.root().sum[1];
      if (count1 + count1 == activated) {
        sgt.traverse_all(Report{}).write();
      } else {
        puts("0");
      }
      fflush(stdout);
      break;
    }
    }
  }
}