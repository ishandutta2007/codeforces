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
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = 0, cnt = 0;
  for (int i = 0; i < k; ++i) {
    int m, a, last;
    scanf("%d%d", &m, &last);
    cnt++;
    int f = last, ok = 1;
    for (int j = 1; j < m; ++j) {
      scanf("%d", &a);
      if (f != 1 || !ok || last + 1 != a) {
        ++cnt;
        ++ans;
        ok = 0;
      }
      last = a;
    }
  }
  printf("%d\n", ans + cnt - 1);
  return 0;
}