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

constexpr int mod = 998244353;

int main() {
  int n;
  scanf("%d", &n);
  struct portal_t {
    int b, a;
    bool initial;
  };
  vector<portal_t> portals(n);
  for (portal_t &p : portals) {
    scanf("%d %d", &p.b, &p.a);
    int initial;
    scanf("%d", &initial);
    p.initial = (initial == 1);
  }

  vector<int> dp(n);
  vector<int> dp_acc(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int next = lower_bound(portals.begin(), portals.end(), portals[i].a,
                           [](const portal_t &p, int pos) {
                             return p.b < pos;
                           }) - portals.begin();

    dp[i] = ((lint)portals[i].b - (lint)portals[i].a + (lint)dp_acc[i] - (lint)dp_acc[next] + 2LL * mod) % mod;
    dp_acc[i + 1] = (dp_acc[i] + dp[i]) % mod;
  }

  int result = (portals[n - 1].b + 1) % mod;
  for (int i = 0; i < n; ++i) {
    if (portals[i].initial) {
      result += dp[i];
      if (result >= mod) result -= mod;
    }
  }
  printf("%d\n", result);

  return 0;
}