#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int x1, y1;
  int x2, y2;
  
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

  int result = 0;

  int n;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    lint v0 = (lint)a * x1 + (lint)b * y1 + c;
    lint v1 = (lint)a * x2 + (lint)b * y2 + c;

    int w = v0 > 0;
    int z = v1 > 0;

    result += (w != z);
  }

  printf("%d\n", result);

  return 0;
}