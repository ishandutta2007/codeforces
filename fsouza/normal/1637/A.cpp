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

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    vector<int> pref_max(n + 1, INT_MIN);
    vector<int> suff_min(n + 1, INT_MAX);
    for (int i = 0; i < n; ++i)
      pref_max[i + 1] = max(pref_max[i], values[i]);
    for (int i = 0; i < n; ++i)
      suff_min[i + 1] = min(suff_min[i], values[n - 1 - i]);
    bool answer = false;
    for (int len = 1; len <= n - 1; ++len)
      if (pref_max[len] > suff_min[n - len]) {
        answer = true;
        break;
      }
    printf(answer ? "YES\n" : "NO\n");
  }
  return 0;
}