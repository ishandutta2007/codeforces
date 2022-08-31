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

char buf[10];

bool ng() {
  scanf("%s", buf);
  if (buf[0] == 'm')
    exit(0);
  return buf[0] == 's';
}

bool ask(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  scanf("%s", buf);
  if (buf[0] == 'e' || buf[0] == 'm')
    exit(0);
  return buf[0] == 'x';
}

int main() {
  while (ng()) {
    int l = 1;
    while (!ask(l - 1, (l << 1) - 1))
      l <<= 1;
    int r = (l << 1) - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (ask(l - 1, mid - 1))
        r = mid - 1;
      else
        l = mid;
    }
    printf("! %d\n", l);
    fflush(stdout);
  }
  return 0;
}