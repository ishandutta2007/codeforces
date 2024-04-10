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

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int sum(int x, int y) {
  add(x, y);
  return x;
}

int mult(int x, int y) {
  return (ll) x * y % mod;
}

int power(int x, ll p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

void precalc() {
}

int n, k, m;
vector<vector<pair<int, int> > > g;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  g.clear();
  n += 2;
  g.resize(n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a].pb(mp(b, c));
  }
  return true;
}

const int maxn = 85;

int dp[maxn][maxn][maxn];
int ndp[maxn][maxn][maxn];

void solve() {
  memset(dp, 0, sizeof(dp));
  for (int it = 0; it < k - 1; it++) {
    for (int l = 0; l < n; l++) {
      for (int mid = l + 1; mid < n; mid++) {
        for (int r = mid + 1; r < n; r++) {
          int &cur = ndp[l][mid][r];
          cur = inf;
          for (auto to : g[mid]) {
            if (to.first <= l) {
              continue;
            }
            if (to.first >= r) {
              continue;
            }
            if (to.first < mid) {
              cur = min(cur, to.second + dp[l][to.first][mid]);
            } else if (to.first > mid) {
              cur = min(cur, to.second + dp[mid][to.first][r]);
            }
          }
        }
      }
    }
    swap(dp, ndp);
  }
  int mn = inf;
  for (int it = 1; it < n - 1; it++) {
    mn = min(mn, dp[0][it][n - 1]);
  }
  if (mn < inf) {
    printf("%d\n", mn);
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