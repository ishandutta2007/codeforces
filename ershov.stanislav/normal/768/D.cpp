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

const int maxn = 1010;

int k, q;
ld p[maxn];
ld dp[maxn], ndp[maxn];
int ans[maxn];

bool read() {
  if (scanf("%d%d", &k, &q) < 2) {
    return false;
  }
  for (int i = 0; i < q; i++) {
    int cur;
    scanf("%d", &cur);
    p[i] = (ld) cur / 2000 - eps;
  }
  return true;
}

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 0; i < q; i++) {
    ans[i] = inf;
  }
  for (int i = 1; i < 30 * maxn; i++) {
    for (int j = 1; j <= k; j++) {
      ndp[j] = dp[j] * j / (ld) k;
      ndp[j] += dp[j - 1] * (k - j + 1) / (ld) k;
    }
    ndp[0] = 0;
    for (int j = 0; j < q; j++) {
      if (ndp[k] >= p[j]) {
        ans[j] = min(ans[j], i);
      }
    }
    swap(dp, ndp);
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", ans[i]);
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