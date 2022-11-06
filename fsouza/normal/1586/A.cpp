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

bool is_prime(int v) {
  if (v <= 1)
    return false;
  for (int x = 2; x * x <= v; ++x)
    if (v % x == 0)
      return false;
  return true;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    int sum = accumulate(values.begin(), values.end(), 0);
    vector<int> result;
    if (!is_prime(sum)) {
      result.resize(n);
      iota(result.begin(), result.end(), 0);
    } else {
      for (int i = 0; i < n; ++i)
        if (!is_prime(sum - values[i])) {
          result.resize(n);
          iota(result.begin(), result.end(), 0);
          result.erase(result.begin() + i);
          break;
        }
    }
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); ++i) {
      if (i > 0) printf(" ");
      printf("%d", result[i] + 1);
    }
    printf("\n");
  }
  return 0;
}