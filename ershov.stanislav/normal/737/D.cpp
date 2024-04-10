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

const int maxn = 4100;
const int maxk = 83;

int dp[2][maxn][maxn], ndp[2][maxn][maxn];
int n;
int a[maxn];
int pref[maxn][maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void solve() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        dp[i][j][k] = ndp[i][j][k] = -inf;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    pref[i][i] = 0;
    for (int j = i; j < n; j++) {
      pref[i][j + 1] = pref[i][j] + a[j];
    }
  }
  for (int k = maxk; k >= 1; k--) {
    for (int len = 0; len <= n - k * (k - 1) / 2; len++) {
      for (int l = max(0, n - len - maxk) / 2; l <= max(0, n - len + maxk) / 2; l++) { //!!!!
        int r = l + len;
        if (r > n) {
          continue;
        }
        auto & cur0 = ndp[0][l][r];
        auto & cur1 = ndp[1][l][r];
        cur0 = -inf;
        cur1 = -inf;
        if (len < k) {
          cur0 = cur1 = 0;
        } else {
          cur0 = max(cur0, -ndp[1][l + k][r] + pref[l][l + k]);
          cur1 = max(cur1, -ndp[0][l][r - k] + pref[r - k][r]);
          if (len >= k + 1) {
            cur0 = max(cur0, -dp[1][l + k + 1][r] + pref[l][l + k + 1]);
            cur1 = max(cur1, -dp[0][l][r - k - 1] + pref[r - k - 1][r]);
          }
        //eprintf("k = %d, l = %d, r = %d, cur0 = %d, cur1 = %d\n", k, l, r, cur0, cur1);
        }
      }
    }
    for (int len = 0; len <= n - k * (k - 1) / 2; len++) {
      for (int l = max(0, n - len - maxk + 1) / 2; l <= max(0, n - len + maxk) / 2; l++) { //!!!!
        int r = l + len;
        if (r > n) {
          continue;
        }
        dp[0][l][r] = ndp[0][l][r];
        dp[1][l][r] = ndp[1][l][r];
      }
    }
  }
  printf("%d\n", dp[0][0][n]);
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