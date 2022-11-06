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

vector<int> fact, invfact;

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y%2 == 1) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p-2, p); }

int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (lint)fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}

int solve(const vector<int> &manyexp) {
  const int s = manyexp.size();
  int result = 0;
  
  for (int i = 0; i+1 < s; ++i) {
    int maxl = accumulate(manyexp.begin(), manyexp.begin()+i+1, 0);
    int maxr = accumulate(manyexp.begin()+i+1, manyexp.end(), 0);
    int lim = min(maxl, maxr);
    
    int totmanyl = modpow(2, maxl, mod);
    int totmanyr = modpow(2, maxr, mod);
    
    vector<int> manyuptol(lim+1);
    for (int l = 0; l <= lim; ++l) {
      manyuptol[l] = binom(maxl, l);
      if (l-1 >= 0) manyuptol[l] = (manyuptol[l] + manyuptol[l-1]) % mod;
    }
    vector<int> manyuptor(lim+1);
    for (int r = 0; r <= lim; ++r) {
      manyuptor[r] = binom(maxr, r);
      if (r-1 >= 0) manyuptor[r] = (manyuptor[r] + manyuptor[r-1]) % mod;
    }

    for (int l = 0; l <= lim; ++l) {
      int manyl = (manyuptol[l] - (l-1 >= 0 ? manyuptol[l-1] : 0) + mod) % mod;
      int manyr = (totmanyr - (l-1 >= 0 ? manyuptor[l-1] : 0) + mod) % mod;
      result = (result + (lint)manyl * manyr % mod * l) % mod;
    }
    for (int r = 0; r <= lim; ++r) {
      int manyr = (manyuptor[r] - (r-1 >= 0 ? manyuptor[r-1] : 0) + mod) % mod;
      int manyl = (totmanyl - manyuptol[r] + mod) % mod;
      result = (result + (lint)manyr * manyl % mod * r) % mod;
    }
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);

  fact.resize(n+1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = (lint)i * fact[i-1] % mod;
  invfact.resize(n+1);
  invfact[n] = inv(fact[n], mod);
  for (int i = n-1; i >= 0; --i) invfact[i] = (lint)(i+1) * invfact[i+1] % mod;

  vector<int> values(n);
  for (int &v : values) scanf("%d", &v);
  const int maxv = *max_element(values.begin(), values.end());

  vector<int> div(maxv+1);
  for (int v = 2; v <= maxv; ++v)
    if (div[v] == 0)
      for (int u = v; u <= maxv; u += v)
	div[u] = v;

  vector<vector<int>> pmanyexp(maxv+1);

  for (int v : values) {
    while (v != 1) {
      int p = div[v], exp = 0;
      do {
	v /= p;
	++exp;
      } while (v%p == 0);
      if ((int)pmanyexp[p].size() <= exp)
	pmanyexp[p].resize(exp+1);
      ++pmanyexp[p][exp];
    }
  }
  
  int result = 0;
  for (int p = 2; p <= maxv; ++p)
    if (div[p] == p && !pmanyexp[p].empty()) {
      pmanyexp[p][0] = n - accumulate(pmanyexp[p].begin()+1, pmanyexp[p].end(), 0);
      result = (result + solve(pmanyexp[p])) % mod;
    }

  printf("%d\n", result);
  
  return 0;
}