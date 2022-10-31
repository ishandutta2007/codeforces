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

const int maxn = (int) 2e5 + 10;
int a[maxn];

int n, k, b, c;

bool read() {
  if (scanf("%d%d%d%d", &n, &k, &b, &c) < 4) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  return 1;
}

int d[5][maxn];
int cnt[5];

int down(int x) {
  int rem = x % 5;
  if (rem < 0) {
    rem += 5;
  }
  x -= rem;
  x /= 5;
  return x;
}

void getVal(int r, int x, int &A, int &B) {
  int rem = x % 5;
  if (rem < 0) {
    rem += 5;
  }
  A = down(x);
  B = 0;
  while (rem != r) {
    B += c;
    if (++rem == 5) {
      rem = 0;
      ++A;
    }
  }
}

void solve() {
  b = min(b, 5 * c);
  sort(a, a + n);
  long long res = 1e18;
  for (int r = 0; r < 5; ++r) {
    memset(cnt, 0, sizeof(cnt));
    int ls[5];
    memset(ls, 0, sizeof(ls));
    long long suma = 0, sumb = 0;
    for (int i = 0; i <= n; ++i) {
      if (i >= k) {
        int nextx = a[i - 1];
        int rem = nextx % 5;
        if (rem < 0) {
          rem += 5;
        }
        while (rem != r) {
          ++nextx;
          if (++rem == 5) {
            rem = 0;
          }
        }

        long long val = b * ((long long) down(nextx) * k - suma) + sumb;
        //eprintf("nextx = %d, val = %lld\n", nextx, val);
        res = min(res, val);
      }

      if (i == n) {
        break;
      }
      {
        int x = a[i];
        int rem = x % 5;
        if (rem < 0) {
          rem += 5;
        }
        d[rem][cnt[rem]++] = x;

        int A, B;
        getVal(r, x, A, B);
        //eprintf("add %d:  %d %d\n", x, A, B);
        suma += A, sumb += B;
      }
      if (i >= k) {
        long long res = -1e18;
        int who = -1;
        for (int rem = 0; rem < 5; ++rem) {
          long long cur = -1e18;
          if (ls[rem] < cnt[rem]) {
            int A, B;
            getVal(r, d[rem][ls[rem]], A, B);
            cur = -(long long) A * b + B;
          }
          if (res < cur) {
            res = cur;
            who = rem;
          }
        }
        //eprintf("delete %d, %d\n", who, d[who][ls[who]]);
        assert(who != -1);
        int A, B;
        getVal(r, d[who][ls[who]], A, B);
        suma -= A, sumb -= B;
        ++ls[who];
      }
    }
  }
  printf(LLD "\n", res);
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
    //break;
#ifdef DEBUG
    eprintf("Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}