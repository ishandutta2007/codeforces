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
  vector<int> sums(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &sums[i]);
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    values[i] = sums[i];
    if (i - 1 >= 0) values[i] -= sums[i - 1];
  }
  vector<int> result;

  vector<int> orig;
  for (int k = 1; k <= n; ++k) {
    orig.assign(k, INT_MAX);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (orig[i % k] != INT_MAX && orig[i % k] != values[i]) {
        ok = false;
        break;
      }
      orig[i % k] = values[i];
    }
    if (ok)
      result.push_back(k);
  }
  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");
  return 0;
}