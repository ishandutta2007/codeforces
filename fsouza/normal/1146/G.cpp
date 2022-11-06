#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

struct dinitz_t {
  int n, source, sink; vector<vector<int>> adj;
  struct edge { int u, flow, cap; }; vector<edge> edges;
  dinitz_t(int _n, int _source, int _sink)
    : n(_n), source(_source), sink(_sink), adj(n) {}
  int add_edge(int a, int b, int abcap, int bacap = 0) {
    int result = edges.size();
    adj[a].push_back(edges.size());edges.push_back({b, 0, abcap});
    adj[b].push_back(edges.size());edges.push_back({a, 0, bacap});
    return result;
  }
  vector<int> mindist, position;
  bool bfs() {
    queue<int> q;
    fill(mindist.begin(), mindist.end(), INT_MAX/2);
    mindist[source] = 0; q.push(source);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int edid : adj[v]) { edge &ed = edges[edid];
	if (ed.flow < ed.cap && mindist[ed.u] > mindist[v] + 1) {
	  mindist[ed.u] = mindist[v] + 1; q.push(ed.u);
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
	if (f > 0) { ed.flow += f; reved.flow -= f; return f; }
      }
    }
    return 0;
  }
  int maxflow() {
    int result = 0; mindist.resize(n); position.resize(n);
    while (bfs()) {
      int extra;
      fill(position.begin(), position.end(), 0);
      do {
        extra = dfs(source, INT_MAX); result += extra;
      } while (extra > 0);
    }
    return result;
  }
};

int main() {
  int n, h, m;
  scanf("%d %d %d", &n, &h, &m);

  int nn = n * h + m + 2;
  int source = nn - 2, sink = nn - 1;
  dinitz_t mf(nn, source, sink);

  struct restr_t {
    int l, r, lim, fine;
  };
  vector<restr_t> res(m);
  for (restr_t &r : res) {
    scanf("%d %d %d %d", &r.l, &r.r, &r.lim, &r.fine), --r.l, --r.r;
  }
  int sum_positive = 0;

  for (int i = 0; i < m; ++i) {
    mf.add_edge(n * h + i, sink, res[i].fine);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      int delta = (j + 1) * (j + 1) - j * j;
      mf.add_edge(source, i * h + j, delta);
      sum_positive += delta;

      if (j - 1 >= 0) {
        mf.add_edge(i * h + j, i * h + (j - 1), INT_MAX / 2);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < m; ++k) {
      if (res[k].l <= i && i <= res[k].r && res[k].lim < h) {
        int id = ((res[k].lim + 1) - 1);
        mf.add_edge(i * h + id, n * h + k, INT_MAX / 2);
      }
    }
  }

  int flow = mf.maxflow();

  printf("%d\n", sum_positive - flow);

  return 0;
}