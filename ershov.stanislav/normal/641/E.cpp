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

const int maxn = (int) 1e6 + 10;

struct Tree {
  int a[maxn];
  int n;

  void build(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i) {
      a[i] = 0;
    }
  }

  void add(int pos, int toadd) {
    for (int x = pos; x < n; x |= (x + 1)) {
      a[x] += toadd;
    }
  }

  int get(int x) {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
      res += a[x];
    }
    return res;
  }
} tree;

int as[maxn], ts[maxn], xs[maxn];

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &as[i], &ts[i], &xs[i]);
  }
  return 1;
}

int where[maxn];

void solve() {
  vector<pair<pair<int, int>, int> > tosort;
  for (int i = 0; i < n; ++i) {
    tosort.pb(mp(mp(xs[i], ts[i]), i));
  }
  sort(tosort.begin(), tosort.end());

  for (int i = 0; i < n; ++i) {
    where[tosort[i].second] = i;
  }

  tree.build(n);

  for (int i = 0; i < n; ++i) {
    if (as[i] == 1) {
      tree.add(where[i], 1);
      continue;
    }
    if (as[i] == 2) {
      tree.add(where[i], -1);
      continue;
    }
    int start = lower_bound(tosort.begin(), tosort.end(), mp(mp(xs[i], -inf), -inf)) - tosort.begin();
    int finish = lower_bound(tosort.begin(), tosort.end(), mp(mp(xs[i], ts[i] + 1), -inf)) - tosort.begin();
    printf("%d\n", tree.get(finish - 1) - tree.get(start - 1));
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