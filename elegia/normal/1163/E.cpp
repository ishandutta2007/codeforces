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

const int N = 200010;

vector<int> a[20];
int b[20], sv[20];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    int lead = 19;
    while (!(x >> lead & 1)) --lead;
    a[lead].push_back(x);
  }
  int cur = 0;
  for (int i = 0; i < 20; ++i) {
    for (int v : a[i]) {
      int x = v;
      for (int j = i; j >= 0; --j)
        if (x >> j & 1) {
          if (!b[j]) {
            b[j] = x;
            sv[j] = v;
            break;
          } else
            x ^= b[j];
        }
    }
    if (!count(sv, sv + i + 1, 0))
      cur = i + 1;
  }
  printf("%d\n", cur);
  vector<int> ans(1, 0);
  for (int i = 0; i < cur; ++i) {
    for (int j = (1 << i) - 1; j >= 0; --j)
      ans.push_back(sv[i] ^ ans[j]);
  }
  for (int v : ans) printf("%d ", v);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}