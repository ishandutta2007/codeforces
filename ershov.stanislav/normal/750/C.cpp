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

const int maxn = 2e5 + 100;
int n;
int c[maxn], d[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", c + i, d + i);
  }
  return true;
}

void solve() {
  int curadd = 0;
  int mx = inf, mn = -inf;
  for (int i = 0; i < n; i++) {
    if (d[i] == 1) {
      mn = max(mn, 1900 - curadd);
    } else {
      mx = min(mx, 1899 - curadd);
    }
    curadd += c[i];
  }
  mx += curadd;
  mn += curadd;
  if (mx < mn) {
    printf("Impossible\n");
  } else {
    if (mx > inf / 2) {
      printf("Infinity\n");
    } else {
      printf("%d\n", mx);
    }
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