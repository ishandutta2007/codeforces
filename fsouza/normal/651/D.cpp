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

int solve(string &kind, int slide, int hcost, int wcost, int maxt) {
  int n = kind.size();
  int result = 0;
  {
    int res = 0, i = 0, takes = 0;
    do {
      if (i != 0) takes += slide;
      takes += kind[i] == 'h' ? hcost : wcost;
      ++res;
      if (takes <= maxt) result = max(result, res);
      i = (i+1)%n;
    } while (i != 0);
  }
  {
    int res = 0, i = 0, j = n-1, takes = 0;
    do {
      if (i != 0) takes += 2*slide;
      takes += kind[i] == 'h' ? hcost : wcost;
      ++res;

      while (j != i && takes + slide + (kind[j] == 'h' ? hcost : wcost) <= maxt) {
	takes += slide + (kind[j] == 'h' ? hcost : wcost);
	++res;
	j = (j-1+n)%n;
      }
      while (j != n-1 && takes > maxt) {
	j = (j+1)%n;
	--res;
	takes -= slide + (kind[j] == 'h' ? hcost : wcost);
      }
      if (takes <= maxt) result = max(result, res);

      if (i == j && (i+1)%n != 0) {
	j = (j+1)%n;
	--res;
	takes -= slide + (kind[j] == 'h' ? hcost : wcost);
      }
      i = (i+1)%n;
    } while (i != 0);
  }
  return result;
}

int main() {
  int n, slide, rot, maxt;
  scanf("%d %d %d %d", &n, &slide, &rot, &maxt);
  string kind(n, ' ');
  scanf("%s", &kind[0]);

  int result = 0;
  for (int rev = 0; rev < 2; ++rev) {
    result = max(result, solve(kind, slide, 1, 1+rot, maxt));
    reverse(kind.begin(), kind.end());
    rotate(kind.begin(), kind.end()-1, kind.end());
  }

  printf("%d\n", result);

  return 0;
}