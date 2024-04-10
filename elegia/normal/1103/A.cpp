#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
char s[1010];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%s", s + 1);
  n = strlen(s + 1);
  int c1 = 0, c2 = 0;
  for (int i = 1; i <= n; ++i)
    if (s[i] == '0') {
      if (++c1 & 1)
        puts("1 1");
      else
        puts("3 1");
    } else {
      printf("%d 3\n", c2 % 4 + 1);
      ++c2;
    }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}