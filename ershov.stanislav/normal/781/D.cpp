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

const int maxn = 510;

typedef bitset<maxn> bits;

const int maxlog = 61;

bits dp[maxlog][2][maxn];

int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < maxlog; i++) {
    for (int j = 0; j < 0; j++) {
      for (int k = 0; k < maxn; k++) {
        dp[i][j][k] = bits();
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, t;
    scanf("%d%d%d", &a, &b, &t);
    a--, b--;
    dp[0][t][a][b] = 1;
  }
  return true;
}

bits tmp[2][maxn];

void solve() {
  for (int i = 1; i < maxlog; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < n; k++) {
        tmp[j][k] = bits();
      }
    }
    for (int j = 0; j < 2; j++) {
      for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
          if (dp[i - 1][j][a][b]) {
            tmp[j][b][a] = 1;
          }
        }
      }
    }
    for (int j = 0; j < 2; j++) {
      for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
          if ((dp[i - 1][j][a] & tmp[!j][b]).any()) {
            dp[i][j][a][b] = 1;
          }
        }
      }
    }
  }
  ll ans = 0;
  int pw = 0;
  bits curpos;
  for (int i = 0; i < maxlog; i++) {
    if (dp[i][0][0].any()) {
      ans = (1ll << i);
      curpos = dp[i][0][0];
      pw = i;
    }
  }
  if (ans) {
    int t = 1;
    for (int i = pw - 1; i >= 0; i--) {
      bool was = false;
      bits npos;
      for (int j = 0; j < n; j++) {
        if (!curpos[j]) {
          continue;
        }
        if (dp[i][t][j].any()) {
          npos |= dp[i][t][j];
          was = true;
        }
      }
      if (was) {
        curpos = npos;
        t ^= 1;
        ans += (1ll << i);
      }
    }
  }
  if (ans > 1e18) {
    printf("-1\n");
  } else {
    printf("%lld\n", ans);
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