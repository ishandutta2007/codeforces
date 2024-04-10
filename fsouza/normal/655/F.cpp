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

const int mod = 1e9+7;

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p-2, p); }

int main() {
  int n, k, nq;
  scanf("%d %d %d", &n, &k, &nq);

  vector<int> fact(n+nq+1), invfact(n+nq+1);
  fact[0] = 1;
  for (int v = 1; v <= n+nq; ++v) fact[v] = (lint)v * fact[v-1] % mod;
  invfact[n+nq] = inv(fact[n+nq], mod);
  for (int v = n+nq-1; v >= 0; --v) invfact[v] = (lint)invfact[v+1] * (v+1) % mod;

  auto binom = [&fact, &invfact](int a, int b) -> int {
    if (0 <= b && b <= a) return (lint)fact[a] * invfact[b] % mod * invfact[a-b] % mod;
    return 0;
  };
  
  vector<int> values(n);
  for (int i = 0; i < n; ++i) scanf("%d", &values[i]);

  const int maxv = 1e6;

  vector<vector<int>> divsof(maxv+1);
  for (int v = 1; v <= maxv; ++v)
    for (int x = v; x <= maxv; x += v)
      divsof[x].push_back(v);
  for (int v = 1; v <= maxv; ++v)
    reverse(divsof[v].begin(), divsof[v].end());
  
  vector<int> manyhave(maxv+1, 0), manysol(maxv+1, 0);
  int result = 0;
  
  for (int i = 0; i < n; ++i) {
    int v = values[i];
    for (int d = 1; d*d <= v; ++d)
      if (v%d == 0) {
	++manyhave[d];
	if (d*d < v) ++manyhave[v/d];
      }
  }

  vector<lint> delta(maxv+1, 0);

  for (int g = maxv; g >= 1; --g) {
    manysol[g] = binom(manyhave[g], k);
    for (int g2 = 2*g; g2 <= maxv; g2 += g)
      delta[g] += manysol[g2];
    manysol[g] = (manysol[g] - delta[g] % mod + mod) % mod;

    result = (result + (lint)g * manysol[g]) % mod;
  }

  vector<int> divbig, divsmall;
  for (int q = 0; q < nq; ++q) {
    int newv;
    scanf("%d", &newv);

    for (int d : divsof[newv]) {
      int oldvalue = manysol[d];
      
      result = (result - (lint)manysol[d] * d % mod + mod) % mod;
      manysol[d] = 0;

      ++manyhave[d];
      manysol[d] = (binom(manyhave[d], k) - delta[d] % mod + mod) % mod;
      result = (result + (lint)manysol[d] * d) % mod;

      for (int x : divsof[d]) delta[x] += manysol[d] - oldvalue;
      delta[d] -= manysol[d] - oldvalue;
    }
    
    printf("%d\n", result);
  }
  
  return 0;
}