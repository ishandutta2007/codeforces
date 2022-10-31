#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

ll gcdExt(ll a, ll b, ll & x, ll & y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll k = a / b;
  ll res = gcdExt(b, a % b, y, x);
  y -= k * x;
  return res;
}

ll gcd(ll a, ll b) {
  return (b == 0) ? a : gcd(b, a % b);
}

void precalc() {
}

ll n, m, k;

bool read() {
  if (scanf("%lld%lld%lld", &n, &m, &k) < 3) {
    return false;
  }
  return true;
}

void solve() {
  ll lcm = n / gcd(n, m) * m;
  ll g = gcd(2 * n, 2 * m);
  for (int i = 0; i < k; i++) {
    ll x, y;
    scanf("%lld%lld", &x, &y);
    ll mn = 1e18;
    for (int mask = 0; mask < 4; mask++) {
      ll curx = (mask & 1) ? x : 2 * n - x;
      ll cury = (mask & 2) ? y : 2 * m - y;
      if (curx % g != cury % g) {
        continue;
      }
      ll a, b;
      gcdExt(2 * n, 2 * m, a, b);
      a += 2 * m / g;
      a %= 2 * m / g;
      ll toadd = 2 * n * a;
      toadd %= 2 * n / g * 2 * m;
      ll t = curx;
      ll want = ((cury - curx) % (2 * m) + 2 * m) % (2 * m);
      t += want / g * toadd;
      t %= 2 * n / g * 2 * m;
      mn = min(mn, t);
    }
    if (mn > lcm) {
      printf("-1\n");
    } else {
      printf("%lld\n", mn);
    }
  }
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