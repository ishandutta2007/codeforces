#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

int tree[4*MAXN][60];

void tree_update(int i, int v, int n, int l, int r) {
  if (l == r) {
    for (int k = 0; k < 60; k++) {
      if (k%v == 0) tree[n][k] = 2;
      else tree[n][k] = 1;
    }
  } else {
    int m = (l+r)/2;
    if (i <= m) tree_update(i, v, 2*n+1, l, m);
    else tree_update(i, v, 2*n+2, m+1, r);
    
    for (int k = 0; k < 60; k++) {
      int a = tree[2*n+1][k];
      int b = tree[2*n+2][(k+a) % 60];
      tree[n][k] = a+b;
    }
  }
}

int tree_query(int a, int b, int t, int n, int l, int r) {
  if (a > r || b < l) return t;
  else if (a <= l && r <= b) return t + tree[n][t % 60];
  else {
    int m = (l+r)/2;
    t = tree_query(a, b, t, 2*n+1, l, m);
    t = tree_query(a, b, t, 2*n+2, m+1, r);
    return t;
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    tree_update(i, v, 0, 0, n-1);
  }

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    char c;
    int x, y;
    scanf(" %c %d %d", &c, &x, &y);
    if (c == 'A') {
      x--, y--;
      int ret = tree_query(x, y-1, 0, 0, 0, n-1);
      printf("%d\n", ret);
    } else {
      x--;
      tree_update(x, y, 0, 0, n-1);
    }
  }

  return 0;
}