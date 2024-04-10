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

const int maxn = (int) 1e5 + 10;
long long a[maxn];

int n, q;

int go[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf(LLD , &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &go[i]);
    --go[i];
  }
  return 1;
}

long long toadd[maxn];
long long val[maxn];

int ks[maxn];

multiset<long long> ins[maxn];
multiset<long long> mn, mx;

void addSet(int v) {
  assert(ks[v] == sz(ins[v]));
  if (ks[v]) {
    mn.insert(*ins[v].begin() + toadd[v]);
    mx.insert(*ins[v].rbegin() + toadd[v]);
  }
}

void delSet(int v) {
  assert(ks[v] == sz(ins[v]));
  if (ks[v]) {
    {
      auto iter = mn.find(*ins[v].begin() + toadd[v]);
      mn.erase(iter);
    }
    {
      auto iter = mx.find(*ins[v].rbegin() + toadd[v]);
      mx.erase(iter);
    }
  }
}

void addVal(int v, long long toadd) {
  delSet(go[v]);
  {
    auto iter = ins[go[v]].find(val[v]);
    ins[go[v]].erase(iter);
    val[v] += toadd;
    ins[go[v]].insert(val[v]);
  }
  addSet(go[v]);
}

void solve() {
  for (int i = 0; i < n; ++i) {
    ks[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    ins[i].clear();
    toadd[i] = 0;
    ks[go[i]] += 1;
    val[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    val[i] += a[i] - (ks[i] + 1) * (a[i] / (ks[i] + 2));
    val[go[i]] += a[i] / (ks[i] + 2);
    toadd[i] += a[i] / (ks[i] + 2);
  }

  for (int i = 0; i < n; ++i) {
    ins[go[i]].insert(val[i]);
  }
  mn.clear(), mx.clear();
  for (int i = 0; i < n; ++i) {
    addSet(i);
  }

  for (int iter = 0; iter < q; ++iter) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int v, u;
      scanf("%d%d", &v, &u);
      --v, --u;
      {
        int s = v, t = go[s];

        assert(ks[t] > 0);
        long long cht = a[t] / (ks[t] + 2) - a[t] / (ks[t] + 1);

        addVal(t, (ks[t] + 1) * (a[t] / (ks[t] + 2)) - (ks[t]) * (a[t] / (ks[t] + 1)) - (a[s] / (ks[s] + 2)));
        addVal(go[t], -cht);

        delSet(t);
        {
          auto iter = ins[t].find(val[s]);
          ins[t].erase(iter);
          val[s] += toadd[t] - (a[t] / (ks[t] + 2));
          --ks[t];
        }
        toadd[t] -= cht;
        addSet(t);
      }
      {
        int s = v, t = u;
        go[s] = t;

        long long cht = a[t] / (ks[t] + 3) - a[t] / (ks[t] + 2);

        addVal(t, -(ks[t] + 2) * (a[t] / (ks[t] + 3)) + (ks[t] + 1) * (a[t] / (ks[t] + 2)) + (a[s] / (ks[s] + 2)));
        addVal(go[t], cht);

        delSet(t);
        toadd[t] += cht;
        {
          ++ks[t];
          val[s] -= toadd[t] - (a[t] / (ks[t] + 2));
          ins[t].insert(val[s]);
        }
        addSet(t);
      }
      continue;
    }
    if (type == 2) {
      int v;
      scanf("%d", &v);
      --v;
      printf(LLD "\n", val[v] + toadd[go[v]]);
      continue;
    }
    if (type == 3) {
      long long mn = *::mn.begin();
      long long mx = *::mx.rbegin();
      printf(LLD " " LLD "\n", mn, mx);
      continue;
    }
    assert(0);
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