#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define INF 1000000000
#define MAXN 200001

using namespace std;

typedef long long lint;

const int mod = 1e9+7;

int modpow(int x, int y) {
  int ret = 1;
  int x2p = x;
  for (int p = 0; y; ++p) {
    if (y & (1<<p)) {
      ret = (lint)ret*x2p % mod;
      y -= 1<<p;
    }
    x2p = (lint)x2p*x2p % mod;
  }
  return ret;
}

int inv(int x) {
  return modpow(x, mod-2);
}

struct segtree {
  struct node {
    int sum, lazy;
    node() {
      sum = 0;
      lazy = 1;
    }
  };
  int n;
  vector<node> tree;
  segtree(int n): n(n), tree(4*n) {}

  void propag(int v, int l, int r) {
    if (tree[v].lazy != 1) {
      tree[v].sum = (lint)tree[v].sum * tree[v].lazy % mod;
      if (l != r) {
    tree[2*v+1].lazy = (lint)tree[2*v+1].lazy * tree[v].lazy % mod;
    tree[2*v+2].lazy = (lint)tree[2*v+2].lazy * tree[v].lazy % mod;
    assert(tree[v].sum == ((lint)tree[2*v+1].sum*tree[2*v+1].lazy + (lint)tree[2*v+2].sum*tree[2*v+2].lazy) % mod);
      }
      tree[v].lazy = 1;
    }
  }

  int query(int a, int b, int v, int l, int r) {
    propag(v, l, r);

    if (a > r || b < l) return 0;
    else if (a <= l && r <= b) return tree[v].sum;
    else {
      int m = (l+r)/2;
      return (query(a, b, 2*v+1, l, m) +
          query(a, b, 2*v+2, m+1, r)) % mod;
    }
  }

  void multiply(int a, int b, int by, int v, int l, int r) {
    propag(v, l, r);

    if (a > r || b < l) {
      propag(v, l, r);
    } else if (a <= l && r <= b) {
      assert(tree[v].lazy == 1);
      tree[v].lazy = by % mod;
      propag(v, l, r);
    } else {
      int m = (l+r)/2;
      multiply(a, b, by, 2*v+1, l, m);
      multiply(a, b, by, 2*v+2, m+1, r);
      tree[v].sum = (tree[2*v+1].sum + tree[2*v+2].sum) % mod;
      assert(tree[v].lazy == 1);
    }
  }

  void update(int pos, int value, int v, int l, int r) {
    propag(v, l, r);

    if (l == r) tree[v].sum = value % mod;
    else {
      int m = (l+r)/2;
      if (pos <= m) {
    update(pos, value, 2*v+1, l, m);
    propag(2*v+2, m+1, r);
      } else {
    update(pos, value, 2*v+2, m+1, r);
    propag(2*v+1, l, m);
      }
      tree[v].sum = (tree[2*v+1].sum + tree[2*v+2].sum) % mod;
    }
  }

  int query(int a, int b) {assert(a <= b); return query(a, b, 0, 0, n-1);}
  int query(int a) {return query(a, a);}
  void update(int pos, int value) {update(pos, value, 0, 0, n-1);}
  void multiply(int a, int b, int by) {assert(a <= b); multiply(a, b, by, 0, 0, n-1);}
};

struct query_t {
  int type;
  int parent;
  int id;
};

vector<int> values;
vector<int> children[MAXN];
int leftmost[MAXN], rightmost[MAXN], posof[MAXN];
int alivechildren[MAXN], parentof[MAXN];

int dfs(int v, int id) {
  leftmost[v] = posof[v] = id;
  ++id;

  for (int c : children[v]) {
    id = dfs(c, id);
  }

  rightmost[v] = id-1;
  return id;
}

int main() {
  int n = 0;

  int v0, nq;
  scanf("%d %d", &v0, &nq);

  parentof[0] = -1;
  values.push_back(v0);
  ++n;

  vector<query_t> queries(nq);
  for (int q = 0; q < nq; ++q) {
    scanf("%d", &queries[q].type);
    if (queries[q].type == 1) {
      int val;
      scanf("%d %d", &queries[q].parent, &val), --queries[q].parent;
      values.push_back(val); ++n;
      parentof[n-1] = queries[q].parent;
      queries[q].id = n-1;

      children[queries[q].parent].push_back(queries[q].id);
    } else {
      scanf("%d", &queries[q].id), --queries[q].id;
    }
  }

  int id = dfs(0, 0);
  assert(id == n);

  for (int i = 0; i < n; ++i) alivechildren[i] = 0;
  
  segtree seg(n);

  seg.update(posof[0], values[0]);
  
  for (int q = 0; q < nq; ++q) {
    if (queries[q].type == 1) {
      int p = queries[q].parent, id = queries[q].id;

      int current = alivechildren[p]+1;
      seg.multiply(leftmost[p], rightmost[p], inv(current));
      ++alivechildren[p];
      int newone = alivechildren[p]+1;
      seg.multiply(leftmost[p], rightmost[p], newone);

      int multiplier = (lint)seg.query(posof[p]) * inv(values[p]) % mod;
      
      seg.update(posof[id], (lint)multiplier * values[id] % mod);
    } else {
      int id = queries[q].id;

      int result = seg.query(leftmost[id], rightmost[id]);

      if (parentof[id] != -1) {
    int p = parentof[id];
    int multiplier = (lint)seg.query(posof[p]) * inv(values[p]) % mod;
    result = (lint)result * inv(multiplier) % mod;
      }

      printf("%d\n", result);
    }
  }
  
  return 0;
}