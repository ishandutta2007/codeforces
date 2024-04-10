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

int n;
vector<vector<int> > tree;

const int maxn = 1e5 + 100;
int c[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree = vector<vector<int> >(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  return true;
}

int cols[maxn];

void dfs(int v, int p) {
  int col = c[v];
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    dfs(to, v);
    int cur = cols[to];
    if (cur == -1) {
      col = -1;
    }
    if (col != cur) {
      col = -1;
    }
  }
  cols[v] = col;
}

int ans;

void dfs2(int v, int p, int pc) {
  bool ok = true;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    if (cols[to] == -1) {
      ok = false;
    }
  }
  if (ok) {
    ans = v;
    return;
  }
  if (c[v] != pc && pc != -1) {
    return;
  }
  pc = c[v];
  int cntbad = 0;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    if (pc != cols[to]) {
      cntbad++;
    }
  }
  if (cntbad == 1) {
    for (int i = 0; i < sz(tree[v]); i++) {
      int to = tree[v][i];
      if (to == p) {
        continue;
      }
      if (pc != cols[to]) {
        dfs2(to, v, pc);
      }
    }
  }
}

void solve() {
  ans = -1;
  dfs(0, -1);
  /*for (int i = 0; i < n; i++) {
    eprintf("%d%c", cols[i], " \n"[i == n - 1]);
  }*/
  dfs2(0, -1, -1);
  if (ans == -1) {
    printf("NO\n");
  } else {
    printf("YES\n");
    printf("%d\n", ans + 1);
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