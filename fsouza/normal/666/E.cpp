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

#define MAXS 500000

using namespace std;

typedef long long lint;

struct SuffixArray {
  vector<int> lcp;
  vector<vector<pair<int, int>>> rmq;
  int n, h;
  vector<int> sa, invsa;
  bool cmp(int a, int b) { return invsa[a+h] < invsa[b+h]; }
  void ternary_sort(int a, int b) {
    if (a == b) return;
    int pivot = sa[a+rand()%(b-a)];
    int left = a, right = b;
    for (int i = a; i < b; ++i) if (cmp(sa[i], pivot)) swap(sa[i], sa[left++]);
    for (int i = b-1; i >= left; --i) if (cmp(pivot, sa[i])) swap(sa[i], sa[--right]);
    ternary_sort(a, left);
    for (int i = left; i < right; ++i) invsa[sa[i]] = right-1;
    if (right-left == 1) sa[left] = -1;
    ternary_sort(right, b);
  }
  SuffixArray() {}
  SuffixArray(vector<int> v): n(v.size()), sa(n) {
    v.push_back(INT_MIN);
    invsa = v;
    iota(sa.begin(), sa.end(), 0);
    h = 0; ternary_sort(0, n);
    for (h = 1; h <= n; h *= 2)
      for (int j = 0, i = j; i != n; i = j)
	if (sa[i] < 0) {
	  while (j < n && sa[j] < 0) j += -sa[j];
	  sa[i] = -(j-i);
	} else {
	  j = invsa[sa[i]]+1;
	  ternary_sort(i, j);
	}
    for (int i = 0; i < n; ++i) sa[invsa[i]] = i;
    lcp.resize(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (invsa[i] > 0) while (v[i+res] == v[sa[invsa[i]-1]+res]) ++res;
      lcp[invsa[i]] = res;
      res = max(res-1, 0);
    }
    int logn = 0; while ((1<<logn+1) <= n) ++logn;
    rmq.resize(logn+1, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i) rmq[0][i] = make_pair(lcp[i], i);
    for (int l = 1; l <= logn; ++l)
      for (int i = 0; i+(1<<l) <= n; ++i)
	rmq[l][i] = min(rmq[l-1][i], rmq[l-1][i+(1<<l-1)]);
  }
  pair<int, int> rmq_query(int a, int b) {
    int size = b-a+1, l = __builtin_clz(1) - __builtin_clz(size);
    return min(rmq[l][a], rmq[l][b-(1<<l)+1]);
  }
  int get_lcp2(int ia, int ib) {
    return rmq_query(min(ia, ib)+1, max(ia, ib)).first;
  }
  pair<int, int> get_range(int strpos, int size) {
    int pos = invsa[strpos];
    int start, end;
    {
      int l = 0, r = pos;
      while (l < r) {
	int m = (l+r)/2;
	if (get_lcp2(m, pos) < size) l = m+1;
	else r = m;
      }
      start = l;
    }
    {
      int l = pos, r = n-1;
      while (l < r) {
	int m = (l+r+1)/2;
	if (get_lcp2(m, pos) < size) r = m-1;
	else l = m;
      }
      end = l;
    }
    return {start, end};
  }
};

struct SegTree {
  int n;
  vector<pair<int, int>> node;
  SegTree(int n): n(n), node(4*n) {
    build(0, 0, n-1);
  }
  void build(int v, int l, int r) {
    if (l == r) node[v] = make_pair(0, -l);
    else {
      int m = (l+r)/2;
      build(2*v+1, l, m);
      build(2*v+2, m+1, r);
      node[v] = max(node[2*v+1], node[2*v+2]);
    }
  }
  void update(int pos, int delta) {
    update(pos, delta, 0, 0, n-1);
  }
  void update(int pos, int delta, int v, int l, int r) {
    if (l == r) node[v].first += delta;
    else {
      int m = (l+r)/2;
      if (pos <= m) update(pos, delta, 2*v+1, l, m);
      else update(pos, delta, 2*v+2, m+1, r);
      node[v] = max(node[2*v+1], node[2*v+2]);
    }
  }
  pair<int, int> query(int a, int b, int v, int l, int r) {
    if (a > r || b < l) return make_pair(-1000000000, 0);
    else if (a <= l && r <= b) return node[v];
    else {
      int m = (l+r)/2;
      return max(query(a, b, 2*v+1, l, m),
		 query(a, b, 2*v+2, m+1, r));
    }
  }
  pair<int, int> query(int a, int b) {
    return query(a, b, 0, 0, n-1);
  }
};

char temp[MAXS+1];

int main() {
  scanf(" %s", temp);
  string s = string(temp);

  vector<int> bigs, ids;
  bigs.reserve(s.size() + 2*50000);
  ids.reserve(s.size() + 2*50000);
  bigs.resize(s.size());
  ids.resize(s.size());
  for (int i = 0; i < (int)s.size(); ++i) {
    bigs[i] = s[i]-'a';
    ids[i] = -1;
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf(" %s", temp);
    int len = strlen(temp);

    int start = bigs.size();
    bigs.resize(start + 1 + len);
    ids.resize(start + 1 + len);
    bigs[start] = 26 + i;
    ids[start] = -1;
    for (int j = 0; j < len; ++j) {
      bigs[start+1+j] = temp[j]-'a';
      ids[start+1+j] = i;
    }
  }

  SuffixArray sa(bigs);
  {
    vector<int> newids(bigs.size());
    for (int i = 0; i < (int)bigs.size(); ++i)
      newids[i] = ids[sa.sa[i]];
    ids = newids;
  }

  int nq;
  scanf("%d", &nq);
  vector<pair<int, int>> result(nq);

  struct query_t {
    int l, r, a, b;
    int qid;
  };

  vector<query_t> queries(nq);

  for (int q = 0; q < nq; ++q) {
    int l, r, a, b;
    scanf("%d %d %d %d", &l, &r, &a, &b), --l, --r, --a, --b;

    // l, r < m
    // a, b < str

    pair<int, int> range = sa.get_range(a, b-a+1); // range in sa

    queries[q] = {l, r, range.first, range.second, q};
  }

  const int div = 1024;

  sort(queries.begin(), queries.end(), [](const query_t &qa, const query_t &qb) {
      if (qa.a/div != qb.a/div) return qa.a < qb.a;
      return qa.b < qb.b;
    });

  SegTree seg(m);
  int nowa = 0, nowb = -1;

  auto update = [&seg, &ids](int pos, int delta) {
    int v = ids[pos];
    if (v != -1)
      seg.update(v, delta);
  };

  for (query_t &q : queries) {
    while (nowb < q.b) update(++nowb, +1);
    while (nowa > q.a) update(--nowa, +1);
    while (nowb > q.b) update(nowb--, -1);
    while (nowa < q.a) update(nowa++, -1);

    pair<int, int> res = seg.query(q.l, q.r);
    result[q.qid] = {-res.second, res.first};
  }

  for (int q = 0; q < nq; ++q)
    printf("%d %d\n", result[q].first+1, result[q].second);

  return 0;
}