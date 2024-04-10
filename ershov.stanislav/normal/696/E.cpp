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

const ll inf = (ll) 1e18 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

mt19937 mrand(random_device{} ()); 
int rnd(int x) {
  return mrand() % x;
}

const int maxn = 1e5 + 100;

ll fenw[maxn];

void fenwadd(int i, ll val) {
  for (; i < maxn; i |= (i + 1)) {
    fenw[i] += val;
  }
}

ll fenwget(int i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fenw[i];
  }
  return res;
}

struct SegmTree {
  const static int maxn = 1 << 18;
  pair<ll, int> mn[maxn];
  ll toadd[maxn];

  SegmTree() {
    memset(mn, 0, sizeof(mn));
    memset(toadd, 0, sizeof(toadd));
  }

  void push(int v) {
    if (toadd[v]) {
      for (int it = 0; it < 2; it++) {
        mn[v * 2 + it].first += toadd[v];
        toadd[v * 2 + it] += toadd[v];
      }
      toadd[v] = 0;
    }
  }

  void treeset(int v, int vl, int vr, int i, pair<ll, int> val) {
    if (vl == vr - 1) {
      mn[v] = val;
    } else {
      int mid = (vl + vr) / 2;
      push(v);
      if (mid > i) {
        treeset(v * 2, vl, mid, i, val);
      } else {
        treeset(v * 2 + 1, mid, vr, i, val);
      }
      mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
    }
  }

  void treeadd(int v, int vl, int vr, int l, int r, ll val) {
    if (vr <= l || r <= vl) {
      return;
    }
    if (l <= vl && vr <= r) {
      mn[v].first += val;
      toadd[v] += val;
    } else {
      int mid = (vl + vr) / 2;
      push(v);
      treeadd(v * 2, vl, mid, l, r, val);
      treeadd(v * 2 + 1, mid, vr, l, r, val);
      mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
    }
  }

  pair<ll, int> treeget(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl) {
      return mp(inf, -1);
    }
    if (l <= vl && vr <= r) {
      return mn[v];
    } else {
      int mid = (vl + vr) / 2;
      push(v);
      return min(treeget(v * 2, vl, mid, l, r), treeget(v * 2 + 1, mid, vr, l, r));
    }
  }
} segm;


void precalc() {
}

int n, m, q;
vector<vector<int> > tree;
int wheregirl[maxn];
vector<vector<int> > girls;
int curgirl[maxn];

void treeadd(int l, int r, ll val) {
  segm.treeadd(1, 0, n, l, r, val);
}

void treeset(int i, pair<ll, int> val) {
  segm.treeset(1, 0, n, i, val);
}

pair<ll, int> treeget(int l, int r) {
  return segm.treeget(1, 0, n, l, r);
}

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  tree = girls = vector<vector<int> > (n);
  memset(curgirl, 0, sizeof(curgirl));
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", wheregirl + i);
    wheregirl[i]--;
    girls[wheregirl[i]].pb(i);
  }

  return true;
}

int curt, cnt[maxn], tin[maxn], tout[maxn], par[maxn];
int top[maxn], where[maxn], last[maxn];

void dfs1(int v, int par = -1) {
  ::par[v] = par;
  cnt[v] = 1;
  tin[v] = curt++;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    dfs1(to, v);
    cnt[v] += cnt[to];
  }
  tout[v] = curt;
}

void dfs2(int v, int top) {
  where[v] = last[top] = curt++;
  ::top[v] = top;
  int mxi = -1;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par[v]) {
      continue;
    }
    if (mxi == -1 || cnt[to] > cnt[tree[v][mxi]]) {
      mxi = i;
    }
  }
  if (mxi == -1) {
    return;
  }
  dfs2(tree[v][mxi], top);
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par[v] || i == mxi) {
      continue;
    }
    dfs2(to, to);
  }
}

bool isanc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

pair<ll, int> getres(vector<int> v) {
  //eprintf("%d %d\n", v[0], v[1]);
  pair<ll, int> ans = mp(inf, -1);
  for (int i = 0; i < 2; i++) {
    while (!isanc(top[v[i]], v[i ^ 1])) {
      //eprintf("%d %d\n", v[i], top[v[i]]);
      int curtop = top[v[i]];
      pair<ll, int> curans = treeget(where[curtop], where[v[i]] + 1);
      curans.first += fenwget(tin[curtop]);
      ans = min(ans, curans);
      v[i] = par[curtop];
    }
  }
  //eprintf("!\n");
  int l = where[v[0]], r = where[v[1]];
  if (l > r) {
    swap(l, r);
  }
  {
      pair<ll, int> curans = treeget(l, r + 1);
      curans.first += fenwget(tin[top[v[0]]]);
      ans = min(ans, curans);
  }
  return ans;
}

void upd(int v) {
  if (curgirl[v] < sz(girls[v])) {
    int cur = girls[v][curgirl[v]];
    treeset(where[v], mp(cur + fenwget(tin[v]) - fenwget(tin[top[v]]), v));
  } else {
    treeset(where[v], mp(inf, -1));
  }
}

void solve() {
  memset(fenw, 0, sizeof(fenw));
  segm = SegmTree();
  curt = 0;
  dfs1(0);
  curt = 0;
  dfs2(0, 0);
  for (int i = 0; i < n; i++) {
    upd(i);
  }
  for (int tt = 0; tt < q; tt++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, u, k;
      scanf("%d%d%d", &v, &u, &k);
      v--, u--;
      vector<int> ans;
      for (int i = 0; i < k; i++) {
        pair<ll, int> res = getres({u, v});
        if (res.first >= inf / 2) {
          break;
        } else {
          ans.pb(girls[res.second][curgirl[res.second]]);
          curgirl[res.second]++;
          upd(res.second);
        }
      }
      printf("%d", sz(ans));
      for (int i = 0; i < sz(ans); i++) {
        printf(" %d", ans[i] + 1);
      }
      printf("\n");
    } else {
      int v, k;
      scanf("%d%d", &v, &k);
      v--;
      fenwadd(tin[v], k);
      fenwadd(tout[v], -k);
      if (top[v] != v) {
        treeadd(where[v], last[top[v]] + 1, k);
      }
    }
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