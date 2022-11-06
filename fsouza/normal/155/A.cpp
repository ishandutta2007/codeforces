#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);

  int mi, ma;
  scanf("%d", &mi);
  ma = mi;

  int ret = 0;

  for (int i = 1; i < n; i++) {
    int v;
    scanf("%d", &v);
    if (v < mi) {
      mi = v;
      ret++;
    }
    if (v > ma) {
      ma = v;
      ret++;
    }
  }
  
  printf("%d\n", ret);

  return 0;
}