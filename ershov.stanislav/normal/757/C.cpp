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

const int mod = 1e9 + 7;

int mult(int a, int b) {
  return (ll) a * b % mod;
}

const int maxn = 1e6 + 100;

int fact[maxn];

void precalc() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
}

int n, m;

vector<vector<pair<int, int> > > tosort;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  tosort = vector<vector<pair<int, int> > > (m);
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    int g;
    scanf("%d", &g);
    vector<int> v;
    for (int j = 0; j < g; j++) {
      int cur;
      scanf("%d", &cur);
      cur--;
      v.pb(cur);
    }
    sort(v.begin(), v.end());
    vector<pair<int, int> > v2;
    for (int j = 0; j < sz(v); ) {
      int j0 = j;
      while (j < sz(v) && v[j] == v[j0]) {
        j++;
      }
      v2.pb(mp(j - j0, v[j0]));
    }
    sort(v2.begin(), v2.end());
    int cnt = 0;
    for (int j = 0; j < sz(v2);) {
      int j0 = j;
      while (j < sz(v2) && v2[j].first == v2[j0].first) {
        j++;
      }
      for (int k = j0; k < j; k++) {
        tosort[v2[k].second].pb(mp(i, cnt));
      }
      cnt++;
    }
  }
  sort(tosort.begin(), tosort.end());
  int res = 1;
  for (int i = 0; i < m; ) {
    int i0 = i;
    while (i < m && tosort[i] == tosort[i0]) {
      i++;
    }
    res = mult(res, fact[i - i0]);
  }
  printf("%d\n", res);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}