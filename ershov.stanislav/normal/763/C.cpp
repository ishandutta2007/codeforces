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

int mod = (int) 1e9 + 7;

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

int root(int a) {
  vector<int> primes;
  int m = mod - 1;
  for (int i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) {
        m /= i;
      }
      primes.pb(i);
    }
  }
  if (m > 1) {
    primes.pb(m);
  }
  int root = -1;
  for (int i = 2; ; i++) {
    bool ok = true;
    for (auto p : primes) {
      if (power(i, (mod - 1) / p) == 1) {
        ok = false;
      }
    }
    if (ok) {
      root = i;
      break;
    }
  }
  vector<pair<int, int> > tosort;
  for (int i = 0, cur = 1; i < 1e5; i++) {
    tosort.pb(mp(cur, i));
    cur = mult(cur, root);
  }
  sort(tosort.begin(), tosort.end());
  int tomult = power(root, (int) 1e5);
  tomult = power(tomult, mod - 2);
  for (int i = 0, cur = a; i < 1e5; i++) {
    int j = (int) (lower_bound(tosort.begin(), tosort.end(), mp(cur, -1)) - tosort.begin());
    if (j == sz(tosort) || tosort[j].first != cur) {
      cur = mult(cur, tomult);
      continue;
    }
    return power(root, (tosort[j].second + (ll) i * 1e5) / 2);
  }
  return 1;
}

void precalc() {
}

const int maxn = 1e5 + 100;
int n;
int a[maxn];

bool read() {
  if (scanf("%d%d", &mod, &n) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void solve() {
  sort(a, a + n);
  if (n == mod) {
    printf("0 1\n");
    return;
  }
  if (n % mod == 0) {
    printf("-1\n");
    return;
  }
  if (mod == 2) {
    printf("%d 1\n", a[0]);
    return;
  }
  int suma = 0, sumsq = 0;;
  for (int i = 0; i < n; i++) {
    add(suma, a[i]);
    add(sumsq, mult(a[i], a[i]));
  }
  int x = mult(suma, power(n, mod - 2));
  if (n == mod - 1) {
    for (int i = 0; i < mod; i++) {
      if (!binary_search(a, a + n, i)) {
        printf("%d %d\n", sum(i, 1), 1);
        return;
      }
    }
  }
  if (n % 2 == 1) {
    int cur = 0;
    for (int i = 1; i <= n / 2; i++) {
      add(cur, mult(i, i));
    }
    cur = mult(cur, 2);
    int r = mult(n, mult(x, x));
    int d = mult(sum(sumsq, mod - r), power(cur, mod - 2));
    eprintf("d = %d\n", d);
    d = root(d);
    eprintf("d = %d\n", d);
    add(x, mult(mod - d, n / 2));
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int cur = sum(x, mult(d, i));
      if (!binary_search(a, a + n, cur)) {
        ok = false;
      }
    }
    if (!ok) {
      printf("-1\n");
    } else {
      printf("%d %d\n", x, d);
    }
  } else {
    int cur = 0;
    for (int i = 1; i <= n - 1; i += 2) {
      add(cur, mult(i, i));
    }
    cur = mult(cur, 2);
    int r = mult(n, mult(x, x));
    int d = mult(sum(sumsq, mod - r), power(cur, mod - 2));
    d = root(d);
    add(x, mult(mod - d, n - 1));
    d = mult(d, 2);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int cur = sum(x, mult(d, i));
      if (!binary_search(a, a + n, cur)) {
        ok = false;
      }
    }
    if (!ok) {
      printf("-1\n");
    } else {
      printf("%d %d\n", x, d);
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
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}