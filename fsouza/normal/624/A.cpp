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
  int d, L, v1, v2;
  scanf("%d %d %d %d", &d, &L, &v1, &v2);

  double ret = (double)(L-d) / (v1+v2);
  printf("%.9f\n", ret);
  
  return 0;
}