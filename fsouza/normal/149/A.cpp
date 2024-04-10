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
  int need;
  scanf("%d", &need);
  int v[12];
  for (int i = 0; i < 12; i++) scanf("%d", &v[i]);
  sort(v, v+12);
  
  int ret = 0;
  for (int i = 11; i >= 0; i--)
    if (need > 0) {
      need = max(0, need - v[i]);
      ret++;
    }

  if (need > 0)
    ret = -1;

  printf("%d\n", ret);

  return 0;
}