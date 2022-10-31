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

const int maxn = 1.1e5;
point a, b, t;
point ps[maxn];
int n;

bool read() {
  if (!a.read()) {
    return false;
  }
  b.read();
  t.read();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  return true;
}

void solve() {
  ld res = 0;
  for (int i = 0; i < n; i++) {
    res += 2 * (ps[i] - t).len();
  }
  //eprintf("%.18f\n", (double) res);
  vector<ld> d1(n), d2(n);
  for (int i = 0; i < n; i++) {
    d1[i] = (ps[i] - a).len() - (ps[i] - t).len();
    d2[i] = (ps[i] - b).len() - (ps[i] - t).len();
  }
  int mn1 = -1, mn2 = -1;
  for (int i = 0; i < n; i++) {
    if (mn1 == -1 || d1[i] < d1[mn1]) {
      mn1 = i;
    }
    if (mn2 == -1 || d2[i] < d2[mn2]) {
      mn2 = i;
    }
  }
  if (mn1 == mn2) {
    int nmn1 = -1, nmn2 = -1;
    for (int i = 0; i < n; i++) {
      if ((i != mn1) && (nmn1 == -1 || d1[i] < d1[nmn1])) {
        nmn1 = i;
      }
      if ((i != mn2) && (nmn2 == -1 || d2[i] < d2[nmn2])) {
        nmn2 = i;
      }
    }
    //eprintf("%d %d\n", nmn1, nmn2);
    ld nres = min(res + d1[mn1], res + d2[mn2]);
    if (nmn1 != -1) {
      nres = min(nres, res + d2[mn2] + d1[nmn1]);
    }
    if (nmn2 != -1) {
      nres = min(nres, res + d1[mn1] + d2[nmn2]);
    }
    res = nres;
  } else {
    ld res2 = res;
    res2 += d1[mn1];
    res2 += d2[mn2];
    res2 = min(min(res2, res + d1[mn1]), res + d2[mn2]);
    res = res2;
  }
  printf("%.18f\n", (double) res);
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