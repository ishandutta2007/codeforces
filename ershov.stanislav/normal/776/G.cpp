#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

const int maxn = 20;
unsigned long long pws[maxn][maxn];

void precalc() {
  for (int i = 0; i < maxn; i++) {
    pws[i][0] = 1;
    for (int j = 1; j < maxn; j++) {
      pws[i][j] = pws[i][j - 1] * (i + 1);
    }
  }
}

char s[2][maxn];
int n[2];
int a[2][maxn];

bool read() {
  for (int it = 0; it < 2; it++) {
    if (scanf("%s", s[it]) < 1) {
      return false;
    }
    n[it] = strlen(s[it]);
    for (int i = 0; i < n[it]; i++) {
      if (isdigit(s[it][i])) {
        a[it][i] = s[it][i] - '0';
      } else {
        a[it][i] = (int) (s[it][i] - 'a') + 10;
      }
    }
    reverse(a[it], a[it] + n[it]);
  }
  return true;
}

ll get(ll cnt, ll have, ll want) {
  assert(want >= have);
  if (have == want) {
    return (ll) pws[want][cnt];
  } else {
    return (ll) pws[want][cnt] - (ll) pws[want - 1][cnt];
  }
}

ll solve(int a[maxn], int n) {
  /*eprintf("=\n");
  for (int i = 0; i < n; i++) {
    eprintf("%d\n", a[i]);
  }*/
  ll mask = 0;
  int mx = 0;
  ll res = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int k = 0; k < a[i]; k++) {
      mask &= -(1ll << (4 * i + 4));
      mask |= ((ll) k) << (4 * i);
      //eprintf("k = %d\n", k);
      for (int want = max(mx, k); want < 16; want++) {
        if (want < 4 * i) {
          if (!i) {
            continue;
          }
          for (int r = 0; r < 16 && r <= want; r++) {
            if (!(r & (1 << (want % 4)))) {
              continue;
            }
            //eprintf("%d %d\n", want, r);
            res += get(i - 1, max(max(mx, k), r), want);
          }
        } else {
          if (mask & (1ll << want)) {
            //eprintf("mask = %lld, want = %d\n", mask, want);
            res += get(i, max(mx, k), want);
          }
        }
      }
      //eprintf("res = %lld\n", res);
    }
    //eprintf("a[i] = %d\n", a[i]);
    mask &= -(1ll << (4 * i + 4));
    mask |= ((ll) a[i]) << (4 * i);
    //eprintf("mask = %lld\n", mask);
    mx = max(mx, a[i]);
  }
  return res;
}

void solve() {
  ll res = 0;
  a[1][n[1]] = 0;
  for (int i = 0, toadd = 1; i < n[1] || toadd; i++) {
    a[1][i] += toadd;
    if (a[1][i] >= 16) {
      a[1][i] -= 16;
      toadd = 1;
    } else {
      toadd = 0;
    }
  }
  if (a[1][n[1]]) {
    n[1]++;
  }
  res += solve(a[1], n[1]);
  res -= solve(a[0], n[0]);
  printf("%lld\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  /*int have = 0;
  for (int i = 1; i < 100000; i++) {
    int cur = i;
    int a[maxn], n = 0;
    int mx = 0;
    while (cur) {
      a[n++] = cur % 16;
      mx = max(mx, cur % 16);
      cur /= 16;
    }
    eprintf("%d\n", i);
    eprintf("%d %d\n", solve(a, n), have);
    assert(have == solve(a, n));
    if (i & (1 << mx)) {
      have++;
    }
  }*/

  int t;
  scanf("%d", &t);

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}