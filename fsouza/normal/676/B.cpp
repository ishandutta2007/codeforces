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
  int n, much;
  scanf("%d %d", &n, &much);

  vector<vector<int>> vals(n);
  for (int i = 0; i < n; ++i) vals[i] = vector<int>(i+1, 0.0);

  int result = 0;
  vals[0][0] = much<<n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (vals[i][j] >= (1<<n)) {
	int extra = vals[i][j] - (1<<n);
	vals[i][j] = 1<<n;
	++result;
	if (i+1 < n) {
	  vals[i+1][j] += extra/2;
	  vals[i+1][j+1] += extra/2;
	}
      }
    }
  }

  printf("%d\n", result);

  return 0;
}