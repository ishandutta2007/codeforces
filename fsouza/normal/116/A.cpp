#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n;
  
  scanf("%d", &n);

  int ret = 0;
  int now = 0;

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    now -= a;
    now += b;
    ret = max(ret, now);
  }

  printf("%d\n", ret);

  return 0;
}