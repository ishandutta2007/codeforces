#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
const ld eps = 1e-11;
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

struct point {
  ld x, y;

  point (ld x = 0, ld y = 0) : x(x), y(y) {}

  bool read() {
    double a, b;
    if (scanf("%lf%lf", &a, &b) < 2) {
      return false;
    }
    x = a, y = b;
    return true;
  }

  point operator-(const point & b) const {
    return point(x - b.x, y - b.y);
  }

  ld slen() const {
    return x * x + y * y;
  }

  ld len() const {
    return sqrt(slen());
  }
};

const int maxn = 5e5 + 100;
int n, k;
int c[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  return true;
}

void solve() {
  int l = 0, r = 1e9 + 10;
  ll sumall = 0;
  for (int i = 0; i < n; i++) {
    sumall += c[i];
  }
  k = min((ll) k, sumall);
  {
    while (l < r - 1) {
      int mid = (l + r) / 2;
      ll cursum = 0;
      for (int i = 0; i < n; i++) {
        cursum += max(0, c[i] - mid);
      }
      if (cursum < k) {
        r = mid;
      } else {
        l = mid;
      }
    }
  }
  ll cursum = 0;
  for (int i = 0; i < n; i++) {
    cursum += max(0, c[i] - l);
    c[i] = min(c[i], l);
  }
  for (int i = 0; i < n; i++) {
    if (c[i] == l && cursum > k) {
      c[i]++;
      cursum--;
    }
  }
  {
    l = 0, r = 1e9 + 10;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      ll cursum = 0;
      for (int i = 0; i < n; i++) {
        cursum += max(0, mid - c[i]);
      }
      if (cursum > k) {
        r = mid;
      } else {
        l = mid;
      }
    }
  }
  cursum = 0;
  for (int i = 0; i < n; i++) {
    cursum += max(0, l - c[i]);
    c[i] = max(c[i], l);
  }
  for (int i = 0; i < n; i++) {
    if (c[i] == l && cursum < k) {
      c[i]++;
      cursum++;
    }
  }
  {
    int mn = 1e9 + 10, mx = 0;
    for (int i = 0; i < n; i++) {
      mn = min(mn, c[i]);
      mx = max(mx, c[i]);
    }
    printf("%d\n", mx - mn);
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