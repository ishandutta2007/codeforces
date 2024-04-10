#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, d, a, s = 0;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    s += a;
  }
  if (s + (n - 1) * 10 <= d)
    printf("%d\n", (d - s) / 5);
  else
    puts("-1");
  return 0;
}