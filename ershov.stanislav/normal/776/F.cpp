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

const int maxn = 5e5 + 100;

int from[maxn], to[maxn], cnte;
vector<vector<int> > in;

void adde(int u, int v) {
  from[cnte] = u;
  to[cnte] = v;
  in[v].pb(cnte);
  cnte++;
  from[cnte] = v;
  to[cnte] = u;
  in[u].pb(cnte);
  cnte++;
}

int n, m;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  cnte = 0;
  in.clear();
  in.resize(n);
  for (int i = 0; i < n; i++) {
    adde(i, (i + 1) % n);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adde(u, v);
  }
  return true;
}

#define rank mrank

int par[maxn], rank[maxn];

int getpar(int v) {
  if (par[v] == v) {
    return v;
  } else {
    return par[v] = getpar(par[v]);
  }
}

void myUnion(int a, int b) {
  a = getpar(a);
  b = getpar(b);
  if (a == b) {
    return;
  }
  if (rank[a] == rank[b]) {
    rank[a]++;
  }
  if (rank[a] < rank[b]) {
    swap(a, b);
  }
  par[b] = a;
}

struct mycomp {
  int center;

  mycomp(int center = 0) : center(center) {}

  bool operator() (const int & a, const int & b) const {
    int c = ((center - from[a]) % n + n) % n;
    int d = ((center - from[b]) % n + n) % n;
    return c < d;
  }
};

int used[maxn];

vector<vector<int> > tree;
int ans[maxn], cnt[maxn];

void getcnt(int v, int par) {
  cnt[v] = 1;
  for (auto to : tree[v]) {
    if (to == par) {
      continue;
    }
    if (used[to]) {
      continue;
    }
    getcnt(to, v);
    cnt[v] += cnt[to];
  }
}

void solve(int v, int depth = 0) {
  getcnt(v, -1);
  int all = cnt[v];
  while (true) {
    int mxi = -1;
    for (auto to : tree[v]) {
      if (used[to]) {
        continue;
      }
      if (cnt[to] < cnt[v] && (mxi == -1 || cnt[mxi] < cnt[to])) {
        mxi = to;
      }
    }
    if (mxi != -1 && cnt[mxi] * 2 > all) {
      v = mxi;
    } else {
      break;
    }
  }
  used[v] = 1;
  ans[v] = depth;
  for (auto to : tree[v]) {
    if (!used[to]) {
      solve(to, depth + 1);
    }
  }
}

void solve() {
  for (int i = 0; i < cnte; i++) {
    par[i] = i;
    rank[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    sort(in[i].begin(), in[i].end(), mycomp(i));
    for (int j = 0; j + 1 < sz(in[i]); j++) {
      int a = in[i][j];
      int b = in[i][j + 1] ^ 1;
      myUnion(a, b);
    }
  }
  memset(used, 0, sizeof(used));
  tree.clear();
  tree.resize(2 * (n + m));
  for (int i = 2 * n; i < 2 * (n + m); i += 2) {
    int u = getpar(i), v = getpar(i ^ 1);
    tree[u].pb(v);
    tree[v].pb(u);
    //eprintf("%d %d\n", u, v);
  }
  solve(in[0][0]);
  memset(used, 0, sizeof(used));
  vector<int> toprint;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j + 1 < sz(in[i]); j++) {
      int a = getpar(in[i][j]);
      if (used[a]) {
        continue;
      }
      toprint.pb(ans[a] + 1);
      used[a] = 1;
    }
  }
  reverse(toprint.begin(), toprint.end());
  assert(sz(toprint));
  for (int i = 0; i < sz(toprint); i++) {
    printf("%d%c", toprint[i], " \n"[i == sz(toprint) - 1]);
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