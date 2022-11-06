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
    for (int &v : values)
      scanf("%d", &v);
    bool result = false;
    for (int use_mask = 1; use_mask < (1<<n); ++use_mask)
      for (int neg_mask = use_mask; neg_mask >= 0;
           neg_mask = (neg_mask == 0 ? -1 : ((neg_mask - 1) & use_mask))) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
          if (use_mask & (1<<i)) {
            if (neg_mask & (1<<i)) sum -= values[i];
            else sum += values[i];
          }
        if (sum == 0) {
          result = true;
        }
      }
    if (result) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}