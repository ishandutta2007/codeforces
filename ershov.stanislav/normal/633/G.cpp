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

ll rdtsc() {
  ll ans;
  asm("rdtsc" : "=A"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 1e5 + 100, maxm = 1e3 + 10;
int n, m, a[maxn];
typedef bitset<maxm> cool;
cool ones;
vector<int> tree[maxn];
int curt, tin[maxn], tout[maxn];
int perm[maxn];

void shift(cool & a, int move) {
  move %= m;
  a = ((a << move) & ones) | (a >> (m - move));
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
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

void dfs(int v, int par = -1) {
  perm[curt] = v;
  tin[v] = curt++;
  for (int i = 0; i < sz(tree[v]); i++) {
    if (tree[v][i] == par) {
      continue;
    }
    dfs(tree[v][i], v);
  }
  tout[v] = curt;
}

cool segmtree[1 << 18];
int toshift[1 << 18];

void build(int v, int vl, int vr) {
  toshift[v] = 0;
  if (vl == vr - 1) {
    segmtree[v] = cool();
    segmtree[v].set(a[perm[vl]] % m);
  } else {
    int mid = (vl + vr) / 2;
    build(v * 2, vl, mid);
    build(v * 2 + 1, mid, vr);
    segmtree[v] = segmtree[v * 2] | segmtree[v * 2 + 1];
  }
}

void push(int v) {
  if (toshift[v]) {
    for (int it = 0; it < 2; it++) {
      shift(segmtree[v * 2 + it], toshift[v]);
      toshift[v * 2 + it] += toshift[v];
    }
    toshift[v] = 0;
  }
}

void treeshift(int v, int vl, int vr, int l, int r, int val) {
  if (vr <= l || r <= vl) {
    return;
  }
  if (l <= vl && vr <= r) {
    toshift[v] += val;
    shift(segmtree[v], val);
  } else {
    int mid = (vl + vr) / 2;
    push(v);
    treeshift(v * 2, vl, mid, l, r, val);
    treeshift(v * 2 + 1, mid, vr, l, r, val);
    segmtree[v] = segmtree[v * 2] | segmtree[v * 2 + 1];
  }
}

cool treeget(int v, int vl, int vr, int l, int r) {
  if (vr <= l || r <= vl) {
    return cool();
  }
  if (l <= vl && vr <= r) {
    return segmtree[v];
  } else {
    int mid = (vl + vr) / 2;
    push(v);
    return treeget(v * 2, vl, mid, l, r) | treeget(v * 2 + 1, mid, vr, l, r);
  }
}

void solve() {
  curt = 0;
  dfs(0);
  assert(curt == n);
  ones = cool();
  for (int i = 0; i < m; i++) {
    ones.set(i, true);
  }
  build(1, 0, n);
  cool primes;
  for (int i = 2; i < m; i++) {
    primes.set(i, true);
  }
  for (int i = 2; i * i < m; i++) {
    if (primes.test(i)) {
      for (int j = i * i; j < m; j += i) {
        primes.set(j, 0);
      }
    }
  }
  int q;
  scanf("%d", &q);
  for (int test = 0; test < q; test++) {
    int t, v;
    scanf("%d%d", &t, &v);
    v--;
    if (t == 1) {
      int x;
      scanf("%d", &x);
      treeshift(1, 0, n, tin[v], tout[v], x % m);
    } else {
      cool ans = treeget(1, 0, n, tin[v], tout[v]);
      ans &= primes;
      /*for (int i = 0; i < m; i++) {
        eprintf("%d%c", ans.test(i), " \n"[i == m - 1]);
      }*/
      printf("%d\n", (int) (ans.count()));
    }
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
    //break;
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}