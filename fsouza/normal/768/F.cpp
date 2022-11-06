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

const int mod = 1e9 + 7;

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int inv(int a, int prime) {
  return modpow(a, prime - 2, prime);
}

vector<int> fact, invfact;

int binom(int a, int b) {
  if (b < 0 || b > a) return 0;
  return (lint)fact[a] * invfact[b] % mod * invfact[a - b] % mod;
}

int get_nway_distribute(int many, int npile) {
  if (many == 0)
    return npile == 0;
  many -= npile;
  return binom(many + npile - 1, npile - 1);
}

int main() {
  int na, nb, good_height;
  scanf("%d %d %d", &nb, &na, &good_height);

  const int fact_limit = max(na, nb) - 1;
  fact.resize(fact_limit + 1);
  invfact.resize(fact_limit + 1);
  fact[0] = 1;
  for (int v = 1; v <= fact_limit; ++v)
    fact[v] = (lint)fact[v-1] * v % mod;
  invfact[fact_limit] = inv(fact[fact_limit], mod);
  for (int v = fact_limit - 1; v >= 0; --v)
    invfact[v] = (lint)invfact[v+1] * (v+1) % mod;

  vector<int> distr_a(na + 1);
  for (int npile = 0; npile <= na; ++npile)
    distr_a[npile] = get_nway_distribute(na, npile);
  vector<int> distr_b(nb + 1);
  for (int npile = 0; npile <= nb; ++npile)
    distr_b[npile] = get_nway_distribute(nb, npile);

  vector<int> distr_a_good(na + 1, 0);
  for (int npile = 0; npile <= na && npile * good_height <= na; ++npile)
    distr_a_good[npile] = get_nway_distribute(na - npile * good_height, npile);

  lint nvalid_distr = 0, ngood_distr = 0;

  for (int npilea = 0; npilea <= na; ++npilea)
    for (int npileb = max(0, npilea - 1);
         npileb <= min(npilea + 1, nb);
         ++npileb) {
      int valid_count = (lint)distr_a[npilea] * distr_b[npileb] % mod;
      if (npilea == npileb) valid_count = 2 * valid_count % mod;
      int good_count = (lint)distr_a_good[npilea] * distr_b[npileb] % mod;
      if (npilea == npileb) good_count = 2 * good_count % mod;
      nvalid_distr += valid_count;
      ngood_distr += good_count;
    }

  nvalid_distr %= mod, ngood_distr %= mod;

  int result = (lint)ngood_distr * inv(nvalid_distr, mod) % mod;
  printf("%d\n", result);

  return 0;
}