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
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  return true;
}

int nxt[maxn];

int st[maxn * 4];
int ans[maxn];

void add(int v, int vl, int vr, int pos, int val) {
  st[v] += val;
  if (vl == vr - 1) {
    return;
  }
  int mid = (vl + vr) / 2;
  if (pos < mid) {
    add(v * 2, vl, mid, pos, val);
  } else {
    add(v * 2 + 1, mid, vr, pos, val);
  }
}

int get(int v, int vl, int vr, int &k) {
  if (k >= st[v]) {
    k -= st[v];
    return vr - vl;
  }
  if (vl == vr - 1) {
    return 0;
  }
  int mid = (vl + vr) / 2;
  int res = get(v * 2, vl, mid, k);
  if (res == mid - vl) {
    res += get(v * 2 + 1, mid, vr, k);
  }
  return res;
}

void solve() {
  vector<int> last(n, n);
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = last[a[i]];
    last[a[i]] = i;
  }
  memset(st, 0, sizeof(st));
  for (int i = 0; i < n; i++) {
    if (last[i] < n) {
      add(1, 0, n, last[i], 1);
    }
  }
  vector<vector<int> > begins(n);
  for (int i = 1; i <= n; i++) {
    begins[0].pb(i);
  }
  memset(ans, 0, sizeof(ans));
  for (int pos = 0; pos < n; pos++) {
    for (int ki = 0; ki < sz(begins[pos]); ki++) {
      int k = begins[pos][ki];
      int nk = k;
      int go = get(1, 0, n, nk);
      if (go < n) {
        begins[go].pb(k);
      }
      ans[k]++;
    }
    add(1, 0, n, pos, -1);
    if (nxt[pos] < n) {
      add(1, 0, n, nxt[pos], 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d%c", ans[i], " \n"[i == n]);
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