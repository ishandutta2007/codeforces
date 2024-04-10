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

const int maxn = 2e5 + 100;

int n;
int p[maxn], a[maxn], b[maxn];
int m;
int c[maxn];

set<pair<int, int> > ids[3];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int it = 0; it < 3; it++) {
    ids[it].clear();
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ids[a[i] - 1].insert(mp(p[i], i));
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    ids[b[i] - 1].insert(mp(p[i], i));
  }
  return true;
}

int used[maxn];

void solve() {
  memset(used, 0, sizeof(used));
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int cur;
    scanf("%d", &cur);
    cur--;
    while (true) {
      if (!sz(ids[cur])) {
        break;
      }
      if (used[ids[cur].begin()->second]) {
        ids[cur].erase(ids[cur].begin());
      } else {
        break;
      }
    }
    if (!sz(ids[cur])) {
      printf("-1\n");
    } else {
      int res = ids[cur].begin()->first;
      used[ids[cur].begin()->second] = 1;
      ids[cur].erase(ids[cur].begin());
      printf("%d%c", res, " \n"[i == m - 1]);
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