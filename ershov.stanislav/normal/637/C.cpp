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

const int INF = (int) 1.01e9;
const ld EPS = 1e-9;

const ld PI = acos(-1.0L);

void precalc() {
}

const int maxn = (int) 1e3 + 10;
char s[maxn][10];

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }
  return 1;
}

void solve() {
  int res = 6;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int eq = 0;
      for (int k = 0; k < 6; ++k) {
        eq += (s[i][k] == s[j][k]);
      }
      res = min(res, (6 - eq - 1) / 2);
    }
  }
  printf("%d\n", res);
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