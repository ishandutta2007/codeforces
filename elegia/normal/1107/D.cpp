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

const int N = 5210;

int n;

bool g[N][N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int calc(bool* arr) {
  int ret = n;
  for (int i = 1; i < n; ++i)
    if (arr[i] != arr[i - 1])
      ret = gcd(ret, i);
//  printf("%d\n", ret);
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    getchar();
    for (int j = 0; j < n; j += 4) {
      char c = getchar();
      int v = isdigit(c) ? (c - '0') : (c - 'A' + 10);
      for (int k = 0; k < 4; ++k)
        g[i][j + k] = (v >> (3 - k)) & 1;
    }/*
    for (int j = 0; j < n; ++j)
      scanf("%d", &g[i][j]);*/
  }
  int ans = n;
  for (int i = 0; i < n; ++i)
    ans = gcd(ans, calc(g[i]));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
      swap(g[i][j], g[j][i]);
  for (int i = 0; i < n; ++i)
    ans = gcd(ans, calc(g[i]));
  printf("%d\n", ans);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}