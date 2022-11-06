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

const int mod = 998244353;

struct dp_t {
  int res0, res1;
};

dp_t solve(int v, const vector<vector<int>> &children) {
  int nc = children[v].size();
  if (nc == 0) {
    return {1, 1};
  } else {
    vector<dp_t> ress;
    for (int c : children[v])
      ress.push_back(solve(c, children));

    int all_zero = 1;
    for (const dp_t &res : ress) {
      all_zero = (lint)all_zero * res.res0 % mod;
    }

    int all_either = 1;
    for (const dp_t &res : ress) {
      all_either = (lint)all_either * (res.res0 + res.res1) % mod;
    }

    int all_at_least_1 = all_either - all_zero;
    if (all_at_least_1 < 0) all_at_least_1 += mod;

    vector<int> pref_0(nc + 1, 1);
    for (int i = 0; i < nc; ++i)
      pref_0[i + 1] = (lint)pref_0[i] * ress[i].res0 % mod;
    vector<int> suff_0(nc + 1, 1);
    for (int i = 0; i < nc; ++i)
      suff_0[i + 1] = (lint)suff_0[i] * ress[nc - 1 - i].res0 % mod;

    int exactly_one = 0;
    for (int i = 0; i < nc; ++i)
      exactly_one = (exactly_one + (lint)pref_0[i] * ress[i].res1 % mod * suff_0[nc - i - 1]) % mod;

    int at_least_2 = all_at_least_1 - exactly_one;
    if (at_least_2 < 0) at_least_2 += mod;

    dp_t res_v;
    res_v.res0 = all_zero + at_least_2;
    if (res_v.res0 >= mod) res_v.res0 -= mod;
    res_v.res1 = all_at_least_1;
    return res_v;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> children(n);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p), --p;
    children[p].push_back(i);
  }
  dp_t result = solve(0, children);
  printf("%d\n", result.res0);
  return 0;
}