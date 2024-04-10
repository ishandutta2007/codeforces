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
#define MAXM 100

using namespace std;

typedef long long lint;

int ma[MAXN], v[MAXN][MAXM];

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int j = 0; j < m; j++) ma[j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      scanf(" %c", &c);
      v[i][j] = c - '0';
      ma[j] = max(ma[j], v[i][j]);
    }

  int ret = 0;

  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (int j = 0; j < m; j++)
      if (v[i][j] == ma[j])
	ok = true;
    if (ok)
      ret++;
  }

  printf("%d\n", ret);

  return 0;
}