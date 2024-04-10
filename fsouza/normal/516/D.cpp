#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <queue>
#include <cmath>

#define MAXN 100000
#define INFLL 1000000000000000000LL

using namespace std;

typedef long long lint;

struct edge {
  int b, cost;
};

vector<edge> adj[MAXN];
lint memdist[MAXN], bigdista[MAXN], bigdistb[MAXN];
lint bigdist[MAXN];

pair<lint, int> dfs(int v, int p, lint dist) {
  pair<lint, int> ret(dist, v);

  memdist[v] = dist;

  for (int i = 0; i < (int)adj[v].size(); i++) {
    edge &ed = adj[v][i];
    if (ed.b == p) continue;
    ret = max(ret, dfs(ed.b, v, dist + ed.cost));
  }
  return ret;
}

int path[MAXN];
lint pathdist[MAXN];
int manygood[MAXN], deltagood[MAXN];
lint maxdelta;

void dfs2(int v, int p, lint dist, int height) {
  path[height] = v;
  pathdist[height] = dist;

  deltagood[v]++;
  int s = lower_bound(pathdist, pathdist + height+1, dist - maxdelta) - pathdist;
  if (s > 0)
    deltagood[path[s-1]]--;

  for (int i = 0; i < (int)adj[v].size(); i++) {
    edge &ed = adj[v][i];
    int v2 = ed.b;
    if (v2 == p) continue;
    if (bigdista[v2] <= bigdistb[v2]) {
      dfs2(v2, v, dist + ed.cost, height + 1);
      manygood[v] += manygood[v2];
    }
  }

  manygood[v] += deltagood[v];
}

lint mi[MAXN], ma[MAXN];

void dfs4(int v, int p, lint mii, lint maa) {
  mi[v] = mii;
  ma[v] = maa;
  
  for (int i = 0; i < (int)adj[v].size(); i++) {
    edge &ed = adj[v][i];
    int v2 = ed.b;
    if (v2 == p) continue;
    
    lint d2 = bigdist[v2];

    dfs4(v2, v, min(mii, d2), max(maa, d2));
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n-1; i++) {
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v), a--, b--;
    adj[a].push_back((edge){b, v});
    adj[b].push_back((edge){a, v});
  }
  
  int e0 = dfs(0, -1, 0).second;
  int e1 = dfs(e0, -1, 0).second;

  dfs(e0, -1, 0);
  for (int i = 0; i < n; i++) bigdista[i] = memdist[i];

  dfs(e1, -1, 0);
  for (int i = 0; i < n; i++) bigdistb[i] = memdist[i];

  for (int i = 0; i < n; i++)
    bigdist[i] = max(bigdista[i], bigdistb[i]);

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int result = 0;

    cin >> maxdelta;

    for (int rep = 0; rep < 2; rep++) {
      pair<lint, int> root(INFLL, -1);
  
      for (int i = 0; i < n; i++)
	if (bigdista[i] >= bigdistb[i])
	  root = min(root, make_pair(bigdista[i], i));
      int r = root.second;

      dfs4(r, -1, bigdist[r], bigdist[r]);

      vector<pair<lint, lint> > guys(n);
  
      for (int i = 0; i < n; i++)
	guys[i] = make_pair(ma[i], mi[i]);
      sort(guys.begin(), guys.end());

      {
	for (int i = 0; i < n; i++) deltagood[i] = manygood[i] = 0;
	dfs2(r, -1, 0LL, 0);
	for (int i = 0; i < n; i++) result = max(result, manygood[i]);
      }

      if (rep == 0) {
	set<pair<pair<lint, lint>, int> > active;

	for (int i = 0; i < n; i++) {
	  lint maxdist = guys[i].first;
	  
	  active.insert(make_pair(make_pair(guys[i].second, guys[i].first), i));

	  while (!active.empty() && maxdist - (active.begin() -> first).first > maxdelta)
	    active.erase(active.begin());

	  result = max(result, (int)active.size());
	}
      }

      for (int i = 0; i < n; i++) swap(bigdista[i], bigdistb[i]);
      swap(e0, e1);
    }

    printf("%d\n", result);
  }

  return 0;
}