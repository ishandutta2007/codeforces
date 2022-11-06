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
  set<int> values;
  for (int i = 0; i < n; ++i) {
    int v;
    scanf("%d", &v);
    values.insert(v);
  }
  bool result = false;
  for (int v = 1; v+2 <= 1000; ++v)
    if (values.count(v) > 0 && values.count(v+1) > 0 && values.count(v+2) > 0) {
      result = true;
      break;
    }

  printf(result ? "YES\n" : "NO\n");
  
  return 0;
}