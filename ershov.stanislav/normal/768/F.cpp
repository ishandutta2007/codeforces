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

const int maxn = 1e5 + 100;
int fact[maxn];

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
}

int getval(int n, int m) {
  if (m == 0) {
    return (n == 0);
  }
  if (n == 0) {
    return 0;
  }
  n--, m--;
  if (m > n) {
    return 0;
  }
  return mult(fact[n], power(mult(fact[n - m], fact[m]), mod - 2));
}

int f, w, h;

bool read() {
  if (scanf("%d%d%d", &f, &w, &h) < 3) {
    return false;
  }
  return true;
}

void solve() {
  int res = 0, good = 0;
  for (int i = 0; i <= f; i++) {
    for (int j = i - 1; j <= i + 1; j++) {
      if (j < 0) {
        continue;
      }
      if (!i && !j) {
        continue;
      }
      int tomult = (i == j) ? 2 : 1;
      int cur = mult(getval(f, i), getval(w, j));
      add(res, mult(cur, tomult));
      if ((ll) j * h <= w) {
        int w2 = w - j * h;
        int cur = mult(getval(f, i), getval(w2, j));
        add(good, mult(cur, tomult));
      }
    }
  }
  good = mult(good, power(res, mod - 2));
  printf("%d\n", good);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}