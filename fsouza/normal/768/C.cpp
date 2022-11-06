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

const int limit = 1024;

int main() {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);

  vector<int> count(limit, 0);
  for (int i = 0; i < n; ++i) {
    int value;
    scanf("%d", &value);
    ++count[value];
  }

  vector<int> newcount(limit, 0);
  for (int rep = 0; rep < k; ++rep) {
    bool even = true;
    fill(newcount.begin(), newcount.end(), 0);
    for (int v = 0; v < limit; ++v) {
      if (even) {
        newcount[v ^ x] += (count[v] + 1) / 2;
        newcount[v] += count[v] / 2;
      } else {
        newcount[v ^ x] += count[v] / 2;
        newcount[v] += (count[v] + 1) / 2;
      }
      if (count[v] % 2 == 1)
        even = !even;
    }
    swap(count, newcount);
  }

  int min_value = limit, max_value = -1;
  for (int v = 0; v < limit; ++v)
    if (count[v] > 0) {
      min_value = min(min_value, v);
      max_value = max(max_value, v);
    }

  printf("%d %d\n", max_value, min_value);

  return 0;
}