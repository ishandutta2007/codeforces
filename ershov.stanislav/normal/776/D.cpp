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

int n, m;
int r[maxn];

int have[maxn];

vector<vector<pair<int, int> > > g;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", r + i);
  }
  g.clear();
  g.resize(m);
  memset(have, -1, sizeof(have));
  for (int j = 0; j < m; j++) {
    int x;
    scanf("%d", &x);
    for (int k = 0; k < x; k++) {
      int cur;
      scanf("%d", &cur);
      cur--;
      if (have[cur] == -1) {
        have[cur] = j;
      } else {
        int a = have[cur], b = j;
        g[a].pb(mp(b, !r[cur]));
        g[b].pb(mp(a, !r[cur]));
      }
    }
  }
  return true;
}

bool ok;
int cols[maxn];

void dfs(int v, int col) {
  if (cols[v] != -1) {
    if (cols[v] != col) {
      ok = false;
    }
    return;
  }
  cols[v] = col;
  for (auto i : g[v]) {
    dfs(i.first, col ^ i.second);
  }
}

void solve() {
  ok = true;
  memset(cols, -1, sizeof(cols));
  for (int i = 0; i < m; i++) {
    if (cols[i] == -1) {
      dfs(i, 0);
    }
  }
  printf(ok ? "YES\n" : "NO\n");
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