#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

#define MAXN 100
#define INF 1000000000

using namespace std;

typedef long long lint;

bool adj[MAXN][MAXN];

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      adj[i][j] = false;

  vector<int> v(n);

  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b); a--, b--;
    adj[a][b] = adj[b][a] = true;
  }

  int ret = INF;

  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      for (int k = j+1; k < n; k++)
	if (adj[i][j] && adj[j][k] && adj[i][k])
	  ret = min(ret, v[i] + v[j] + v[k]);

  if (ret < INF)
    printf("%d\n", ret);
  else
    printf("-1\n");

  return 0;
}