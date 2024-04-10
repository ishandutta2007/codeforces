#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<double> point;

const double pi = 2*acos(0.0);

struct SegTree {
  struct node { point m, a; };
  int n;
  vector<node> tree;
  SegTree(int n): n(n), tree(4*n, {1., 0.}) {}

  node combine(node n2, node n1) {
    return {n1.m * n2.m, n1.a*n2.m + n2.a};
  }
  
  void propag(int v, int l, int r) {
    if (l != r) {
      tree[2*v+1] = combine(tree[v], tree[2*v+1]);
      tree[2*v+2] = combine(tree[v], tree[2*v+2]);
      tree[v] = {1., 0.};
    }
  }

  void update(int a, int b, node trans) { update(a, b, trans, 0, 0, n-1); }
  void update(int a, int b, node trans, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[v] = combine(trans, tree[v]);
    } else {
      int m = (l+r)/2;
      update(a, b, trans, 2*v+1, l, m);
      update(a, b, trans, 2*v+2, m+1, r);
    }
  }

  node query(int pos) { return query(pos, 0, 0, n-1); }
  node query(int pos, int v, int l, int r) {
    propag(v, l, r);
    if (l == r) return tree[v];
    else {
      int m = (l+r)/2;
      if (pos <= m) return query(pos, 2*v+1, l, m);
      else return query(pos, 2*v+2, m+1, r);
    }
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m), ++n;

  SegTree seg(n);
  for (int i = 0; i < n; ++i)
    seg.update(i, i, {1.0, point(i, 0)});

  for (int j = 0; j < m; ++j) {
    int type, segid;
    scanf("%d %d", &type, &segid), --segid;

    point A = seg.query(segid).a, B = seg.query(segid+1).a;

    if (type == 1) {
      double len;
      scanf("%lf", &len);

      point delta = (B-A)*len/abs(B-A);
      seg.update(segid+1, n-1, {1.0, delta});
    } else {
      double degang;
      scanf("%lf", &degang);
      double ang = degang / 360. * 2 * pi;
      point rotator(cos(-ang), sin(-ang));
      seg.update(segid+1, n-1, {rotator, A - A * rotator});
    }

    point tail = seg.query(n-1).a;
    printf("%.10f %.10f\n", real(tail), imag(tail));
  }
  
  return 0;
}