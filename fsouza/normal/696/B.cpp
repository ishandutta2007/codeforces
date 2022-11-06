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
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);

  vector<vector<int>> children(n);
  vector<int> tworesult(n);

  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p), --p;
    children[p].push_back(i);
  }

  function<int(int, int)> dfs = [&](int v, int depth) {
    int sts = 1;
    for (int u : children[v])
      sts += dfs(u, depth + 1);
    tworesult[v] = 2*(1 + depth) + (n - sts - depth);
    return sts;
  };
  dfs(0, 0);

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d.%d", tworesult[i]/2, tworesult[i]%2*5);
  }
  printf("\n");

  return 0;
}