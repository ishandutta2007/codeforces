#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

struct UnionFind {
  int n;
  vector<int> parent, rank;
  UnionFind(int n): parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int search(int a) {
    if (a == parent[a]) return a;
    return parent[a] = search(parent[a]);
  }
  void join(int a, int b) {
    a = search(a); b = search(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    if (rank[a] == rank[b]) ++rank[b];
  }
};

struct SegTree {
  int n;
  UnionFind &uf;
  vector<bool> nodes;
  SegTree(int n, UnionFind &uf): n(n), uf(uf), nodes(4*n, false) {}
  void operate(int a, int b) { operate(a, b, 0, 0, n-1); }
  void operate(int a, int b, int v, int l, int r) {
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      joinall(v, l, r);
    } else {
      int m = (l+r)/2;
      operate(a, b, 2*v+1, l, m);
      operate(a, b, 2*v+2, m+1, r);
    }
  }
  void joinall(int v, int l, int r) {
    if (nodes[v]) return;
    nodes[v] = true;
    if (l == r) {
      uf.join(l, l+1);
    } else {
      int m = (l+r)/2;
      joinall(2*v+1, l, m);
      joinall(2*v+2, m+1, r);
    }
  }
};

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);

  UnionFind uf(n);
  SegTree seg(n-1, uf);

  for (int q = 0; q < nq; ++q) {
    int kind, l, r;
    scanf("%d %d %d", &kind, &l, &r), --l, --r;
    if (kind == 1) uf.join(l, r);
    else if (kind == 2) {
      if (l < r) seg.operate(l, r-1);
    } else printf(uf.search(l) == uf.search(r) ? "YES\n" : "NO\n");
  }
  
  return 0;
}