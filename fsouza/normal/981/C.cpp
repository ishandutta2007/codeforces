#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 100000;

vector<int> adj[maxn];
bool ok;
vector<pair<int, int>> result;

int dfs(int v, int p) {
  int res = -1;
  int nc = 0;
  for (int u : adj[v])
    if (u != p) {
      ++nc;
      res = dfs(u, v);
    }
  if (nc == 0) return v;
  else if (nc == 1) return res;
  else {
    ok = false;
    return -1;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int v = 0;
  for (int i = 1; i < n; ++i)
    if (adj[i].size() > adj[v].size())
      v = i;

  ok = true;
  for (int u : adj[v]) {
    result.push_back(make_pair(v, dfs(u, v)));
  }
  if (!ok) printf("No\n");
  else {
    printf("Yes\n");
    printf("%d\n", (int)result.size());
    for (pair<int, int> path : result)
      printf("%d %d\n", path.first + 1, path.second + 1);
  }

  return 0;
}