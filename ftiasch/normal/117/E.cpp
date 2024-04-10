#include <bits/stdc++.h>

template <typename NestedT> struct HeavyLightDecomposition {
  using Tree = std::vector<std::vector<int>>;

  explicit HeavyLightDecomposition(int n, const Tree &tree, int root)
      : path(n), depth(n), lowest(n), highest(n) {
    build(tree, -1, root);
    for (int u = 0; u < n; ++u) {
      lowest[u] = lowest[highest[u]];
      if (highest[u] == u) {
        path[u] = new NestedT{depth[u] - get_lowest_depth(u)};
      }
    }
  }

  template <typename Result> Result query(bool include_lca, int a, int b) {
    Result result;
    while (highest[a] != highest[b]) {
      int &p = get_lowest_depth(a) > get_lowest_depth(b) ? a : b;
      int base = depth[highest[p]];
      result.update(path[highest[p]], base - depth[p],
                    base - get_lowest_depth(p) - 1);
      p = lowest[p];
    }
    if (include_lca || a != b) {
      if (depth[a] < depth[b]) {
        std::swap(a, b);
      }
      // depth[a] >= depth[b]
      int base = depth[highest[a]];
      result.update(path[highest[a]], base - depth[a],
                    base - depth[b] - (!include_lca));
    }
    return result;
  }

private:
  int build(const Tree &tree, int p, int u) {
    depth[u] = ~p ? depth[p] + 1 : 0;
    int size = 1;
    std::pair<int, int> candidate{0, u};
    for (int v : tree[u]) {
      if (v != p) {
        int subtree_size = build(tree, u, v);
        size += subtree_size;
        candidate =
            std::max(candidate, std::make_pair(subtree_size, highest[v]));
      }
    }
    highest[u] = candidate.second;
    lowest[highest[u]] = p;
    return size;
  }

  int get_lowest_depth(int u) const {
    return ~lowest[u] ? depth[lowest[u]] : -1;
  }

  std::vector<NestedT *> path;
  std::vector<int> depth, lowest, highest;
};

struct SegmentTree {
  explicit SegmentTree(int n) : n(n), tree(n << 1) {
  }

  static int get_id(int l, int r) { return l + r | (l != r); }

  int count() { return count(0, n - 1); }

  int count(int a, int b) { return count(0, n - 1, a, b); }

  void flip(int a, int b) { return flip(0, n - 1, a, b); }

private:
  struct Node {
    void flip(int l, int r) {
      flipped ^= 1;
      count = (r - l + 1) - count;
    }

    bool flipped;
    int count;
  };

#define PUSH_DOWN                                                              \
  do {                                                                         \
    if (tree[id].flipped) {                                                    \
      tree[id].flipped = false;                                                \
      tree[lid].flip(l, m);                                                    \
      tree[rid].flip(m + 1, r);                                                \
    }                                                                          \
  } while (0)

  int count(int l, int r, int a, int b) {
    if (b < l || r < a) {
      return 0;
    }
    int id = get_id(l, r);
    if (a <= l && r <= b) {
      return tree[id].count;
    }
    int m = (l + r) >> 1;
    int lid = get_id(l, m);
    int rid = get_id(m + 1, r);
    PUSH_DOWN;
    return count(l, m, a, b) + count(m + 1, r, a, b);
  }

  void flip(int l, int r, int a, int b) {
    if (b < l || r < a) {
      return;
    }
    int id = get_id(l, r);
    if (a <= l && r <= b) {
      tree[id].flip(l, r);
    } else {
      int m = (l + r) >> 1;
      int lid = get_id(l, m);
      int rid = get_id(m + 1, r);
      PUSH_DOWN;
      flip(l, m, a, b);
      flip(m + 1, r, a, b);
      tree[id].count = tree[lid].count + tree[rid].count;
    }
  }

#undef PUSH_DOWN

  int n;
  std::vector<Node> tree;
};

struct Flip {
  void update(SegmentTree *tree, int a, int b) {
    delta -= tree->count();
    tree->flip(a, b);
    delta += tree->count();
  }

  int delta = 0;
};

struct Count {
  void update(SegmentTree *tree, int a, int b) { sum += tree->count(a, b); }

  int sum = 0;
};

template <typename T> void erase(std::vector<T> &v, T e) {
  v.erase(std::find(v.begin(), v.end(), e));
}

void propagate(const std::vector<std::vector<int>> &graph,
               std::vector<int> &cycidx, int i, int u) {
  for (int v : graph[u]) {
    if (cycidx[v] == -1) {
      cycidx[v] = i;
      propagate(graph, cycidx, i, v);
    }
  }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<int> degree(n);
  {
    std::vector<int> queue;
    queue.reserve(n);
    for (int i = 0; i < n; ++i) {
      if ((degree[i] = graph[i].size()) == 1) {
        queue.push_back(i);
      }
    }
    for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
      int u = queue[head];
      for (int v : graph[u]) {
        if (--degree[v] == 1) {
          queue.push_back(v);
        }
      }
    }
  }
  std::vector<int> cycle;
  int c0 = 0;
  while (degree[c0] != 2) {
    c0++;
  }
  int cm = -1;
  {
    int u = c0;
    do {
      cycle.push_back(u);
      for (int v : graph[u]) {
        if (v != cm && degree[v] == 2) {
          cm = u;
          u = v;
          break;
        }
      }
    } while (u != c0);
  }
  std::vector<int> cycidx(n, -1);
  int m = cycle.size();
  for (int i = 0; i < m; ++i) {
    cycidx[cycle[i]] = i;
  }
  for (int i = 0; i < m; ++i) {
    propagate(graph, cycidx, i, cycle[i]);
  }
  erase(graph[c0], cm);
  erase(graph[cm], c0);
  HeavyLightDecomposition<SegmentTree> ds{n, graph, c0};
  int on_tree_edges = 0, on_nontree_edges = 0;
  for (int _ = 0, a, b; _ < q; ++_) {
    scanf("%d%d", &a, &b);
    int i = cycidx[--a];
    int j = cycidx[--b];
    if (i == j) {
      on_tree_edges += ds.query<Flip>(false, a, b).delta;
    } else {
      on_tree_edges += ds.query<Flip>(false, a, cycle[i]).delta;
      on_tree_edges += ds.query<Flip>(false, b, cycle[j]).delta;
      int idist = std::abs(i - j);
      int odist = m - idist;
      int inode = cycle[(i + 1) % m];
      int onode = cycle[(i + m - 1) % m];
      if (i > j) {
        std::swap(i, j);
        std::swap(inode, onode);
      }
      if (idist < odist || (idist == odist && inode < onode)) {
        on_tree_edges += ds.query<Flip>(false, cycle[i], cycle[j]).delta;
      } else {
        on_tree_edges += ds.query<Flip>(false, c0, cycle[i]).delta;
        on_tree_edges += ds.query<Flip>(false, cycle[j], cm).delta;
        on_nontree_edges ^= 1;
      }
    }
    printf("%d\n",
           n - on_tree_edges - on_nontree_edges +
               ((ds.query<Count>(false, c0, cm).sum + on_nontree_edges) == m));
  }
}