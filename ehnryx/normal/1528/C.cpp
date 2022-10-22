#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/data_structure/segment_tree.h"

template <class Node_t, typename Query_t, bool push = true, bool break_cond = false>
struct segment_tree {
  int lim, length;
  vector<Node_t> data;
  Node_t& operator [] (int i) { return data[i]; }

  segment_tree(int n, bool init_build = false): lim(n),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2*length) {
    if (init_build) build();
  }
  template <class Input_t>
  segment_tree(const vector<Input_t>& a, int offset = 0): lim((int)size(a)),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2*length) {
    for (int i = offset; i < lim; i++) {
      data[length + i] = Node_t(a[i]);
    }
    build();
  }
  void build() {
    for (int i = length - 1; i > 0; i--) {
      data[i].pull(data[2*i], data[2*i + 1]);
    }
  }

  template <class... Args>
  void update_range(int l, int r, const Args&... args) {
    update(l, r, args...);
  }
  template <class... Args>
  void update(int l, int r, const Args&... args) {
    if (r < l) return;
    assert(0 <= l && r < lim);
    __update(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update(int l, int r, int i, int first, int last, const Args&... args) {
    if constexpr (break_cond) {
      if (data[i].break_condition(args...)) return;
      if (l <= first && last <= r && data[i].put_condition(args...)) {
        return data[i].put(args...);
      }
      assert(i < length);
    } else {
      if (l <= first && last <= r) {
        return data[i].put(args...);
      }
    }
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(l <= mid) __update(l, r, 2*i, first, mid, args...);
    if(mid < r) __update(l, r, 2*i + 1, mid + 1, last, args...);
    data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_range(int l, int r, const Args&... args) {
    return query(l, r, args...);
  }
  template <class... Args>
  Query_t query(int l, int r, const Args&... args) {
    if (r < l) return Node_t::default_value();
    assert(0 <= l && r < lim);
    return __query(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query(int l, int r, int i, int first, int last, const Args&... args) {
    if (l <= first && last <= r) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(r <= mid) return __query(l, r, 2*i, first, mid, args...);
    if(mid < l) return __query(l, r, 2*i + 1, mid + 1, last, args...);
    return Node_t::merge(
        __query(l, r, 2*i, first, mid, args...),
        __query(l, r, 2*i + 1, mid + 1, last, args...));
  }

  template <class... Args>
  void update_point(int x, const Args&... args) {
    assert(0 <= x && x < lim);
    __update_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update_point(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].put(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) __update_point(x, 2*i, first, mid, args...);
    else __update_point(x, 2*i + 1, mid + 1, last, args...);
    data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_point(int x, const Args&... args) {
    assert(0 <= x && x < lim);
    return __query_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_point(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) return __query_point(x, 2*i, first, mid, args...);
    else return __query_point(x, 2*i + 1, mid + 1, last, args...);
  }

  template <class... Args>
  Query_t query_up(int x, const Args&... args) {
    assert(0 <= x && x < lim);
    return __query_up(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_up(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) {
      return Node_t::merge(data[i].get(args...), __query_up(x, 2*i, first, mid, args...));
    } else {
      return Node_t::merge(data[i].get(args...), __query_up(x, 2*i + 1, mid + 1, last, args...));
    }
  }

  template <class... Args>
  int search_left(int l, int r, Args... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return __search_left(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int search_left_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return __search_left(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int __search_left(int l, int r, int i, int first, int last, tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, tuple_cat(tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (l <= mid ? __search_left(l, r, 2*i, first, mid, args) : lim);
    if (res == lim && mid < r) res = __search_left(l, r, 2*i + 1, mid + 1, last, args);
    return res;
  }

  template <class... Args>
  int search_right(int l, int r, Args... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return __search_right(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int search_right_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    assert(0 <= l && r < lim);
    return __search_right(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int __search_right(int l, int r, int i, int first, int last, tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, tuple_cat(tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (mid < r ? __search_right(l, r, 2*i + 1, mid + 1, last, args) : lim);
    if (res == lim && l <= mid) res = __search_right(l, r, 2*i, first, mid, args);
    return res;
  }
};

// END #include "../../../lca/data_structure/segment_tree.h"
// START #include "../../../lca/tree/range_query_tree.h"

// START #include "rooted_tree.h"

struct rooted_tree {
  vector<vector<int>> adj;
  vector<int> parent, depth, subtree, start, preorder, in, out;
  vector<int>& operator [] (int i) { return adj[i]; }
  rooted_tree(const vector<vector<int>>& adj_list, int root): adj(adj_list),
    parent(adj.size(), -1), depth(adj.size()), subtree(adj.size()), start(adj.size()),
    in(adj.size()), out(adj.size()) {
    preorder.reserve(adj.size());
    build(root, -1, 0);
  }
  rooted_tree(vector<vector<int>>&& adj_list, int root): adj(move(adj_list)),
    parent(adj.size(), -1), depth(adj.size()), subtree(adj.size()), start(adj.size()),
    in(adj.size()), out(adj.size()) {
    preorder.reserve(adj.size());
    build(root, -1, 0);
  }

private:
  int build(int u, int par, int idx) {
    in[u] = idx++;
    start[u] = (int)preorder.size();
    preorder.push_back(u);
    parent[u] = par;
    subtree[u] = 1;
    if (par != -1) {
      depth[u] = depth[par] + 1;
      vector<int>::iterator it = find(adj[u].begin(), adj[u].end(), par);
      if (it != adj[u].end()) {
        adj[u].erase(it);
      }
    }
    for (int v : adj[u]) {
      idx = build(v, u, idx);
      subtree[u] += subtree[v];
    }
    out[u] = idx++;
    return idx;
  }
};

// END #include "rooted_tree.h"

template <class DS, typename Query_t>
struct range_query_tree : rooted_tree {
  DS range_ds;
  vector<int> top; // top of heavy chains
  range_query_tree(const vector<vector<int>>& adj_list, int root):
    rooted_tree(adj_list, root), range_ds((int)adj.size()), top(adj.size()) {
    preorder.clear();
    top[root] = root;
    build(root, 0);
  }
  range_query_tree(vector<vector<int>>&& adj_list, int root):
    rooted_tree(move(adj_list), root), range_ds((int)adj.size()), top(adj.size()) {
    preorder.clear();
    top[root] = root;
    build(root, 0);
  }

  int lca(int u, int v) const {
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      u = parent[top[u]];
    }
    return depth[u] < depth[v] ? u : v;
  }

  template <class... Args>
  void update_point(int u, const Args&... args) {
    range_ds.update_point(start[u], args...);
  }
  template <class... Args>
  Query_t query_point(int u, const Args&... args) {
    return range_ds.query_point(start[u], args...);
  }

  template <class... Args>
  void update_subtree(int u, const Args&... args) {
    range_ds.update_range(start[u], start[u] + subtree[u] - 1, args...);
  }
  template <class... Args>
  Query_t query_subtree(int u, const Args&... args) {
    return range_ds.query_range(start[u], start[u] + subtree[u] - 1, args...);
  }

  template <class... Args>
  int update_path(int u, int v, bool include_lca, const Args&... args) {
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      range_ds.update_range(start[top[u]], start[u], args...);
      u = parent[top[u]];
    }
    if (include_lca || u != v) {
      if (depth[u] < depth[v]) swap(u, v);
      range_ds.update_range(start[v] + !include_lca, start[u], args...);
    }
    return v; // return the lowest common ancestor
  }
  template <class Combine, class... Args>
  Query_t query_path(int u, int v, bool include_lca, Query_t res,
                     const Combine& merge, const Args&... args) {
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) swap(u, v);
      res = merge(res, range_ds.query_range(start[top[u]], start[u], args...));
      u = parent[top[u]];
    }
    if (include_lca || u != v) {
      if (depth[u] < depth[v]) swap(u, v);
      res = merge(res, range_ds.query_range(start[v] + !include_lca, start[u], args...));
    }
    return res;
  }

  template <class... Args>
  int search_path(int u, int v, bool include_lca, Args... args) {
    bool rev = false;
    vector<pair<int, int>> down;
    while (top[u] != top[v]) {
      if (depth[top[u]] < depth[top[v]]) {
        swap(u, v);
        rev ^= 1;
      }
      int left = start[top[u]];
      int right = start[u];
      if (rev) {
        down.emplace_back(left, right);
      } else {
        int res = range_ds.search_right_mutable(left, right, args...);
        if (res != range_ds.lim) return preorder[res];
      }
      u = parent[top[u]];
    }
    if (include_lca || u != v) {
      if (depth[u] < depth[v]) {
        swap(u, v);
        rev ^= 1;
      }
      int left = start[v] + !include_lca;
      int right = start[u];
      if (rev) {
        down.emplace_back(left, right);
      } else {
        int res = range_ds.search_right_mutable(left, right, args...);
        if (res != range_ds.lim) return preorder[res];
      }
    }
    for (auto it = down.rbegin(); it != down.rend(); it++) {
      int res = range_ds.search_left_mutable(it->first, it->second, args...);
      if (res != range_ds.lim) return preorder[res];
    }
    return -1;
  }

private:
  int build(int u, int idx) {
    in[u] = idx++;
    start[u] = (int)preorder.size();
    preorder.push_back(u);
    if (!adj[u].empty()) {
      pair<int, size_t> big;
      for (size_t i = 0; i < adj[u].size(); i++) {
        big = max(big, pair(subtree[adj[u][i]], i));
      }
      if (big.second > 0) {
        swap(adj[u][0], adj[u][big.second]);
      }
      // continue heavy chain
      top[adj[u].front()] = top[u];
      idx = build(adj[u].front(), idx);
      // start new chain
      for (size_t i = 1; i < adj[u].size(); i++) {
        int v = adj[u][i];
        top[v] = v;
        idx = build(v, idx);
      }
    }
    out[u] = idx++;
    return idx;
  }
};

// END #include "../../../lca/tree/range_query_tree.h"

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

struct Node {
  int value;
  void put(int v) { value = v; }
  int get() const { return value; }
  void push(Node&, Node&) {}
  void pull(const Node& a, const Node& b) {
    value = max(a.value, b.value);
  }
  bool contains() const { return value > 0; }
  static int merge(int a, int b) { return max(a, b); }
  static int default_value() { assert(false); }
};
using HLD = range_query_tree<segment_tree<Node, int>, int>;

int solve(int u, int ans, const vector<vector<int>>& adj, HLD& hld) {
  int down = hld.query_subtree(u);
  int up = hld.query_path(u, 1, true, 0, Node::merge);
  if (!down) {
    if(!up) {
      ans++;
    } else {
      hld.update_point(up, 0);
    }
    hld.update_point(u, u);
  }
  int res = ans;
  for(int v : adj[u]) {
    res = max(res, solve(v, ans, adj, hld));
  }
  if (!down) {
    if (up) {
      hld.update_point(up, up);
    }
    hld.update_point(u, 0);
  }
  return res;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1), other(n+1);
    for(int i=2; i<=n; i++) {
      int p;
      cin >> p;
      adj[p].push_back(i);
    }
    for(int i=2; i<=n; i++) {
      int p;
      cin >> p;
      other[p].push_back(i);
    }
    HLD hld(move(other), 1);
    cout << solve(1, 0, adj, hld) << nl;
  }

  return 0;
}