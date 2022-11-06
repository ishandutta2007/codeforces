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
  vector<int> perm(n);
  for (int &v : perm)
    scanf("%d", &v), --v;

  for (int i = 0; i < n; ++i)
    if (perm[i] == i) {
      printf("YES\n");
      for (int j = 0; j < n; ++j)
	if (j != i)
	  printf("%d %d\n", j+1, i+1);
      return 0;
    }

  vector<bool> mark(n, false);
  vector<vector<int>> cycles;

  for (int i = 0; i < n; ++i)
    if (!mark[i]) {
      vector<int> cycle;
      int j = i;
      do {
	cycle.push_back(j);
	mark[j] = true;
	j = perm[j];
      } while (j != i);
      cycles.push_back(move(cycle));
    }

  for (vector<int> &mid : cycles)
    if (mid.size() == 2) {
      int a = mid[0], b = mid[1];
      bool ok = true;
      for (vector<int> &cycle : cycles)
	if (cycle.size()%2 == 1) {
	  ok = false;
	  break;
	}
      if (!ok) break;

      printf("YES\n");
      printf("%d %d\n", a+1, b+1);
      for (vector<int> &cycle : cycles)
	if (cycle != mid) {
	  for (int i = 0; i < (int)cycle.size(); ++i)
	    if (i%2 == 0) printf("%d %d\n", a+1, cycle[i]+1);
	    else printf("%d %d\n", b+1, cycle[i]+1);
	}
      return 0;
    }

  printf("NO\n");

  return 0;
}