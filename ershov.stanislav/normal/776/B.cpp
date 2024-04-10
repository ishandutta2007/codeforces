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

const int maxn = 1e6;

bool isprime[maxn];

void precalc() {
  for (int i = 2; i < maxn; i++) {
    isprime[i] = true;
  }
  for (int i = 2; i * i < maxn; i++) {
    if (!isprime[i]) {
      continue;
    }
    for (int j = i * i; j < maxn; j += i) {
      isprime[j] = false;
    }
  }
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  if (n == 1) {
    printf("1\n1\n");
    return;
  }
  if (n == 2) {
    printf("1\n1 1\n");
    return;
  }
  printf("2\n");
  for (int i = 2; i <= n + 1; i++) {
    printf("%d%c", isprime[i] ? 1 : 2, " \n"[i == n + 1]);
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
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}