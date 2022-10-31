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

const int maxn = (int) 1e5 + 100;

int n;
ld mn[maxn], mx[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    double tmp;
    scanf("%lf", &tmp);
    mx[i] = tmp;
  }
  for (int i = 0; i < n; i++) {
    double tmp;
    scanf("%lf", &tmp);
    mn[i] = tmp;
  }
  return true;
}

void solve() {
  vector<ld> a(n + 1), b(n + 1);
  a[n] = 1, b[n] = 1;
  for (int i = 1; i < n; i++) {
    mx[i] += mx[i - 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    mn[i] += mn[i + 1];
  }
  for (int i = 1; i < n; i++) {
    ld c = -(1 + mx[i - 1] - mn[i]);
    ld d = mx[i - 1];
    //eprintf("c = %.18f, d = %.18f\n", (double) c, (double) d);
    ld D = sqrt(max(0.0L, c * c - 4 * d));
    ld x1 = (-c + D) / 2;
    ld x2 = (-c - D) / 2;
    //eprintf("x1 = %.18f, x2 = %.18f\n", (double) x1, (double) x2);
    if (x1 >= a[i - 1] - eps && x2 >= b[i - 1] - eps) {
      a[i] = x1, b[i] = x2;
    } else {
      b[i] = x1, a[i] = x2;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%.18f%c", max(0.0, (double) (a[i + 1] - a[i])), " \n"[i == n - 1]);
  }
  for (int i = 0; i < n; i++) {
    printf("%.18f%c", max(0.0, (double) (b[i + 1] - b[i])), " \n"[i == n - 1]);
  }
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