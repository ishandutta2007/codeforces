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

vector<bool> present;
vector<vector<int>> adj;

int dfs(int v, int p) {
  if (present[v])
    return v;
  for (int u : adj[v])
    if (u != p) {
      int res = dfs(u, v);
      if (res != -1)
        return res;
    }
  return -1;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    adj.resize(n);
    for (int i = 0; i < n; ++i)
      adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      scanf("%d %d", &a, &b), --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int k1;
    scanf("%d", &k1);
    vector<int> nodes1(k1);
    for (int i = 0; i < k1; ++i)
      scanf("%d", &nodes1[i]), --nodes1[i];
    int k2;
    scanf("%d", &k2);
    vector<int> nodes2(k2);
    for (int i = 0; i < k2; ++i)
      scanf("%d", &nodes2[i]), --nodes2[i];

    printf("B %d\n", nodes2[0] + 1);
    fflush(stdout);
    int mine;
    scanf("%d", &mine), --mine;

    if (find(nodes1.begin(), nodes1.end(), mine) != nodes1.end()) {
      printf("C %d\n", mine + 1);
      fflush(stdout);
    } else {
      present.assign(n, false);
      for (int v : nodes1) present[v] = true;
      int closest = dfs(mine, -1);
      printf("A %d\n", closest + 1);
      fflush(stdout);
      int his;
      scanf("%d", &his), --his;
      if (find(nodes2.begin(), nodes2.end(), his) != nodes2.end()) {
        printf("C %d\n", closest + 1);
        fflush(stdout);
      } else {
        printf("C -1\n");
        fflush(stdout);
      }
    }
  }
  return 0;
}