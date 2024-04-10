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

void precalc() {
}

const int maxn = (int) 5e5 + 100;

int n, k, s, t;
int g[maxn];
int c[maxn], v[maxn];

bool read() {
  if (scanf("%d%d%d%d", &n, &k, &s, &t) < 4) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", c + i, v + i);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", g + i);
  }
  return true;
}

void solve() {
  g[k++] = 0;
  g[k++] = s;
  sort(g, g + k);
  ll mn = 0;
  vector<pair<ll, pair<ll, ll> > > events;
  for (int i = 1; i < k; i++) {
    ll curdist = g[i] - g[i - 1];
    mn = max(mn, curdist);
    events.pb(mp(curdist, mp((ll) -1, 3 * curdist)));
    events.pb(mp(curdist * 2, mp((ll) 1, -3 * curdist)));
    events.pb(mp(curdist * 2, mp((ll) 0, curdist)));
  }
  sort(events.begin(), events.end());
  vector<pair<int, int> > tosort;
  for (int i = 0; i < n; i++) {
    tosort.pb(mp(v[i], i));
  }
  sort(tosort.begin(), tosort.end());
  int res = inf;
  int j = 0;
  ll cura = 0, curb = 0;
  for (auto ii : tosort) {
    int i = ii.second;
    while (j < sz(events) && events[j].first <= v[i]) {
      cura += events[j].second.first;
      curb += events[j].second.second;
      j++;
    }
    if (v[i] < mn) {
      continue;
    }
    if (cura * v[i] + curb <= t) {
      res = min(res, c[i]);
    }
  }
  if (res == inf) {
    printf("-1\n");
  } else {
    printf("%d\n", res);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}