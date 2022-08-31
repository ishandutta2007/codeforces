#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 110;

int a[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int sum = a[1];
  vector<int> v;
  v.push_back(1);
  for (int i = 2; i <= n; ++i)
    if (a[i] * 2 <= a[1]) {
      sum += a[i];
      v.push_back(i);
    }
  int tot = accumulate(a + 1, a + n + 1, 0);
  if (sum * 2 > tot) {
    printf("%lu\n", v.size());
    for (int x : v) printf("%d ", x);
  } else
    puts("0");

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}