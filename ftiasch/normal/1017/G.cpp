#line 1 "/home/ftiasch/Documents/shoka/heavy_light_decomp_base.h"
#include <algorithm>
#include <vector>

struct HeavyLightDecompositionBase {
  using Tree = std::vector<std::vector<int>>;

  HeavyLightDecompositionBase(const Tree &tree, int root)
      : n(tree.size()), parent(n), size(n), depth(n), top(n), bottom(n) {
    parent[root] = -1;
    build(tree, root);
    for (int u = 0; u < n; ++u) {
      top[u] = top[bottom[u]];
    }
  }

  int lca(int a, int b) const {
    while (bottom[a] != bottom[b]) {
      if (get_lowest_depth(a) > get_lowest_depth(b)) {
        a = top[a];
      } else {
        b = top[b];
      }
    }
    return depth[a] < depth[b] ? a : b;
  }

  int n;
  std::vector<int> parent, size, depth;

protected:
  void build(const Tree &tree, int u) {
    const int p = parent[u];
    depth[u] = ~p ? depth[p] + 1 : 0;
    size[u] = 1;
    std::pair<int, int> candidate{0, u};
    for (int v : tree[u]) {
      if (v != p) {
        parent[v] = u;
        build(tree, v);
        size[u] += size[v];
        candidate = std::max(candidate, std::make_pair(size[v], bottom[v]));
      }
    }
    bottom[u] = candidate.second;
    top[bottom[u]] = p;
  }

  int get_lowest_depth(int u) const { return ~top[u] ? depth[top[u]] : -1; }

  std::vector<int> top, bottom;
};
#line 2 "/home/ftiasch/Documents/shoka/heavy_light_decomp_subtree.h"

template <typename NestedT, bool BIASED = false>
struct HeavyLightDecompositionSubtree : public HeavyLightDecompositionBase {
  HeavyLightDecompositionSubtree(const Tree &tree, int root)
      : HeavyLightDecompositionBase(tree, root), position(n) {
    vertices.reserve(n);
    dfs(tree, root);
    sgt = new NestedT(vertices);
  }

  ~HeavyLightDecompositionSubtree() { delete sgt; }

  template <typename Handler> Handler traverse_all(Handler &&h) {
    return sgt->template traverse_all<Handler>(std::forward<Handler>(h));
  }

  template <typename Handler> Handler traverse_subtree(Handler &&h, int u) {
    return sgt->template traverse<Handler>(
        std::forward<Handler>(h), position[u], position[u] + size[u] - 1);
  }

  template <typename Handler>
  Handler traverse_path(Handler &&h, bool include_lca, int a, int b) {
    while (bottom[a] != bottom[b]) {
      if (get_lowest_depth(a) > get_lowest_depth(b)) {
        h.template update<0>(sgt,
                             position[a] - (depth[a] - get_lowest_depth(a)) + 1,
                             position[a]);
        a = top[a];
      } else {
        h.template update<1>(sgt,
                             position[b] - (depth[b] - get_lowest_depth(b)) + 1,
                             position[b]);
        b = top[b];
      }
    }
    if (include_lca || a != b) {
      if (depth[a] > depth[b]) {
        h.template update<0>(sgt, position[b] + (!include_lca), position[a]);
      } else {
        h.template update<1>(sgt, position[a] + (!include_lca), position[b]);
      }
    }
    return h;
  }

private:
  void dfs(const Tree &tree, int u) {
    position[u] = vertices.size();
    vertices.push_back(u);
    for (int v : tree[u]) {
      if (v != parent[u] && bottom[v] == bottom[u]) {
        dfs(tree, v);
        break;
      }
    }
    for (int v : tree[u]) {
      if (v != parent[u] && bottom[v] != bottom[u]) {
        dfs(tree, v);
      }
    }
  }

  std::vector<int> vertices, position;
  NestedT *sgt;
};
#line 1 "/home/ftiasch/Documents/shoka/io.h"
#include <cctype>
#include <cstdint>
#include <cstdio>

struct FastIn {
  FastIn(FILE *in_ = stdin) : in(in_) {}

  char next_char() {
    if (head == length) {
      head = 0;
      length = fread(buffer, 1, LENGTH, in);
    }
    return buffer[head++];
  }

  uint64_t next_uint() {
    char c = next_char();
    while (!std::isdigit(c)) {
      c = next_char();
    }
    uint64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10U + c - '0';
    }
    return x;
  }

  int64_t next_int() {
    char c = next_char();
    while (!std::isdigit(c) && c != '-') {
      c = next_char();
    }
    int64_t sign = 1;
    if (c == '-') {
      sign = -1;
      c = next_char();
    }
    int64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10 + c - '0';
    }
    return sign * x;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  size_t head = 0;
  size_t length = 0;
  FILE *in;
};

struct FastOut {
  static const int BUFSIZE = 4096;

  void putchar(char c) {
    buf[len++] = c;
    if (len == BUFSIZE) {
      fwrite(buf, 1, BUFSIZE, stdout);
      len = 0;
    }
  }

  void puts(const char *s) {
    while (*s) {
      putchar(*(s++));
    }
    putchar('\n');
  }

  void print(int64_t n) {
    static char bufn[32];
    bool negative = false;
    if (n < 0) {
      n = -n;
      negative = true;
    }
    int top = 32;
    while (n >= 10) {
      bufn[--top] = '0' + n % 10;
      n /= 10;
    }
    bufn[--top] = '0' + n;
    if (negative) {
      bufn[--top] = '-';
    }
    for (; top < 32; ++top) {
      putchar(bufn[top]);
    }
  }

  void println(int64_t n) {
    print(n);
    putchar('\n');
  }

  ~FastOut() {
    if (len) {
      fwrite(buf, 1, len, stdout);
    }
    fflush(stdout);
  }

  char buf[BUFSIZE];
  int len = 0;
};

static FastIn STDIN;
static FastOut STDOUT;
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
#line 4 "main.cc"

#include <bits/stdc++.h>

struct Info {
  int sum = 0, maxsuf = -1;
};

Info operator+(const Info &a, const Info &b) {
  return Info{a.sum + b.sum, std::max(a.maxsuf + b.sum, b.maxsuf)};
}

struct Node {
  void cover(int l, int r) {
    covered = true;
    info.sum = -(r - l + 1);
    info.maxsuf = -1;
  }

  int covered = false;
  Info info;
};

struct SGT : public SegmentTreeBase<Node, SGT> {
  SGT(const std::vector<int> &vertices) : SegmentTreeBase(vertices.size()) {}

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {
    if (n.covered) {
      n.covered = false;
      ln.cover(l, m);
      rn.cover(m + 1, r);
    }
  }

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.info = ln.info + rn.info;
  }

  struct Cover {
    void update(int l, int r, Node &n) { n.cover(l, r); }
  };

  struct Query {
    Query(Info &result) : result(result) {}

    void update(int l, int r, Node &n) { result = n.info + result; }

    Info &result;
  };

  struct Add {
    void update(int l, int r, Node &n) {
      assert(l == r);
      n.info.sum += delta;
      n.info.maxsuf = n.info.sum;
    }

    int delta;
  };
};

struct Query {
  template <int _> void update(SGT *t, int l, int r) {
    t->reverse_traverse(SGT::Query(result), l, r);
  }

  int maxsuf() const { return result.maxsuf; }

  Info result;
};

struct Add {
  template <int _> void update(SGT *t, int l, int r) {
    assert(l == r);
    t->traverse(SGT::Add{delta}, l, r);
  }

  int delta;
};

using HLD = HeavyLightDecompositionSubtree<SGT>;

int main() {
  int n = STDIN.next_uint();
  int q = STDIN.next_uint();
  std::vector<std::vector<int>> tree(n);
  for (int i = 1; i < n; ++i) {
    int p = STDIN.next_uint() - 1;
    tree[p].push_back(i);
    tree[i].push_back(p);
  }
  HLD hld(tree, 0);
  hld.traverse_all(SGT::Cover());
  while (q--) {
    int op = STDIN.next_uint();
    int v = STDIN.next_uint() - 1;
    if (op == 1) {
      hld.traverse_path(Add{1}, true, v, v);
    } else if (op == 2) {
      hld.traverse_subtree(SGT::Cover(), v);
      int m = hld.traverse_path(Query{}, true, 0, v).maxsuf();
      if (m >= 0) {
        hld.traverse_path(Add{-1 - m}, true, v, v);
      }
    } else {
      STDOUT.puts(hld.traverse_path(Query{}, true, 0, v).maxsuf() >= 0
                      ? "black"
                      : "white");
    }
  }
}