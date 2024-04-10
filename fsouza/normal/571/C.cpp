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

#define MAXN 200000

using namespace std;

typedef long long lint;

struct edge_t {
  int u, edid;
  int idval, forv, foru;
};

bool mark[MAXN], mark2[MAXN];
vector<edge_t> adj[MAXN];

int find_cycle(int v, int pedge) {
  int ans = -1;
  mark[v] = true;
  for (edge_t &ed : adj[v])
    if (ed.edid != pedge) {
      if (mark[ed.u]) ans = v;
      else {
	int res = find_cycle(ed.u, ed.edid);
	if (res != -1) ans = res;
      }
    }
  return ans;
}

void dfs(int v, int pedge, int root, vector<int> &result) {
  mark2[v] = true;
  for (edge_t &ed : adj[v]) {
    if (ed.edid != pedge) {
      if (!mark2[ed.u]) {
	result[ed.idval] = ed.foru;
	dfs(ed.u, ed.edid, root, result);
      } else {
	if (ed.u == root) result[ed.idval] = ed.foru;
      }
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<vector<int>> iftrue(m), iffalse(m);
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int val;
      scanf("%d", &val);
      int id = abs(val)-1;
      if (val > 0) iftrue[id].push_back(i);
      else iffalse[id].push_back(i);
    }
  }

  int nedge = 0;
  for (int i = 0; i < m; ++i) {
    if (iftrue[i].empty()) {
      for (int c : iffalse[i])
	adj[c].push_back({c, nedge++, i, 0, 0});
    } else if (iffalse[i].empty()) {
      for (int c : iftrue[i])
	adj[c].push_back({c, nedge++, i, 1, 1});
    } else {
      assert(iftrue[i].size() == 1);
      assert(iffalse[i].size() == 1);
      int t = iftrue[i].front(), f = iffalse[i].front();
      adj[t].push_back({f, nedge, i, 1, 0});
      adj[f].push_back({t, nedge, i, 0, 1});
      ++nedge;
    }
  }

  bool ok = true;
  vector<int> result(m);

  fill(mark, mark+n, false);
  fill(mark2, mark2+n, false);
  for (int i = 0; i < n; ++i)
    if (!mark[i]) {
      int c = find_cycle(i, -1);
      if (c == -1) {
	ok = false;
	break;
      }
      dfs(c, -1, c, result);
    }

  if (!ok) printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < m; ++i) printf("%d", result[i]);
    printf("\n");
  }

  return 0;
}