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
  int n;
  scanf("%d", &n);
  int ceilsqn = (int)ceil(sqrt((double)n));
  int ncol = ceilsqn, nrow = (n + ncol - 1) / ncol;
  vector<vector<int>> table(nrow, vector<int>(ncol, -1));
  int cur = 0;
  for (int x = 0; x < ncol; ++x)
    for (int y = nrow - 1; y >= 0; --y)
      if (y * ncol + x < n)
        table[y][x] = cur++;
  vector<int> result;
  for (int y = 0; y < nrow; ++y)
    for (int x = 0; x < ncol; ++x)
      if (table[y][x] != -1)
        result.push_back(table[y][x]);
  assert((int)result.size() == n);
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i] + 1);
  }
  printf("\n");
  return 0;
}