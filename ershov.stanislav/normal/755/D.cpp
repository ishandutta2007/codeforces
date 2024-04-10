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

const int maxn = 1e6 + 100;
int n, k;

int fenw[maxn];

void add(int i) {
  for (; i < maxn; i |= (i + 1)) {
    fenw[i]++;
  }
}

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fenw[i];
  }
  return res;
}

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

void solve() {
  memset(fenw, 0, sizeof(fenw));
  ll sum = 1;
  for (int i = 0, cur = 0; i < n; i++) {
    int w = min(k, n - k);
    int a = cur - w + 1;
    int b = cur + w - 1;
    a = (a % n + n) % n;
    b = (b % n + n) % n;
    if (a < b) {
      int res = 0;
      res = get(b);
      if (a) {
        res -= get(a - 1);
      }
      sum += res + 1;
    } else {
      int res = get(n - 1);
      if (a) {
        res -= get(a - 1);
      }
      res += get(b);
      sum += res + 1;
    }
    add(cur);
    cur = (cur + k) % n;
    printf("%lld%c", sum, " \n"[i == n - 1]);
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