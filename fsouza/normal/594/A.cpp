#include <algorithm>
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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  for (int &v : values) scanf("%d", &v);
  sort(values.begin(), values.end());

  const int dist = n/2;

  int result = INT_MAX;
  for (int i = 0; i+dist < n; ++i)
    result = min(result, values[i+dist] - values[i]);

  printf("%d\n", result);

  return 0;
}