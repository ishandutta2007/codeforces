#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

const int maxn = 5e5;
int n, a, b;
int x[maxn], y[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &a, &b) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  return true;
}

void solve() {
  ld mn = 1e18, mx = 0;
  for (int i = 0; i < n; i++) {
    ld cur = (ll) (x[i] - a) * (x[i] - a) + (ll) (y[i] - b) * (y[i] - b);
    mn = min(mn, cur);
    mx = max(mx, cur);
  }
  x[n] = x[0];
  y[n] = y[0];
  for (int i = 0; i < n; i++) {
    ld cur = (ll) (x[i] - a) * (y[i + 1] - b) - (ll) (y[i] - b) * (x[i + 1] - a);
    cur = abs(cur / sqrt((ll) (x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (ll) (y[i] - y[i + 1]) * (y[i] - y[i + 1])));
    ll c = (ll) (a - x[i]) * (x[i + 1] - x[i]) + (ll) (b - y[i]) * (y[i + 1] - y[i]);
    ll d = (ll) (a - x[i + 1]) * (x[i + 1] - x[i]) + (ll) (b - y[i + 1]) * (y[i + 1] - y[i]);
    if (c >= 0 && d <= 0) {
      mn = min(mn, cur * cur);
      mx = max(mx, cur * cur);
    }
  }
  printf("%.18f\n", (double) ((mx - mn) * pi));
}

int main() {
  srand(rdtsc());
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