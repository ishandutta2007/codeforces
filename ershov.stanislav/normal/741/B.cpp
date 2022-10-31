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

const int maxn = 1100;

int n, m, allw;

vector<vector<int> > graph;
int w[maxn], b[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &allw) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", w + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  graph = vector<vector<int> > (n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  return true;
}

bool used[maxn];
vector<int> comp;

void dfs(int v) {
  if (used[v]) {
    return;
  }
  comp.pb(v);
  used[v] = 1;
  for (auto i : graph[v]) {
    dfs(i);
  }
}

int dp[maxn], ndp[maxn];

void upd(int curw, int curb) {
  for (int i = 0; i + curw <= allw; i++) {
    ndp[i + curw] = max(ndp[i + curw], dp[i] + curb);
  }
}

void solve() {
  memset(used, 0, sizeof(used));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    comp.clear();
    dfs(i);
    for (int i = 0; i <= allw; i++) {
      ndp[i] = dp[i];
    }
    int sumw = 0, sumb = 0;
    for (auto i : comp) {
      sumw += w[i];
      sumb += b[i];
      upd(w[i], b[i]);
    }
    upd(sumw, sumb);
    swap(dp, ndp);
  }
  printf("%d\n", dp[allw]);
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