#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[505], in[505], deg[505];
int g[505][505];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int v = 0, e = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a; --b;
    g[a][b] = g[b][a] = c;
  }
  double ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (g[i][j])
        ans = max(ans, 1.0 * (arr[i] + arr[j]) / g[i][j]);
  printf("%.15lf\n", ans);
  return 0;
}