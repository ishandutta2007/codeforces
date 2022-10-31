#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

const int maxn = 5e5 + 100;
int n, m;
int lens[maxn];
vector<vector<int> > a;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  a = vector<vector<int> > (n);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    a[i].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &a[i][j]);
    }
    lens[i] = k;
  }
  return true;
}

void solve() {
  vector<vector<pair<int, int> > > v(m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(a[i]); j++) {
      v[a[i][j]].pb(mp(i, j));
    }
  }
  for (int it = 1; it <= m; it++) {
    auto & b = v[it];
    vector<int> last(sz(b), sz(b));
    for (int d = 2; d <= 40; d++) {
      int j = sz(b);
      int was = -1;
      int l = sz(b);
      for (int i = sz(b) - 1; i >= 0; i--) {
        if (lens[b[i].first] % d == 0) {
          if (b[i].second % d != was) {
            j = l;
            was = b[i].second % d;
          }
          l = i;
        }
        last[i] = min(last[i], j);
      }
    }
    int res = 0;
    for (int i = 0; i < sz(b); ) {
      int i0 = i;
      while (i + 1 < sz(b) && b[i].first == b[i + 1].first - 1) {
        i++;
      }
      for (int j = i0; j <= i; j++) {
        int l = min(last[j], i + 1);
        res = max(res, l - j);
      }
      i++;
    }
    printf("%d\n", res);
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