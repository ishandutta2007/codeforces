#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <chrono>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#ifdef LBT

#define LOG(FMT...) fprintf(stderr, FMT)

#else

#define LOG(FMT...)

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int belongs[10];

void qry(const vector<int>& s) {
  printf("next");
  for (int v : s)
    printf(" %d", v);
  putchar('\n');
  fflush(stdout);
  int k;
  scanf("%d", &k);
  static char tmp[11];
  while (k--) {
    scanf("%s", tmp);
    for (char* p = tmp; *p; ++p)
      belongs[*p - '0'] = k;
  }
}

int main() {
  while (true) {
    qry({0, 1});
    qry({1});
    if (belongs[0] == belongs[1])
      break;
  }
  while (count(belongs, belongs + 10, 0) != 10)
    qry({0, 1, 2, 3, 4, 5, 6, 7 ,8 ,9});
  puts("done");
  return 0;
}