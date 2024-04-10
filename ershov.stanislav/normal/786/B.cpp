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

const int maxn = 1 << 20;

int n0, q, s;

bool read() {
  if (scanf("%d%d%d", &n0, &q, &s) < 3) {
    return false;
  }
  s--;
  return true;
}

int n;

vector<vector<pair<int, int> > > g;

void add1(int v, int vl, int vr, int l, int r, int to, int cost) {
  if (vr <= l || r <= vl) {
    return;
  }
  if (l <= vl && vr <= r) {
    g[to + 3 * n].pb(mp(v, cost));
  } else {
    int mid = (vl + vr) / 2;
    add1(v * 2, vl, mid, l, r, to, cost);
    add1(v * 2 + 1, mid, vr, l, r, to, cost);
  }
}

void add2(int v, int vl, int vr, int l, int r, int to, int cost) {
  if (vr <= l || r <= vl) {
    return;
  }
  if (l <= vl && vr <= r) {
    g[v + 2 * n].pb(mp(to + n, cost));
  } else {
    int mid = (vl + vr) / 2;
    add2(v * 2, vl, mid, l, r, to, cost);
    add2(v * 2 + 1, mid, vr, l, r, to, cost);
  }
}

void solve() {
  for (n = 1; n < n0; n <<= 1);
  g.clear();
  g.resize(n * 4);
  for (int i = 0; i < n; i++) {
    g[i + n].pb(mp(i + 3 * n, 0));
    g[i + 3 * n].pb(mp(i + n, 0));
  }
  for (int i = 1; i < n; i++) {
    g[i].pb(mp(i * 2, 0));
    g[i].pb(mp(i * 2 + 1, 0));
    g[i * 2 + 2 * n].pb(mp(i + 2 * n, 0));
    g[i * 2 + 1 + 2 * n].pb(mp(i + 2 * n, 0));
  }
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, u, w;
      scanf("%d %d %d", &v, &u, &w);
      v--, u--;
      g[v + n].pb(mp(u + n, w));
    } else {
      int v, l, r, w;
      scanf("%d%d%d%d", &v, &l, &r, &w);
      v--, l--;
      if (t == 2) {
        add1(1, 0, n, l, r, v, w);
      } else {
        add2(1, 0, n, l, r, v, w);
      }
    }
  }
  vector<ll> dist(4 * n, 1e18);
  dist[s + n] = 0;
  set<pair<ll, int> > tree;
  tree.insert(mp(0, s + n));
  while (sz(tree)) {
    auto cur = tree.begin()->second;
    tree.erase(tree.begin());
    for (auto to : g[cur]) {
      ll ndist = dist[cur] + to.second;
      if (ndist < dist[to.first]) {
        tree.erase(mp(dist[to.first], to.first));
        dist[to.first] = ndist;
        tree.insert(mp(dist[to.first], to.first));
      }
    }
  }
  for (int i = 0; i < n0; i++) {
    printf("%lld%c", dist[i + n] == 1e18 ? -1 : dist[i + n], " \n"[i == n0 - 1]);
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