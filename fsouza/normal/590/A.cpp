#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
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
  vector<int> v(n), res(n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

  int takes = 0;
  for (int j = 0, i = j; i < n; i = j = j+1) {
    while (j+1 < n && v[j+1] != v[j]) ++j;
    int size = j-i+1;
    
    if (size%2 == 1) {
      assert(v[i] == v[j]);
      for (int k = i; k <= j; ++k) res[k] = v[i];
      takes = max(takes, (size-1)/2);
    } else {
      assert(v[i] != v[j]);
      for (int k = i; k < i+size/2; ++k) res[k] = v[i];
      for (int k = i+size/2; k <= j; ++k) res[k] = v[j];
      takes = max(takes, size/2 - 1);
    }
  }

  printf("%d\n", takes);
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", res[i]);
  }
  printf("\n");
  
  return 0;
}