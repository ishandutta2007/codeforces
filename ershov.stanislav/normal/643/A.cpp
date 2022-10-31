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

const int maxn = (int) 5e3 + 10;
int a[maxn];
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    --a[i];
  }
  return 1;
}

int cnt[maxn], ans[maxn];

void solve() {
  for (int i = 0; i < n; ++i) {
    ans[i] = 0;
  }
  for (int l = 0; l < n; ++l) {
    for (int i = 0; i < n; ++i) {
      cnt[i] = 0;
    }
    pair<int, int> mx(0, 0);
    for (int r = l; r < n; ++r) {
      cnt[a[r]] += 1;
      mx = max(mx, mp(cnt[a[r]], -a[r]));
      ans[-mx.second] += 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
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