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

void precalc() {
}

const int mod = 1e9 + 7;

void add(int & a, int b) {
  if ((a += b) >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

int power(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, a);
    }
    a = mult(a, a);
    p >>= 1;
  }
  return res;
}

const int maxn = 5100;
int n;
char s[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", s);
  return true;
}

int dp[maxn][maxn], sum[maxn][maxn];
int last[maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j + 1 < maxn; j++) {
      add(dp[i][j + 1], sum[i][j]);
      add(dp[i][j + 1], mod - sum[last[s[i]] + 1][j]);
    }
    if (last[s[i]] == -1) {
      add(dp[i][1], 1);
    }
    for (int j = 1; j < maxn; j++) {
      sum[i + 1][j] = sum[i][j];
      add(sum[i + 1][j], dp[i][j]);
    }
    last[s[i]] = i;
  }
  int res = 0;
  int c = 1;
  for (int i = 1; i <= n; i++) {
    add(res, mult(c, sum[n][i]));
    c = mult(c, n - i);
    c = mult(c, power(i, mod - 2));
  }
  printf("%d\n", res);
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