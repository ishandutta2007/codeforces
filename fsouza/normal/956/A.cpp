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

int main() {
  int height, width;
  scanf("%d %d", &height, &width);
  vector<string> field(height, string(width, ' '));

  vector<vector<int>> adj(height + width);
  int nblack = 0;
  for (int y = 0; y < height; ++y) {
    scanf(" %s", &field[y][0]);
    for (int x = 0; x < width; ++x) {
      if (field[y][x] == '#') {
        ++nblack;
        adj[y].push_back(height + x);
        adj[height + x].push_back(y);
      }
    }
  }

  int nrow, nline;
  int nblack2 = 0;
  vector<bool> mark(height + width, false);
  function<void(int)> dfs = [&](int v) {
    mark[v] = true;
    if (v < height) ++nrow;
    else ++nline;
    for (int u : adj[v])
      if (!mark[u])
        dfs(u);
  };
  for (int y = 0; y < height; ++y)
    if (!mark[y]) {
      nrow = 0, nline = 0;
      dfs(y);
      nblack2 += nrow * nline;
    }

  if (nblack == nblack2) printf("Yes\n");
  else printf("No\n");

  return 0;
}