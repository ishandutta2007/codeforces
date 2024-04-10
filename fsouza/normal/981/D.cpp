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

const int maxn = 50, maxng = 50;

bool dp[maxn + 1][maxng + 1];
lint acc[maxn + 1];

bool possible(const vector<lint> &values, int ng, lint want) {
  const int n = values.size();
  memset(dp, 0, sizeof(dp));
  dp[n][0] = true;
  for (int i = n - 1; i >= 0; --i) {
    dp[i][0] = false;
    for (int g = 1; g <= ng; ++g) {
      for (int j = i; j < n; ++j)
        if (dp[j + 1][g - 1] && ((acc[j + 1] - acc[i]) & want) == want) {
          dp[i][g] = true;
          break;
        }
    }
  }
  return dp[0][ng];
}

int main() {
  int n, ng;
  scanf("%d %d", &n, &ng);
  vector<lint> values(n);
  acc[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &values[i]);
    acc[i + 1] = acc[i] + values[i];
  }
  lint result = 0LL;
  for (int l = 60; l >= 0; --l)
    if (possible(values, ng, result | (1LL<<l)))
      result |= 1LL<<l;
  printf("%lld\n", result);
  return 0;
}