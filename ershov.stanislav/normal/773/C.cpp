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

const int maxn = 1e5 + 100;
int n;
ll a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  return true;
}

void solve() {
  vector<ll> bad;
  vector<ll> powers;
  for (int i = 0; i < n; i++) {
    if (!(a[i] & (a[i] - 1))) {
      powers.pb(a[i]);
    } else {
      bad.pb(a[i]);
    }
  }
  vector<ll> ends;
  {
    int now = 0;
    int cnt = 0;
    for (int i = 0; i < sz(powers); ) {
      int i0 = i;
      for (; i < sz(powers) && powers[i] == powers[i0]; i++) ;
      if (powers[i0] != (1ll << now)) {
        printf("-1\n");
        return;
      }
      if (!i0) {
        cnt = i - i0;
      } else {
        for (int j = i - i0; j < cnt; j++) {
          ends.pb(1ll << (now - 1));
        }
        for (int j = cnt; j < i - i0; j++) {
          bad.pb(1ll << now);
        }
        cnt = min(cnt, i - i0);
      }
      now++;
    }
    while (cnt) {
      ends.pb(powers.back());
      cnt--;
    }
  }
  sort(bad.begin(), bad.end());
  reverse(bad.begin(), bad.end());
  /*for (auto i : bad) {
    eprintf("%d ", i);
  }
  eprintf("\n");
  for (auto i : ends) {
    eprintf("%d ", i);
  }
  eprintf("\n");*/
  int res = 0;
  for (auto i : bad) {
    if (!sz(ends) || ends.back() * 2 < i) {
      printf("-1\n");
      return;
    }
    ends.pop_back();
    res++;
  }
  int mx = res + sz(ends);
  int mn;
  {
    int k = 0;
    int s = 0;
    while (k < sz(ends) && sz(ends) - k - 1 >= s + __builtin_ctzll(ends[k]) + 1) {
      s += __builtin_ctzll(ends[k]) + 1;
      k++;
    }
    mn = mx - k;
  }
  for (int i = mn; i <= mx; i++) {
    printf("%d%c", i, " \n"[i == mx]);
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