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

int n, m;
int b[maxn], g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", g + i);
  }
  return true;
}

void solve() {
  int mx = 0, mn = 1e9;
  sort(b, b + n);
  sort(g, g + m);
  for (int i = 0; i < n; i++) {
    mx = max(mx, b[i]);
  }
  for (int j = 0; j < m; j++) {
    mn = min(mn, g[j]);
  }
  if (mx > mn) {
    printf("-1\n");
    return;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += b[i];
  }
  ans *= m;
  for (int i = 0; i < m; i++) {
    ans += max(0, g[i] - mx);
  }
  if (mx < mn) {
    ans += b[n - 1] - b[n - 2];
  }
  printf("%lld\n", ans);
}

int main() {
  precalc();

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}