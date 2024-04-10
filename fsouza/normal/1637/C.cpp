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
    lint result = 0LL;
    bool any_good = false;
    for (int i = 1; i < n - 1; ++i) {
      if (values[i] >= 2) any_good = true;
      result += values[i];
      if (values[i] % 2 == 1) result += 1;
    }
    if (any_good && !(n == 3 && values[1]%2 == 1)) result /= 2LL;
    else result = -1;
    printf("%lld\n", result);
  }
  return 0;
}