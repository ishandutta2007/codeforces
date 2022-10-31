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
ll a, b, h, w;
int n;

int tomult[maxn];

bool read() {
  if (scanf("%lld%lld%lld%lld%d", &a, &b, &h, &w, &n) < 5) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", tomult + i);
  }
  return true;
}

vector<pair<int, int> > v;

bool can;
ll curh, curw;

void dfs(int pos) {
  if (pos == sz(v)) {
    if (curh >= a && curw >= b) {
      can = true;
    }
    if (curh >= b && curw >= a) {
      can = true;
    }
    return;
  }
  ll wash = curh;
  ll wasw = curw;
  for (int i = 0; i <= v[pos].second; i++) {
    for (int j = 0; j < i; j++) {
      curh *= v[pos].first;
      curh = min(curh, (ll) maxn);
    }
    for (int j = 0; j < v[pos].second - i; j++) {
      curw *= v[pos].first;
      curw = min(curw, (ll) maxn);
    }
    dfs(pos + 1);
    curh = wash;
    curw = wasw;
  }
}

void solve() {
  sort(tomult, tomult + n, greater<int> ());
  map<int, int> tree;
  for (int i = 0; i <= n; i++) {
    curh = h, curw = w;
    can = false;
    v.clear();
    for (auto j : tree) {
      v.pb(j);
    }
    dfs(0);
    if (can) {
      printf("%d\n", i);
      return;
    }
    if (i < n) {
      tree[tomult[i]]++;
    }
  }
  printf("-1\n");
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