#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const ll inf = (ll) 1e15;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

struct SegmTree {
  const static int maxn = 1 << 20;
  ll mn[maxn], toadd[maxn];
  int n;

  void build(int _n) {
    n = _n;
    memset(mn, 0, sizeof(mn));
    memset(toadd, 0, sizeof(toadd));
  }

  void push(int v) {
    if (toadd[v]) {
      for (int it = 0; it < 2; it++) {
        mn[v * 2 + it] += toadd[v];
        toadd[v * 2 + it] += toadd[v];
      }
      toadd[v] = 0;
    }
  }

  ll getmn(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
      return inf;
    }
    if (l <= vl && vr <= r) {
      return mn[v];
    }
    int mid = (vl + vr) / 2;
    push(v);
    return min(getmn(v * 2, vl, mid, l, r), getmn(v * 2 + 1, mid, vr, l, r));
  }

  void add(int v, int vl, int vr, int l, int r, ll val) {
    if (vr <= l || r <= vl) {
      return;
    }
    if (l <= vl && vr <= r) {
      toadd[v] += val;
      mn[v] += val;
      return;
    }
    int mid = (vl + vr) / 2;
    push(v);
    add(v * 2, vl, mid, l, r, val);
    add(v * 2 + 1, mid, vr, l, r, val);
    mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
  }

  ll getmn(int l, int r) {
    return getmn(1, 0, n, l, r);
  }

  void add(int l, int r, ll val) {
    add(1, 0, n, l, r, val);
  }
} segm;

int n, m;
vector<vector<int> > tree;
#define ends mends
vector<vector<int> > starts, ends;
vector<int> costs;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  starts = ends = tree = vector<vector<int> > (n);
  costs = vector<int> (m);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--, v--;
    starts[u].pb(i);
    ends[v].pb(i);
    costs[i] = c;
  }
  return true;
}

int t;
vector<int> where;
bool can;

ll dfs(int v, int par = -1) {
  ll summn = 0;
  int l = t;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    int r = t;
    ll curmn = dfs(to, v);
    segm.add(l, r, curmn);
    segm.add(r, t, summn);
    summn += curmn;
  }
  for (auto i : starts[v]) {
    where[i] = t;
    segm.add(t, t + 1, summn + costs[i]);
    t++;
  }
  for (auto i : ends[v]) {
    segm.add(where[i], where[i] + 1, inf);
  }
  ll res = segm.getmn(l, t);
  if (res >= inf) {
    can = false;
  }
  //eprintf("%d %lld\n", v, res);
  return res;
}

void solve() {
  where = vector<int> (m);
  t = 0;
  segm.build(m);
  can = true;
  ll res = 0;
  for (auto i : tree[0]) {
    res += dfs(i, 0);
  }
  if (!can) {
    printf("-1\n");
  } else {
    printf(LLD "\n", res);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}