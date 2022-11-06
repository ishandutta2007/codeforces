#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n, a, b, c;

  scanf("%d %d %d %d", &n, &a, &b, &c);

  int ret = 0;

  for (int na = 0; na*a <= n; na++)
    for (int nb = 0; na*a + nb*b <= n; nb++) {
      int rest = n - na*a - nb*b;
      if (rest%c == 0) {
	int nc = rest/c;
	ret = max(ret, na + nb + nc);
      }
    }

  printf("%d\n", ret);

  return 0;
}