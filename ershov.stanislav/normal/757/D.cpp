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

const int mod = 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

const int maxk = 20;

void precalc() {
}

const int maxn = 100;

int n;
int a[maxn];
char s[maxn];

bool read() {
  if (scanf("%d%s", &n, s) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  return true;
}

int dp[maxn][1 << maxk];

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    auto & ndp = dp[i];
    ndp[0] = 1;
    int cur = 0;
    int cur2 = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (a[j]) {
        if (j < i - 10) {
          break;
        }
        cur += cur2;
      }
      if (!cur && j < i - 10) {
        break;
      }
      cur2 *= 2;
      if (cur > maxk) {
        break;
      }
      if (cur > 0) {
        for (int r = 0; r < (1 << maxk); r++) {
          add(ndp[r | (1 << (cur - 1))], dp[j][r]);
        }
      }
    }
    for (int i = 1; i <= maxk; i++) {
      add(res, ndp[(1 << i) - 1]);
    }
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