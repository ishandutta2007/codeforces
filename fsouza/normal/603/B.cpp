#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

const int mod = 1e9+7;

int modpow(int x, int y, int mod) {
  int result = 1 % mod, x2p = x;
  while (y > 0) {
    if (y%2) result = (lint)result * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return result;
}

int main() {
  int p, k;
  scanf("%d %d", &p, &k);

  int result;
  if (k == 0) result = modpow(p, p-1, mod);
  else if (k == 1) result = modpow(p, p, mod);
  else {
    int ngroup = 1;
    for (int v = (lint)k * k % p; v != k; v = (lint)v * k % p)
      ++ngroup;
    assert((p-1) % ngroup == 0);
    int groupsize = (p-1) / ngroup;
    result = modpow(p, groupsize, mod);
  }

  printf("%d\n", result);
  
  return 0;
}