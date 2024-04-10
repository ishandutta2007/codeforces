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
  int n, d, h;
  scanf("%d%d%d", &n, &d, &h);
  if (d < h || d > 2 * h) {
    puts("-1");
    return 0;
  }

  if (d == 1) {
    if (h == 1 && n == 2) {
      puts("1 2");
    } else {
      puts("-1");
    }
    return 0;
  }

  for (int i = 1; i <= h; ++i) {
    printf("%d %d\n", i, i + 1);
  }
  for (int i = h + 1; i <= d; ++i) {
    if (i == h + 1) printf("%d %d\n", 1, i + 1);
    else printf("%d %d\n", i, i + 1);
  }

  for (int i = d + 2; i <= n; ++i)
    printf("%d %d\n", (d == h ? 2 : 1), i);

  return 0;
}