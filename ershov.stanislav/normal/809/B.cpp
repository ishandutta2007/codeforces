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

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

int n, k;

set<int> s;

bool read() {
#ifndef DEBUG
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
#else
  n = 2 + rnd(100), k = 2 + rnd(n - 1);
  s.clear();
  while (sz(s) < k) {
    s.insert(1 + rnd(n));
  }
#endif
  return true;
}

bool ask(int x, int y) {
#ifndef DEBUG
  printf("1 %d %d\n", x, y);
  fflush(stdout);
  char s[10];
  scanf("%s", s);
  return !strcmp(s, "TAK");
#else
  int a = inf, b = inf;
  for (auto i : s) {
    a = min(a, abs(i - x));
    b = min(b, abs(i - y));
  }
  return a <= b;
#endif
}

int getany(int l, int r) {
  if (l == r) {
    return l;
  }
  int mid = (r + l) / 2;
  if ((r - l) % 2) {
    if (ask(mid, mid + 1)) {
      return getany(l, mid);
    } else {
      return getany(mid + 1, r);
    }
  } else {
    if (ask(mid - 1, mid + 1)) {
      return getany(l, mid);
    } else {
      return getany(mid + 1, r);
    }
  }
}

void solve() {
  int a = getany(1, n);
  int b = getany(1, max(1, a - 1));
  int c = getany(min(a + 1, n), n);
  if (!ask(a, b)) {
    swap(a, b);
  }
  if (!ask(a, c)) {
    swap(a, c);
  }
  if (!ask(b, c)) {
    swap(b, c);
  }
  if (a != b) {
    printf("2 %d %d\n", a, b);
    assert(a != b);
#ifdef DEBUG
    assert(s.find(a) != s.end());
    assert(s.find(b) != s.end());
#endif
  } else {
    printf("2 %d %d\n", a, c);
    assert(a != c);
#ifdef DEBUG
    assert(s.find(a) != s.end());
    assert(s.find(c) != s.end());
#endif
  }
  fflush(stdout);
}

int main() {
  precalc();

  while (true) {
    read();
    solve();
    exit(0);
  }
#ifdef DEBUG
  eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}