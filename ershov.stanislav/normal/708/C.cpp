#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

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

const int maxn = 5e5 + 100;

int n;
vector<vector<int> > tree;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree = vector<vector<int> > (n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }
  return true;
}

int cnt[maxn];
int best[maxn];
int ans[maxn];
int p[maxn];
int cool[maxn];

void dfs1(int v, int par) {
  p[v] = par;
  cnt[v] = 1;
  best[v] = 0;
  vector<int> mxpref, mxsuf;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    dfs1(to, v);
    cnt[v] += cnt[to];
    mxpref.pb(cnt[to]);
    mxsuf.pb(cnt[to]);
    best[v] = max(best[v], cnt[to]);
  }
  for (int i = 1; i < sz(mxpref); i++) {
    mxpref[i] = max(mxpref[i - 1], mxpref[i]);
  }
  for (int i = sz(mxpref) - 2; i >= 0; i--) {
    mxsuf[i] = max(mxsuf[i + 1], mxsuf[i]);
  }
  for (int i = 0, j = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    cool[to] = max((j ? mxpref[j - 1] : 0), ((j + 1 < sz(mxsuf)) ? mxsuf[j + 1] : 0));
    cool[to] = max(cool[to], n - cnt[v]);
    j++;
    if (cnt[to] > n / 2) {
      best[v] = best[to];
    }
  }
  if (cnt[v] <= n / 2) {
    best[v] = cnt[v];
  }
}

void dfs2(int v, int par, int up = -1) {
  if (up == -1 && n - cnt[v] > n / 2) {
    up = v;
  }
  int mxu = -1;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    dfs2(to, v, up);
    if (mxu == -1 || cnt[to] > cnt[mxu]) {
      mxu = to;
    }
  }
  ans[v] = 1;
  if (mxu != -1 && cnt[mxu] > n / 2) {
    if (cnt[mxu] - best[mxu] > n / 2) {
      ans[v] = 0;
    }
  }
  if (n - cnt[v] > n / 2) {
    int curmx = cool[up];
    int cur = p[up];
    assert(cur != -1);
    if (curmx > n / 2 && n - cnt[v] - best[cur] > n / 2) {
      ans[v] = 0;
    }
    if (curmx <= n / 2) {
      if (n - cnt[v] - curmx > n / 2) {
        ans[v] = 0;
      }
    }
  }
}

void solve() {
  memset(cool, 0, sizeof(cool));
  dfs1(0, -1);
  dfs2(0, -1);
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i], " \n"[i == n - 1]);
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