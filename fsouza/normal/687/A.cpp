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
int color[MAXN];
bool ok;

void dfs(int v, int c) {
  if (color[v]) {
    if (color[v] != c) ok = false;
    return;
  }
  color[v] = c;
  for (int u : adj[v])
    dfs(u, -c);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  ok = true;
  for (int i = 0; i < n; ++i) {
    color[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (!color[i]) {
      dfs(i, 1);
    }
  }

  if (!ok) printf("-1\n");
  else {
    vector<int> resulta, resultb;
    for (int i = 0; i < n; ++i) {
      if (color[i] == 1) resulta.push_back(i);
      else resultb.push_back(i);
    }
    for (vector<int> result : {resulta, resultb}) {
      printf("%d\n", (int)result.size());
      for (int i = 0; i < (int)result.size(); ++i) {
	if (i > 0) printf(" ");
	printf("%d", result[i]+1);
      }
      printf("\n");
    }
  }

  return 0;
}