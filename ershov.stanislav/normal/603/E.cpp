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

const int maxn = (int) 3e5 + 100;
int n, m;
int a[maxn], b[maxn], l[maxn];
#define rank mrank
int par[maxn], rank[maxn], isodd[maxn];
vector<pair<int*, int> > st;
pair<int, int> sorted[maxn];
int ans[maxn];
int curedge;
vector<int> tree[1 << 20];
int cntodd;

void totime(int t) {
  while (sz(st) > t) {
    pair<int *, int> &cur = st.back();
    *(cur.first) = cur.second;
    st.pop_back();
  }
}

int getpar(int v) {
  if (par[v] == v) {
    return v;
  } else return getpar(par[v]);
}

void myUnion(int a, int b) {
  a = getpar(a);
  b = getpar(b);
  if (a == b) {
    return;
  }
  if (rank[a] == rank[b]) {
    st.eb(rank + a, rank[a]);
    rank[a]++;
  }
  if (rank[a] < rank[b]) {
    swap(a, b);
  }
  if (isodd[a] && isodd[b]) {
    st.eb(&cntodd, cntodd);
    cntodd -= 2;
  }
  if (isodd[b]) {
    st.eb(isodd + a, isodd[a]);
    isodd[a] ^= 1;
  }
  st.eb(par + b, par[b]);
  par[b] = a;
}

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", a + i, b + i, l + i);
    a[i]--, b[i]--;
    sorted[i] = mp(l[i], i);
  }
  return true;
}

void build(int v, int vl, int vr) {
  tree[v].clear();
  if (vl < vr - 1) {
    int mid = (vl + vr) / 2;
    build(v * 2, vl, mid);
    build(v * 2 + 1, mid, vr);
  }
}

void pushtree(int v, int vl, int vr, int l, int r, int i) {
  if (vl >= r || vr <= l) {
    return;
  }
  if (l <= vl && vr <= r) {
    tree[v].pb(i);
  } else {
    int mid = (vl + vr) / 2;
    pushtree(v * 2, vl, mid, l, r, i);
    pushtree(v * 2 + 1, mid, vr, l, r, i);
  }
}

void solve(int v, int vl, int vr) {
  int was = sz(st);
  for (auto i : tree[v]) {
    myUnion(a[i], b[i]);
  }
  if (vl == vr - 1) {
    while (curedge < m && cntodd) {
      int edge = sorted[curedge].second;
      if (edge <= vl) {
        myUnion(a[edge], b[edge]);
      }
      if (edge < vl) {
        //eprintf("push: [%d, %d)\n", edge, vl);
        pushtree(1, 0, m, edge, vl, edge);
      }
      curedge++;
    }
    if (cntodd) {
      ans[vl] = -1;
    } else {
      assert(curedge);
      ans[vl] = sorted[curedge - 1].first;
    }
  } else {
    int mid = (vl + vr) / 2;
    solve(v * 2 + 1, mid, vr);
    solve(v * 2, vl, mid);
  }
  totime(was);
}

void solve() {
  sort(sorted, sorted + m);
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 0;
    isodd[i] = 1;
  }
  curedge = 0;
  build(1, 0, m);
  cntodd = n;
  solve(1, 0, m);
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
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