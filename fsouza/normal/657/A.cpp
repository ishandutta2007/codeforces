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
  int n, diam, height;
  scanf("%d %d %d", &n, &diam, &height);

  if (diam == 1) {
    if (n == 2 && height == 1) {
      printf("1 2\n");
      return 0;
    } else {
      printf("-1\n");
      return 0;
    }
  } else {
    if (height > diam || diam > 2*height) {
      printf("-1\n");
      return 0;
    } else {
      int left = height, right = diam - left;
      int need = 1 + left + right;
      if (n < need) {
	printf("-1\n");
	return 0;
      } else {
	for (int x = 1; x <= left; ++x)
	  printf("%d %d\n", x, x+1);
	int prev = 1;
	for (int x = left+2; x <= need; ++x) {
	  printf("%d %d\n", prev, x);
	  prev = x;
	}
	int extra = n - need;
	int from = left;
	for (int x = need+1; x <= need+extra; ++x)
	  printf("%d %d\n", from, x);
	return 0;
      }
    }
  }

  return 0;
}