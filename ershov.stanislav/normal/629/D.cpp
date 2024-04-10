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

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 1e5 + 100;
int n;
int r[maxn], h[maxn];
ll vol[maxn];
ll tree[maxn * 4];

void build() {
  memset(tree, 0, sizeof(tree));
}

void change(int v, int vl, int vr, int i, ll val) {
  if (vl == vr - 1) {
    tree[v] = max(tree[v], val);
  } else {
    int mid = (vl + vr) / 2;
    if (mid > i) {
      change(v * 2, vl, mid, i, val);
    } else {
      change(v * 2 + 1, mid, vr, i, val);
    }
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
  }
}

ll get(int v, int vl, int vr, int l, int r) {
  if (vr <= l || r <= vl) {
    return 0;
  } else if (l <= vl && vr <= r) {
    return tree[v];
  } else {
    int mid = (vl + vr) / 2;
    return max(get(v * 2, vl, mid, l, r), get(v * 2 + 1, mid, vr, l, r));
  }
}

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", r + i, h + i);
  }
  return true;
}

void solve() {
  vector<ll> vols;
  for (int i = 0; i < n; i++) {
    vol[i] = (ll) r[i] * r[i] * h[i];
    vols.pb(vol[i]);
  }
  sort(vols.begin(), vols.end());
  vols.resize(unique(vols.begin(), vols.end()) - vols.begin());
  for (int i = 0; i < n; i++) {
    vol[i] = (int) (lower_bound(vols.begin(), vols.end(), vol[i]) - vols.begin());
  }
  build();
  for (int i = 0; i < n; i++) {
    ll cur = get(1, 0, n + 1, 0, vol[i]);
    cur += vols[vol[i]];
    change(1, 0, n + 1, vol[i], cur);
  }
  ll ans = get(1, 0, n + 1, 0, n + 1);
  printf("%.18f\n", (double) ans * acos(-1.0));
}

int main() {
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