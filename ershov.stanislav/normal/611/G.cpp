#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

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

ll rdtsc() {
  ll ans;
  asm("rdtsc" : "=A"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

struct point {
  ll x, y;

  point (ll x = 0, ll y = 0) : x(x), y(y) { }

  void read() {
    scanf(LLD " " LLD, &x, &y);
  }

  ll operator^(const point & b) const {
    return x * b.y - y * b.x;
  }
};

int n;
vector<point> ps;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  ps.resize(n);
  for (int i = 0; i < n; i++) {
    ps[i].read();
  }
  reverse(ps.begin(), ps.end());
  return true;
}

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  int ans = a + b;
  if (ans >= MOD) {
    ans -= MOD;
  }
  return ans;
}

int mult(int a, int b) {
  return (ll) a * b % MOD;
}

void solve() {
  for (int i = 0; i < n; i++) {
    ps.pb(ps[i]);
  }
  vector<point> was = ps;
  vector<ll> sumpref(2 * n);
  vector<point> pointsum(2 * n + 1);
  for (int i = 0; i < 2 * n - 1; i++) {
    sumpref[i + 1] = sumpref[i] + (ps[i] ^ ps[i + 1]);
  }
  for (int i = 0; i < 2 * n; i++) {
    ps[i].x = (ps[i].x % MOD + MOD) % MOD;
    ps[i].y = (ps[i].y % MOD + MOD) % MOD;
  }
  for (int i = 0; i < 2 * n; i++) {
    pointsum[i + 1].x = add(pointsum[i].x, ps[i].x);
    pointsum[i + 1].y = add(pointsum[i].y, ps[i].y);
  }
  vector<int> sumsuf(2 * n), sumsumsuf(2 * n + 1);
  for (int i = 2 * n - 2; i >= 0; i--) {
    sumsuf[i] = add(sumsuf[i + 1], add(mult(ps[i].x, ps[i + 1].y), MOD - mult(ps[i].y, ps[i + 1].x)));
  }
  for (int i = 2 * n - 1; i >= 0; i--) {
    sumsumsuf[i] = add(sumsumsuf[i + 1], sumsuf[i]);
  }
  /*eprintf("sumsuf: ");
  for (int i = 0; i < 2 * n; i++) {
    eprintf("%d%c", sumsuf[i], " \n"[i == 2 * n - 1]);
  }
  eprintf("sumsumsuf: ");
  for (int i = 0; i < 2 * n; i++) {
    eprintf("%d%c", sumsumsuf[i], " \n"[i == 2 * n - 1]);
  }*/
  ll area = sumpref[n];
  int ans = 0;
  for (int i = 0, j = 1; i < n; i++) {
    while (sumpref[j + 1] - sumpref[i] + (was[j + 1] ^ was[i]) <= area / 2) {
      j++;
    }
    //eprintf("i = %d, j = %d\n", i, j);
    point tomult(add(pointsum[j + 1].x, MOD - pointsum[i + 1].x), add(pointsum[j + 1].y, MOD - pointsum[i + 1].y));
    tomult.x = add(tomult.x, MOD - add(pointsum[i + n].x, MOD - pointsum[j + 1].x));
    tomult.y = add(tomult.y, MOD - add(pointsum[i + n].y, MOD - pointsum[j + 1].y));
    ans = add(ans, mult(2, add(mult(ps[i].x, tomult.y), MOD - mult(ps[i].y, tomult.x))));
    //eprintf("ans = %d\n", ans);
    int cnti = -(j + 1 - (i + 1)) + (i + n - 1 + 1 - (j + 1));
    cnti = (cnti % MOD + MOD) % MOD;
    ans = add(ans, mult(2, add(sumsumsuf[i], MOD - sumsumsuf[j])));
    ans = add(ans, mult(2, MOD - mult(sumsuf[j], j - i)));
    ans = add(ans, mult(add(cnti, MOD - 2), add(sumsuf[i], MOD - sumsuf[j])));
    //eprintf("ans = %d\n", ans);

    int cntj = (n - 1);
    cntj = (cntj % MOD + MOD) % MOD;
    ans = add(ans, mult(MOD - 2, add(sumsumsuf[j], MOD - sumsumsuf[i + n])));
    ans = add(ans, mult(MOD - 2, MOD - mult(sumsuf[i + n], i + n - j)));
    ans = add(ans, mult(add(cntj, 2), add(sumsuf[j], MOD - sumsuf[i + n])));
    //eprintf("ans = %d\n", ans);
    //eprintf("cnti = %d, cntj = %d\n", cnti, cntj);
  }
  ans = add(ans, MOD - mult(area % MOD, n * 2));
  printf("%d\n", mult(ans, (MOD + 1) / 2));
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}