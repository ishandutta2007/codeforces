#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

typedef long long lint;

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  int ret = 0;

  for (int a = 0; a*a <= n; a++) {
    int b = n - a*a;
    if (a + b*b == m)
      ret++;
  }

  printf("%d\n", ret);
  
  return 0;
}