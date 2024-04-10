#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

int n, m;
vector<vector<int> > graph;
vector<vector<int> > t;
vector<int> col;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  graph = t = vector<vector<int> > (n);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    scanf("%d%d %c", &u, &v, &c);
    u--, v--;
    graph[u].pb(v);
    graph[v].pb(u);
    if (c == 'R') {
      t[u].pb(1);
      t[v].pb(1);
    } else {
      assert(c == 'B');
      t[u].pb(0);
      t[v].pb(0);
    }
  }
  return true;
}

vector<int> comp[2];
bool ok;

void dfs(int v, int cur) {
  if (col[v] != -1) {
    if (col[v] != cur) {
      ok = false;
    }
  } else {
    col[v] = cur;
    comp[cur].pb(v);
    for (int i = 0; i < sz(graph[v]); i++) {
      dfs(graph[v][i], cur ^ t[v][i]);
    }
  }
}

void solve() {
  int mn = inf;
  vector<int> ans;
  for (int it = 0; it < 2; it++) {
    col = vector<int> (n, -1);
    ok = true;
    vector<int> curans;
    for (int i = 0; i < n; i++) {
      if (col[i] == -1) {
        comp[0] = comp[1] = vector<int> ();
        dfs(i, 0);
        if (sz(comp[1]) < sz(comp[0])) {
          swap(comp[1], comp[0]);
        }
        for (int j = 0; j < sz(comp[0]); j++) {
          curans.pb(comp[0][j]);
        }
      }
    }
    if (ok && sz(curans) < mn) {
      ans = curans;
      mn = sz(curans);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < sz(graph[i]); j++) {
        t[i][j] ^= 1;
      }
    }
  }
  if (mn == inf) {
    printf("-1\n");
  } else {
    printf("%d\n", mn);
    for (int i = 0; i < sz(ans); i++) {
      printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
    }
  }
}

int main() {
  srand(rdtsc());
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