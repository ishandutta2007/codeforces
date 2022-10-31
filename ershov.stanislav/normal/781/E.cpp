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

const int inf = (int) 2.01e9;
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

const int maxn = 3e5 + 100;

vector<pair<int, int> > tree[maxn * 4];
int mn[maxn * 4];

void add(int v, int vl, int vr, int pos, int h, int val) {
  if (vl > pos || vr <= pos) {
    return;
  }
  if (vl == vr - 1) {
    tree[v].pb(mp(h, val));
    mn[v] = h;
  } else {
    int mid = (vl + vr) / 2;
    add(v * 2, vl, mid, pos, h, val);
    add(v * 2 + 1, mid, vr, pos, h, val);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
  }
}

int get(int v, int vl, int vr, int l, int r, int mx) {
  if (vr <= l || r <= vl) {
    return 0;
  }
  if (mn[v] > mx) {
    return 0;
  }
  int mid = (vl + vr) / 2;
  if (vl == vr - 1) {
    int res = 0;
    while (sz(tree[v]) && tree[v].back().first <= mx) {
      add(res, tree[v].back().second);
      tree[v].pop_back();
    }
    if (sz(tree[v])) {
      mn[v] = tree[v].back().first;
    } else {
      mn[v] = inf;
    }
    return res;
  }
  int res = sum(get(v * 2, vl, mid, l, r, mx), get(v * 2 + 1, mid, vr, l, r, mx));
  mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
  return res;
}

int h, w, n;
int u[maxn], l[maxn], r[maxn], s[maxn];

bool read() {
  if (scanf("%d%d%d", &h, &w, &n) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", u + i, l + i, r + i, s + i);
    l[i]--;
  }
  return true;
}

void solve() {
  for (int i = 0; i < 4 * maxn; i++) {
    mn[i] = inf;
  }
  vector<pair<int, int> > tosort;
  for (int i = 0; i < n; i++) {
    tosort.pb(mp(u[i], i));
  }
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i < w; i++) {
    add(1, 0, w, i, h + 1, 1);
  }
  for (int i = sz(tosort) - 1; i >= 0; i--) {
    int curi = tosort[i].second;
    int curl = l[curi];
    int curr = r[curi];
    int mx = u[curi] + s[curi];
    int down = get(1, 0, w, curl, curr, mx);
    if (curl) {
      add(1, 0, w, curl - 1, u[curi], down);
    } else {
      add(1, 0, w, curr, u[curi], down);
    }
    if (curr < w) {
      add(1, 0, w, curr, u[curi], down);
    } else {
      add(1, 0, w, curl - 1, u[curi], down);
    }
  }
  printf("%d\n", get(1, 0, w, 0, w, inf));
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