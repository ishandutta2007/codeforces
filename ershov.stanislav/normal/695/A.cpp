#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);


void precalc() {
}

const int maxn = 20;
ld a[maxn];

int n, k;

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    double tmp;
    scanf("%lf", &tmp);
    a[i] = tmp;
  }
  return 1;
}

ld as[1 << maxn];

ld dp[1 << maxn];
ld ans[maxn];

void solve() {
  dp[0] = 1;
  memset(ans, 0, sizeof(ans));
  as[0] = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > eps) {
      cnt++;
    }
  }
  k = min(k, cnt);
  for (int mask = 1; mask < (1 << n); ++mask) {
    as[mask] = 0;
    for (int v = 0; v < n; ++v) {
      if ((mask >> v) & 1) {
        as[mask] = as[mask ^ (1 << v)] + a[v];
        break;
      }
    }
  }
  for (int mask = 1; mask < (1 << n); ++mask) {
    ld &cur = dp[mask];
    cur = 0;
    for (int v = 0; v < n; ++v) {
      if ((mask >> v) & 1) {
        if (a[v] < eps) {
          continue;
        }
        ld tmp = dp[mask ^ (1 << v)] * a[v];
        cur += tmp / (1 - as[mask ^ (1 << v)]);
      }
    }
    if (__builtin_popcount(mask) == k) {
      for (int v = 0; v < n; ++v) {
        if ((mask >> v) & 1) {
          ans[v] += cur;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%.18f%c", (double) ans[i], " \n"[i == n - 1]);
  }
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".out", "w", stdout));
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}