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

const int maxn = 1e3 + 100;

int n;
int k, x;
int dp[maxn], ndp[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &k, &x) < 3) {
    return false;
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    int cur;
    scanf("%d", &cur);
    dp[cur]++;
  }
  return true;
}

void solve() {
  for (int it = 0; it < k; it++) {
    memset(ndp, 0, sizeof(ndp));
    for (int i = 0, cur = 0; i < maxn; i++) {
      if (cur & 1) {
        ndp[i ^ x] += dp[i] / 2;
        ndp[i] += (dp[i] + 1) / 2;
      } else {
        ndp[i ^ x] += (dp[i] + 1) / 2;
        ndp[i] += dp[i] / 2;
      }
      cur += dp[i];
    }
    swap(dp, ndp);
  }
  int mn = inf, mx = -inf;
  for (int i = 0; i < maxn; i++) {
    if (dp[i]) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  printf("%d %d\n", mx, mn);
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