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

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;

const ld pi = acos(-1.0L);

void precalc() {
}

const int maxn = (int) 15e4 + 10;
int ps[maxn];
int ts[maxn];

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", ps + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", ts + i);
  }
  return 1;
}

int perm[maxn];

struct myComp {
  inline int operator () (const int a, const int b) {
    return (long long) ts[a] * ps[b] < (long long) ts[b] * ps[a];
  }
};

pair<int, int> tosort[maxn];

long long times[maxn][2];

long long T;

bool isok(ld c) {
  ld lastmax = -1e40;
  for (int i = 0; i < n;) {
    int i0 = i;
    ld curmin = 1e40, curmax = -1e40;
    while (i < n && tosort[i].first == tosort[i0].first) {
      int v = tosort[i].second;
      //eprintf("v = %d   %.3f %.3f\n", v, (double) (ps[v] * (T - c * times[v][1])), (double) (ps[v] * (T - c * times[v][0])));
      curmin = min(curmin, ps[v] * (T - c * times[v][1]));
      curmax = max(curmax, ps[v] * (T - c * times[v][0]));
      ++i;
    }
    if (lastmax > curmin) {
      return 0;
    }
    lastmax = max(lastmax, curmax);
  }
  return 1;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    perm[i] = i;
    tosort[i] = mp(ps[i], i);
  }
  sort(perm, perm + n, myComp());
  sort(tosort, tosort + n);

  long long passed = 0;
  for (int i = 0; i < n;) {
    int i0 = i;
    long long passed0 = passed;
    while (i < n && !myComp()(perm[i0], perm[i])) {
      passed += ts[perm[i]];
      ++i;
    }
    for (int j = i0; j < i; ++j) {
      int v = perm[j];
      times[v][0] = passed0 + ts[v];
      times[v][1] = passed;
      //eprintf("%d:  %lld %lld\n", v, times[v][0], times[v][1]);
    }
  }
  T = passed;

  ld left = 0, right = 1;
  for (int iter = 0; iter < 30; ++iter) {
    ld c = (left + right) / 2;

    if (isok(c)) {
      left = c;
    } else {
      right = c;
    }
  }
  printf("%.18f\n", (double) left);
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  precalc();
  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}