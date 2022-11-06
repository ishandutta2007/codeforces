#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <set>
#include <vector>

#define INF 1000000000
#define MAXN 100000
#define MAXLOGN 17

using namespace std;

typedef long long lint;

int preorderpos;
int invpreorder[MAXN], isimp[MAXN], newidof[MAXN];
int parent[MAXN][MAXLOGN+1], height[MAXN], logn;
vector<int> adj[MAXN];

vector<int> children[MAXN];
int dp[MAXN][2];

void solve(int v) {
  for (int c : children[v]) solve(c);

  if (isimp[v]) {
    dp[v][1] = INF;

    dp[v][0] = 0;
    for (int c : children[v])
      dp[v][0] = min(INF, dp[v][0] + dp[c][1]);
  } else {
    lint sum0 = 0, sum1 = 0;
    for (int c : children[v])
      sum0 += dp[c][0], sum1 += dp[c][1];

    dp[v][1] = min(min(1 + sum0, sum1), (lint)INF);

    dp[v][0] = min(1 + sum0, (lint)INF);
    for (int c : children[v]) {
      lint cand = dp[c][0] + (sum1 - dp[c][1]);
      dp[v][0] = min((lint)dp[v][0], cand);
    }
  }
}

void dfs(int v, int p, int h) {
  invpreorder[v] = preorderpos++;
  height[v] = h;
  parent[v][0] = p;
  for (int l = 1; l <= logn; ++l)
    parent[v][l] = parent[parent[v][l-1]][l-1];

  for (int u : adj[v])
    if (u != p)
      dfs(u, v, h+1);
}

int goup(int v, int dist) {
  for (int l = 0; l <= logn; ++l)
    if (dist & (1<<l))
      v = parent[v][l];
  return v;
}

int lca(int a, int b) {
  if (height[a] < height[b]) swap(a, b);
  a = goup(a, height[a] - height[b]);
  if (a == b) return a;
  for (int l = logn; l >= 0; --l)
    if (parent[a][l] != parent[b][l])
      a = parent[a][l], b = parent[b][l];
  return parent[a][0];
}

bool is_parent(int p, int v) {
  if (height[p] > height[v]) return false;
  return p == goup(v, height[v] - height[p]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  logn = 0;
  while ((1<<(logn+1)) <= n) ++logn;

  preorderpos = 0;
  dfs(0, 0, 0);

  vector<int> imp, useful, stack;
  for (int i = 0; i < n; ++i) isimp[i] = 0;
  
  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    imp.clear();
    useful.clear();
    stack.clear();

    int nimp;
    scanf("%d", &nimp);
    imp.resize(nimp);
    useful.resize(nimp);
    
    for (int i = 0; i < nimp; ++i) {scanf("%d", &imp[i]), --imp[i]; useful[i] = imp[i];}

    sort(imp.begin(), imp.end(), [](int a, int b) {return invpreorder[a] < invpreorder[b];});
    
    for (int i = 0; i < nimp; ++i) {
      int v = imp[i];
      if (parent[v][0] != v) useful.push_back(parent[v][0]);
      if (i+1 < nimp) {
    int u = imp[i+1];
    int l = lca(u, v);
    useful.push_back(l);
      }
    }
    useful.push_back(0);

    sort(useful.begin(), useful.end());
    useful.resize(unique(useful.begin(), useful.end())-useful.begin());

    sort(useful.begin(), useful.end(), [](int a, int b) {return invpreorder[a] < invpreorder[b];});

    for (int i = 0; i < (int)useful.size(); ++i) {
      newidof[useful[i]] = i;
      children[i].clear();
    }

    for (int v : imp) isimp[newidof[v]] = 1;

    for (int i = 0; i < (int)useful.size(); ++i) {
      int v = useful[i];

      if (i != 0) {
    while (!is_parent(stack.back(), v)) stack.pop_back();
    children[newidof[stack.back()]].push_back(newidof[v]);
      }

      stack.push_back(v);
    }

    solve(0);

    int res = dp[0][0];
    if (res >= INF) printf("-1\n");
    else printf("%d\n", res);

    for (int v : imp) isimp[newidof[v]] = 0;
  }
  
  return 0;
}