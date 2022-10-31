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

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1e6;
int mn[maxn], toadd[maxn];

void push(int v) {
  if (toadd[v]) {
    for (int it = 0; it < 2; it++) {
      mn[v * 2 + it] += toadd[v];
      toadd[v * 2 + it] += toadd[v];
    }
    toadd[v] = 0;
  }
}

void add(int v, int vl, int vr, int l, int r, int val) {
  if (vr <= l || r <= vl) {
    return;
  }
  if (l <= vl && vr <= r) {
    mn[v] += val;
    toadd[v] += val;
  } else {
    int mid = (vl + vr) / 2;
    push(v);
    add(v * 2, vl, mid, l, r, val);
    add(v * 2 + 1, mid, vr, l, r, val);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
  }
}

int get(int v, int vl, int vr, int val) {
  if (mn[v] >= val) {
    return vl;
  }
  if (vl == vr - 1) {
    return vr;
  }
  int mid = (vl + vr) / 2;
  push(v);
  int res = get(v * 2 + 1, mid, vr, val);
  if (res == mid) {
    res = get(v * 2, vl, mid, val);
  }
  return res;
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int vals[maxn];

void solve() {
  memset(mn, 0, sizeof(mn));
  memset(toadd, 0, sizeof(toadd));
  int all = 0;
  for (int i = 0; i < n; i++) {
    int p, t;
    scanf("%d%d", &p, &t);
    p--;
    if (!t) {
      t = -1;
    } else {
      scanf("%d", vals + p);
    }
    all += t;
    add(1, 0, n + 1, p + 1, n + 1, t);
    int res = get(1, 0, n + 1, all);
    if (res == 0) {
      printf("-1\n");
    } else {
      printf("%d\n", vals[res - 1]);
    }
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}