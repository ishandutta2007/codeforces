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

int n, m;
int a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i)
    scanf("%d", &a[i]);
  int sum = accumulate(a + 1, a + m + 1, 0);
  int ans = sum;
  for (int i = m + 1; i < n; ++i) {
    sum += a[i] - a[i - m];
    ans = min(ans, sum);
  }
  printf("%d\n", ans);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}