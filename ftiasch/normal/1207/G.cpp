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

#include <bits/stdc++.h>

struct Node;

Node *null;

struct Node {
  Node *add(int l, int r, int a, int b) {
    // [a, b)
    if (b <= l || r <= a) {
      return this;
    }
    Node *n = this;
    if (n == null) {
      n = new Node{0, null, null};
    }
    if (a <= l && r <= b) {
      n->delta++;
      return n;
    }
    int m = (l + r) >> 1;
    n->left = n->left->add(l, m, a, b);
    n->right = n->right->add(m, r, a, b);
    return n;
  }

  int ask(int l, int r, int k) const {
    if (this == null || k < l || r <= k) {
      return 0;
    }
    int m = (l + r) >> 1;
    return delta + left->ask(l, m, k) + right->ask(m, r, k);
  }

  int delta;

  Node *left, *right;
};

Node *merge(Node *a, Node *b) {
  if (a == null) {
    return b;
  }
  if (b == null) {
    return a;
  }
  a->delta += b->delta;
  a->left = merge(a->left, b->left);
  a->right = merge(a->right, b->right);
  return a;
}

const int N = 400'001;
const int C = 26;

char buffer[N];
int song_node[N], pattern_tree[N][C], trie[N][C], fail[N], go[N][C], dfn[N],
    size[N];
std::vector<int> children[N];
std::vector<std::pair<int, int>> queries[N];
Node *sgt[N];
int result[N];

void prepare(int &&clock, int u) {
  dfn[u] = clock++;
  size[u] = 1;
  for (int c = 0; c < C; ++c) {
    int v = pattern_tree[u][c];
    if (~v) {
      prepare(std::move(clock), v);
      size[u] += size[v];
    }
  }
}

void dfs_pattern(int m, int u, int p) {
  for (int c = 0; c < C; ++c) {
    int v = pattern_tree[u][c];
    if (~v) {
      int q = go[p][c];
      sgt[q] = sgt[q]->add(0, m, dfn[v], dfn[v] + size[v]);
      dfs_pattern(m, v, q);
    }
  }
}

Node *dfs_trie(int m, int u) {
  Node *s = sgt[u];
  for (int v : children[u]) {
    auto ss = dfs_trie(m, v);
    s = merge(s, ss);
  }
  for (auto [d, id] : queries[u]) {
    result[id] = s->ask(0, m, d);
  }
  return s;
}

int main() {
  null = new Node{0, nullptr, nullptr};
  null->left = null->right = null;

  int n, pattern_size = 1;
  memset(pattern_tree, -1, sizeof(pattern_tree));
  scanf("%d", &n);
  for (int i = 0, type; i < n; ++i) {
    scanf("%d", &type);
    int p = 0;
    if (type == 1) {
      scanf("%s", buffer);
    } else {
      scanf("%d%s", &p, buffer);
      p = song_node[p - 1];
    }
    int c = *buffer - 'a';
    if (!~pattern_tree[p][c]) {
      pattern_tree[p][c] = pattern_size++;
    }
    song_node[i] = pattern_tree[p][c];
  }
  prepare(0, 0);
  int q, trie_size = 1;
  memset(trie, -1, sizeof(trie));
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int s;
    scanf("%d%s", &s, buffer);
    int p = 0;
    for (int j = 0; buffer[j]; ++j) {
      int c = buffer[j] - 'a';
      if (!~trie[p][c]) {
        trie[p][c] = trie_size++;
      }
      p = trie[p][c];
    }
    queries[p].emplace_back(dfn[song_node[s - 1]], i);
  }
  std::vector<int> queue;
  for (int c = 0; c < C; ++c) {
    int u = trie[0][c];
    if (~u) {
      fail[u] = 0;
      go[0][c] = u;
      queue.push_back(u);
    } else {
      go[0][c] = 0;
    }
  }
  for (int head = 0; head < static_cast<int>(queue.size()); ++head) {
    int u = queue[head];
    for (int c = 0; c < C; ++c) {
      int v = trie[u][c];
      if (~v) {
        fail[v] = go[fail[u]][c];
        go[u][c] = v;
        queue.push_back(v);
      } else {
        go[u][c] = go[fail[u]][c];
      }
    }
  }
  std::fill(sgt, sgt + trie_size, null);
  dfs_pattern(pattern_size, 0, 0);
  for (int i = queue.size(); i-- > 0;) {
    int u = queue[i];
    children[fail[u]].push_back(u);
  }
//   std::cout << KV(trie_size) << queue << std::endl;
  memset(result, -1, sizeof(result));
  dfs_trie(pattern_size, 0);
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}