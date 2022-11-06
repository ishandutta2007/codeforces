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

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

const int mod = 1e9 + 7;

int inv(int a) {
  int res = modpow(a, mod - 2, mod);
  assert((lint)res * a % mod == 1);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);

  vector<vector<int>> win_prob(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      win_prob[i][j] = (lint)values[i] * inv(values[i] + values[j]) % mod;
    }
  }

  int result = 0;

  int sum = 0;

  vector<int> prob(1<<n);
  prob[0] = 0;
  for (int s = 1; s < (1<<n); ++s) {
    int size = 0;
    prob[s] = 1;
    for (int i = 0; i < n; ++i) {
      if (!(s & (1<<i)))
        continue;
      size += 1;
      for (int j = 0; j < n; ++j) {
        if (s & (1<<j))
          continue;
        prob[s] = (lint)prob[s] * win_prob[i][j] % mod;
      }
    }
    for (int s2 = (s - 1) & s; s2 > 0; s2 = (s2 - 1) & s) {
      int by = 1;

      for (int i = 0; i < n; ++i) {
        if (!(s & (1<<i)))
          continue;
        if (s2 & (1<<i))
          continue;

        for (int j = 0; j < n; ++j) {
          if (s & (1<<j))
            continue;

          by = (lint)by * win_prob[i][j] % mod;
        }
      }


      prob[s] -= (lint)prob[s2] * by % mod;
      if (prob[s] < 0) prob[s] += mod;
    }

    sum = (sum + prob[s]) % mod;

    result = (result + (lint)size * prob[s]) % mod;
  }

  printf("%d\n", result);

  return 0;
}