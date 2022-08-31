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

map<int , int> mp;

int gcd(int a , int b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int q;
  scanf("%d", &q);
  while (q--) {
    int a;
    scanf("%d", &a);
    if (mp[a]) {
      printf("%d\n", mp[a]);
      continue;
    }
    if (!(a & (a + 1))) {
      for (int x = a - 1; x; --x)
        if (a % x == 0 && x != a) {
          printf("%d\n", mp[a] = x);
          break;
        }
    } else {
      int l = 27;
      while (!(a >> l & 1))
        --l;
      printf("%d\n", (1 << (l + 1)) - 1);
    }
  }

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}