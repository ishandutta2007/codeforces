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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int mod = 1e9+21;

struct seqset {
  int size = INT_MIN, nway = 0;
  seqset() {}
  seqset(int size, int nway): size(size), nway(nway) {}
};
seqset operator + (const seqset &a, const seqset &b) {
  if (a.size > b.size) return a;
  if (b.size > a.size) return b;
  return {a.size, (a.nway + b.nway) % mod};
}

struct SegTree {
  int n;
  vector<seqset> node;
  SegTree(int n): n(n), node(4*n) {}
  void update(int i, seqset val) { update(i, val, 0, 0, n-1); }
  void update(int i, seqset val, int v, int l, int r) {
    if (l == r) node[v] = node[v] + val;
    else {
      int m = (l+r)/2;
      if (i <= m) update(i, val, 2*v+1, l, m);
      else update(i, val, 2*v+2, m+1, r);
      node[v] = node[2*v+1] + node[2*v+2];
    }
  }
  seqset query(int a, int b) { return query(a, b, 0, 0, n-1); }
  seqset query(int a, int b, int v, int l, int r) {
    if (a > r || b < l) return seqset();
    else if (a <= l && r <= b) return node[v];
    else {
      int m = (l+r)/2;
      return (query(a, b, 2*v+1, l, m) +
	      query(a, b, 2*v+2, m+1, r));
    }
  }
};

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  vector<int> orig(n);
  for (int &v : orig) scanf("%d", &v);
  struct query_t {
    int id, val;
  };
  vector<query_t> queries(nq);
  for (query_t &q : queries)
    scanf("%d %d", &q.id, &q.val), --q.id;

  int maxv;
  {
    vector<int> values = orig;
    for (query_t &q : queries) values.push_back(q.val);
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());
    for (int &v : orig) v = lower_bound(values.begin(), values.end(), v) - values.begin();
    for (query_t &q : queries)
      q.val = lower_bound(values.begin(), values.end(), q.val) - values.begin();
    maxv = values.size();
  }

  vector<vector<int>> queriesat(n);
  for (int i = 0; i < nq; ++i)
    queriesat[queries[i].id].push_back(i);

  seqset all;
  vector<seqset> leftold(nq), leftnew(nq), rightold(nq), rightnew(nq);
  {
    SegTree seg(maxv);
    for (int i = 0; i < n; ++i) {
      seqset old = seg.query(0, orig[i]-1) + seqset(0, 1);
      for (int q : queriesat[i]) {
	leftold[q] = old;
	leftnew[q] = seg.query(0, queries[q].val-1) + seqset(0, 1);
      }
      seg.update(orig[i], {old.size+1, old.nway});
    }
    all = seg.query(0, maxv-1) + seqset(0, 1);
  }
  {
    SegTree seg(maxv);
    for (int i = n-1; i >= 0; --i) {
      seqset old = seg.query(orig[i]+1, maxv-1) + seqset(0, 1);
      for (int q : queriesat[i]) {
	rightold[q] = old;
	rightnew[q] = seg.query(queries[q].val+1, maxv-1) + seqset(0, 1);
      }
      seg.update(orig[i], {old.size+1, old.nway});
    }
    seqset all2 = seg.query(0, maxv-1) + seqset(0, 1);
    assert(all.size == all2.size && all.nway == all2.nway);
  }

  for (int q = 0; q < nq; ++q) {
    int withoutsize;
    if (leftold[q].size + 1 + rightold[q].size == all.size &&
	(lint)leftold[q].nway * rightold[q].nway % mod == all.nway)
      withoutsize = all.size - 1;
    else
      withoutsize = all.size;

    int withsize = leftnew[q].size + 1 + rightnew[q].size;

    printf("%d\n", max(withoutsize, withsize));
  }

  return 0;
}