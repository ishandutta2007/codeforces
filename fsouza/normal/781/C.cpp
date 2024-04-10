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

#define MAXN 200000

using namespace std;

typedef long long lint;

vector<int> adj[MAXN];
vector<int> path;
bool mark[MAXN];

void dfs(int v) {
  mark[v] = true;
  path.push_back(v);
  for (int u : adj[v])
    if (!mark[u]) {
      dfs(u);
      path.push_back(v);
    }
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  fill(mark, mark + n, false);
  dfs(0);
  int pathsize = path.size();

  int position = 0;
  for (int j = 0; j < k; ++j) {
    int partsize = pathsize / k;
    if (j < pathsize % k) ++partsize;
    if (partsize == 0) {
      printf("1 1\n");
    } else {
      printf("%d", partsize);
      for (int rep = 0; rep < partsize; ++rep, ++position)
        printf(" %d", path[position] + 1);
      printf("\n");
    }
  }

  return 0;
}