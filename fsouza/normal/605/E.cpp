#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

const double E = 1e-9;

int main() {
  int n;
  scanf("%d", &n);

  vector<vector<double>> prob(n, vector<double>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int p;
      scanf("%d", &p);
      prob[i][j] = p / 100.;
    }
  }

  vector<double> result(n, 1.0);
  vector<double> allfail(n, 1.0);
  vector<int> mark(n, 0);

  int v = n-1;
  result[n-1] = 0.0;
  allfail[n-1] = 0.0;

  while (v != -1) {
    mark[v] = 1;
    result[v] /= 1 - allfail[v];

    for (int u = 0; u < n; ++u)
      if (!mark[u]) {
	result[u] += allfail[u] * prob[u][v] * result[v];
	allfail[u] *= 1.0 - prob[u][v];
      }

    v = -1;
    for (int u = 0; u < n; ++u)
      if (!mark[u] && allfail[u] < 1.0-E && (v == -1 || result[u]/(1-allfail[u]) < result[v]/(1-allfail[v])))
	v = u;
  }

  printf("%.9f\n", result[0]);
  
  return 0;
}