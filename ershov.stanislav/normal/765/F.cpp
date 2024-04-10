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

void precalc() {
}

const int maxn = 3e5 + 100;

int n;
int a[maxn];
vector<pair<int, int> > tosort;
int st[maxn * 4];

void treeupd(int v, int vl, int vr, int pos, int val) {
  if (vl > pos || vr <= pos) {
    return;
  }
  if (vl == vr - 1) {
    st[v] = max(st[v], val);
    return;
  }
  int mid = (vl + vr) / 2;
  treeupd(v * 2, vl, mid, pos, val);
  treeupd(v * 2 + 1, mid, vr, pos, val);
  st[v] = max(st[v * 2], st[v * 2 + 1]);
}

int get(int v, int vl, int vr, int l, int r) {
  if (r <= vl || vr <= l) {
    return -1;
  } else if (l <= vl && vr <= r) {
    return st[v];
  } else {
    int mid = (vl + vr) / 2;
    return max(get(v * 2, vl, mid, l, r), get(v * 2 + 1, mid, vr, l, r));
  }
}

int fenw[maxn];

void upd(int i, int val) {
  for (; i < maxn; i |= (i + 1)) {
    fenw[i] = min(fenw[i], val);
  }
}

int getfenw(int i) {
  int res = inf;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res = min(res, fenw[i]);
  }
  return res;
}

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

int ans[maxn];
int where[maxn];

void solve() {
  tosort.clear();
  for (int i = 0; i < n; i++) {
    tosort.pb(mp(a[i], i));
  }
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i < n; i++) {
    where[tosort[i].second] = i;
  }
  memset(st, -1, sizeof(st));
  for (int i = 0; i < maxn; i++) {
    fenw[i] = inf;
  }
  int m;
  scanf("%d", &m);
  vector<vector<pair<int, int> > > qs;
  qs.resize(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    qs[r].pb(mp(l, i));
  }
  for (int pos = 0; pos < n; pos++) {
    int cur = a[pos];
    int l = where[pos] + 1;
    int r = n;
    //eprintf("pos = %d\n", pos);
    while (l < r) {
      int toupd = get(1, 0, n, l, r);
      if (toupd == -1) {
        break;
      }
      //eprintf("upd %d %d\n", toupd, abs(a[toupd] - cur));
      upd(maxn - 1 - toupd, abs(a[toupd] - cur));
      if (a[toupd] == cur) {
        break;
      }
      int nmx = cur + (a[toupd] - cur) / 2;
      r = (int) (upper_bound(tosort.begin(), tosort.end(), mp(nmx, inf)) - tosort.begin());
    }
    l = 0;
    r = where[pos];
    while (l < r) {
      int toupd = get(1, 0, n, l, r);
      //eprintf("%d %d\n", l, r);
      if (toupd == -1) {
        break;
      }
      //eprintf("upd %d %d\n", toupd, abs(a[toupd] - cur));
      upd(maxn - 1 - toupd, abs(a[toupd] - cur));
      if (a[toupd] == cur) {
        break;
      }
      int nmn = cur - (cur - a[toupd]) / 2;
      l = (int) (lower_bound(tosort.begin(), tosort.end(), mp(nmn, -1)) - tosort.begin());
    }
    for (auto i : qs[pos]) {
      ans[i.second] = getfenw(maxn - 1 - i.first);
    }
    treeupd(1, 0, n, where[pos], pos);
  }
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
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