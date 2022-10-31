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

const int maxn = (int) 2e5 + 100;
int n;
int a[maxn], b[maxn], c[maxn];
int used[maxn], maxu, depth[maxn], par[maxn];
vector<int> tree[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
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

void dfs(int v, int curpar = -1, int dep = 0) {
  depth[v] = dep;
  par[v] = curpar;
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == curpar) {
      continue;
    }
    dfs(to, v, dep + 1);
  }
}

int move0(int v, int * perm, int curpar = -1) {
  if (perm[v] == 0) {
    return 0;
  }
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == curpar || used[to] == maxu) {
      continue;
    }
    int res = move0(to, perm, v);
    if (res >= 0) {
      swap(perm[v], perm[to]);
      return res + 1;
    }
  }
  return -1;
}

void solve() {
  int root = (int) (find(a, a + n, 0) - a);
  dfs(root);
  memcpy(c, b, n * sizeof(int));
  maxu++;
  int restree = move0(root, c);
  assert(a[root] == 0 && c[root] == 0);
  vector<int> ends;
  int anc = -1;
  //eprintf("c: ");
  /*for (int i = 0; i < n; i++) {
    //eprintf("%d%c", c[i], " \n"[i == n - 1]);
  }*/
  for (int i = 0; i < n; i++) {
    if (a[i] != c[i]) {
      if (anc == -1 || depth[anc] > depth[par[i]]) {
        anc = par[i];
      }
      bool leaf = true;
      for (int j = 0; j < sz(tree[i]); j++) {
        int to = tree[i][j];
        if (to == par[i]) {
          continue;
        }
        if (a[to] != c[to]) {
          leaf = false;
          break;
        }
      }
      if (leaf) {
        ends.pb(i);
      }
    }
  }
  if (sz(ends) > 2) {
    printf("-1\n");
    return;
  }
  if (sz(ends) == 0) {
    printf("0 %d\n", restree);
    return;
  }
  assert(anc != -1);
  if (sz(ends) == 1) {
    ends.pb(anc);
  }
  //eprintf("ends:\n");
  /*for (int i = 0; i < sz(ends); i++) {
    eprintf("%d%c", ends[i], " \n" [i == sz(ends) - 1]);
  }*/
  vector<int> cycle, cycle1, cycle2;
  maxu++;
  for (int it = 0; it < 2; it++) {
    for (int i = ends[it]; i != anc; i = par[i]) {
      if (i == -1 || used[i] == maxu) {
        printf("-1\n");
        return;
      }
      if (!it) {
        cycle1.pb(i);
      } else {
        cycle2.pb(i);
      }
      used[i] = maxu;
    }
  }
  cycle.pb(anc);
  used[anc] = maxu;
  for (int i = sz(cycle2) - 1; i >= 0; i--) {
    cycle.pb(cycle2[i]);
  }
  for (int i = 0; i < sz(cycle1); i++) {
    cycle.pb(cycle1[i]);
  }
  int m = sz(cycle);
  //eprintf("cycle\n");
  //eprintf("%d\n", m);
  /*for (int i = 0; i < sz(cycle); i++) {
    eprintf("%d\n", cycle[i]);
  }*/
  int res = 0;
  for (int i = 0; i < m; i++) {
    res += max(0, move0(cycle[i], a));
    res += max(0, move0(cycle[i], b));
  }
  /*eprintf("a: ");
  for (int i = 0; i < n; i++) {
    eprintf("%d%c", a[i], " \n"[i == n - 1]);
  }
  eprintf("b: ");
  for (int i = 0; i < n; i++) {
    eprintf("%d%c", b[i], " \n"[i == n - 1]);
  }*/
  //eprintf("res = %d\n", res);
  vector<int> incycle(n, -1), inb(n);
  for (int i = 0; i < n; i++) {
    inb[b[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    incycle[cycle[i]] = i;
  }
  vector<int> nperm(m);
  for (int i = 0; i < m; i++) {
    int val = incycle[inb[a[cycle[i]]]];
    if (val == -1) {
      printf("-1\n");
      return;
    }
    nperm[i] = val;
  }
  vector<int> rev(m);
  for (int i = 0; i < m; i++) {
    rev[nperm[i]] = i;
  }
  /*eprintf("rev: ");
  for (int i = 0; i < m; i++) {
    eprintf("%d%c", rev[i], " \n" [i == m - 1]);
  }*/
  assert(m > 1);
  ll rescycle = lINF;
  vector<int> curperm = rev;
  for (int it = 0; it < 2; it++) {
    /*eprintf("curperm: \n");
    for (int i = 0; i < m; i++) {
      eprintf("%d%c", curperm[i], " \n"[i == m - 1]);
    }*/
    vector<int> now(m);
    int curres = 0;
    for (int i = 0; i < m; i++) {
      now[i] = i;
    }
    for (int i = 0; curperm[i] != 0; i++) {
      curres++;
      swap(now[i], now[i + 1]);
    }
    int diff = -1;
    /*for (int i = 0; i < m; i++) {
      eprintf("%d%c", now[i], " \n" [i == m - 1]);
    }*/
    for (int j = 0; j < m; j++) {
      if (now[j] != 0) {
        int curdiff = ((now[j] - curperm[j]) % (m - 1) + (m - 1)) % (m - 1);
        if (diff != -1 && curdiff != diff) {
          printf("-1\n");
          return;
        }
        diff = curdiff;
      }
    }
    //eprintf("diff = %d\n", diff);
    rescycle = min(rescycle, curres + (ll) (min(diff, m - 1 - diff)) * m);
    for (int i = 0; i < m; i++) {
      int j = !i ? 0 : (m - i);
      curperm[i] = rev[j] ? (m - rev[j]) : 0;
    }
  }
  if (ends[0] > ends[1]) {
    swap(ends[0], ends[1]);
  }
  printf("%d %d " LLD "\n", ends[0] + 1, ends[1] + 1, rescycle + res);
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
    break;
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}