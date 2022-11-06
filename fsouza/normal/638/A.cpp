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
  int n, a;
  scanf("%d %d", &n, &a);
  int ret;
  if (a%2 == 1) ret = (a-1)/2 + 1;
  else ret = (n-a)/2 + 1;
  printf("%d\n", ret);
  return 0;
}