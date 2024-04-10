#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct SegTree {
  int n;
  struct node {
    lint sum;
    int lazy;
    node(): sum(0), lazy(INT_MIN) {}
    node(node &a, node &b): sum(a.sum + b.sum), lazy(INT_MIN) {}
  };
  vector<node> tree;
  SegTree(int n): n(n), tree(4*n) {}
  void update(int a, int b, int value) { update(a, b, value, 0, 0, n-1); }
  lint query(int a, int b) { return query(a, b, 0, 0, n-1); }
  void update(int a, int b, int value, int n, int l, int r) {
    propag(n, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[n].lazy = value;
      propag(n, l, r);
    } else {
      int m = (l+r)/2;
      update(a, b, value, 2*n+1, l, m);
      update(a, b, value, 2*n+2, m+1, r);
      tree[n] = node(tree[2*n+1], tree[2*n+2]);
    }
  }
  lint query(int a, int b, int n, int l, int r) {
    propag(n, l, r);
    if (a > r || b < l) return 0;
    else if (a <= l && r <= b) return tree[n].sum;
    else {
      int m = (l+r)/2;
      return query(a, b, 2*n+1, l, m) + query(a, b, 2*n+2, m+1, r);
    }
  }
  void propag(int n, int l, int r) {
    if (tree[n].lazy != INT_MIN) {
      tree[n].sum = (lint)(r-l+1) * tree[n].lazy;
      if (l != r)
	tree[2*n+1].lazy = tree[2*n+2].lazy = tree[n].lazy;
      tree[n].lazy = INT_MIN;
    }
  }
};

struct MaxSum {
  int n;
  SegTree seg;
  set<int> leaders;
  vector<int> vals;
  MaxSum(int n): n(n), seg(n), vals(n, 0) {
    leaders.insert(0);
  }
  lint query(int a, int b) { return seg.query(a, b); }
  void increase(int pos, int val) {
    if (vals[pos] >= val) return;
    vals[pos] = val;
    auto it = leaders.upper_bound(pos); --it;
    if (*it != pos) {
      if (vals[*it] >= val) return;
      else it = leaders.insert(pos).first;
    }
    auto it2 = it; ++it2;
    while (it2 != leaders.end() && vals[*it2] <= val) {
      auto next = it2; ++next;
      leaders.erase(it2);
      it2 = next;
    }
    int until = it2 == leaders.end() ? n-1 : *it2-1;
    seg.update(pos, until, val);
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vals(n);
  for (int &v : vals) scanf("%d", &v);
  const int maxv = *max_element(vals.begin(), vals.end());

  vector<vector<int>> divs(maxv+1);
  for (int v = 1; v <= maxv; ++v)
    for (int u = v; u <= maxv; u += v)
      divs[u].push_back(v);

  vector<int> leftmost(maxv+1, n), rightmost(maxv+1, -1);
  for (int i = 0; i < n; ++i)
    for (int d : divs[vals[i]])
      leftmost[d] = min(leftmost[d], i), rightmost[d] = max(rightmost[d], i);

  MaxSum ms(n);
  for (int i = 0; i < n; ++i) {
    int start = 0;
    for (int d : divs[vals[i]])
      if (leftmost[d] < i)
	start = d;
    ms.increase(i, start);
  }

  lint result = 0;
  int rightres = 0;
  for (int i = n-1; i >= 0; --i) {
    result += rightres;
    if (i > 0) result += ms.query(0, i-1);

    if (i > 0) {
      for (int d : divs[vals[i]]) {
	if (leftmost[d] < i) {
	  ms.increase(leftmost[d], d);
	  leftmost[d] = n;
	}
	if (rightmost[d] > i) rightres = max(rightres, d);
      }
      ms.increase(0, rightres);
    }
  }

  printf("%lld\n", result);

  return 0;
}