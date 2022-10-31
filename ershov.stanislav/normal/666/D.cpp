#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

int x[4], y[4];

bool read() {
  if (scanf("%d%d", x + 0, y + 0) < 2) {
    return false;
  }
  for (int i = 1; i < 4; i++) {
    scanf("%d%d", x + i, y + i);
  }
  return true;
}

void solve() {
  int res = inf;
  vector<pair<int, int> > ans(4);
  for (int mask = 0; mask < 16; mask++) {
    vector<int> perm(4);
    for (int i = 0; i < 4; i++) {
      perm[i] = i;
    }
    do {
      vector<int> a(4, -inf);
      bool ok = true;
      for (int i = 0; i < 4; i++) {
        int isy = (mask >> i) & 1;
        if (!isy) {
          if (a[perm[i] & 1] != -inf && a[perm[i] & 1] != x[i]) {
            ok = false;
          }
          a[perm[i] & 1] = x[i];
        } else {
          if (a[2 + !!(perm[i] & 2)] != -inf && a[2 + !!(perm[i] & 2)] != y[i]) {
            ok = false;
          }
          a[2 + !!(perm[i] & 2)] = y[i];
        }
      }
      if (!ok) {
        continue;
      }
      int bad = -1;
      int cntbad = 0;
      for (int i = 0; i < 4; i++) {
        if (a[i] == -inf) {
          bad = i;
          cntbad++;
        }
      }
      assert(cntbad <= 2);
      if (cntbad == 1) {
        int c = 0, d = 0;
        for (int i = 0; i < 4; i++) {
          int coef = (__builtin_popcount(i) & 1) ? -1 : 1;
          if (i == bad) {
            d += coef;
          } else {
            c += a[i] * coef;
          }
        }
        assert(abs(d) == 1);
        a[bad] = -c / d;
        cntbad = 0;
      }
      if (cntbad == 2) {
        /*for (int i = 0; i < 4; i++) {
          eprintf("%d%c", a[i], " \n"[i == 3]);
        }*/
        int c = 0, d = 0;
        for (int i = 0; i < 4; i++) {
          int coef = (__builtin_popcount(i) & 1) ? -1 : 1;
          if (i == bad) {
            d -= coef;
          } else if (a[i] != -inf) {
            c -= a[i] * coef;
          }
        }
        //eprintf("c = %d d = %d\n", c, d);
        for (int i = 0; i < 4; i++) {
          if (i != bad && a[i] == -inf) {
            if (__builtin_popcount(i) & 1) {
              c *= -1;
              d *= -1;
            }
          }
        }
        assert(abs(d) == 1);
        //eprintf("c = %d d = %d\n", c, d);
        vector<int> tomin;
        for (int i = 0; i < 4; i++) {
          if ((perm[i] & 1) == bad) {
            tomin.pb(x[i]);
          } else if (a[perm[i] & 1] == -inf) {
            if (d == 1) {
              tomin.pb(-c + x[i]);
            } else {
              tomin.pb(c - x[i]);
            }
          }
          if (2 + (!!(perm[i] & 2)) == bad) {
            tomin.pb(y[i]);
          } else if (a[2 + !!(perm[i] & 2)] == -inf) {
            if (d == 1) {
              tomin.pb(-c + y[i]);
            } else {
              tomin.pb(c - y[i]);
            }
          }
        }
        /*eprintf("!\n");
        for (auto i : tomin) {
          eprintf("%d\n", i);
        }*/
        sort(tomin.begin(), tomin.end());
        int x = tomin[0] + (tomin.back() - tomin[0]) / 2;
        //eprintf("x = %d\n", x);
        a[bad] = x;
        int bad2;
        for (int i = 0; i < 4; i++) {
          if (a[i] == -inf) {
            bad2 = i;
            a[i] = c + d * x;
          }
        }
        if (a[0] == a[1]) {
          x++;
          a[bad] = x;
          a[bad2] = x * d + c;
        }
      }
      if (a[3] - a[2] != a[1] - a[0]) {
        continue;
      }
      if (a[1] - a[0] == 0) {
        continue;
      }
      int curans = 0;
      for (int i = 0; i < 4; i++) {
        int toadd = abs(x[i] - a[perm[i] & 1]) + abs(y[i] - a[2 + !!(perm[i] & 2)]);
        curans = max(curans, toadd);
      }
      if (curans < res) {
        res = curans;
        for (int i = 0; i < 4; i++) {
          ans[i].first = a[perm[i] & 1];
          ans[i].second = a[2 + !!(perm[i] & 2)];
        }
      }
    } while (next_permutation(perm.begin(), perm.end()));
  }
  if (res == inf) {
    printf("-1\n");
  } else {
    printf("%d\n", res);
    for (int i = 0; i < 4; i++) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  int t;
  scanf("%d", &t);
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}