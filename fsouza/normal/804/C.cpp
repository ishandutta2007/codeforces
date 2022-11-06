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

vector<vector<int>> adj;
vector<vector<int>> kinds;
vector<int> color_of;

void dfs(int v, int p) {
  static vector<int> used; used.clear();
  for (int k : kinds[v])
    if (color_of[k] != -1)
      used.push_back(color_of[k]);
  sort(used.begin(), used.end());
  int current_color = 0, current_pos = 0;
  for (int k : kinds[v])
    if (color_of[k] == -1) {
      while (current_pos < (int)used.size() &&
             used[current_pos] <= current_color) {
        if (used[current_pos] == current_color)
          ++current_color;
        ++current_pos;
      }
      color_of[k] = current_color++;
    }
  for (int u : adj[v])
    if (u != p)
      dfs(u, v);
}

int main() {
  int n, nkind;
  scanf("%d %d", &n, &nkind);

  adj.resize(n);
  kinds.resize(n);
  color_of.resize(nkind, -1);

  for (int i = 0; i < n; ++i) {
    int many;
    scanf("%d", &many);
    for (int j = 0; j < many; ++j) {
      int kind;
      scanf("%d", &kind), --kind;
      kinds[i].push_back(kind);
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(0, -1);

  for (int i = 0; i < nkind; ++i)
    if (color_of[i] == -1)
      color_of[i] = 0;

  int max_color = *max_element(color_of.begin(), color_of.end());
  printf("%d\n", max_color + 1);
  for (int i = 0; i < nkind; ++i) {
    if (i > 0) printf(" ");
    printf("%d", color_of[i] + 1);
  }
  printf("\n");
  return 0;
}