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

const int N = 200010;

int n;
ll k;
int p[N], c[N], cnt[101];

ll calc(int r) {
  ll ret = 0;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= r; ++i)
    ++cnt[c[i]];
  int pos = 1;
  for (int i = 100; i >= 0; --i)
    while (cnt[i]--)
      ret += p[pos++] * i;
  return ret;
}

void solve() {
  scanf("%d", &n);
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    p[i] /= 100;
  }
  int x, a;
  for (int rep = 0; rep < 2; ++rep) {
    scanf("%d%d", &x, &a);
    for (int i = a; i <= n; i += a)
      c[i] += x;
  }
  scanf("%lld", &k);
  sort(p + 1, p + n + 1, greater<int>());
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (calc(mid) < k)
      l = mid;
    else
      r = mid - 1;
  }
  if (l == n)
    puts("-1");
  else
    printf("%d\n", l + 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}