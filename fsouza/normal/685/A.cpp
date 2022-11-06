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
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  lint n, m;
  scanf("%lld %lld", &n, &m);

  int sn = 1, sm = 1;
  lint limitn = 7, limitm = 7;

  while (limitn < n) {
    ++sn;
    limitn *= 7;
  }
  while (limitm < m) {
    ++sm;
    limitm *= 7;
  }

  int result = 0;

  vector<int> perm;
  for (int s = 0; s < (1<<7); ++s)
    if (__builtin_popcount(s) == sn + sm) {
      perm.clear();
      for (int i = 0; i < 7; ++i)
	if (s & (1<<i))
	  perm.push_back(i);
      do {
	lint v0 = 0, v1 = 0;
	for (int i = 0; i < sn; ++i)
	  v0 = 7LL * v0 + perm[i];
	for (int i = 0; i < sm; ++i)
	  v1 = 7LL * v1 + perm[sn + i];
	if (v0 < n && v1 < m)
	  ++result;
      } while (next_permutation(perm.begin(), perm.end()));
    }

  printf("%d\n", result);

  return 0;
}