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
  lint k;
  scanf("%d %lld", &n, &k), --k;

  vector<lint> values(n, 0LL);
  for (int i = 1; i < n; ++i) {
    int p;
    lint delta;
    scanf("%d %lld", &p, &delta), --p;
    values[i] = (values[p] ^ delta);
  }
  sort(values.begin(), values.end());

  vector<lint> masked = values;
  vector<lint> new_masked = masked;

  auto flip_bit = [&](int bit) {
    for (int j = 0, i = j; i < n; i = j) {
      while (j < n && (masked[j] >> (bit + 1)) == (masked[i] >> (bit + 1))) ++j;
      int mid = i;
      while (mid < n && (masked[mid] >> bit) == (masked[i] >> bit)) ++mid;
      // i, mid, j;
      int len0 = mid - i;
      int len1 = j - mid;
      copy(masked.begin() + i, masked.begin() + mid,
           new_masked.begin() + i + len1);
      copy(masked.begin() + mid, masked.begin() + j,
           new_masked.begin() + i);
      for (int k2 = i; k2 < j; ++k2)
        new_masked[k2] ^= (1LL<<bit);
    }
    swap(masked, new_masked);
  };

  auto count_for_bit = [&](int bit) {
    lint result = 0LL;
    int lb = 0, ub = 0;
    for (int i = 0; i < n; ++i) {
      while (lb < n && ((masked[lb] >> bit) < (values[i] >> bit))) ++lb;
      while (ub < n && ((masked[ub] >> bit) <= (values[i] >> bit))) ++ub;
      result += ub - lb;
    }
    return result;
  };

  lint result = 0LL;
  for (int bit = 61; bit >= 0; --bit) {
    lint many = count_for_bit(bit);
    if (k >= many) {
      k -= many;
      result |= (1LL<<bit);
      flip_bit(bit);
    }
  }
  printf("%lld\n", result);

  return 0;
}