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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct unionfind_t {
  vector<int> parent, rank;
  vector<bool> is_dirty;
  vector<int> dirty;
  unionfind_t(int n): parent(n), rank(n, 0), is_dirty(n, false) {
    iota(parent.begin(), parent.end(), 0);
  }
  void join(int a, int b) {
    a = search(a); b = search(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    parent[a] = b;
    mark_dirty(a);
    if (rank[a] == rank[b]) {
      ++rank[b];
      mark_dirty(b);
    }
  }
  int search(int a) {
    if (parent[a] == a) return a;
    mark_dirty(a);
    return parent[a] = search(parent[a]);
  }
  void mark_dirty(int a) {
    if (!is_dirty[a]) {
      is_dirty[a] = true;
      dirty.push_back(a);
    }
  }
  void rollback() {
    for (int v : dirty) {
      parent[v] = v;
      rank[v] = 0;
      is_dirty[v] = false;
    }
    dirty.clear();
  }
};

struct edgechecker_t {
  unionfind_t uf;
  edgechecker_t(int n): uf(2*n) {}
  bool add(int a, int b, bool *conflict = nullptr) {
    if (uf.search(2*a) != uf.search(2*b+1) ||
	uf.search(2*a+1) != uf.search(2*b)) {
      uf.join(2*a, 2*b+1);
      uf.join(2*a+1, 2*b);
      if (conflict)
	*conflict = (uf.search(2*a) == uf.search(2*a+1));
      return true;
    } else {
      if (conflict) *conflict = false;
      return false;
    }
  }
  void rollback() {
    uf.rollback();
  }
};

struct edge_t {
  int a, b, c;
};

struct edge_greater_c {
  const vector<edge_t> &edges;
  edge_greater_c(const vector<edge_t> &edges): edges(edges) {}
  bool operator()(int a, int b) const {
    return edges[a].c > edges[b].c;
  }
};

struct segtree_t {
  int n;
  const vector<edge_t> &edges;
  vector<vector<int>> nodes;
  edgechecker_t checker;
  segtree_t(const vector<edge_t> &edges, int nnode)
    : n(edges.size()), edges(edges), nodes(4*n), checker(nnode) {
    build(0, 0, n-1);
  }
  void strip(vector<int> &ids) {
    int newsize = 0;
    for (int i = 0; i < (int)ids.size(); ++i) {
      int id = ids[i];
      if (checker.add(edges[id].a, edges[id].b))
	ids[newsize++] = id;
    }
    ids.resize(newsize);
    checker.rollback();
  }
  void build(int v, int l, int r) {
    if (l == r) {
      nodes[v].push_back(l);
    } else {
      int m = (l+r)/2;
      build(2*v+1, l, m);
      build(2*v+2, m+1, r);
      nodes[v].resize(nodes[2*v+1].size() + nodes[2*v+2].size());
      merge(nodes[2*v+1].begin(), nodes[2*v+1].end(),
	    nodes[2*v+2].begin(), nodes[2*v+2].end(),
	    nodes[v].begin(), edge_greater_c(edges));
      strip(nodes[v]);
    }
  }
  vector<int> query(int a, int b) { return move(query(a, b, 0, 0, n-1)); }
  vector<int> query(int a, int b, int v, int l, int r) {
    if (a > r || b < l) return {};
    else if (a <= l && r <= b) return nodes[v];
    else {
      int m = (l+r)/2;
      vector<int> left = query(a, b, 2*v+1, l, m);
      vector<int> right = query(a, b, 2*v+2, m+1, r);
      if (left.empty()) return move(right);
      else if (right.empty()) return move(left);
      else {
	vector<int> result(left.size() + right.size());
	merge(left.begin(), left.end(),
	      right.begin(), right.end(),
	      result.begin(), edge_greater_c(edges));
	return move(result);
      }
    }
  }
};

int main() {
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  vector<edge_t> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c), --a, --b;
    edges.push_back((edge_t){a, b, c});
  }
  segtree_t seg(edges, n);
  edgechecker_t checker(n);

  for (int q = 0; q < nq; ++q) {
    int l, r;
    scanf("%d %d", &l, &r), --l, --r;
    vector<int> ids = seg.query(l, r);
    int result = -1;
    for (int id : ids) {
      bool conflict;
      checker.add(edges[id].a, edges[id].b, &conflict);
      if (conflict) {
	result = edges[id].c;
	break;
      }
    }
    checker.rollback();
    printf("%d\n", result);
  }

  return 0;
}