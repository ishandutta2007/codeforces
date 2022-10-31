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

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
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

int mult(int a, int b) {
  return (ll) a * b % mod;
}

const int maxn = 1e6 + 100;
const int maxk = 30;

int dp[maxn][maxk];
int minp[maxn], primes[maxn], cntp;

void precalc() {
  dp[0][0] = 1;
  for (int j = 1; j < maxk; j++) {
    dp[0][j] = 2;
  }
  for (int i = 1; i < maxn; i++) {
    int cur = 0;
    for (int j = 0; j < maxk; j++) {
      add(cur, dp[i - 1][j]);
      dp[i][j] = cur;
    }
  }
  cntp = 0;
  memset(minp, -1, sizeof(minp));
  for (int i = 2; i < maxn; i++) {
    if (minp[i] == -1) {
      primes[cntp] = i;
      minp[i] = cntp++;
    }
    for (int j = 0; j <= minp[i] && primes[j] * i < maxn; j++) {
      minp[primes[j] * i] = j;
    }
  }
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    int r, n;
    scanf("%d%d", &r, &n);
    int res = 1;
    while (n > 1) {
      int curp = minp[n];
      int cnt = 0;
      while (minp[n] == curp) {
        n /= primes[minp[n]];
        cnt++;
      }
      res = mult(res, dp[r][cnt]);
    }
    printf("%d\n", res);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}