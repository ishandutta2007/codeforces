#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int get_closer(int a, int b, int half_of) {
  if (a == -1) return b;
  if (b == -1) return a;
  if (abs(2 * a - half_of) < abs(2 * b - half_of)) return a;
  else return b;
}

struct segtree_t {
  struct node_t {
    map<int, int> value_count;
    void add(int val) {
      ++value_count[val];
    }
    void erase(int val) {
      auto it = value_count.find(val);
      if (--it->second == 0)
        value_count.erase(it);
    }
    int closer_to(int half_of) {
      int result = -1;
      auto it = value_count.lower_bound((half_of + 1) / 2);
      if (it != value_count.end()) result = get_closer(result, it->first, half_of);
      if (it != value_count.begin()) {
        --it;
        result = get_closer(result, it->first, half_of);
      }
      return result;
    }
  };
  int n;
  vector<node_t> tree;

  segtree_t(int _n): n(_n), tree(4*n) {}

  enum op_t { ADD, ERASE };
  template<op_t op> void update(int pos, int value, int v, int l, int r) {
    if (op == ADD) tree[v].add(value);
    else tree[v].erase(value);
    if (l != r) {
      int m = l+(r-l)/2;
      if (pos <= m) update<op>(pos, value, 2*v+1, l, m);
      else update<op>(pos, value, 2*v+2, m+1, r);
    }
  }
  template<op_t op> void update(int pos, int value) {
    update<op>(pos, value, 0, 0, n-1);
  }
  int query(int a, int b, int half_of, int v, int l, int r) {
    if (a > r || b < l) return -1;
    else if (a <= l && r <= b) return tree[v].closer_to(half_of);
    else {
      int m = l+(r-l)/2;
      return get_closer(query(a, b, half_of, 2*v+1, l, m),
                        query(a, b, half_of, 2*v+2, m+1, r),
                        half_of);
    }
  }
  int query(int a, int b, int half_of) {
    return query(a, b, half_of, 0, 0, n-1);
  }
};

struct tree_t {
  int n;
  vector<vector<int>> adj;
  vector<int> subtreesize, preorder, rank, lastrank, results;
  segtree_t seg;
  tree_t(int _n)
    : n(_n), adj(n), subtreesize(n), rank(n), lastrank(n), results(n), seg(n) {}
  void dfs(int v, int p) {
    subtreesize[v] = 1;
    rank[v] = preorder.size();
    preorder.push_back(v);
    for (int u : adj[v])
      if (u != p) {
        dfs(u, v);
        subtreesize[v] += subtreesize[u];
      }
    lastrank[v] = preorder.size() - 1;
  }
  void init(int _root) {
    root = _root;
    dfs(_root, -1);
  }
  int root;
  vector<int> dfs_stack;
  vector<int> dfs_stack_sts;
  void dfs2(int v, int p) {
    dfs_stack.push_back(v);
    dfs_stack_sts.push_back(subtreesize[v]);
    seg.update<segtree_t::ERASE>(rank[v], subtreesize[v]);
    for (int u : adj[v])
      if (u != p)
        dfs2(u, v);

    if (adj[v].size() <= 1) {
      results[v] = subtreesize[root] - 1;
    } else {
      int smallest = p != -1 ? subtreesize[root] - subtreesize[v] : n;
      int biggest = subtreesize[root] - subtreesize[v], biggest_from = p;
      int second_biggest = 0;
      for (int u : adj[v])
        if (u != p) {
          smallest = min(smallest, subtreesize[u]);
          if (subtreesize[u] > second_biggest) {
            second_biggest = subtreesize[u];
            if (second_biggest > biggest) {
              swap(biggest, second_biggest);
              biggest_from = u;
            }
          }
        }

      int closest_size;
      if (biggest_from != p) {
        closest_size =
            get_closer(seg.query(rank[biggest_from], lastrank[biggest_from],
                                 biggest - smallest),
                       0, biggest - smallest);
      } else {
        closest_size =
          get_closer(seg.query(0, rank[v] - 1, biggest - smallest),
                     seg.query(lastrank[v] + 1, n - 1, biggest - smallest),
                     biggest - smallest);

        auto it = lower_bound(dfs_stack_sts.rbegin(), dfs_stack_sts.rend(),
                              (biggest - smallest + 1) / 2 + subtreesize[v]);
        if (it != dfs_stack_sts.rend())
          closest_size = get_closer(closest_size, *it - subtreesize[v],
                                    biggest - smallest);
        if (it != dfs_stack_sts.rbegin()) {
          --it;
          closest_size = get_closer(closest_size, *it - subtreesize[v],
                                    biggest - smallest);
        }
      }

      results[v] = max(second_biggest,
                       max(biggest - closest_size, smallest + closest_size));
    }

    seg.update<segtree_t::ADD>(rank[v], subtreesize[v]);
    dfs_stack_sts.pop_back();
    dfs_stack.pop_back();
  }
  void solve(int _root) {
    root = _root;
    for (int v = 0; v < n; ++v)
      seg.update<segtree_t::ADD>(rank[v], subtreesize[v]);
    dfs2(root, -1);
  }
};

int main() {
  int n;
  scanf("%d", &n);
  tree_t tree(n);
  int root = -1;
  for (int i = 0; i < n; ++i) {
    int parent, v;
    scanf("%d %d", &parent, &v), --parent, --v;
    if (parent == -1) root = v;
    else {
      tree.adj[v].push_back(parent);
      tree.adj[parent].push_back(v);
    }
  }
  assert(root != -1);
  tree.init(root);
  tree.solve(root);

  for (int v = 0; v < n; ++v)
    printf("%d\n", tree.results[v]);

  return 0;
}