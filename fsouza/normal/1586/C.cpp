#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<string> grid(n, string(m, ' '));
  for (int y = 0; y < n; ++y)
    for (int x = 0; x < m; ++x)
      scanf(" %c", &grid[y][x]);

  vector<int> next_pair(m, m);
  for (int y = 0; y+1 < n; ++y)
    for (int x = 0; x+1 < m; ++x)
      if (grid[y + 1][x] == 'X' && grid[y][x + 1] == 'X')
        next_pair[x] = x;
  for (int x = m - 2; x >= 0; --x)
    next_pair[x] = min(next_pair[x], next_pair[x + 1]);

  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    if (b >= next_pair[a] + 1) printf("NO\n");
    else printf("YES\n");
  }

  return 0;
}