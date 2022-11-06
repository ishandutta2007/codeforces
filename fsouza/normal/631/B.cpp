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
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  vector<vector<int>> result(n, vector<int>(m, 0));
  struct query_t { int kind, pos, color; };
  vector<query_t> queries(nq);
  for (int q = 0; q < nq; ++q) {
    query_t &query = queries[q];
    scanf("%d %d %d", &query.kind, &query.pos, &query.color), --query.pos;
  }
  vector<bool> donerow(n, false), donecol(m, false);
  for (int q = nq-1; q >= 0; q--) {
    query_t &query = queries[q];
    if (query.kind == 1) {
      int row = query.pos;
      if (donerow[row]) continue;
      donerow[row] = true;
      for (int x = 0; x < m; ++x)
	if (result[row][x] == 0)
	  result[row][x] = query.color;
    } else {
      int col = query.pos;
      if (donecol[col]) continue;
      donecol[col] = true;
      for (int y = 0; y < n; ++y)
	if (result[y][col] == 0)
	  result[y][col] = query.color;
    }
  }
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (x > 0) printf(" ");
      printf("%d", result[y][x]);
    }
    printf("\n");
  }
  return 0;
}