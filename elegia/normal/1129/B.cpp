#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  int k;
  while (scanf("%d", &k)!=EOF) {
  int a, b, x;/*
  if (k == 1) {
    a = 1;
    b = 2;
    x = 3;
  } else if (k <= 1000000 - 3) {
    a = 0;
    x = k + 3;
    b = 1;
  } else {
    while (true) {
      x = rand() | rand() << 16;
      x = x % 500000 + 500000;
      a = k / x;
      if ((a + 1) * x)
    }
  }*/
  bool flag= false;
  for (int i = 0; i < 2000; ++i) {
    for (int j = 0; i + j + 2 <= 2000; ++j) {
      int v = k + i + j + 2;
      if (v % (i + 1) == 0 && v / (i + 1) <= 1000000) {
        x = v / (i + 1);
        a = i;
        b = j;
        //LOG("%d(%d) %d %d\n", x, v, a, b);
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  // 0 -1 0 x
  // (b+1)x, (x-1)(a+b+2)
  // (a+1)x -a-b-2
  printf("%d\n", a + b + 2);
  while (a--) printf("0 ");
  printf("-1 ");
  while (b--) printf("0 ");
  printf("%d\n", x);
}

  return 0;
}