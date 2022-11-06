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
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int a, b;
    scanf("%d %d", &a, &b);
    lint mult = (lint)a * b;
    lint multk = pow(1.0 * mult, 1.0 / 3);
    while (multk * multk * multk < mult) ++multk;
    while (multk * multk * multk > mult) --multk;
    bool result;
    if (multk * multk * multk != mult) result = false;
    else {
      result = a % multk == 0 && b % multk == 0;
    }
    if (result) printf("Yes\n");
    else printf("No\n");
  }

  return 0;
}