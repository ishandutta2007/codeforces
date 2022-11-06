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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 100000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];

struct res_t {
  bool dproot, dpchild;
  bool singlepath, doublepath;
};

bool badroot[MAXN];

res_t dfs(int v, int p, bool single = true) {
  int nchild = 0;
  for (int u : adj[v])
    if (u != p)
      ++nchild;

  vector<res_t> children;
  for (int u : adj[v])
    if (u != p)
      children.push_back(dfs(u, v, (single && (nchild == 1))));

  int nonsimple = 0;
  if (!single) ++nonsimple;
  for (res_t child : children)
    if (!child.doublepath)
      ++nonsimple;

  if (nonsimple <= 1) badroot[v] = true;

  res_t result;
  if (children.size() == 0) {
    result.singlepath = result.doublepath = true;
  } else if (children.size() == 1) {
    result.singlepath = result.doublepath = children[0].singlepath;
  } else if (children.size() == 2) {
    result.singlepath = false;
    result.doublepath = (children[0].singlepath && children[1].singlepath);
  } else {
    result.singlepath = result.doublepath = false;
  }

  int nimportant = 0;

  for (res_t child : children) {
    if (child.doublepath) {
    } else if (!child.dpchild) {
      result.dproot = result.dpchild = false;
      return result;
    } else {
      ++nimportant;
    }
  }

  result.dproot = (nimportant <= 2);
  result.dpchild = (nimportant <= 1);

  return result;
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

  for (int i = 0; i < n; ++i) {
    badroot[i] = false;
  }

  vector<int> cands;

  for (int i = 0; i < n; ++i)
    if (adj[i].size() >= 3)
      cands.push_back(i);

  int root = -1;
  dfs(0, -1);
  for (int cand : cands)
    if (!badroot[cand]) {
      root = cand;
      break;
    }

  bool result;
  if (root == -1) result = true;
  else result = dfs(root, -1).dproot;

  if (result) printf("Yes\n");
  else printf("No\n");

  return 0;
}