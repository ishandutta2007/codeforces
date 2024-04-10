#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[100005];
set<pair<int, int> > f;

bool blockEdge(int a, int b) {
  if (a > b) swap(a, b);
  if (f.count(make_pair(a, b))) return false;
  f.insert(make_pair(a, b));
  return true;
}

int used[100005];

int dfs(int v, int par = -1) {
  used[v] = 1;
  vector<int> arr, left;
  for (int i = 0; i < g[v].size(); ++i) {
    if (blockEdge(v, g[v][i]))
      arr.push_back(g[v][i]);
  }
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i] == par) continue;
    if (used[arr[i]]) {
      left.push_back(arr[i]);
      continue;
    }
    int ret = dfs(arr[i], v);
    if (ret != -1) left.push_back(ret);
  }
  for (int i = 0; i + 1 < left.size(); i += 2) {
    printf("%d %d %d\n", left[i] + 1, v + 1, left[i + 1] + 1);
  }
  used[v] = 2;
  if (left.size() % 2 == 1) {
    printf("%d %d %d\n", left.back() + 1, v + 1, par + 1);
    return -1;
  }
  return v;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  if (m & 1) puts("No solution");
  else dfs(0);
  return 0;
}