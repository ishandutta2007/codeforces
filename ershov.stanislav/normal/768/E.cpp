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

void precalc() {
}

map<pair<int, ll>, int> m;

int getdp(int a, ll mask) {
  if (a == 0) {
    return 0;
  }
  if (m.find(mp(a, mask)) != m.end()) {
    return m[mp(a, mask)];
  }
  vector<int> used(a + 1);
  for (int i = 1; i <= a; i++) {
    if (mask & (1ll << i)) {
      continue;
    }
    ll curmask = mask | (1ll << i);
    used[getdp(a - i, curmask)] = 1;
  }
  for (int i = 0; i < sz(used); i++) {
    if (used[i] == 0) {
      return m[mp(a, mask)] = i;
    }
  }
  assert(0);
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    int cur;
    scanf("%d", &cur);
    res ^= getdp(cur, 0);
  }
  if (res) {
    printf("NO\n");
  } else {
    printf("YES\n");
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