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

const int nmod = 2;
const lint mods[12] = {3029999933, 3029999333, 3029999033, 3029998133, 3029997433, 3029995433, 3029992633, 3029992333, 3029989327, 2000000531, 2000000533, 2000000641};

lint modpow(lint x, lint y, lint mod) {
  lint res = 1 % mod, x2p = x % mod;
  while (y > 0) {
    if (y%2) res = res * x2p % mod;
    y /= 2;
    x2p = x2p * x2p % mod;
  }
  return res;
}

lint invp(lint x, lint p) { return modpow(x, p-2, p); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  lint k;
  cin >> n >> k; ++n;
  vector<lint> values(n);
  for (lint &v : values) cin >> v;
  vector<int> ans(n, INT_MIN);

  for (int j = 0; j < nmod; ++j) {
    lint mod = mods[j];

    lint have = 0;
    for (int i = n-1; i >= 0; --i) {
      have = (have + have) % mod;
      have = (have + values[i] % mod + mod) % mod;
    }

    lint multby = 1;
    for (int i = 0; i < n; ++i) {
      lint without = (have - multby * values[i] % mod + mod) % mod;
      lint need = (mod - without) % mod;
      lint X = need * invp(multby, mod) % mod;

      if (i == n-1 && X == 0) {
      } else {
	int r;
	if (0 <= X && X <= k) r = X;
	else if (mod-k <= X && X < mod) r = X-mod;
	else r = INT_MAX;

	if (r == INT_MAX || ans[i] == INT_MAX || (ans[i] != INT_MIN && ans[i] != r)) ans[i] = INT_MAX;
	else ans[i] = r;
      }

      multby = (multby + multby) % mod;
    }
  }

  lint result = 0;
  for (int i = 0; i < n; ++i)
    if (ans[i] != INT_MIN && ans[i] != INT_MAX)
      ++result;

  cout << result << endl;

  return 0;
}