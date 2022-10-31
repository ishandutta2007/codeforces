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

const int maxn = (int) 1e5 + 10;
int a[maxn];
char s[maxn];
int used[maxn];

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return 1;
}

void solve() {
  int x = 0;
  for (int i = 0; i < n; ++i) {
    used[i] = 0;
  }
  while (1) {
    if (x < 0 || x >= n) {
      printf("FINITE\n");
      return;
    }
    if (used[x]) {
      printf("INFINITE\n");
      return;
    }
    used[x] = 1;
    x += (s[x] == '>' ? 1 : -1) * a[x];
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