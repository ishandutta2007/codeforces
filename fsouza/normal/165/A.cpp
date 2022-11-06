#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> x(n), y(n);

  for (int i = 0; i < n; i++)
    scanf("%d %d", &x[i], &y[i]);

  int ret = 0;

  for (int i = 0; i < n; i++) {
    bool ok[4] = {false,false,false,false};
    for (int j = 0; j < n; j++)
      if (i != j) {
	if (x[j] == x[i]) {
	  if (y[j] < y[i]) ok[0] = true;
	  else ok[1] = true;
	} else if (y[j] == y[i]) {
	  if (x[j] < x[i]) ok[2] = true;
	  else ok[3] = true;
	}
      }

    if (ok[0] && ok[1] && ok[2] && ok[3])
      ret++;
  }

  printf("%d\n", ret);

  return 0;
}