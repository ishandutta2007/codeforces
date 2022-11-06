#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

const int maxn = 300000;
const int maxlogn = 20;

lint result[maxn];
int delta[maxn];
int prefix[maxn];
vector<int> adj[maxn];
int parent[maxn][maxlogn+1];
vector<int> atlevel[maxn];
int travel[maxn], tsize;
int levelof[maxn];
int valuec[maxn];
char str[maxn+1];

int goup(int a, int dist) {
  for (int l = 0; l <= maxlogn; ++l)
    if (dist & (1<<l))
      a = parent[a][l];
  return a;
}

int lca(int a, int b) {
  if (levelof[a] < levelof[b]) swap(a, b);
  a = goup(a, levelof[a] - levelof[b]);
  if (a == b) return a;
  for (int l = maxlogn; l >= 0; --l)
    if (parent[a][l] != parent[b][l])
      a = parent[a][l], b = parent[b][l];
  return parent[a][0];
}

void dfs(int v, int p, int lev) {
  travel[tsize++] = v;
  atlevel[lev].push_back(v);
  levelof[v] = lev;
  
  parent[v][0] = p;
  for (int l = 1; l <= maxlogn; ++l)
    parent[v][l] = parent[parent[v][l-1]][l-1];

  for (int u : adj[v])
    if (u != p) {
      dfs(u, v, lev+1);
    }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &valuec[i]);

  scanf(" %s", str);

  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  tsize = 0;
  dfs(0, 0, 0);

  prefix[0] = 0;
  int sofar = 0;
  
  for (int lev = 1; lev < n; ++lev) {
    vector<pair<lint, int>> tosort;
    for (int v : atlevel[lev])
      tosort.push_back(make_pair(prefix[parent[v][0]] * 30LL + str[v]-'a', v));
    sort(tosort.begin(), tosort.end());

    lint lastval = -1;
    for (auto valv : tosort) {
      lint val = valv.first;
      int v = valv.second;
      if (val != lastval) {
	++sofar;
	lastval = val;
      }
      prefix[v] = sofar;
    }
  }

  for (int i = 0; i < n; ++i) delta[i] = 0;
  
  for (int lev = 0; lev < n; ++lev) {
    for (int i = 0; i < (int)atlevel[lev].size(); ++i) {
      int v = atlevel[lev][i];
      ++delta[v];
    }
    stable_sort(atlevel[lev].begin(), atlevel[lev].end(), [](int u, int v) {
	return prefix[u] < prefix[v];
      });
    for (int i = 0; i+1 < (int)atlevel[lev].size(); ++i) {
      int v = atlevel[lev][i], u = atlevel[lev][i+1];
      if (prefix[v] == prefix[u]) {
	int lcauv = lca(u, v);
	--delta[lcauv];
      }
    }
  }

  for (int v = 0; v < n; ++v) result[v] = 0;
  
  for (int lev = n-1; lev >= 0; --lev) {
    for (int v : atlevel[lev]) {
      result[v] += delta[v];
      if (lev != 0)
	result[parent[v][0]] += result[v];
    }
  }

  for (int v = 0; v < n; ++v)
    result[v] += valuec[v];

  lint maxret = *max_element(result, result+n);
  lint manyret = count(result, result+n, maxret);

  cout << maxret << endl << manyret << endl;
  
  return 0;
}