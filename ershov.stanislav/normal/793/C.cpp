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

const int maxn = 1e5 + 100;

int n;
int x[2][2];
int pos[2][maxn], v[2][maxn];

bool read() {
  if (scanf("%d%d%d%d%d", &n, &x[0][0], &x[1][0], &x[0][1], &x[1][1]) < 5) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", pos[0] + i, pos[1] + i, v[0] + i, v[1] + i);
  }
  return true;
}

void solve() {
  ld l = 0, r = 1e18;
  for (int i = 0; i < n; i++) {
    for (int it = 0; it < 2; it++) {
      if (!v[it][i]) {
        if (pos[it][i] > x[it][0] && pos[it][i] < x[it][1]) {
        } else {
          r = -1;
        }
      } else {
        ld a = (ld) (x[it][0] - pos[it][i]) / v[it][i];
        ld b = (ld) (x[it][1] - pos[it][i]) / v[it][i];
        if (a > b) {
          swap(a, b);
        }
        l = max(l, a);
        r = min(r, b);
      }
    }
  }
  if (l + eps >= r) {
    printf("-1\n");
  } else {
    printf("%.18f\n", (double) l);
  }
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