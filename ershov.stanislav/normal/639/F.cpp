#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

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

struct Graph {
  int n;
  vector<vector<int> > es;
  vector<vector<int> > eid;
  int cnte;

  Graph(int _n = 0) {
    n = _n;
    cnte = 0;
    es = eid = vector<vector<int> > (n);
  }

  void adde(int a, int b) {
    es[a].pb(b);
    es[b].pb(a);
    eid[a].pb(cnte);
    eid[b].pb(cnte);
    cnte++;
  }

  vector<int> used, tin, dp;
  vector<int> col;
  int cntcols, curt;
  vector<int> st;

  void dfs(int v, int pid = -1) {
    dp[v] = tin[v] = curt++;
    used[v] = 1;
    st.pb(v);
    for (int i = 0; i < sz(es[v]); i++) {
      int to = es[v][i];
      if (eid[v][i] == pid) {
        continue;
      }
      if (used[to]) {
        dp[v] = min(dp[v], tin[to]);
      } else {
        dfs(to, eid[v][i]);
        dp[v] = min(dp[v], dp[to]);
        if (dp[to] > tin[v]) {
          while(true) {
            int cur = st.back();
            col[cur] = cntcols;
            st.pop_back();
            if (cur == to) {
              break;
            }
          }
          cntcols++;
        }
      }
    }
  }

  void getcols() {
    cntcols = curt = 0;
    col = used = tin = dp = vector<int> (n);
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        dfs(i);
        while (sz(st)) {
          col[st.back()] = cntcols;
          st.pop_back();
        }
        cntcols++;
      }
    }
  }
};

int n, m, q;
Graph g;
int z;
vector<vector<int> > tree;
vector<vector<int> > uptree;
vector<int> tin, tout, used;
int curt;

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  g = Graph(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g.adde(u, v);
  }
  return true;
}

void dfs(int v, int par = -1) {
  tin[v] = curt++;
  uptree[0][v] = (par == -1) ? v : par;
  //eprintf("par[%d] = %d\n", v, par);
  used[v] = 1;
  for (int i = 0; i < sz(tree[v]); i++) {
    if (tree[v][i] != par) {
      dfs(tree[v][i], v);
    }
  }
  tout[v] = curt;
}

bool isanc(int a, int b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getlca(int a, int b) {
  for (int i = 19; i >= 0; i--) {
    if (!isanc(uptree[i][a], b)) {
      a = uptree[i][a];
    }
  }
  if (!isanc(a, b)) {
    a = uptree[0][a];
  }
  return a;
}

vector<int> interesting;

int getid(int v) {
  return (int) (lower_bound(interesting.begin(), interesting.end(), v) - interesting.begin());
}

int R;

int rotate(int i) {
  i = (i + R) % n;
  if (i == 0) {
    i = n;
  }
  return i;
}

void solve() {
  g.getcols();
  z = g.cntcols;
  //eprintf("z = %d\n", z);
  tree = vector<vector<int> > (z);
  uptree = vector<vector<int> > (20, vector<int> (z));
  tin = tout = used = vector<int> (z);
  curt = 0;
  /*eprintf("col:\n");
  for (int i = 0; i < n; i++) {
    eprintf("col[%d] = %d\n", i, g.col[i]);
  }*/
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(g.es[i]); j++) {
      int u = i, v = g.es[i][j];
      if (g.col[u] != g.col[v] && u < v) {
        tree[g.col[u]].pb(g.col[v]);
        tree[g.col[v]].pb(g.col[u]);
//        eprintf("%d %d\n", g.col[u], g.col[v]);
      }
    }
  }
  for (int i = 0; i < z; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < z; j++) {
      uptree[i][j] = uptree[i - 1][uptree[i - 1][j]];
    }
  }
  R = 0;
  for (int tnum = 0; tnum < q; tnum++) {
    int ni, mi;
    scanf("%d%d", &ni, &mi);
    vector<int> curv(ni);
    vector<pair<int, int> > cure(mi);
    interesting.clear();
    for (int i = 0; i < ni; i++) {
      scanf("%d", &curv[i]);
      curv[i] = rotate(curv[i]);
      curv[i] = g.col[curv[i] - 1];
      interesting.pb(curv[i]);
    }
    for (int i = 0; i < mi; i++) {
      scanf("%d%d", &cure[i].first, &cure[i].second);
      cure[i].first = rotate(cure[i].first);
      cure[i].second = rotate(cure[i].second);
      cure[i].first = g.col[cure[i].first - 1];
      cure[i].second = g.col[cure[i].second - 1];
      interesting.pb(cure[i].first);
      interesting.pb(cure[i].second);
    }
    sort(interesting.begin(), interesting.end());
    interesting.resize(unique(interesting.begin(), interesting.end()) - interesting.begin());
    vector<pair<int, int> > tosort;
    for (auto i : interesting) {
      tosort.pb(mp(tin[i], i));
    }
    sort(tosort.begin(), tosort.end());
    for (int i = 0; i + 1 < sz(tosort); i++) {
      int u = tosort[i].second, v = tosort[i + 1].second;
      if (uptree[19][u] != uptree[19][v]) {
        continue;
      }
      int lca = getlca(u, v);
      //eprintf("u = %d v = %d lca = %d\n", u, v, lca);
      interesting.pb(lca);
    }
    sort(interesting.begin(), interesting.end());
    interesting.resize(unique(interesting.begin(), interesting.end()) - interesting.begin());
    /*for (auto i : interesting) {
      cerr << i << endl;
    }*/
    Graph curg(sz(interesting));
    vector<int> st;
    tosort.clear();
    for (auto i : interesting) {
      tosort.pb(mp(tin[i], i));
    }
    sort(tosort.begin(), tosort.end());
    for (auto i : tosort) {
      int u = i.second;
      while (sz(st) && tout[st.back()] <= tin[u]) {
        st.pop_back();
      }
      if (sz(st)) {
        curg.adde(getid(u), getid(st.back()));
      }
      st.pb(u);
    }
    for (int i = 0; i < mi; i++) {
      curg.adde(getid(cure[i].first), getid(cure[i].second));
    }
    curg.getcols();
    bool yes = true;
    for (int i = 0; i + 1 < sz(curv); i++) {
      int u = curv[i], v = curv[i + 1];
      if (curg.col[getid(u)] != curg.col[getid(v)]) {
        yes = false;
        break;
      }
    }
    R += (yes ? tnum + 1 : 0);
    R %= n;
    printf(yes ? "YES\n" : "NO\n");
  }
}

int main() {
  srand(rdtsc());
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