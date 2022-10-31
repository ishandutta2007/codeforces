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
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
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

int n, q;
const int maxn = (int) 1e6 + 10;

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return 0;
  }
  return 1;
}

int a[maxn];

void solve() {
  int odd = 0, even = 0;
  for (int iter = 0; iter < q; ++iter) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x;
      scanf("%d", &x);
      odd += x, even += x;
    } else {
      if (even & 1) {
        --even;
        ++odd;
      } else {
        ++even;
        --odd;
      }
    }
    odd %= n, even %= n;
  }
  for (int i = 0; i < n; ++i) {
    int val = (i + (!(i & 1) ? even : odd)) % n;
    if (val < 0) {
      val += n;
    }
    a[val] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i] + 1, " \n"[i == n - 1]);
  }
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.2f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}