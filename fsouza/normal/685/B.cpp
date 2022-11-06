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

#define MAXN 300000

using namespace std;

typedef long long lint;

vector<int> children[MAXN];
int sts[MAXN], parent[MAXN], result[MAXN];

void dfs0(int v) {
  sts[v] = 1;
  for (int u : children[v]) {
    dfs0(u);
    sts[v] += sts[u];
  }
}

void dfs1(int v) {
  pair<int, int> biggest = make_pair(-1, -1);
  for (int u : children[v]) {
    dfs1(u);
    biggest = max(biggest, make_pair(sts[u], u));
  }

  if (biggest.first == -1 || !(2*biggest.first > sts[v])) {
    result[v] = v;
  } else {
    int r = result[biggest.second];
    while (2*(sts[v] - sts[r]) > sts[v])
      r = parent[r];
    result[v] = r;
  }
}

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p), --p;
    children[p].push_back(i);
    parent[i] = p;
  }
  dfs0(0);
  dfs1(0);

  for (int q = 0; q < nq; ++q) {
    int v;
    scanf("%d", &v), --v;
    printf("%d\n", result[v]+1);
  }

  return 0;
}