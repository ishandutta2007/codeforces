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

int n, m, k;

vector<vector<int> > g;

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  g.clear();
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  return true;
}

int used[maxn];
vector<int> ans;

void dfs(int v) {
  used[v] = 1;
  for (auto to : g[v]) {
    if (used[to]) {
      continue;
    }
    ans.pb(to);
    dfs(to);
    ans.pb(v);
  }
}

void solve() {
  ans.clear();
  memset(used, 0, sizeof(used));
  ans.pb(0);
  dfs(0);
  int j = 0;
  int mx = (2 * n + k - 1) / k;
  for (int i = 0; i < k; i++) {
    vector<int> cur;
    for (int it = 0; it < mx && j < sz(ans); it++, j++) {
      cur.pb(ans[j]);
    }
    if (!sz(cur)) {
      cur.pb(0);
    }
    printf("%d", sz(cur));
    for (auto i : cur) {
      printf(" %d", i + 1);
    }
    printf("\n");
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