#include <algorithm>
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
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxv = (int)1e9;

struct SegTree {
  struct node {
    lint maxpref, maxsuff, maxsub, sum;
    node() {}
    node(lint value) {
      maxpref = max(0LL, value);
      maxsuff = max(0LL, value);
      maxsub = max(0LL, value);
      sum = value;
    }
    node(const node &left, const node &right) {
      maxpref = max(left.maxpref, left.sum + right.maxpref);
      maxsuff = max(right.maxsuff, right.sum + left.maxsuff);
      sum = left.sum + right.sum;
      maxsub = max({left.maxsub, right.maxsub, left.maxsuff + right.maxpref});
    }
  };

  int n;
  vector<node> tree;
  SegTree(const vector<lint> &values): n(values.size()), tree(4*n) {
    build(0, 0, n-1, values);
  }
  void build(int v, int l, int r, const vector<lint> &values) {
    if (l == r) {
      tree[v] = node(values[l]);
    } else {
      int m = l+(r-l)/2;
      build(2*v+1, l, m, values);
      build(2*v+2, m+1, r, values);
      tree[v] = node(tree[2*v+1], tree[2*v+2]);
    }
  }
  void update(int i, lint newvalue) { update(i, newvalue, 0, 0, n-1); }
  void update(int i, lint newvalue, int v, int l, int r) {
    if (l == r) tree[v] = node(newvalue);
    else {
      int m = l+(r-l)/2;
      if (i <= m) update(i, newvalue, 2*v+1, l, m);
      else update(i, newvalue, 2*v+2, m+1, r);
      tree[v] = node(tree[2*v+1], tree[2*v+2]);
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<lint> values(n);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    values[i] = v;
  }
  SegTree seg(values);

  for (int i = 0; i < n; ++i) {
    int pos;
    scanf("%d", &pos), --pos;
    seg.update(pos, (lint)n * (-maxv-1));
    printf("%lld\n", seg.tree[0].maxsub);
  }

  return 0;
}