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

using namespace std;

typedef long long lint;

vector<vector<pair<int, int>>> adj;
vector<int> colorof;

void dfs(int v, int p, int pc) {
  int color = 0;
  for (auto ed : adj[v]) {
    int u, id;
    tie(u, id) = ed;
    if (u != p) {
      if (color == pc) ++color;
      colorof[id] = color;
      dfs(u, v, color);
      ++color;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  adj.resize(n);
  colorof.resize(n-1);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
  }
  dfs(0, -1, -1);
  int ncolor = *max_element(colorof.begin(), colorof.end()) + 1;
  vector<vector<int>> result(ncolor);
  for (int i = 0; i < n-1; ++i) result[colorof[i]].push_back(i);
  printf("%d\n", ncolor);
  for (int c = 0; c < ncolor; ++c) {
    printf("%d", (int)result[c].size());
    for (int id : result[c])
      printf(" %d", id+1);
    printf("\n");
  }

  return 0;
}