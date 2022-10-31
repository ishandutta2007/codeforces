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

int n, d, h;

bool read() {
  if (scanf("%d%d%d", &n, &d, &h) < 3) {
    return 0;
  }
  return 1;
}

const int maxn = (int) 1e5 + 10;
int used[maxn];

void solve() {
  if (d == 1) {
    if (n == 2) {
      printf("%d %d\n", 1, 2);
      return;
    }
    printf("-1\n");
    return;
  }

  if (d > 2 * h) {
    printf("-1\n");
    return;
  }

  for (int i = 1; i <= h; ++i) {
    printf("%d %d\n", i, i + 1);
  }
  if (d > h) {
    printf("1 %d\n", h + 2);
    for (int i = h + 2; i <= d; ++i) {
      printf("%d %d\n", i, i + 1);
    }
  }
  for (int i = d + 1; i < n; ++i) {
    printf("%d %d\n", (d == h ? 2 : 1), i + 1);
  }
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