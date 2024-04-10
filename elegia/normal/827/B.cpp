#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int main() {
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  int n, k;
  scanf("%d%d", &n, &k);
  int v = n - 1;
  int l = v / k, b = v % k, a = k - b;
  if (b == 0) {
    printf("%d\n", l * 2);
  } else if (b == 1)
    printf("%d\n", l * 2 + 1);
  else
    printf("%d\n", l * 2 + 2);
  int cnt = 1;
  while (a--) {
    // l
    printf("%d %d\n", 1, ++cnt);
    for (int rep = 1; rep < l; ++rep) {
      int cur = cnt;
      printf("%d %d\n", cur, ++cnt);
    }
  }
  while (b--) {
    // l + 1
    printf("%d %d\n", 1, ++cnt);
    for (int rep = 1; rep <= l; ++rep) {
      int cur = cnt;
      printf("%d %d\n", cur, ++cnt);
    }
  }

  return 0;
}