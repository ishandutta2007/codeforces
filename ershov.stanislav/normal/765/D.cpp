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

const int maxn = 1e5 + 100;
int n;
int f[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", f + i);
  }
  return true;
}

int h[maxn];
int g[maxn];
int used[maxn];

void solve() {
  memset(used, -1, sizeof(used));
  int m = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] == i) {
      ++m;
      h[m] = i;
      g[i] = m;
      used[i] = m;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (used[f[i]] == -1) {
      printf("-1\n");
      return;
    } else {
      g[i] = used[f[i]];
    }
  }
  printf("%d\n", m);
  for (int i = 1; i <= n; i++) {
    printf("%d%c", g[i], " \n"[i == n]);
  }
  for (int i = 1; i <= m; i++) {
    printf("%d%c", h[i], " \n"[i == m]);
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