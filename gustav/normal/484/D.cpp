#include <cstdio>
#include <cassert>

#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#define L(n) ((n) << 1)
#define R(n) (L(n) | 1)

const int off = 1 << 20;

llint t[off << 1];
llint p[off << 1];

void propagate(int n) {
  if (!p[n]) return;
  t[L(n)] += p[n]; p[L(n)] += p[n];
  t[R(n)] += p[n]; p[R(n)] += p[n];
  p[n] = 0;
}

void prop_from_root(int n) {
  if (!n) return;
  prop_from_root(n / 2);
  propagate(n);
}

void set(int i, llint v) {
  i += off;
  prop_from_root(i / 2);
  t[i] = v;
  for (i /= 2; i; i /= 2)
    t[i] = max(t[L(i)], t[R(i)]);
}

void update(int lo, int hi, llint v, int l = 0, int r = off, int n = 1) {
  if (l >= hi || r <= lo) return;
  if (l >= lo && r <= hi) {
    t[n] += v;
    p[n] += v;
    return;
  }

  propagate(n);

  update(lo, hi, v, l, (l + r) / 2, L(n));
  update(lo, hi, v, (l + r) / 2, r, R(n));
  
  t[n] = max(t[L(n)], t[R(n)]);
}

const int inf = 1000000001;
const int MAXN = 1000005;

struct Level {
  int x, v;
};

int N;
int a[MAXN];
llint dp[MAXN];

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);

  deque< Level > mins, maxs;

  mins.push_front({N, -inf});
  maxs.push_front({N, +inf});

  for (int i = N - 1; i >= 0; --i) {
    while (maxs[0].v <= a[i]) {
      update(maxs[0].x, maxs[1].x, abs(maxs[0].v - a[i]));
      maxs.pop_front();
    }
    maxs.push_front({i, a[i]});

    while (mins[0].v >= a[i]) {
      update(mins[0].x, mins[1].x, abs(mins[0].v - a[i]));
      mins.pop_front();
    }
    mins.push_front({i, a[i]});

    set(i, dp[i + 1]);
    dp[i] = t[1];
  }

  printf("%I64d\n", dp[0]);

  return 0;
}