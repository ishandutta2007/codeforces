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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> table(n, string(m, ' '));
  for (string &line : table) scanf("%s", &line[0]);
  int result = 0;
  vector<vector<int>> have(n, vector<int>(m, 0));
  vector<int> lazy(m, 0);
  for (int y = n-1; y >= 0; --y)
    for (int x = m-1; x >= 0; --x) {
      have[y][x] += lazy[x];
      int want = (table[y][x] == 'W' ? +1 : -1);
      int delta = want - have[y][x];
      if (delta != 0) {
	++result;
	for (int x2 = x; x2 >= 0; --x2)
	  lazy[x2] += delta;
      }
    }
  printf("%d\n", result);

  return 0;
}