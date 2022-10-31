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

void precalc() {
}

#define y1 my1
int x1, y1, x2, y2, k;

bool read() {
  if (scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k) < 5) {
    return false;
  }
  return true;
}

int get(int x, int y) {
  if (x <= 0 || y <= 0) {
    return 0;
  }
  int res = 0;
  for (int bitx = 0; bitx < 30; bitx++) {
    for (int bity = 0; bity < 30; bity++) {
      if (x & (1 << bitx)) {
        if (y & (1 << bity)) {
          int mx = max(bitx, bity);
          int cur = (x ^ y) & (-(1 << mx));
          if (bitx != bity) {
            cur ^= (1 << mx);
          }
          if (cur >= k) {
            continue;
          }
          int s = 0;
          if ((cur ^ ((1 << mx) - 1)) >= k) {
            s = sum((cur + 1) % mod, k % mod);
            s = mult(s, (mod + 1) / 2);
            s = mult(s, (k - cur) % mod);
          } else {
            s = sum((cur + 1) % mod, ((cur + (1 << mx))) % mod);
            s = mult(s, (mod + 1) / 2);
            s = mult(s, (1 << mx) % mod);
          }
          add(res, mult(s, (1 << min(bitx, bity)) % mod));
        }
      }
    }
  }
  return res;
}

void solve() {
  int res = get(x1 - 1, y1 - 1);
  add(res, mod - get(x1 - 1, y2 - 0));
  add(res, mod - get(x2 - 0, y1 - 1));
  add(res, get(x2 - 0, y2 - 0));
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  int q;
  scanf("%d", &q);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}