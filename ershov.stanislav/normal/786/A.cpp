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

const int maxn = 7100;

int n;
vector<int> s[2];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  s[0].clear(), s[1].clear();
  for (int it = 0; it < 2; it++) {
    int k;
    scanf("%d", &k);
    s[it].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &s[it][j]);
    }
  }
  return true;
}

int dp[2][maxn];
int deg[2][maxn];

void solve() {
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  dp[1][0] = 0;
  vector<pair<int, int> > q;
  q.pb(mp(0, 0));
  q.pb(mp(1, 0));
  for (int l = 0; l < sz(q); l++) {
    int t = q[l].first;
    int i = q[l].second;
    for (auto step : s[!t]) {
      int prev = ((i - step) % n + n) % n;
      if (dp[!t][prev] != -1) {
        continue;
      }
      if (!dp[t][i]) {
        dp[!t][prev] = 1;
        q.pb(mp(!t, prev));
      } else {
        deg[!t][prev]++;
        if (deg[!t][prev] == sz(s[!t])) {
          dp[!t][prev] = 0;
          q.pb(mp(!t, prev));
        }
      }
    }
  }
  for (int it = 0; it < 2; it++) {
    for (int i = 1; i < n; i++) {
      if (dp[it][i] == -1) {
        printf("Loop");
      } else if (dp[it][i] == 0) {
        printf("Lose");
      } else {
        printf("Win");
      }
      if (i + 1 < n) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
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