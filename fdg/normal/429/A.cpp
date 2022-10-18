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
vector<int> ans, init, goal;

void dfs(int v, int u1, int u2, int par = -1) {
  int val = u2 ^ init[v];
  if (val != goal[v]) {
    u2 ^= 1;
    ans.push_back(v);
  }
  swap(u1, u2);
  for (int u : g[v]) {
    if (u != par) dfs(u, u1, u2, v);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  init.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &init[i]);
  goal.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &goal[i]);
  dfs(0, 0, 0);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d\n", ans[i] + 1);
  }
  return 0;
}