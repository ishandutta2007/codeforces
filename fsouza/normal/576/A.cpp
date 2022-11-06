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
  int n;
  scanf("%d", &n);
  vector<int> div(n+1, -1);
  for (int v = 2; v <= n; ++v)
    if (div[v] == -1)
      for (int u = v; u <= n; u += v)
	div[u] = v;

  vector<int> result;
  for (int v = 2; v <= n; ++v)
    if (div[v] == v)
      for (int u = v; u <= n; u *= v)
	result.push_back(u);

  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}