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

const int N = 500010;

int n, m;
int nxt[N];
char s[N], t[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = 2; i <= m; ++i) {
    int k = nxt[i - 1];
    while (k && t[k + 1] != t[i])
      k = nxt[k];
    if (t[k + 1] == t[i])
      ++k;
    nxt[i] = k;
  }
  int c1 = count(s + 1, s + n + 1, '1'), c2 = count(t + 1, t + m + 1, '1');
  int cyc = m - nxt[m], cc = count(t + nxt[m] + 1, t + m + 1, '1');
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (m + (i - 1) * cyc > n)
      break;
    ll res = n - (i - 1) * (ll)cyc - m, remain1 = c1 - cc * (ll)(i - 1) - c2;
    if (remain1 < 0 || remain1 > res)
      continue;
    ans = i;
  }
  if (ans == 0)
    puts(s + 1);
  else {
    printf("%s", t + 1);
    --ans;
    c1 -= c2;
    n -= m;
    while (ans--) {
      printf("%s", t + nxt[m] + 1);
      n -= cyc;
      c1 -= cc;
    }
    while (c1--) {
      putchar('1');
      n--;
    }
    while (n--)
      putchar('0');
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}