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

const int p[2] = {(int) 1e9 + 7, (int) 1e9 + 9};

struct Hash {
  const static int n = 2;

  int a[n];

  Hash(int x = 0) {
    for (int i = 0; i < n; i++) {
      a[i] = x % p[i];
    }
  }

  Hash operator+(const Hash & b) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = a[i] + b.a[i];
      if (res.a[i] > p[i]) {
        res.a[i] -= p[i];
      }
    }
    return res;
  }

  Hash operator-(const Hash & b) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = a[i] - b.a[i];
      if (res.a[i] < 0) {
        res.a[i] += p[i];
      }
    }
    return res;
  }

  Hash operator*(const Hash & b) const {
    Hash res;
    for (int i = 0; i < n; i++) {
      res.a[i] = (ll) a[i] * b.a[i] % p[i];
    }
    return res;
  }

  bool operator<(const Hash & b) const {
    for (int i = 0; i < n; i++) {
      if (a[i] != b.a[i]) {
        return a[i] < b.a[i];
      }
    }
    return false;
  }

  bool operator==(const Hash & b) const {
    for (int i = 0; i < n; i++) {
      if (a[i] != b.a[i]) {
        return false;
      }
    }
    return true;
  }
};

const int maxn = 1e6;

Hash P;
Hash ps[maxn];

void precalc() {
  P = 239017 + rnd(1000);
  ps[0] = 1;
  for (int i = 1; i < maxn; i++) {
    ps[i] = ps[i - 1] * P;
  }
}

int n;
vector<vector<int> > tree;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree = vector<vector<int> > (n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  return true;
}

typedef pair<Hash, int> magic;

magic operator+(const magic & a, const magic & b) {
  return mp(a.first * ps[b.second] + b.first, a.second + b.second);
}

magic hv[maxn];

void dfs0(int v, int p) {
  vector<magic> tosort;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    dfs0(to, v);
    tosort.pb(hv[to]);
  }
  sort(tosort.begin(), tosort.end());
  magic ans = mp('(', 1);
  for (auto i : tosort) {
    ans = ans + i;
  }
  ans = ans + mp(')', 1);
  hv[v] = ans;
}

map<Hash, int> cnts;
int all;

void add(magic cur) {
  cnts[cur.first]++;
  if (cnts[cur.first] == 1) {
    all++;
  }
}

void del(magic cur) {
  cnts[cur.first]--;
  if (cnts[cur.first] == 0) {
    all--;
  }
}

pair<int, int> ans;

void solve(int v, int p, magic ph) {
  ans = max(ans, mp(all, v));
  vector<magic> tosort(1, ph);
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    tosort.pb(hv[to]);
  }
  sort(tosort.begin(), tosort.end());
  vector<magic> left, right;
  left.pb(mp(Hash('('), 1));
  for (int i = 0; i < sz(tosort); i++) {
    left.pb(left.back() + tosort[i]);
  }
  right.pb(mp(Hash(')'), 1));
  for (int i = sz(tosort) - 1; i >= 0; i--) {
    right.pb(tosort[i] + right.back());
  }
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == p) {
      continue;
    }
    int pos = (int) (lower_bound(tosort.begin(), tosort.end(), hv[to]) - tosort.begin());
    magic cur = left[pos] + right[sz(tosort) - 1 - pos];
    del(hv[v]);
    add(cur);
    solve(to, v, cur);
    del(cur);
    add(hv[v]);
  }
}

void solve() {
  dfs0(0, -1);
  cnts.clear();
  for (int i = 0; i < n; i++) {
    cnts[hv[i].first]++;
  }
  all = sz(cnts);
  ans = mp(0, 0);
  solve(0, -1, mp(Hash(0), 0));
  printf("%d\n", ans.second + 1);
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