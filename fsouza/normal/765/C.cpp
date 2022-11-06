#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int k, a, b;
  scanf("%d %d %d", &k, &a, &b);
  int na = a / k, nb = b / k;
  if (a <= (lint)na * k + (lint)nb * (k - 1) &&
      b <= (lint)nb * k + (lint)na * (k - 1)) {
    printf("%d\n", na + nb);
  } else {
    printf("-1\n");
  }
  return 0;
}