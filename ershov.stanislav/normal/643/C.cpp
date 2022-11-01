#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

inline int rnd(int x) {
  return myrand() % x;
}

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

void precalc() {
}

const int maxn = (int) 2e5 + 10;
int n, k;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  return 1;
}

ld dp[maxn];

ld sum[maxn], sum1[maxn], sum2[maxn];


vector<pair<ld, ld> > st;

ld inter(const pair<ld, ld> &a, const pair<ld, ld> &b) {
  return (a.second - b.second) / (b.first - a.first);
}

void add(ld a, ld b) {
#ifdef DEBUG
  if (sz(st)) {
    assert(st.back().first > a + eps);
  }
#endif
  pair<ld, ld> toadd(a, b);
  while (sz(st) >= 2 && inter(toadd, st.back()) <= inter(st.back(), st[sz(st) - 2])) {
    st.pop_back();
  }
  st.pb(toadd);
}

ld get(ld x) {
  assert(sz(st));
  int left = 0, right = sz(st);
  while (right - left > 2) {
    int m1 = (left + right) / 2;
    int m2 = m1 + 1;
    assert(m2 < right);
    ld f1 = (x * st[m1].first + st[m1].second);
    ld f2 = (x * st[m2].first + st[m2].second);
    if (f1 < f2) {
      right = m2;
    } else {
      left = m1;
    }
  }
  ld res = 1e18;
  for (int i = left; i < right; ++i) {
    res = min(res, st[i].first * x + st[i].second);
  }
#ifdef DEBUG
  ld res0 = 1e18;
  for (int i = 0; i < sz(st); ++i) {
    res0 = min(res0, st[i].first * x + st[i].second);
  }
  assert(abs(res0 - res) < eps);
#endif
  return res;
}

void solve() {
  sum[0] = sum1[0] = sum2[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
    sum1[i + 1] = sum1[i] + (ld) sum[i + 1] / a[i];
    sum2[i + 1] = sum2[i] + (ld) 1 / a[i];
  }
  for (int i = 0; i <= n; ++i) {
    dp[i] = 1e18;
  }
  dp[0] = 0;

  for (int iter = 0; iter < k; ++iter) {
    st.clear();
    for (int i = iter; i <= n; ++i) {
      ld dp0 = dp[i];
      if (i > iter) {
        dp[i] = get(sum2[i]) + sum1[i];
        //eprintf("%.3f%c", (double) dp[i], " \n"[i == n]);
      }
      if (!i || iter) {
        //eprintf("add %d (%.2f)\n", i, (double) dp0);
        add(-sum[i], sum[i] * sum2[i] + dp0 - sum1[i]);
      }
    }
  }
  printf("%.18f\n", (double) dp[n]);
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef LOCAL
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}