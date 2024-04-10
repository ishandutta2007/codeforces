#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}


void precalc() {
}

const int maxn = 2e5 + 100;
int n, m, k;
int c[maxn];
int mask[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    mask[i] = 0;
  }
  int a;
  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    int cur;
    scanf("%d", &cur);
    cur--;
    mask[cur] |= 1;
  }
  int b;
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    int cur;
    scanf("%d", &cur);
    cur--;
    mask[cur] |= 2;
  }
  return true;
}

int fenw[maxn];
ll fenwc[maxn];

void add(int i, int val) {
  for (; i < maxn; i |= (i + 1)) {
    fenw[i] += val;
  }
}

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fenw[i];
  }
  return res;
}

void addc(int i, int val) {
  for (; i < maxn; i |= (i + 1)) {
    fenwc[i] += val;
  }
}

ll getc(int i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fenwc[i];
  }
  return res;
}

int where[maxn];

int cntall;
ll all;

void alive(int i) {
  all -= c[i];
  cntall--;
  add(where[i], 1);
  addc(where[i], c[i]);
}

void dead(int i) {
  //eprintf("dead %d\n", i);
  all += c[i];
  cntall++;
  add(where[i], -1);
  addc(where[i], -c[i]);
}

ll getk() {
  if (m < cntall) {
    return 1e18;
  }
  int l = -1, r = maxn;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (get(mid - 1) >= m - cntall) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return getc(r - 1) + all;
}

void solve() {
  if (m < k) {
    printf("-1\n");
    return;
  }
  memset(fenw, 0, sizeof(fenw));
  memset(fenwc, 0, sizeof(fenwc));
  vector<pair<int, int> > tosort;
  vector<pair<int, int> > v[4];
  for (int i = 0; i < n; i++) {
    v[mask[i]].pb(mp(c[i], i));
    tosort.pb(mp(c[i], i));
  }
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i < n; i++) {
    where[tosort[i].second] = i;
  }
  for (int it = 0; it < 4; it++) {
    sort(v[it].begin(), v[it].end());
  }
  int mn = max(max(0, k - sz(v[1])), max(0, k - sz(v[2])));
  int mx = sz(v[3]);
  if (mn > mx) {
    printf("-1\n");
    return;
  }
  all = 0;
  cntall = 0;
  for (int i = 0; i < n; i++) {
    all += c[i];
    cntall++;
    alive(i);
  }
  for (int i = 0; i < mn; i++) {
    dead(v[3][i].second);
  }
  for (int i = 0; i < k - mn; i++) {
    dead(v[1][i].second);
    dead(v[2][i].second);
  }
  ll res = 1e18;
  //eprintf("mn = %d\n", mn);
  for (int i = mn; i <= mx; i++) {
    res = min(res, getk());
    //eprintf("%lld\n", res);
    if (i < mx) {
      dead(v[3][i].second);
      if (k > i) {
        alive(v[1][k - i - 1].second);
        alive(v[2][k - i - 1].second);
      }
    }
  }
  if (res < 1e18 / 2) {
    printf("%lld\n", res);
  } else {
    printf("-1\n");
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}