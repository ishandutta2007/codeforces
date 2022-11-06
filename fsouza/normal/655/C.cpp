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
  int n, k;
  scanf("%d %d", &n, &k);
  string busy(n, ' ');
  scanf("%s", &busy[0]);

  int result = INT_MAX;

  set<int> active;
  set<int>::iterator mid = active.end();
  
  for (int i = 0; i < n; ++i)
    if (busy[i] == '0') {
      active.insert(i);
      if (active.size() == 1) mid = active.begin();
      
      if ((int)active.size() > k+1) {
	if (mid == active.begin()) ++mid;
	active.erase(active.begin());
      }

      if ((int)active.size() == k+1) {
	int first = *active.begin(), last = *active.rbegin();
	while (*mid != last) {
	  auto next = mid; ++next;
	  if (max(*next - first, last - *next) <=
	      max(*mid - first, last - *mid))
	    mid = next;
	  else
	    break;
	}
	result = min(result, max(*mid - first, last - *mid));
      }
    }

  printf("%d\n", result);
  
  return 0;
}