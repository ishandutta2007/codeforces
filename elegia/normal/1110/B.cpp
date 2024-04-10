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

int n, m, k;
int b[N], a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &k);
  int ans = n;
  k = n - k;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &b[i]);
  for (int i = 1; i < n; ++i)
    a[i] = b[i + 1] - b[i] - 1;
  nth_element(a + 1, a + k, a + n);
  ans += accumulate(a + 1, a + k + 1, 0);
  printf("%d\n", ans);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}