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

const int mod = (int) 1e9 + 7;

void add(int & a, int b) {
  if ((a += b) >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

int pws[1000];

void precalc() {
  pws[0] = 1;
  for (int i = 1; i < 1000; i++) {
    pws[i] = mult(pws[i - 1], 2);
  }
}

ll have;
vector<ll> v, where;

void add(ll val) {
  //eprintf("add: %lld\n", val);
  have |= val;
  for (int i = 0; i < sz(v); i++) {
    if (val & where[i]) {
      val ^= v[i];
    }
  }
  if (val) {
    v.pb(val);
    where.pb(((ll) 1) << __builtin_ctzll(val));
  }
}

const int maxn = 5e5 + 100;

int n, m;
vector<vector<int> > graph;
vector<vector<ll> > t;

int used[maxn];
vector<int> st;
ll vals[maxn];

void dfs(int v, ll cur = 0) {
  if (used[v]) {
    add(cur ^ vals[v]);
    return;
  }
  st.pb(v);
  used[v] = true;
  vals[v] = cur;
  //eprintf("vals[%d] = %lld\n", v, cur);
  for (int i = 0; i < sz(graph[v]); i++) {
    dfs(graph[v][i], cur ^ t[v][i]);
  }
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  graph = vector<vector<int> > (n);
  t = vector<vector<ll> > (n);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll curt;
    scanf("%d%d%lld", &u, &v, &curt);
    u--, v--;
    graph[u].pb(v);
    graph[v].pb(u);
    t[u].pb(curt);
    t[v].pb(curt);
  }
  return true;
}

void solve() {
  memset(used, 0, sizeof(used));
  int res = 0;
  int inv2 = (mod + 1) / 2;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    where.clear();
    v.clear();
    have = 0;
    st.clear();
    dfs(i);
    for (int j = 0; j < 61; j++) {
      if (have & (1ll << j)) {
        add(res, mult(sz(st), mult(sz(st) - 1, mult(inv2, pws[sz(v) - 1 + j]))));
      } else {
        int cnt1 = 0, cnt0 = 0;
        for (auto k : st) {
          if (vals[k] & (1ll << j)) {
            cnt1++;
          } else {
            cnt0++;
          }
        }
        //eprintf("%d %d\n", cnt0, cnt1);
        add(res, mult(cnt0, mult(cnt1, pws[sz(v) + j])));
      }
    }
  }
  printf("%d\n", res);
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