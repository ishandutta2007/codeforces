#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n, k;
  scanf("%d %d", &n, &k), --k;

  int result = 0, val = n*n;
  vector<vector<int>> table(n, vector<int>(n));
  for (int y = n-1; y >= 0; --y) {
    for (int x = n-1; x >= k; --x)
      table[y][x] = val--;
    result += table[y][k];
  }
  for (int y = n-1; y >= 0; --y)
    for (int x = k-1; x >= 0; --x)
      table[y][x] = val--;
  printf("%d\n", result);
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (x > 0) printf(" ");
      printf("%d", table[y][x]);
    }
    printf("\n");
  }
  
  return 0;
}