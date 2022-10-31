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

const int inf = (int) 1e8 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 5e5 + 100;

int n;
int p[maxn], c[maxn];
int cnt[maxn];
int ans[maxn];
int depth[maxn];

int maxdepth[1 << 22];

vector<vector<int> > tree;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree = vector<vector<int> > (n);
  for (int i = 1; i < n; i++) {
    char ch;
    scanf("%d %c", p + i, &ch);
    c[i] = ch - 'a';
    p[i]--;
    tree[p[i]].pb(i);
  }
  return true;
}

typedef vector<pair<int, int> > vpii;

void merge(vpii &a, vpii &b, int v) {
  for (auto &i : b) {
    ans[v] = max(ans[v], maxdepth[i.first] + i.second - 2 * depth[v]);
    for (int j = 0; j < 'v' - 'a' + 1; j++) {
      ans[v] = max(ans[v], maxdepth[i.first ^ (1 << j)] + i.second - 2 * depth[v]);
    }
  }
  for (auto &i : b) {
    a.pb(i);
    maxdepth[i.first] = max(maxdepth[i.first], i.second);
  }
}

void dfs(int v, int mask, vpii & vec) {
  int mxi = -1;
  for (int i = 0; i < sz(tree[v]); i++) {
    depth[tree[v][i]] = depth[v] + 1;
    if (mxi == -1 || cnt[tree[v][mxi]] < cnt[tree[v][i]]) {
      mxi = i;
    }
  }
  vpii tomerge = {mp(mask, depth[v])};
  if (mxi == -1) {
    merge(vec, tomerge, v);
    return;
  }
  vector<vpii> small;
  for (int i = 0; i < sz(tree[v]); i++) {
    if (i != mxi) {
      small.pb(vpii());
      dfs(tree[v][i], mask ^ (1 << c[tree[v][i]]), small.back());
      for (auto &j : small.back()) {
        maxdepth[j.first] = -inf;
      }
    }
  }
  dfs(tree[v][mxi], mask ^ (1 << c[tree[v][mxi]]), vec);
  for (auto &curvec : small) {
    merge(vec, curvec, v);
  }
  merge(vec, tomerge, v);
}

void solve() {
  for (int i = 0; i < (1 << 22); i++) {
    maxdepth[i] = -inf;
  }
  for (int i = 0; i < n; i++) {
    cnt[i] = 1;
  }
  for (int i = n - 1; i; i--) {
    cnt[p[i]] += cnt[i];
  }
  memset(ans, 0, sizeof(ans));
  vpii v;
  depth[0] = 0;
  dfs(0, 0, v);
  for (int i = n - 1; i; i--) {
    ans[p[i]] = max(ans[p[i]], ans[i]);
  }
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

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}