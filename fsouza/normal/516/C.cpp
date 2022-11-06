#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <queue>
#include <cmath>

#define MAXN2 (2* 100000)
#define INFLL 1000000000000000

using namespace std;

typedef long long lint;

int dist[MAXN2], height[MAXN2];
lint dsum[MAXN2];

struct node {
  lint bleft, bright, best;
  node() {
    bleft = bright = best = -INFLL;
  }
  node(int i) {
    best = -INFLL;
    bright = 2LL*height[i] + dsum[i];
    bleft = 2LL*height[i] - dsum[i];
  }
  node(const node &a, const node &b) {
    bleft = max(a.bleft, b.bleft);
    bright = max(a.bright, b.bright);
    best = max(a.bleft + b.bright,
	       max(a.best, b.best));
  }
} tree[4*MAXN2];

void build_tree(int n, int l, int r) {
  if (l == r) tree[n] = node(l);
  else {
    int m = (l+r)/2;
    build_tree(2*n+1, l, m);
    build_tree(2*n+2, m+1, r);
    tree[n] = node(tree[2*n+1], tree[2*n+2]);
  }
}

node query(int a, int b, int n, int l, int r) {
  if (a > r || b < l) return node();
  else if (a <= l && r <= b) return tree[n];
  else {
    int m = (l+r)/2;
    return node(query(a, b, 2*n+1, l, m),
		query(a, b, 2*n+2, m+1, r));
  }
}

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%d", &dist[i]);
    dist[n + i] = dist[i];
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &height[i]);
    height[n + i] = height[i];
  }

  dsum[0] = 0;
  for (int i = 1; i < 2*n; i++) {
    dsum[i] = dsum[i-1] + dist[i-1];
  }

  build_tree(0, 0, 2*n-1);

  for (int q = 0; q < m; q++) {
    int a, b;
    scanf("%d %d", &a, &b), a--, b--;

    lint ret;
    if (a <= b) {
      ret = query(b+1, a-1+n, 0, 0, 2*n-1).best;
    } else {
      ret = query(b+1, a-1, 0, 0, 2*n-1).best; 
    }

    printf("%I64d\n", ret);
  }

  return 0;
}