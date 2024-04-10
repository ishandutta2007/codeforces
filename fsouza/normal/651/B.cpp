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
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  int result = n;
  for (int j = 0, i = j; i < n; i = j) {
    while (j < n && v[j] == v[i]) ++j;
    result = min(result, n - (j-i));
  }
  printf("%d\n", result);
  
  return 0;
}