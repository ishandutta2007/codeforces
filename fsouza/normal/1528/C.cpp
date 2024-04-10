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

struct tree_t {
  int n;
  vector<vector<int>> adj;
  vector<int> preorder, invpreorder, endsubtree;
  tree_t(int _n): n(_n), adj(n) {}
  void dfs(int v, int p) {
    preorder.push_back(v);
    invpreorder[v] = preorder.size() - 1;
    for (int u : adj[v])
      if (u != p)
        dfs(u, v);
    endsubtree[v] = preorder.size() - 1;
  }
  void compute() {
    preorder.reserve(n);
    invpreorder.resize(n, -1);
    endsubtree.resize(n, -1);
    dfs(0, -1);
  }
};

struct segtree_t {
  int n;
  vector<int> tree;
  vector<pair<int, int>> undos;
  segtree_t(int _n): n(_n), tree(4 * n, -1) {}
  void update(int a, int b, int value) {
    update(a, b, value, 0, 0, n - 1);
  }
  void update(int a, int b, int value, int v, int l, int r) {
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      undos.emplace_back(v, tree[v]);
      tree[v] = value;
    } else {
      int m = l + (r - l) / 2;
      update(a, b, value, 2*v+1, l, m);
      update(a, b, value, 2*v+2, m+1, r);
    }
  }
  void rollback(int when) {
    for (int i = (int)undos.size() - 1; i >= when; --i)
      tree[undos[i].first] = undos[i].second;
    undos.resize(when);
  }
  int query(int pos) { return query(pos, 0, 0, n - 1); }
  int query(int pos, int v, int l, int r) {
    if (l == r) {
      return tree[v];
    } else {
      int result = tree[v];
      int m = l + (r - l) / 2;
      if (pos <= m) result = max(result, query(pos, 2*v+1, l, m));
      else result = max(result, query(pos, 2*v+2, m+1, r));
      return result;
    }
  }
};

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    tree_t t1(n), t2(n);
    for (tree_t *tree : {&t1, &t2}) {
      for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p), --p;
        tree->adj[i].push_back(p);
        tree->adj[p].push_back(i);
      }
    }

    t2.compute();

    segtree_t seg(n);
    int final_result = 0;
    int cur_answer_size = 0;

    function<void(int, int)> dfs = [&](int v, int p) {
      int from = t2.invpreorder[v];
      int to = t2.endsubtree[v];

      int now = seg.undos.size();
      int old_cur_answer_size = cur_answer_size;

      int conflict = seg.query(t2.invpreorder[v]);
      if (conflict != -1) {
        --cur_answer_size;

        int rem_from = t2.invpreorder[conflict];
        int rem_to = t2.endsubtree[conflict];
        seg.update(rem_from, rem_to, -1);
      }

      seg.update(from, to, v);
      ++cur_answer_size;

      final_result = max(final_result, cur_answer_size);

      for (int u : t1.adj[v])
        if (u != p)
          dfs(u, v);

      seg.rollback(now);
      cur_answer_size = old_cur_answer_size;
    };
    dfs(0, -1);

    printf("%d\n", final_result);
  }
  return 0;
}