#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 2.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);


void precalc() {
}

int n, m;

int S, T;

vector<vector<int> > es, cs, ids;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  scanf("%d%d", &S, &T);
  --S, --T;
  es = cs = ids = vector<vector<int> >(n);
  for (int i = 0; i < m; ++i) {
    int s, t, c;
    scanf("%d%d%d", &s, &t, &c);
    --s, --t;
    es[s].pb(t), es[t].pb(s);
    cs[s].pb(c), cs[t].pb(c);
    ids[s].pb(i), ids[t].pb(i);
  }
  return 1;
}

const int maxn = 1000 + 10;

vector<int> path;
vector<int> costp;
vector<int> idp;

int used[maxn];

bool dfs1(int v, int T) {
  if (v == T) {
    path.pb(v);
    return 1;
  }
  used[v] = 1;
  for (int it = 0; it < sz(es[v]); ++it) {
    int u = es[v][it];
    if (used[u]) {
      continue;
    }
    if (dfs1(u, T)) {
      path.pb(v);
      costp.pb(cs[v][it]);
      idp.pb(ids[v][it]);
      return 1;
    }
  }
  return 0;
}

int delId;

int maxu;

int hasT[maxn];

int tme;
int times[maxn];

pair<int, int> ok;

int dfs(int v, int epr = -1) {
  used[v] = maxu;
  hasT[v] = (v == T);
  times[v] = tme++;
  int res = times[v];

  for (int it = 0; it < sz(es[v]); ++it) {
    int u = es[v][it];
    if (ids[v][it] == delId) {
      continue;
    }
    if (used[u] == maxu) {
      if (ids[v][it] != epr) {
        res = min(res, times[u]);
      }
      continue;
    }
    int got = dfs(u, ids[v][it]);
    hasT[v] = max(hasT[v], hasT[u]);

    if (got >= times[u]) {
      if (hasT[u]) {
        ok = min(ok, mp(cs[v][it], ids[v][it]));
      }
    }
    res = min(res, got);
  }

  return res;
}

int scnt, sid;

int solve1() {
  int res = inf;
  ok = mp(inf, -1);
  ++maxu;
  tme = 0;
  dfs(S, T);
  if (!hasT[S]) {
    scnt = 0;
    sid = -1;
    return 0;
  }
  scnt = 1;
  sid = ok.second;
  return ok.first;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    used[i] = 0;
  }
  costp.clear();
  path.clear();
  idp.clear();
  if (!dfs1(S, T)) {
    printf("0 0\n");
    return;
  }
  maxu = 2;
  int res = inf;
  int cnt = -1;
  int rA, rB;

  for (int i = 0; i < sz(path) - 1; ++i) {
    delId = idp[i];
    int got = solve1();
    if (got == inf) {
      continue;
    }
    got += costp[i];
    if (res > got) {
      res = got;
      cnt = scnt + 1;
      rA = idp[i];
      rB = sid;
    }
  }
  if (res == inf) {
    printf("-1\n");
    return;
  }
  printf("%d\n%d\n%d", res, cnt, rA + 1);
  if (cnt == 2) {
    printf(" %d", rB + 1);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".out", "w", stdout));
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}