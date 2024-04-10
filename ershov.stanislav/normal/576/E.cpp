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

const int maxn = (int) 5e5 + 100;
const int maxk = (int) 55;
int n, m, k, q;
int a[maxn], b[maxn];
int rk[maxk][maxn], pr[maxk][maxn], cost[maxk][maxn];
vector<pair<int *, int> > was;
int e[maxn], c[maxn], where[maxn];
vector<int> when[maxn];
vector<vector<int> > todo;

void totime(int t) {
  while (sz(was) > t) {
    *(was.back().first) = was.back().second;
    was.pop_back();
  }
}

int getpar(int v, int c, int & len) {
  if (pr[c][v] == v) {
    return v;
  } else {
    len ^= cost[c][v];
    return getpar(pr[c][v], c, len);
  }
}

void myUnion(int a, int b, int c) {
  int len1 = 0, len2 = 0;
  a = getpar(a, c, len1), b = getpar(b, c, len2);
  if (a == b) {
    return;
  }
  if (rk[c][a] == rk[c][b]) {
    was.eb(rk[c] + a, rk[c][a]);
    rk[c][a]++;
  }
  if (rk[c][a] < rk[c][b]) {
    swap(a, b);
  }
  was.eb(pr[c] + b, pr[c][b]);
  pr[c][b] = a;
  was.eb(cost[c] + b, cost[c][b]);
  cost[c][b] = len1 ^ len2 ^ 1;
}

void precalc() {
  for (int i = 0; i < maxk; i++) {
    for (int j = 0; j < maxn; j++) {
      pr[i][j] = j;
    }
  }
}

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &k, &q) < 1) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    when[i] = vector<int> (1, -1);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", a + i, b + i);
    a[i]--, b[i]--;
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%d", e + i, c + i);
    e[i]--, c[i]--;
    where[i] = sz(when[e[i]]);
    when[e[i]].pb(i);
  }
  for (int i = 0; i < m; i++) {
    when[i].pb(q);
  }
  todo = vector<vector<int> >(4 * q);
  return true;
}

int ans[maxn];
int now[maxn];

void treepush(int v, int vl, int vr, int l, int r, int event) {
  if (r <= vl || vr <= l) {
    return;
  }
  if (l <= vl && vr <= r) {
    todo[v].pb(event);
  } else {
    int mid = (vl + vr) / 2;
    treepush(v * 2, vl, mid, l, r, event);
    treepush(v * 2 + 1, mid, vr, l, r, event);
  }
}

void solve(int v, int vl, int vr) {
  int t1 = sz(was);
  //eprintf("vl = %d, vr = %d\n", vl, vr);
  for (auto i : todo[v]) {
    //eprintf("a = %d, b = %d, c = %d\n", a[e[i]], b[e[i]], c[i]);
    myUnion(a[e[i]], b[e[i]], c[i]);
  } 
  if (vl == vr - 1) {
    int len1 = 0, len2 = 0;
    int cura = getpar(a[e[vl]], c[vl], len1);
    int curb = getpar(b[e[vl]], c[vl], len2);
    //eprintf("len1 = %d, len2 = %d, cura = %d, curb = %d\n", len1, len2, cura, curb);
    if ((len1 ^ len2) || cura != curb) {
      //eprintf("l = %d, r = %d, event = %d\n", vl + 1, when[e[vl]][where[vl] + 1], vl);
      treepush(1, 0, q, vl + 1, when[e[vl]][where[vl] + 1], vl);
      now[e[vl]] = vl;
      ans[vl] = 1;
    } else {
      if (now[e[vl]] != -1) {
        //eprintf("l = %d, r = %d, event = %d\n", vl + 1, when[e[vl]][where[vl] + 1], now[e[vl]]);
        treepush(1, 0, q, vl + 1, when[e[vl]][where[vl] + 1], now[e[vl]]);
      }
      ans[vl] = 0;
    }
  } else {
    int mid = (vl + vr) / 2;
    solve(v * 2, vl, mid);
    solve(v * 2 + 1, mid, vr);
  }
  totime(t1);
}

void solve() {
  memset(now, -1, sizeof(now));
  solve(1, 0, q);
  for (int i = 0; i < q; i++) {
    printf(ans[i] ? "YES\n" : "NO\n");
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}