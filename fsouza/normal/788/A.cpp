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
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<int> value_if_even(n - 1), value_if_odd(n - 1);
  for (int i = 0; i + 1 < n; ++i) {
    int val = abs(a[i] - a[i+1]);
    if ((i + 1) % 2 == 1) val = -val;
    value_if_even[i] = val;
    value_if_odd[i] = -val;
  }
  lint result = LLONG_MIN;
  lint best_sum_even = 0, best_sum_odd = 0;
  for (int i = n - 2; i >= 0; --i) {
    best_sum_even += value_if_even[i];
    best_sum_odd += value_if_odd[i];
    if ((i + 1) % 2 == 0) result = max(result, best_sum_even);
    else result = max(result, best_sum_odd);
    best_sum_even = max(best_sum_even, 0LL);
    best_sum_odd = max(best_sum_odd, 0LL);
  }
  printf("%lld\n", result);
  return 0;
}