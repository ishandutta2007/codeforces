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
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  bool ok = false;
  for (int na = 0; a*na <= c; ++na) {
    int remain = c - a*na;
    if (remain%b == 0)
      ok = true;
  }

  printf(ok ? "Yes\n" : "No\n");
  
  return 0;
}