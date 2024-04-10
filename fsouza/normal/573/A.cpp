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
  int n;
  scanf("%d", &n);

  int result = -1;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    while (v%2 == 0) v /= 2;
    while (v%3 == 0) v /= 3;
    if (result == -2) {
    } else if (result == -1) {
      result = v;
    } else {
      if (result != v)
	result = -2;
    }
  }

  if (result == -2) printf("No\n");
  else printf("Yes\n");

  return 0;
}