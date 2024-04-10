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

const int N = 500010;

int n;
int a[N], cnt[N];
ll sum[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int parity = accumulate(a + 1, a + n + 1, 0, bit_xor<int>()) & 1;
  sort(a + 1, a + n + 1, greater<int>());
  for (int i = 1; i <= n; ++i)
    sum[i] = sum[i - 1] + a[i];
  int ptr = n;
  for (int i = 1; i <= n; ++i) { // res +- x >= 0
    // ans >= a[i]
    ll res = i * (ll)(i - 1) - sum[i - 1];
    while (ptr && a[ptr] < i)
      --ptr;
    if (ptr >= i) {
      res += sum[n] - sum[ptr] + (ptr - i + 1) * (ll)i;
    } else
      res += sum[n] - sum[i - 1];
    res = min(res, (ll)n);
    if (a[i] <= res) {
      ++cnt[a[i]];
      --cnt[res + 1];
    }
    // ans < a[i]
    res = i * (ll)(i - 1) - sum[i];
    if (ptr > i)
      res += sum[n] - sum[ptr] + (ptr - i) * (ll)i;
    else
      res += sum[n] - sum[i];
    if (a[i] <= i) {
      res = max(-res, 0LL);
      if (res <= a[i]) {
        ++cnt[res];
        --cnt[a[i]];
      }
    } else {
      // ans in [i, a[i])
      if (res + i >= 0) {
        ++cnt[i];
        --cnt[a[i]];
      }
      res = max(-res, 0LL);
      if (res <= i) {
        ++cnt[res];
        --cnt[i];
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    cnt[i] += cnt[i - 1];
  bool flag = false;
  for (int i = 0; i <= n; ++i)
    if (cnt[i] == n && ((i & 1) == parity)) {
      printf("%d ", i);
      flag = true;
    }
  if (!flag)
    puts("-1");

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}