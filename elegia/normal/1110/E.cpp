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

const int N = 100010;

int n;
ll a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &b[i]);
  for (int i = n; i > 1; --i)
    a[i] -= a[i - 1];
  for (int i = n; i > 1; --i)
    b[i] -= b[i - 1];
  sort(a + 2, a + n + 1);
  sort(b + 2, b + n + 1);
  puts((a[1] == b[1] && equal(a + 2, a + n + 1, b + 2, b + n + 1)) ? "Yes" : "No");

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}