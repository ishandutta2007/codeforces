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

#define MAXN 100000

using namespace std;

typedef long long lint;

struct edge {
  int u;
  char c;
};

vector<edge> adj[MAXN];
int side[MAXN];
bool ok;
vector<int> side0, side1;

void dfs(int v, int s, char color) {
  if (side[v] != -1) {
    if (side[v] != s)
      ok = false;
    return;
  }
  side[v] = s;
  if (s == 0) side0.push_back(v);
  else side1.push_back(v);
  for (edge &ed : adj[v])
    dfs(ed.u, s ^ (ed.c == color), color);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    char c;
    scanf(" %d %d %c", &a, &b, &c), --a, --b;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  int result = INT_MAX;
  vector<int> nodes;
  for (char color : {'R', 'B'}) {
    int res = 0;
    vector<int> resnodes;
    for (int i = 0; i < n; ++i) side[i] = -1;
    for (int i = 0; i < n; ++i)
      if (side[i] == -1) {
	ok = true;
	side0.clear(); side1.clear();
	dfs(i, 0, color);
	if (!ok) {
	  res = INT_MAX;
	  break;
	}
	for (int v : (side0.size() < side1.size() ? side0 : side1)) resnodes.push_back(v);
	res += min(side0.size(), side1.size());
      }
    if (res < result) {
      result = res;
      nodes = move(resnodes);
    }
  }

  if (result == INT_MAX) printf("-1\n");
  else {
    vector<int> &resnodes = nodes;
    sort(resnodes.begin(), resnodes.end());
    printf("%d\n", resnodes.size());
    for (int i = 0; i < (int)resnodes.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", resnodes[i]+1);
    }
    printf("\n");
  }

  return 0;
}