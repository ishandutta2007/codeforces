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

ll s;

bool read() {
  if (scanf("%lld", &s) < 1) {
    return false;
  }
  return true;
}

const int maxn = 110;

ll dp[2][maxn], ndp[2][maxn];

void solve() {
  ll res = 0;
  for (int left = 0; left < maxn / 2; left++) {
    for (int right = 0; right < maxn / 2; right++) {
      ll a = 1;
      a += (1ll << (left + 1)) - 2;
      a += (1ll << (right + 1)) - 2;
      if (s < a) {
        continue;
      }
      ll rem = s % a;
      if (right) {
        rem -= (1ll << right) - 1;
        if (rem < 0) {
          continue;
        }
      }
      //eprintf("left = %d, right = %d, rem = %lld\n", left, right, rem);
      memset(dp, 0, sizeof(dp));
      dp[0][rem & 1] = 1;
      for (int i = 1; i < maxn / 2; i++) {
        memset(ndp, 0, sizeof(ndp));
        for (int r = 0; r < 2; r++) {
          for (int j = 0; j < maxn; j++) {
            if (!dp[r][j]) {
              continue;
            }
            ll real = (rem & ((1ll << i) - 1)) + j;
            real = (real & ((1ll << i) - 1));
            if (r) {
              real += (1ll << i);
            }
            int mx1 = 0, mx2 = 0;
            if (i <= left - 1) {
              mx1++;
            }
            if (i <= right - 1) {
              mx2++;
            }
            for (int x = 0; x <= mx1; x++) {
              for (int y = 0; y <= mx2; y++) {
                ll cur = real + ((1ll << i) - 1) * (x + y);
                ll val = (cur - rem) & ((1ll << (i + 1)) - 1);
                if (val >= maxn) {
                  continue;
                }
                ndp[!!(cur & (1ll << (i + 1)))][val] += dp[r][j];
              }
            }
          }
        }
        swap(dp, ndp);
      }
      res += dp[0][0];
    }
  }
  printf("%lld\n", res);
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