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
vector<vector<int> > tree;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree.clear();
  tree.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  return true;
}

int cnt;

int used[maxn], maxu, cols[maxn];

void dfs(int v, int p) {
  maxu++;
  used[cols[v]] = maxu;
  if (p != -1) {
    used[cols[p]] = maxu;
  }
  int j = 0;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    while (used[j] == maxu) {
      j++;
    }
    assert(j < cnt);
    cols[to] = j++;
  }
  for (auto to : tree[v]) {
    if (to == p) {
      continue;
    }
    dfs(to, v);
  }
}

void solve() {
  cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt = max(cnt, sz(tree[i]) + 1);
  }
  cols[0] = 0;
  dfs(0, -1);
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++) {
    printf("%d%c", cols[i] + 1, " \n"[i == n - 1]);
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