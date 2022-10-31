#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 1e5 + 100;
int n, m;
vector<int> tree[maxn];
int tin[maxn], tout[maxn], depth[maxn], up[20][maxn], t;
int cnt[maxn];
ll sum[maxn];
vector<pair<int, ll> > dp[maxn];
ll all[maxn];

void dfs(int v, int par = 0, int dep = 0) {
  up[0][v] = par;
  cnt[v] = 1;
  sum[v] = 0;
  tin[v] = t++;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    dfs(to, v, dep + 1);
    cnt[v] += cnt[to];
    sum[v] += sum[to] + cnt[to];
  }
  tout[v] = t;
  depth[v] = dep;
}

void dfs2(int v, int par = 0) {
  if (v == 0) {
    all[v] = sum[v];
  } else {
    all[v] = all[up[0][v]] - cnt[v] + n - cnt[v];
  }
  for (int i = 0; i < sz(tree[v]); i++) {
    if (tree[v][i] != par) {
      dfs2(tree[v][i], v);
    }
  }
}

bool isanc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getlca(int a, int b) {
  for (int i = 19; i >= 0; i--) {
    if (!isanc(up[i][a], b)) {
      a = up[i][a];
    }
  }
  if (!isanc(a, b)) {
    a = up[0][a];
  }
  return a;
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    tree[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  return true;
}

void solve() {
  t = 0;
  dfs(0);
  dfs2(0);
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < n; i++) {
      up[j][i] = up[j - 1][up[j - 1][i]];
    }
  }
  //eprintf("cnt, sum:\n");
  for (int i = 0; i < n; i++) {
    ////eprintf("%d %d\n", cnt[i], (int) sum[i]);
  }
  for (int i = 0; i < m; i++) {
    int u[2];
    scanf("%d%d", u, u + 1);
    u[0]--, u[1]--;
    int lca = getlca(u[0], u[1]);
    //eprintf("lca = %d\n", lca);
    ld ans = depth[u[0]] + depth[u[1]] - 2 * depth[lca] + 1;
    //eprintf("%d %d %d\n", depth[u[0]], depth[u[1]], depth[lca]);
    //eprintf("%.18f\n", (double) ans);
    for (int j = 0; j < 2; j++) {
      int curcnt = n;
      ll cursum = all[u[j]];
      //eprintf("cursum = %d\n", (int) cursum);
      int cntgood = 0;
      for (int k = 0; k < sz(tree[u[j]]); k++) {
        int to = tree[u[j]][k];
        if ((u[j] != lca && to == up[0][u[j]]) || (u[j] == lca && isanc(to, u[!j]) && to != up[0][u[j]])) {
          if (to == up[0][u[j]]) {
            curcnt = cnt[u[j]];
            cursum = sum[u[j]];
          } else {
            curcnt -= cnt[to];
            cursum -= sum[to] + cnt[to];
          }
          cntgood++;
        }
      }
      assert(cntgood == 1);
      assert(curcnt > 0);
      ans += (ld) cursum / curcnt;
      //eprintf("%.18f\n", (double) cursum / curcnt);
    }
    printf("%.18f\n", (double) ans);
  }
}

int main() {
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