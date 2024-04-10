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

void precalc() {
}

ll n, l, r;

bool read() {
  if (scanf("%lld%lld%lld", &n, &l, &r) < 3) {
    return false;
  }
  return true;
}

void solve() {
  int allcnt = 64 - __builtin_clzll(n);
  r = min(r, (1ll << allcnt) - 1);
  l--;
  ll res = 0;
  for (int i = 0; i < allcnt; i++) {
    if (n & (1ll << i)) {
      ll first = 1ll << (allcnt - 1 - i);
      ll step = 1ll << (allcnt - i);
      if (r >= first) {
        res += (r - first) / step + 1;
      }
      if (l >= first) {
        res -= (l - first) / step + 1;
      }
    }
  }
  printf("%lld\n", res);
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