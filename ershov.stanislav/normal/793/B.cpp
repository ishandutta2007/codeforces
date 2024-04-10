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

const int maxn = 1100;
char s[maxn][maxn];

int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  return true;
}

int dp[maxn][maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cur = 0;
      if (s[i][j] == 'S') {
        cur = 1;
      } else if (s[i][j] == 'T') {
        cur = 2;
      }
      if (cur) {
        for (int ii = i; ii >= 0; ii--) {
          if (s[ii][j] == '*') {
            break;
          }
          dp[ii][j] |= cur;
        }
        for (int ii = i; ii < n; ii++) {
          if (s[ii][j] == '*') {
            break;
          }
          dp[ii][j] |= cur;
        }
        for (int jj = j; jj >= 0; jj--) {
          if (s[i][jj] == '*') {
            break;
          }
          dp[i][jj] |= cur;
        }
        for (int jj = j; jj < m; jj++) {
          if (s[i][jj] == '*') {
            break;
          }
          dp[i][jj] |= cur;
        }
      }
    }
  }
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '*') {
        cur = 0;
      } else {
        cur |= dp[i][j];
        if (cur == 3) {
          ok = true;
        }
      }
    }
  }
  for (int j = 0; j < m; j++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '*') {
        cur = 0;
      } else {
        cur |= dp[i][j];
        if (cur == 3) {
          ok = true;
        }
      }
    }
  }
  printf(ok ? "YES\n" : "NO\n");
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