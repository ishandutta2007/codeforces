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
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  bool result;

  if (c == 0) result = a == b;
  else result = (b-a)%c == 0 && (b-a)/c >= 0;

  printf(result ? "YES\n" : "NO\n");

  return 0;
}