#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

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

int mod;

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

const int maxn = 2000;
int inv[maxn];

void precalc() {
}

int n, d;

bool read() {
  if (scanf("%d%d%d", &n, &d, &mod) < 3) {
    return false;
  }
  return true;
}

int dp[maxn];

void solve() {
  if (n == 1) {
    printf("1\n");
    return;
  }
  if ((n - 2) % (d - 1)) {
    printf("0\n");
    return;
  }
  for (int i = 1; i < maxn; i++) {
    inv[i] = power(i, mod - 2);
  }
  int k = (n - 2) / (d - 1);
  dp[0] = dp[1] = 1;
  vector<vector<int> > tmp(k / 2 + 1, vector<int> (d));
  tmp[0][0] = 1;
  for (int j = 1; j <= k / 2; j++) {
    if (j >= 2) {
      dp[j] = 0;
      for (int i = 0; i < d; i++) {
        add(dp[j], tmp[j - 1][i]);
      }
    }
    for (int k1 = k / 2; k1 >= 0; k1--) {
      for (int k2 = d - 1; k2 >= 0; k2--) {
        for (int cnt = 1, c = 1; k1 + cnt * j <= k / 2 && k2 + cnt < d; cnt++) {
          c = mult(c, inv[cnt]);
          c = mult(c, dp[j] + cnt - 1);
          add(tmp[k1 + cnt * j][k2 + cnt], mult(tmp[k1][k2], c));
        }
      }
    }
  }
  if (k > 1) {
    int & cur = dp[k];
    if (k % 2 == 0) {
      cur = mult(inv[2], mult(dp[k / 2], dp[k / 2] + 1));
    }
    tmp = vector<vector<int> > (k, vector<int> (d + 1));
    tmp[0][0] = 1;
    for (int j = 1; j * 2 < k; j++) {
      for (int k1 = k - 1; k1 >= 0; k1--) {
        for (int k2 = d - 1; k2 >= 0; k2--) {
          for (int cnt = 1, c = 1; k1 + cnt * j < k && k2 + cnt <= d; cnt++) {
            c = mult(c, inv[cnt]);
            c = mult(c, dp[j] + cnt - 1);
            add(tmp[k1 + cnt * j][k2 + cnt], mult(tmp[k1][k2], c));
          }
        }
      }
    }
    for (int j = 0; j <= d; j++) {
      //eprintf("j = %d, tmp = %d\n", j, tmp[i - 1][j]);
      add(cur, tmp[k - 1][j]);
    }
    //eprintf("%d %d\n", i, cur);
  }
  printf("%d\n", dp[k]);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}