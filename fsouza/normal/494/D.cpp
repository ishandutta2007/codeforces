#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define MAXQ 100000
#define MAXN 100000
#define MAXLOGN 16

using namespace std;

const int mod = 1e9 + 7;

typedef long long lint;

struct sol_t {
  int many;
  int sum2;
  int sum1;
  sol_t() {many = sum1 = sum2 = 0;}

  void include(const sol_t &other) {
    many = (many + other.many) % mod;
    sum2 = (sum2 + other.sum2) % mod;
    sum1 = (sum1 + other.sum1) % mod;
  }

  void uninclude(const sol_t &other) {
    many = (many - other.many + mod) % mod;
    sum2 = (sum2 - other.sum2 + mod) % mod;
    sum1 = (sum1 - other.sum1 + mod) % mod;
  }

  void increase_all(int by) {
    sum2 = (sum2 + (lint)many * by % mod * by % mod + 2LL * by * sum1) % mod;
    sum1 = (sum1 + (lint)many * by) % mod;
  }
};

vector<pair <int, int> > adj[MAXN];
int height[MAXN];
lint depth[MAXN];
sol_t down[MAXN];
sol_t up[MAXN];
sol_t full[MAXN];

vector<int> path;
vector<lint> pathsum;
vector<pair<int, int> > queries[MAXN];
sol_t result[MAXQ];

int logn;
int parent[MAXN][MAXLOGN+1];

int goup(int a, int dist) {
  for (int l = 0; (1<<l) <= dist; l++)
    if (dist & (1<<l))
      a = parent[a][l];
  return a;
}

int lca(int a, int b) {
  if (height[a] < height[b]) swap(a, b);
  a = goup(a, height[a] - height[b]);
  if (a == b) return a;
  for (int l = logn; l >= 0; l--)
    if (parent[a][l] != parent[b][l]) {
      a = parent[a][l];
      b = parent[b][l];
    }
  return parent[a][0];
}

lint dist(int a, int b) {
  return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

void dfs3(int u, int p, lint sum = 0) {
  path.push_back(u);
  pathsum.push_back(sum);

  for (pair<int, int> query : queries[u]) {
    int v = query.first;
    int qid = query.second;

    if (height[v] < (int)path.size() && path[height[v]] == v) {
      result[qid].include(full[u]);
      
      sol_t temp = up[v];
      temp.increase_all((sum - pathsum[height[v]]) % mod);
      
      result[qid].uninclude(temp);
      result[qid].uninclude(temp);
    } else {
      result[qid].uninclude(full[u]);
      
      sol_t temp = down[v];
      temp.increase_all(dist(u, v) % mod);
      result[qid].include(temp);
      result[qid].include(temp);
    }
  }

  for (const pair <int, int> &pp : adj[u]) {
    int v2 = pp.first, dist = pp.second;
    if (v2 == p) continue;
    
    dfs3(v2, u, sum + dist);
  }

  path.pop_back();
  pathsum.pop_back();
}

void dfs2(int v, int p, sol_t got) {
  up[v] = got;

  full[v] = up[v];
  full[v].include(down[v]);

  vector<pair <int, int> > child;

  for (const pair <int, int> &pp : adj[v]) {
    int v2 = pp.first, dist = pp.second;
    if (v2 == p) continue;
    child.push_back(make_pair(v2, dist));
  }

  int nc = child.size();

  sol_t sum = down[v];

  for (int c = 0; c < nc; c++) {
    sol_t just = sum;
    
    {
      sol_t temp = down[child[c].first];
      temp.increase_all(child[c].second);
      just.uninclude(temp);
    }

    just.include(got);
    just.increase_all(child[c].second);

    dfs2(child[c].first, v, just);
  }
}

void dfs(int v, int p, int h, lint d) {
  for (int l = 1; l <= logn; l++)
    parent[v][l] = parent[parent[v][l-1]][l-1];

  height[v] = h;
  depth[v] = d;

  down[v] = sol_t();
  down[v].many = 1;

  for (const pair <int, int> &pp : adj[v]) {
    int v2 = pp.first, dist = pp.second;
    if (v2 == p) continue;
    
    parent[v2][0] = v;
    dfs(v2, v, h+1, d + dist);

    sol_t temp = down[v2];
    temp.increase_all(dist);

    down[v].include(temp);
  }
}

int main() {
  int n;

  scanf("%d", &n);

  logn = 0;
  while ((1<<(logn+1)) <= n) logn++;
  
  for (int i = 0; i < n-1; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); a--, b--;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  parent[0][0] = 0;
  dfs(0, -1, 0, 0);

  sol_t temp;
  dfs2(0, -1, temp);

  int nq;

  scanf("%d", &nq);

  for (int q = 0; q < nq; q++) {
    int u, v;
    scanf("%d %d", &u, &v); u--, v--;
    queries[u].push_back(make_pair(v, q));
  }

  dfs3(0, -1);

  for (int q = 0; q < nq; q++)
    printf("%d\n", result[q].sum2);

  return 0;
}