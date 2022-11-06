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
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  map<lint, lint> placecost;

  int nq;
  scanf("%d", &nq);
  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      lint v, u;
      int extra;
      scanf("%lld %lld %d", &v, &u, &extra);
      while (v != u)
	if (v > u) placecost[v] += extra, v /= 2;
	else placecost[u] += extra, u /= 2;
    } else {
      lint v, u;
      scanf("%lld %lld", &v, &u);
      lint result = 0;
      while (v != u)
	if (v > u) result += placecost[v], v /= 2;
	else result += placecost[u], u /= 2;
      printf("%lld\n", result);
    }
  }

  return 0;
}