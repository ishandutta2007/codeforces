#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> pairmin(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &pairmin[i][j]);

  vector<bool> mark(n, false);
  int first = 0;
  
  vector<int> result(n);
  for (int k = 0; k < n-1; ++k) {
    int minv = INT_MAX;
    for (int i = 0; i < n; ++i)
      if (i != first && !mark[i])
	minv = min(minv, pairmin[first][i]);

    for (int i = 0; i < n; ++i)
      if (!mark[i]) {
	bool ok = true;
	for (int j = 0; j < n; ++j)
	  if (!mark[j] && j != i && pairmin[i][j] != minv) {
	    ok = false;
	    break;
	  }
	if (ok) {
	  result[i] = minv;
	  mark[i] = true;
	  while (first < n && mark[first]) ++first;
	  break;
	}
      }
  }
  result[first] = n;

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");
  
  return 0;
}