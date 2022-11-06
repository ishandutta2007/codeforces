#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

#define MAXN 200000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];

pair<int, int> dfs(int v, int p) {
  pair<int, int> result(0, v);
  for (int u : adj[v])
    if (u != p) {
      pair<int, int> res = dfs(u, v);
      result = max(result, make_pair(res.first + 1, res.second));
    }
  return result;
}

pair<int, int> dfs2(int v, int p) {
  int result = 0;
  int nfree = 0;
  
  for (int u : adj[v])
    if (u != p) {
      pair<int, int> res = dfs2(u, v);
      result += res.first;
      nfree += res.second;
    }

  if (nfree >= 2) return make_pair(result+2, 0);
  else if (nfree == 1) return make_pair(result+1, 1);
  else return make_pair(result, 1);
}

int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  lint result;
  
  if (y < x) {
    int diam = dfs(dfs(0, -1).second, -1).first;
    bool useall = diam == 0 || diam >= 3;
    if (useall) result = (lint)(n-1) * y;
    else result = (lint)(n-2) * y + x;
  } else {
    int maxuse = dfs2(0, -1).first;
    result = (lint)maxuse * x + (lint)(n-1-maxuse) * y;
  }

  cout << result << "\n";
  
  return 0;
}