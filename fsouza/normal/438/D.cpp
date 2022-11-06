#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <climits>

#define INF (INT_MAX/2)
#define MAXN 100000

typedef long long lint;

using namespace std;

int v[MAXN];
struct node {
  lint sum;
  int maxv;
} tree[4*MAXN];

void build(int n, int l, int r) {
  if (l == r) {
    tree[n].sum = tree[n].maxv = v[l];
  } else {
    int m = (l+r)/2;
    build(2*n+1, l, m);
    build(2*n+2, m+1, r);
    tree[n].sum = tree[2*n+1].sum + tree[2*n+2].sum;
    tree[n].maxv = max(tree[2*n+1].maxv, tree[2*n+2].maxv);
  }
}

lint query(int a, int b, int n, int l, int r) {
  if (a > r || b < l) return 0;
  else if (a <= l && r <= b) return tree[n].sum;
  else {
    int m = (l+r)/2;
    return (query(a, b, 2*n+1, l, m) +
	    query(a, b, 2*n+2, m+1, r));
  }
}

void change(int k, int x, int n, int l, int r) {
  if (l == r) {
    tree[n].sum = tree[n].maxv = x;
  } else {
    int m = (l+r)/2;
    if (k <= m) change(k, x, 2*n+1, l, m);
    else change(k, x, 2*n+2, m+1, r);
    tree[n].sum = tree[2*n+1].sum + tree[2*n+2].sum;
    tree[n].maxv = max(tree[2*n+1].maxv, tree[2*n+2].maxv);
  }
}

void update(int a, int b, int mod, int n, int l, int r) {
  if (a > r || b < l || tree[n].maxv < mod) {
  } else if (l == r) {
    tree[n].sum = tree[n].maxv = (tree[n].maxv % mod);
  } else {
    int m = (l+r)/2;
    update(a, b, mod, 2*n+1, l, m);
    update(a, b, mod, 2*n+2, m+1, r);
    tree[n].sum = tree[2*n+1].sum + tree[2*n+2].sum;
    tree[n].maxv = max(tree[2*n+1].maxv, tree[2*n+2].maxv);
  }
}

int main() {
  int n, m;

  cin >> n >> m;

  for (int i = 0; i < n; i++) cin >> v[i];

  build(0, 0, n-1);

  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r; l--, r--;
      cout << query(l, r, 0, 0, n-1) << endl;
    } else if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x; l--, r--;
      update(l, r, x, 0, 0, n-1);
    } else if (type == 3) {
      int k, x;
      cin >> k >> x; k--;
      change(k, x, 0, 0, n-1);
    }
  }

  return 0;
}