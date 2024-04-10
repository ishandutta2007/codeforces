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

const int mod = 1e9 + 7;

void add(int & a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

int power(int a, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, a);
    }
    a = mult(a, a);
    p >>= 1;
  }
  return res;
}

int inv2, inv3;

void precalc() {
  inv3 = power(3, mod - 2);
  inv2 = power(2, mod - 2);
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int res1 = 2, res2 = mod - 1;
  for (int i = 0; i < n; i++) {
    ll a;
    scanf("%lld", &a);
    res1 = power(res1, a);
    res2 = power(res2, a);
  }
  res1 = mult(res1, inv2);
  add(res2, res1);
  res2 = mult(res2, inv3);
  printf("%d/%d\n", res2, res1);
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