#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100005;
const int MAXM = 5005;
const llint inf = 1000000000000000000LL;

int n, m, k, p;
int h[MAXN];
int a[MAXN];
int cnt[MAXM];

bool check(llint H) {
  llint cuts = 0;

  REP(i, m + 1) cnt[i] = 0;

  REP(i, n) {
    llint now = H;
    llint day = m;

    auto adjust = [&](llint a) {
      llint ccuts = (a - now + p - 1) / p;
      cnt[day] += ccuts;
      now += ccuts * p;
      cuts += ccuts;
    };

    for (;;) {
      llint nday = max(0LL, day - now / a[i]);
      now -= (day - nday) * a[i];
      day = nday;
      if (day) adjust(a[i]);
      else break;
      if (cuts > m * k) return false;
    }

    if (now < h[i]) adjust(h[i]);
    if (cuts > m * k) return false;
  }

  REP(i, m) {
    cnt[i] = max(0, cnt[i] - 10);
    if (cnt[i]) cnt[i + 1] += cnt[i];
  }

  if (cnt[m]) return false;

  return true;
}

int main(void) 
{
  scanf("%d%d%d%d", &n, &m, &k, &p);
  REP(i, n) scanf("%d%d", h + i, a + i);

  llint lo = 0, hi = inf, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  printf("%I64d\n", lo);

  return 0;
}