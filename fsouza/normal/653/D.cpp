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
  void reset() {
    for (auto &ed : edges) ed.flow = 0;
  }
};

int main() {
  int n, m, nbear;
  scanf("%d %d %d", &n, &m, &nbear);
  vector<pair<int, int>> edges;
  Dinitz mf(n, 0, n-1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c), --a, --b;
    edges.push_back({mf.add_edge(a, b, 0), c});
  }

  double l = 0, r = 1e6;
  for (int rep = 0; rep < 70; ++rep) {
    double m = (l+r)/2;
    mf.reset();
    for (int i = 0; i < (int)edges.size(); ++i) {
      int id = edges[i].first;
      int mw = edges[i].second;
      mf.edges[id].cap = (int)floor(min(mw / m, 1.0*nbear));
    }
    if (mf.maxflow() >= nbear) l = m;
    else r = m;
  }
  
  printf("%.10f\n", l * nbear);
  
  return 0;
}