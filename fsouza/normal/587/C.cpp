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

#define MAXN 100000
#define MAXLOGN 16

using namespace std;

typedef long long lint;
const int maxa = 10;

struct ans_t {
  int ids[maxa];
  ans_t(int v = INT_MAX) {
    ids[0] = v;
    for (int i = 1; i < maxa; ++i) ids[i] = INT_MAX;
  }
  void add(int v) {
    if (v < ids[maxa-1]) {
      ids[maxa-1] = v;
      for (int i = maxa-1; i > 0 && ids[i] < ids[i-1]; --i)
	swap(ids[i], ids[i-1]);
    }
  }
};

ans_t combine(const ans_t &a1, const ans_t &a2) {
  int res[2*maxa];
  merge(a1.ids, a1.ids+maxa, a2.ids, a2.ids+maxa, res);
  ans_t ans;
  for (int i = 0; i < maxa; ++i) ans.ids[i] = res[i];
  return ans;
}

vector<int> adj[MAXN];
struct path_t {
  int up;
  ans_t answer;
} paths[MAXN][MAXLOGN+1];
int logn, depth[MAXN];

void dfs(int v, int p, int d) {
  paths[v][0].up = p;
  depth[v] = d;
  for (int l = 1; l <= logn; ++l) {
    if (paths[v][l-1].up == -1)
      paths[v][l].up = -1, paths[v][l].answer = paths[v][l-1].answer;
    else {
      paths[v][l].up = paths[paths[v][l-1].up][l-1].up;
      paths[v][l].answer = combine(paths[v][l-1].answer, paths[paths[v][l-1].up][l-1].answer);
    }
  }
  for (int u : adj[v])
    if (u != p)
      dfs(u, v, d+1);
}

path_t get_path(int v, int size) {
  path_t res;
  for (int l = 0; 1<<l <= size; ++l)
    if (size & (1<<l)) {
      res.answer = combine(res.answer, paths[v][l].answer);
      v = paths[v][l].up;
    }
  res.up = v;
  return res;
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  a = get_path(a, depth[a] - depth[b]).up;
  if (a == b) return a;
  for (int l = logn; l >= 0; --l)
    if (paths[a][l].up != paths[b][l].up)
      a = paths[a][l].up, b = paths[b][l].up;
  return paths[a][0].up;
}

int main() {
  int n, npeople, nq;
  scanf("%d %d %d", &n, &npeople, &nq);
  logn = 0; while (1<<logn+1 <= n) ++logn;
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < npeople; ++i) {
    int v;
    scanf("%d", &v), --v;
    paths[v][0].answer.add(i);
  }
  dfs(0, -1, 0);

  for (int q = 0; q < nq; ++q) {
    int u, v, a;
    scanf("%d %d %d", &u, &v, &a), --u, --v;
    int l = lca(u, v);
    path_t p1 = get_path(u, depth[u] - depth[l]), p2 = get_path(v, depth[v] - depth[l]);
    ans_t ans = combine(combine(p1.answer, p2.answer), paths[l][0].answer);
    a = min(a, (int)(lower_bound(ans.ids, ans.ids+maxa, INT_MAX) - ans.ids));
    printf("%d", a);
    for (int i = 0; i < a; ++i) printf(" %d", ans.ids[i]+1);
    printf("\n");
  }
  
  return 0;
}