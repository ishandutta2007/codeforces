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
#include <stack>
#include <unordered_map>
#include <vector>

#define MAXN 300000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
vector<pair<int, int>> workers[MAXN];
int depth[MAXN];

struct solution {
  int depth;
  lint cost;
};
struct solset {
  struct bydepth {
    bool operator()(const solution &a, const solution &b) const {
      if (a.depth != b.depth) return a.depth < b.depth;
      return a.cost < b.cost;
    }
  };
  struct bycost {
    bool operator()(const solution &a, const solution &b) const {
      if (a.cost != b.cost) return a.cost < b.cost;
      return a.depth < b.depth;
    }
  };
  set<solution, bydepth> setd;
  set<solution, bycost> setc;
  lint deltacost = 0;
  void prune_above(int d) {
    while (!setd.empty() && setd.rbegin()->depth > d) {
      solution last = *setd.rbegin();
      setd.erase(last);
      setc.erase(last);
    }
  }
  lint mincost() {
    return deltacost + setc.begin()->cost;
  }
};

solset merge(solset a, solset b) {
  if (a.setd.size() > b.setd.size()) return merge(move(b), move(a));
  for (const solution &sol : a.setd) {
    solution newsol = {sol.depth, sol.cost + a.deltacost - b.deltacost};
    b.setd.insert(newsol);
    b.setc.insert(newsol);
  }
  return move(b);
}

solset dfs(int v, int p, int d) {
  depth[v] = d;
  vector<solset> children;
  for (int u : adj[v])
    if (u != p)
      children.push_back(dfs(u, v, d+1));
  lint totalmincost = 0;
  for (solset &ss : children) {
    ss.prune_above(d);
    if (ss.setd.empty()) return {};
    totalmincost += ss.mincost();
  }
  for (solset &ss : children)
    ss.deltacost += totalmincost - ss.mincost();
  solset result;
  for (auto worker : workers[v]) {
    solution sol = {depth[worker.first], totalmincost + worker.second};
    result.setd.insert(sol);
    result.setc.insert(sol);
  }
  for (solset &ss : children) result = merge(move(result), move(ss));
  return move(result);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < m; ++i) {
    int down, up, cost;
    scanf("%d %d %d", &down, &up, &cost), --down, --up;
    if (down != up) workers[down].emplace_back(up, cost);
  }
  workers[0].emplace_back(0, 0);
  solset result = dfs(0, -1, 0);
  if (result.setc.empty()) printf("-1\n");
  else printf("%lld\n", result.mincost());

  return 0;
}