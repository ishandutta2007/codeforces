#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define MAXN 150

using namespace std;

typedef long long lint;

struct edge_t { int u, mind; };
vector<edge_t> adj[MAXN];

int mindist[MAXN][MAXN];

void calc_mindist(int n, int have) {
  queue<int> q;
  for (int start = 0; start < n; ++start) {
    for (int v = 0; v < n; ++v) mindist[start][v] = INT_MAX;
    mindist[start][start] = 0;
    q.push(start);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (edge_t &ed : adj[v])
	if (have >= ed.mind && mindist[start][ed.u] > mindist[start][v]+1) {
	  mindist[start][ed.u] = mindist[start][v] + 1;
	  q.push(ed.u);
	}
    }
  }
}

struct matrix_t {
  vector<bitset<MAXN>> lines;
  matrix_t(int n): lines(n) {}
  bool get(int y, int x) const {
    return lines[y].test(x);
  }
  void set(int y, int x) {
    lines[y].set(x);
  }
  size_t size() const {
    return lines.size();
  }
};

matrix_t operator * (const matrix_t &a, const matrix_t &b) {
  int n = a.size();
  matrix_t ret(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (a.get(i, j))
	ret.lines[i] |= b.lines[j];
  return ret;
}

matrix_t pow(matrix_t x, int y) {
  matrix_t x2p = x, ret(x.size());
  for (int i = 0; i < (int)x.size(); ++i) ret.set(i, i);
  while (y > 0) {
    if (y%2 == 1) ret = ret * x2p;
    y /= 2;
    x2p = x2p * x2p;
  }
  return ret;
}

int main() {
  vector<int> blocks;

  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, mind;
    scanf("%d %d %d", &a, &b, &mind), --a, --b;
    adj[a].push_back({b, mind});
    blocks.push_back(mind);
  }
  blocks.push_back(0);
  sort(blocks.begin(), blocks.end());
  blocks.resize(unique(blocks.begin(), blocks.end()) - blocks.begin());

  int result = INT_MAX;
  matrix_t reach(n);
  for (int v = 0; v < n; ++v) reach.set(v, v);

  for (int i = 0; i < (int)blocks.size(); ++i) {
    calc_mindist(n, blocks[i]);
    for (int v = 0; v < n; ++v)
      if (reach.get(0, v) && mindist[v][n-1] != INT_MAX)
	result = min(result, blocks[i] + mindist[v][n-1]);
    if (i+1 < (int)blocks.size()) {
      matrix_t walk(n);
      for (int v = 0; v < n; ++v)
	for (edge_t &ed : adj[v])
	  if (blocks[i] >= ed.mind)
	    walk.set(v, ed.u);

      reach = reach * pow(walk, blocks[i+1] - blocks[i]);
    }
  }

  if (result == INT_MAX) printf("Impossible\n");
  else printf("%d\n", result);

  return 0;
}