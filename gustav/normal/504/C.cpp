#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;
const int MAXN = 100005;
int n, a[MAXN];

int outer() {
  int ret = 0;
  while (ret < n / 2 && a[ret] == a[n - 1 - ret]) 
    ++ret;
  return ret;
}

int inner() {
  int ret = 0;
  int lc = n / 2 - 1;
  while (ret < n / 2 && a[lc - ret] == a[n - 1 - lc + ret])
    ++ret;
  return ret;
}

int tot[MAXN];
int cnt[MAXN];
llint calc_pref(int x) {
  memset(tot, 0, sizeof tot);
  memset(cnt, 0, sizeof cnt);
  
  REP(i, n) ++tot[a[i]], ++cnt[a[i]];
  int p = n - 1;

  while (p > n / 2 && 2 * (cnt[a[p]] - 1) >= tot[a[p]]) {
    --cnt[a[p]];
    --p;
  }

  llint ret = 0;
  int l = 0, r = n - 1;

  while (l <= r && r >= p) {
    ret += r - p + x;
    if (a[l] != a[r]) break;
    ++l; --r;
  }

  return ret;
}

int main(void) 
{
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);

  llint sol = 0;

  sol += calc_pref(1);
  reverse(a, a + n);
  sol += calc_pref(0);

  int what = -1;
  REP(i, n) {
    if (tot[i + 1] % 2 == 1) {
      if (what != -1) {
	puts("0");
	exit(0);
      }
      what = i + 1;
    }
  }

  bool lr_good = true;
  memset(cnt, 0, sizeof cnt);
  REP(i, n / 2) ++cnt[a[i]];
  REP(i, n) if (cnt[i + 1] != tot[i + 1] / 2) 
    lr_good = false;

  if ((n % 2 == 0 || a[n / 2] == what) && lr_good) {
    if (outer() == n / 2)
      sol += (llint)(n / 2) * (n / 2 + 1);
    else
      sol += 2LL * (outer() + 1) * (inner() + 1);
  }

  printf("%I64d\n", sol);

  return 0;
}