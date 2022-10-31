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

void precalc() {
}

const int maxn = 1e4 + 100;
int n, c;
int p[maxn], s[maxn];

bool read() {
  if (scanf("%d%d", &n, &c) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", s + i);
  }
  return true;
}

ll dp[maxn], pdp[maxn];

void solve() {
  dp[0] = 0;
  for (int i = n - 1; i >= 0; i--) {
    swap(dp, pdp);
    for (int cnt = 0; cnt <= n - i; cnt++) {
      ll & cur = dp[cnt];
      cur = 1e18;
      if (cnt < n - i) {
        cur = min(cur, pdp[cnt] + p[i]);
      }
      if (cnt) {
        cur = min(cur, pdp[cnt - 1] + s[i] + (ll) (n - i - cnt) * c);
      }
      //eprintf("%lld%c", cur, " \n"[cnt == n - i]);
    }
  }
  ll res = 1e18;
  for (int i = 0; i <= n; i++) {
    res = min(res, dp[i]);
  }
  printf("%lld\n", res);
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