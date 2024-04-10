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

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> fac;
  for (int x = 2; n != 1; ++x) {
    while (n % x == 0) {
      fac.push_back(x);
      n /= x;
    }
  }
  if (fac.size() < k) {
    puts("-1");
  } else {
    while (--k) {
      printf("%d ", fac.back());
      fac.pop_back();
    }
    int prod = 1;
    for (int v : fac)
      prod *= v;
    printf("%d\n", prod);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}