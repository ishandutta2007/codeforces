#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define MAXN 750
#define MAXS 10000000

using namespace std;

typedef long long lint;

struct AhoCorasick {
  static const int nletter = 2;
  struct node {
    vector<int> keywords;
    node *go[nletter] = {}, *failure = {}, *output = {};
  } *root = new node();
  node *add(int size, int *values, int keywordid) {
    assert(size > 0);
    node *v = root;
    for (int i = 0; i < size; ++i) {
      node *&u = v->go[values[i]];
      if (!u) u = new node();
      v = u;
    }
    v->keywords.push_back(keywordid);
    return v;
  }
  void build() {
    queue<node*> q;
    for (int i = 0; i < nletter; ++i) {
      node *&v = root->go[i];
      if (v) {
	v->failure = root;
	v->output = v->keywords.size() > 0 ? v : nullptr;
	q.push(v);
      } else {
	v = root;
      }
    }
    while (!q.empty()) {
      node *u = q.front(); q.pop();
      for (int i = 0; i < nletter; ++i) {
	node *v = u->go[i];
	if (v) {
	  node *x = u->failure;
	  while (!x->go[i]) x = x->failure;
	  v->failure = x->go[i];
	  v->output = v->keywords.size() > 0 ? v : v->failure->output;
	  q.push(v);
	}
      }
    }
  }
  node *iterate(node *v, int value) {
    while (!v->go[value]) v = v->failure;
    return v->go[value];
  }
  vector<int> matches(node *v) {
    vector<int> result;
    for (node *x = v->output; x; x = x->failure->output)
      result.insert(result.end(), x->keywords.begin(), x->keywords.end());
    return result;
  }
};

struct Dinitz {
  int n, source, sink;
  vector<vector<int>> adj;
  struct edge { int u, flow, cap; };
  vector<edge> edges;
  Dinitz(int n, int source, int sink)
    : n(n), source(source), sink(sink), adj(n) {}
  int add_edge(int a, int b, int abcap, int bacap = 0) {
    int result = edges.size();
    adj[a].push_back(edges.size());
    edges.push_back({b, 0, abcap});
    adj[b].push_back(edges.size());
    edges.push_back({a, 0, bacap});
    return result;
  }
  vector<int> mindist, position;
  bool bfs() {
    queue<int> q;
    fill(mindist.begin(), mindist.end(), INT_MAX/2);
    mindist[source] = 0;
    q.push(source);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int edid : adj[v]) {
	edge &ed = edges[edid];
	if (ed.flow < ed.cap && mindist[ed.u] > mindist[v] + 1) {
	  mindist[ed.u] = mindist[v] + 1;
	  q.push(ed.u);
	}
      }
    }
    return mindist[sink] < n;
  }
  int dfs(int v, int maxf) {
    if (v == sink) return maxf;
    for (int &pos = position[v]; pos < (int)adj[v].size(); ++pos) {
      int edid = adj[v][pos];
      edge &ed = edges[edid], &reved = edges[edid^1];
      if (ed.flow < ed.cap && mindist[ed.u] == mindist[v] + 1) {
	int f = dfs(ed.u, min(maxf, ed.cap - ed.flow));
	if (f > 0) {
	  ed.flow += f;
	  reved.flow -= f;
	  return f;
	}
      }
    }
    return 0;
  }
  int maxflow() {
    int result = 0;
    mindist.resize(n);
    position.resize(n);
    while (bfs()) {
      int extra;
      do {
	fill(position.begin(), position.end(), 0);
	extra = dfs(source, INT_MAX);
	result += extra;
      } while (extra > 0);
    }
    return result;
  }
};

struct BipartiteVertexCover {
  int nleft, nright;
  vector<bool> mark;
  Dinitz din;
  BipartiteVertexCover(int nleft, int nright)
    : nleft(nleft), nright(nright), mark(1+nleft+nright+1)
    , din(1+nleft+nright+1, 0, 1+nleft+nright) {
    for (int l = 0; l < nleft; ++l) din.add_edge(0, 1+l, 1);
    for (int r = 0; r < nright; ++r) din.add_edge(1+nleft+r, 1+nleft+nright, 1);
  }
  void add_edge(int l, int r) {
    din.add_edge(1+l, 1+nleft+r, 1);
  }
  void dfs(int v) {
    mark[v] = true;
    for (int edid : din.adj[v]) {
      Dinitz::edge &ed = din.edges[edid];
      if (ed.flow < ed.cap && !mark[ed.u])
	dfs(ed.u);
    }
  }
  vector<pair<int, int>> solve() {
    int maxflow = din.maxflow();
    dfs(0);
    vector<pair<int, int>> result;
    for (int i = 0; i < (int)din.edges.size(); ++i) {
      Dinitz::edge &ed = din.edges[i];
      int to = ed.u, from = din.edges[i^1].u;
      if (mark[from] && !mark[to] && ed.cap > 0) {
	if (from == 0) result.push_back({0, to-1});
	else result.push_back({1, from-1-nleft});
      }
    }
    assert(maxflow == result.size());
    return result;
  }
};

int adj[MAXN][MAXN];

int main() {
  using node = AhoCorasick::node;
  
  int n;
  scanf("%d", &n);
  
  AhoCorasick aho;
  vector<vector<int>> keywords(n);
  for (int i = 0; i < n; ++i) {
    static char str[MAXS+1];
    scanf("%s", str);
    vector<int> v(strlen(str));
    for (int j = 0; str[j]; ++j) v[j] = str[j]-'a';
    aho.add(v.size(), &v[0], i);
    keywords[i] = move(v);
  }
  aho.build();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      adj[i][j] = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> &values = keywords[i];
    node *state = aho.root;
    for (int value : values) {
      state = aho.iterate(state, value);
      node *out = state->output;
      if (out) {
	int id = out->keywords.front();
	if (id == i) {
	  out = out->failure->output;
	  if (out) id = out->keywords.front();
	  else id = -1;
	}
	if (id != -1) adj[i][id] = 1;
      }
    }
  }
  
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
	adj[i][j] |= adj[i][k] & adj[k][j];

  BipartiteVertexCover bvc(n, n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (adj[i][j])
	bvc.add_edge(i, j);
  vector<bool> inresult(n, true);
  for (pair<int, int> node : bvc.solve())
    inresult[node.second] = false;

  vector<int> result;
  for (int i = 0; i < n; ++i)
    if (inresult[i])
      result.push_back(i);
  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]+1);
  }
  printf("\n");
  
  return 0;
}