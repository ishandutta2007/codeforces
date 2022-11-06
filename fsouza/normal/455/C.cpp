#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXN 300000

using namespace std;

typedef long long lint;

bool mark[MAXN];
int parent[MAXN], height[MAXN], diameter[MAXN];
vector <int> adj[MAXN];

int search(int v) {
  if (v == parent[v]) return v;
  return parent[v] = search(parent[v]);
}

int join(int a, int b) {
  a = search(a); b = search(b);
  if (a == b) return a;
  if (height[a] > height[b]) swap(a, b);
  parent[a] = b;
  if (height[a] == height[b]) height[b]++;
  return b;
}

pair <int, int> dfs(int v, int p) {
  pair <int, int> ret = make_pair(0, v);

  mark[v] = true;
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int v2 = adj[v][i];
    if (v2 != p) {
      pair <int, int> v2ret = dfs(v2, v);
      ret = max(ret, make_pair(v2ret.first + 1, v2ret.second));
    }
  }

  return ret;
}

int main() {
  int n, m, q;

  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < n; i++) {
    parent[i] = i;
    height[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b); a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    join(a, b);
  }

  for (int i = 0; i < n; i++) mark[i] = false;

  for (int i = 0; i < n; i++)
    if (!mark[i]) {
      pair <int, int> dfs0 = dfs(i, -1);
      pair <int, int> dfs1 = dfs(dfs0.second, -1);
      int root = search(i);
      diameter[root] = dfs1.first;
    }

  for (int i = 0; i < q; i++) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int v;
      scanf("%d", &v); v--;
      int root = search(v);
      printf("%d\n", diameter[root]);
    } else {
      int ra, rb;
      {
	int a, b;
	scanf("%d %d", &a, &b); a--, b--;
	ra = search(a); rb = search(b);
      }
      if (ra != rb) {
	int da = diameter[ra], db = diameter[rb];
	int mid = (da+1)/2 + 1 + (db+1)/2;
	int newd = max(mid, max(da, db));
	diameter[join(ra, rb)] = newd;
      }
    }
  }
  
  return 0;
}