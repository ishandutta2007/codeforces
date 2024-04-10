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

const int maxv = 1e7;
const int mod = 1e9+7;

using namespace std;

typedef long long lint;

int pow2[maxv+1];
int divp[maxv+1] = {};
int many[maxv+1] = {};
int nmul[maxv+1] = {};
int withg[maxv+1] = {};
int primemult[maxv+1+10];

int main() {
  pow2[0] = 1;
  for (int i = 1; i <= maxv; ++i) {
    pow2[i] = 2 * pow2[i-1];
    if (pow2[i] >= mod) pow2[i] -= mod;
  }

  for (int v = 2; v <= maxv; ++v)
    if (divp[v] == 0)
      for (int u = v; u <= maxv; u += v)
	divp[u] = v;

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    ++many[v];
  }

  for (int v = 1; v <= maxv; ++v) {
    nmul[v] = 0;
    for (int u = v; u <= maxv; u += v)
      nmul[v] += many[u];
  }

  for (int g = maxv; g >= 1; --g) {
    lint res = pow2[nmul[g]] - 1;
    for (int u = 2*g; u <= maxv; u += g)
      res -= withg[u];
    res %= mod;
    if (res < 0) res += mod;
    withg[g] = res;
  }

  int result = 0;

  vector<int> primes;
  for (int g = 2; g <= maxv; ++g) {
    primes.clear();
    {
      int val = g;
      while (val != 1) {
	int p = divp[val];
	primes.push_back(p);
	while (divp[val] == p) val /= p;
      }
    }
    int np = primes.size();

    primemult[0] = 1;
    for (int i = 0; i < np; ++i)
      primemult[1<<i] = primes[i];

    lint res = 0;
    for (int s = 0; s < 1<<np; ++s) {
      int nbit = __builtin_popcount(s);
      if (nbit >= 2) {
	primemult[s] = primemult[s&-s] * primemult[s ^ (s&-s)];
      }

      int val = primemult[s];
      if ((nbit&1) == 0) {
	res += nmul[val];
	//	if (res >= mod) res -= mod;
      } else {
	res -= nmul[val];
	//	if (res < 0) res += mod;
      }
    }
    res %= mod;
    if (res < 0) res += mod;

    result = (result + (lint)res * withg[g]) % mod;
  }

  printf("%d\n", result);

  return 0;
}