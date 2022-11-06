#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
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
  vector<int> p(n);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]), --p[i];
  vector<int> inv(n);
  for (int i = 0; i < n; ++i) inv[p[i]] = i;
  
  int result = n;
  int size = 0;
  for (int i = 0; i < n; ++i) {
    ++size;
    if (i-1 >= 0 && inv[i-1] > inv[i]) size = 1;
    result = min(result, n - size);
  }

  printf("%d\n", result);
  
  return 0;
}