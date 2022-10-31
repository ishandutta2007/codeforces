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

const int maxn = 5e5;
int n;
vector<vector<int> > tree;
int tin[maxn], tout[maxn], depth[maxn];
int up[20][maxn];
int curt;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  tree = vector<vector<int> > (n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    tree[u].pb(v);
    tree[v].pb(u);
  }
  return true;
}

void dfs(int v, int par = -1, int dep = 0) {
  tin[v] = curt++;
  depth[v] = dep;
  up[0][v] = max(par, 0);
  for (int i = 0; i < sz(tree[v]); i++) {
    if (tree[v][i] != par) {
      dfs(tree[v][i], v, dep + 1);
    }
  }
  tout[v] = curt;
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

vector<int> good;
vector<pair<int, int> > nv;
vector<vector<int> > ntree;

pair<int, bool> getdp(int v, int par = -1) {
  int res = 0;
  bool have = binary_search(good.begin(), good.end(), nv[v].second);
  int cnthave = 0;
  for (int i = 0; i < sz(ntree[v]); i++) {
    int to = ntree[v][i];
    if (to == par) {
      continue;
    }
    pair<int, bool> curres = getdp(to, v);
    if (curres.first == inf) {
      return mp(inf, false);
    }
    res += curres.first;
    if (curres.second) {
      if (have) {
        if (depth[nv[v].second] == depth[nv[to].second] - 1 && binary_search(good.begin(), good.end(), nv[to].second)) {
          return mp(inf, false);
        } else {
          res++;
        }
      } else {
        cnthave++;
      }
    }
  }
  if (cnthave >= 2) {
    cnthave = 0;
    res++;
  }
  if (cnthave) {
    have = true;
  }
  //eprintf("v = %d %d %d\n", v, res, have);
  return mp(res, have);
}

void solve() {
  curt = 0;
  dfs(0);
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }
  int q;
  scanf("%d", &q);
  for (int t = 0; t < q; t++) {
    //eprintf("t = %d\n", t);
    int k;
    scanf("%d", &k);
    good.clear();
    for (int i = 0; i < k; i++) {
      int a;
      scanf("%d", &a);
      good.pb(a - 1);
    }
    sort(good.begin(), good.end());
    vector<pair<int, int> > tosort;
    for (int i = 0; i < k; i++) {
      tosort.eb(tin[good[i]], good[i]);
    }
    sort(tosort.begin(), tosort.end());
    nv = tosort;
    for (int i = 0; i + 1 < k; i++) {
      int toadd = getlca(tosort[i].second, tosort[i + 1].second);
      nv.eb(tin[toadd], toadd);
    }
    nv.eb(tin[0], 0);
    sort(nv.begin(), nv.end());
    nv.resize(unique(nv.begin(), nv.end()) - nv.begin());
    /*for (auto i : nv) {
      cerr << i.second << ' ';
    }
    cerr << endl;*/
    ntree = vector<vector<int> > (sz(nv));
    vector<int> st;
    for (int i = 0; i < sz(nv); i++) {
      int cur = nv[i].second;
      while (sz(st) && tout[nv[st.back()].second] <= tin[cur]) {
        st.pop_back();
      }
      if (sz(st)) {
        //eprintf("add %d %d\n", i, st.back());
        ntree[i].pb(st.back());
        ntree[st.back()].pb(i);
      }
      st.pb(i);
    }
    pair<int, bool> res = getdp(0);
    if (res.first == inf) {
      printf("-1\n");
    } else {
      printf("%d\n", res.first);
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