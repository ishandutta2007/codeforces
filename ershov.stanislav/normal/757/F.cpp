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

const ll infll = (ll) 1e18 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 2e5 + 100;

int n, m, s;
vector<vector<int> > es;
#define ws mws
vector<vector<int> > ws;

bool read() {
  if (scanf("%d%d%d", &n, &m, &s) < 3) {
    return false;
  }
  s--;
  es = vector<vector<int> > (n);
  ws = vector<vector<int> > (n);
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--, b--;
    es[a].pb(b);
    es[b].pb(a);
    ws[a].pb(w);
    ws[b].pb(w);
  }
  return true;
}

ll dist[maxn];

void dijk() {
  set<pair<ll, int> > st;
  st.insert(mp(0ll, s));
  for (int i = 0; i < n; i++) {
    dist[i] = infll;
  }
  dist[s] = 0;
  while (sz(st)) {
    int cur = st.begin()->second;
    st.erase(st.begin());
    if (dist[cur] > infll / 2) {
      break;
    }
    for (int i = 0; i < sz(es[cur]); i++) {
      int to = es[cur][i];
      int w = ws[cur][i];
      if (dist[to] > dist[cur] + w) {
        st.erase(mp(dist[to], to));
        dist[to] = dist[cur] + w;
        st.insert(mp(dist[to], to));
      }
    }
  }
}

pair<ll, int> tosort[maxn];
int perm[maxn];
int where[maxn];
int bad[maxn];
int deg[maxn];

int cnt;

vector<pair<int *, int> > toback;

void makeback() {
  while (sz(toback)) {
    auto cur = toback.back();
    toback.pop_back();
    *cur.first = cur.second;
  }
}

void dfs(int v) {
  cnt++;
  bad[v] = 1;
  int city = perm[v];
  //eprintf("%d ", city);
  for (int i = 0; i < sz(es[city]); i++) {
    int to = es[city][i];
    if (where[to] > v && dist[to] == dist[city] + ws[city][i]) {
      toback.pb(mp(&deg[where[to]], deg[where[to]]));
      deg[where[to]]--;
      if (deg[where[to]] == 0) {
        dfs(where[to]);
      }
    }
  }
}

void solve() {
  dijk();
  for (int i = 0; i < n; i++) {
    tosort[i] = mp(dist[i], i);
  }
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    perm[i] = tosort[i].second;
    //eprintf("%d%c", perm[i], " \n"[i == n - 1]);
    where[perm[i]] = i;
  }
  memset(deg, 0, sizeof(deg));
  memset(bad, 0, sizeof(bad));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(es[i]); j++) {
      int to = es[i][j];
      if (where[to] > where[i] && dist[to] == dist[i] + ws[i][j]) {
        deg[where[to]]++;
      }
    }
  }
  int res = 0;
  for (int i = 1; i < n; i++) {
    if (dist[perm[i]] > infll / 2) {
      continue;
    }
    if (bad[i]) {
      continue;
    }
    cnt = 0;
    dfs(i);
    //eprintf("\n");
    makeback();
    res = max(res, cnt);
  }
  printf("%d\n", res);
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