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
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  vector<vector<pair<int, int>>> table(n, vector<pair<int, int>>(m));
  vector<vector<int>> result(n, vector<int>(m, 0));

  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x)
      table[y][x] = make_pair(y, x);

  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int r;
      scanf("%d", &r), --r;
      rotate(table[r].begin(), table[r].begin()+1, table[r].end());
    } else if (kind == 2) {
      int c;
      scanf("%d", &c), --c;
      auto first = table[0][c];
      for (int y = 0; y+1 < n; ++y)
	table[y][c] = table[y+1][c];
      table[n-1][c] = first;
    } else if (kind == 3) {
      int y, x, v;
      scanf("%d %d %d", &y, &x, &v), --y, --x;
      pair<int, int> pos = table[y][x];
      result[pos.first][pos.second] = v;
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