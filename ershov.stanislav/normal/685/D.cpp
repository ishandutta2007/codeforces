#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
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

void precalc() {
}

const int maxn = 1e5 + 100;

int n, k;
int x[maxn], y[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  k--;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  return true;
}

ll ans[maxn];

void solve() {
  memset(ans, 0, sizeof(ans));
  vector<int> goodx;
  for (int i = 0; i < n; i++) {
    goodx.pb(x[i]);
    goodx.pb(x[i] + k + 1);
  }
  sort(goodx.begin(), goodx.end());
  goodx.resize(unique(goodx.begin(), goodx.end()) - goodx.begin());
  vector<pair<int, int> > ps;
  for (int i = 0; i < n; i++) {
    ps.eb(x[i], y[i]);
  }
  sort(ps.begin(), ps.end());
  multiset<int> cur;
  int l = 0, r = 0;
  for (int i0 = 0; i0 < sz(goodx); i0++) {
    int i = goodx[i0];
    while (r < sz(ps) && ps[r].first <= i) {
      cur.insert(ps[r++].second);
    }
    while (l < sz(ps) && ps[l].first < i - k) {
      cur.erase(cur.lower_bound(ps[l++].second));
    }
    int curcnt = 0;
    vector<int> v1, v2;
    for (auto j : cur) {
      v1.pb(j);
      v2.pb(j + k + 1);
    }
    vector<int> v(sz(v1) + sz(v2));
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
    for (int j = 0, a = 0, b = 0; j < sz(v); j++) {
      while (a < sz(v1) && v1[a] <= v[j]) {
        curcnt++;
        a++;
      }
      while (b < sz(v2) && v2[b] <= v[j]) {
        curcnt--;
        b++;
      }
      if (curcnt) {
        ans[curcnt] += (ll) (v[j + 1] - v[j]) * (goodx[i0 + 1] - goodx[i0]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf(LLD "%c", ans[i], " \n"[i == n]);
  }
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