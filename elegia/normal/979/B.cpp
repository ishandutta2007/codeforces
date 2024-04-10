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

const int N = 100010;

int n;
int cnt[256];
char s[N];

int calc() {
  int m = strlen(s);
  if (m == 1)
    return 1;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < m; ++i)
    ++cnt[s[i]];
  int c = *max_element(cnt, cnt + 256);
  if (n == 1) {
    if (c == m)
      return c - 1;
    else
      return c + 1;
  }
  return min(c + n, m);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  int a, b, c;
  scanf("%s", s); a = calc();
  scanf("%s", s); b = calc();
  scanf("%s", s); c = calc();
  LOG("%d %d %d\n", a, b, c);
  if (a > b && a > c) puts("Kuro");
  else if (b > a && b > c) puts("Shiro");
  else if (c > a && c > b) puts("Katie");
  else puts("Draw");

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}