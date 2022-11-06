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

struct segtree_t {
  struct node_t {
    int cost[4][4];
    node_t() {}
    node_t(int v) {
      for (int a = 0; a < 4; ++a)
        for (int b = 0; b < 4; ++b)
          cost[a][b] = INT_MAX;

      for (int a = 0; a < 4; ++a)
        if (a != v)
          cost[a][a] = 0;
      cost[v][v] = 1;
      if (v + 1 < 4) {
        cost[v][v + 1] = 0;
      }
    }
    node_t(const node_t &l, const node_t &r) {
      for (int a = 0; a < 4; ++a)
        for (int b = 0; b < 4; ++b) {
          cost[a][b] = INT_MAX;
          for (int c = 0; c < 4; ++c)
            if (l.cost[a][c] != INT_MAX && r.cost[c][b] != INT_MAX)
              cost[a][b] = min(cost[a][b], l.cost[a][c] + r.cost[c][b]);
        }
    }
  };
  int n;
  vector<node_t> tree;
  segtree_t(const string &s): n(s.size()), tree(4*n) {
    build(0, 0, n - 1, s);
  }
  void build(int v, int l, int r, const string &s) {
    if (l == r) {
      tree[v] = node_t(s[l] - 'a');
    } else {
      int m = l + (r - l) / 2;
      build(2*v+1, l, m, s);
      build(2*v+2, m+1, r, s);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  void update(int pos, int value) {
    update(pos, value, 0, 0, n - 1);
  }
  void update(int pos, int value, int v, int l, int r) {
    if (l == r) {
      tree[v] = node_t(value);
    } else {
      int m = l + (r - l) / 2;
      if (pos <= m) update(pos, value, 2*v+1, l, m);
      else update(pos, value, 2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, nq;
  cin >> n >> nq;
  string s;
  cin >> s;
  segtree_t seg(s);

  for (int q = 0; q < nq; ++q) {
    int pos;
    char let;
    cin >> pos; --pos;
    cin >> let;

    seg.update(pos, let - 'a');
    int result = INT_MAX;
    for (int v = 0; v < 3; ++v)
      result = min(result, seg.tree[0].cost[0][v]);
    printf("%d\n", result);
  }

  return 0;
}