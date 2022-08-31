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

const int N = 1010;

int n;
int x[N], y[N], a[N], b[N];

bool pred(int u, int v) {
  set<pair<int, int> > pts;
  for (int i = 1; i <= n; ++i)
    pts.insert(make_pair(a[i], b[i]));
  for (int i = 1; i <= n; ++i)
    if (!pts.count(make_pair(u - x[i], v - y[i])))
      return false;
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &a[i], &b[i]);
  for (int i = 1; i <= n; ++i) {
    int u = x[1] + a[i], v = y[1] + b[i];
    if (pred(u, v)) {
      printf("%d %d\n", u, v);
      return 0;
    }
  }


#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}