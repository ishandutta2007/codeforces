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

const ll lINF = 1e18;
const ll INF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = (int) 1e5 + 100;
int a[maxn], n;
vector<int> tree[maxn];
ll dp1[maxn], dp2[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
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

pair<ll, ll> add(pair<ll, ll> a, ll b) {
  if (b > a.first) {
    a.second = a.first;
    a.first = b;
  } else {
    if (b > a.second) {
      a.second = b;
    }
  }
  return a;
}

pair<ll, ll> join(pair<ll, ll> a, pair<ll, ll> b) {
  return add(add(a, b.first), b.second);
}

void getmx(int v, int par = -1) {
  ll & ans1 = dp1[v], & ans2 = dp2[v];
  ans1 = 0, ans2 = 0;
  pair<ll, ll> mxs(0, 0);
  for (int i = 0; i < sz(tree[v]); i++) {
    int to = tree[v][i];
    if (to == par) {
      continue;
    }
    getmx(to, v);
    ans1 = max(ans1, dp1[to]);
    ans2 = max(ans2, dp2[to]);
    mxs = add(mxs, dp1[to]);
  }
  ans1 += a[v];
  ans2 = max(mxs.first + mxs.second + a[v], max(ans2, ans1));
}

ll ans;

void solve(int v, int par = -1, ll up1 = 0, ll up2 = 0) {
  ans = max(ans, up2 + dp2[v]);
  //eprintf("v = %d\n", v + 1);
  //eprintf("up1 = " LLD ", up2 = " LLD ", " LLD "\n", (ll) up1, (ll) up2, dp2[v]);
  int m = sz(tree[v]);
  vector<ll> pref2(m + 1, 0), suf2(m + 1, 0);
  vector<pair<ll, ll> > pref1(m + 1, mp(0, 0)), suf1(m + 1, mp(0, 0));
  for (int i = 0; i < m; i++) {
    if (tree[v][i] == par) {
      pref1[i + 1] = pref1[i];
      pref2[i + 1] = pref2[i];
      continue;
    }
    pref1[i + 1] = add(pref1[i], dp1[tree[v][i]]);
    pref2[i + 1] = max(pref2[i], dp2[tree[v][i]]);
  }
  for (int i = m - 1; i >= 0; i--) {
    if (tree[v][i] == par) {
      suf1[i] = suf1[i + 1];
      suf2[i] = suf2[i + 1];
      continue;
    }
    suf1[i] = add(suf1[i + 1], dp1[tree[v][i]]);
    suf2[i] = max(suf2[i + 1], dp2[tree[v][i]]);
  }
  for (int i = 0; i < m; i++) {
    if (tree[v][i] == par) {
      continue;
    }
    ll nup2 = up2;
    nup2 = max(nup2, pref2[i]);
    nup2 = max(nup2, suf2[i + 1]);
    pair<ll, ll> mxs = join(pref1[i], suf1[i + 1]);
    //eprintf("i = %d, mxs: " LLD " " LLD "\n", i, mxs.first, mxs.second);
    mxs = add(mxs, up1);
    nup2 = max(nup2, mxs.first + mxs.second + a[v]);
    solve(tree[v][i], v, max(up1, max(pref1[i].first, suf1[i + 1].first)) + a[v], nup2);
  }
}

int used[maxn];
#define kill mkill
bool ok;
ll kill(int from, int to, int par = -1) {
  if (from == to) {
    if (used[from]) {
      ok = false;
    }
    used[from] = 1;
    return a[from];
  }
  for (int i = 0; i < sz(tree[from]); i++) {
    int u = tree[from][i];
    if (u == par) {
      continue;
    }
    ll res = kill(u, to, from);
    if (res >= 0) {
      if (used[from]) {
        ok = false;
      }
      used[from] = 1;
      return res + a[from];
    }
  }
  return -1;
}

void solve() {
  ans = 0;
  for (int i = 0; i < 1; i++) {
    int v = i;
    ll was = ans;
    ans = 0;
    getmx(v);
    /*for (int i = 0; i < n; i++) {
      eprintf(LLD " " LLD "\n", (ll) dp1[i], (ll) dp2[i]);
      }*/
    solve(v);
    if (ans != was && i) {
      eprintf("%d " LLD " " LLD "\n", i, was, ans);
      exit(1);
    }
  }
  printf(LLD "\n", ans);
  /*ll ans2 = ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        for (int r = 0; r < n; r++) {
          ok = true;
          memset(used, 0, sizeof(used));
          ll res = kill(i, j);
          ll res2 = kill(k, r);
          if (ok) {
            if (ans < res + res2) {
              eprintf("%d %d %d %d\n", i, j, k, r);
              eprintf(LLD " " LLD "\n", res, res2);
            }
            ans = max(ans, res + res2);
          }
        }
      }
    }
  }
  assert(ans == ans2);*/
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
    //eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}