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
typedef double ld;

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

struct comp {
  ld x, y;

  comp(ld x = 0, ld y = 0) : x(x), y(y) {}

  comp operator+(const comp & b) const {
    return comp(x + b.x, y + b.y);
  }

  comp operator-(const comp & b) const {
    return comp(x - b.x, y - b.y);
  }

  comp operator*(const comp & b) const {
    return comp(x * b.x - y * b.y, x * b.y + y * b.x);
  }
};

namespace FFT {
  const int maxn = 1 << 20;

  int rev[maxn], n, logn;
  comp a[maxn];
  comp w[maxn];

  int wasn = -1;

  void fft(comp * a) {
    if (wasn != n) {
      wasn = n;
      rev[0] = 0;
      comp tomult;
      w[1] = 1;
      for (int i = 1, j = -1; i < n; i++) {
        if (!(i & (i - 1))) {
          j++;
          tomult = comp(cos(pi / 2 / i), sin(pi / 2 / i));
        }
        if (i < n / 2) {
          w[i * 2] = w[i];
          w[i * 2 + 1] = w[i] * tomult;
        }
        rev[i] = rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j));
      }
    }

    for (int i = 0; i < n; i++) {
      if (rev[i] < i) {
        swap(a[i], a[rev[i]]);
      }
    }

    for (int i0 = 1, pos = 1; i0 < n; i0 <<= 1) {
      for (int i = 0; i < n; i += i0) {
        for (int j = i + i0, it = 0; it < i0; it++, j++, i++) {
          comp toadd = a[j] * w[pos + it];
          a[j] = a[i] - toadd;
          a[i] = a[i] + toadd;
        }
      }
      pos += i0;
    }
  }

  int mult(int n1, double * a1, int n2, double * a2, double * res) {
    if ((ll) n1 * n2 < 1000) {
      for (int i = 0; i < n1 + n2 - 1; i++) {
        res[i] = 0;
      }
      for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
          res[i + j] += a1[i] * a2[j];
        }
      }
      return n1 + n2 - 1;
    }
    for (n = 1, logn = 0; n < n1 + n2 - 1; n <<= 1, logn++);

    for (int i = 0; i < n; i++) {
      a[i].x = (i < n1) ? a1[i] : 0;
      a[i].y = (i < n2) ? a2[i] : 0;
    }
    fft(a);
    for (int i = 0; i <= n - i; i++) {
      int j = i ? (n - i) : 0;
      auto c = a[i] * a[i], d = a[j] * a[j];
      a[i] = comp((c + d).y / 4, (d - c).x / 4);
      a[j] = comp(a[i].x, -a[i].y);
    }
    reverse(a + 1, a + n);
    fft(a);
    for (int i = 0; i < n1 + n2 - 1; i++) {
      res[i] = a[i].x / n;
    }
    return (n1 + n2 - 1);
  }
};

const int maxn = 1e5 + 100;
int n, m, q;
vector<vector<int> > g;
int cols[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  g.clear();
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  return true;
}

int dp[maxn];
vector<vector<int> > dps;
vector<vector<double> > vecs;

void dfs1(int v, int par) {
  cols[v] = sz(dps) - 1;
  dp[v] = 0;
  for (auto to : g[v]) {
    if (to == par) {
      continue;
    }
    dfs1(to, v);
    dp[v] = max(dp[v], dp[to] + 1);
  }
}

void dfs2(int v, int par, int up = 0) {
  vector<int> pref(sz(g[v]));
  vector<int> suf(sz(g[v]));
  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];
    if (to == par) {
      continue;
    }
    pref[i] = 2 + dp[to];
    suf[i] = 2 + dp[to];
  }
  for (int i = 1; i < sz(g[v]); i++) {
    pref[i] = max(pref[i], pref[i - 1]);
  }
  for (int i = sz(g[v]) - 2; i >= 0; i--) {
    suf[i] = max(suf[i], suf[i + 1]);
  }
  dps.back().pb(max(up, dp[v]));
  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];
    if (to == par) {
      continue;
    }
    int cur = up + 1;
    if (i) {
      cur = max(cur, pref[i - 1]);
    }
    if (i + 1 < sz(g[v])) {
      cur = max(cur, suf[i + 1]);
    }
    dfs2(to, v, cur);
  }
}

double tmpa[maxn], tmpb[maxn], tmpans[maxn * 2];

void solve() {
  memset(cols, -1, sizeof(cols));
  for (int i = 0; i < n; i++) {
    if (cols[i] != -1) {
      continue;
    }
    dps.pb(vector<int> ());
    dfs1(i, -1);
    dfs2(i, -1);
    int mx = 0;
    for (auto j : dps.back()) {
      mx = max(mx, j);
    }
    vecs.pb(vector<double> (mx + 1));
    for (auto j : dps.back()) {
      vecs.back()[j] += 1 / (ld) sz(dps.back());
    }
  }
  map<pair<int, int>, double> mem;
  for (int it = 0; it < q; it++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    if (cols[u] == cols[v]) {
      printf("-1\n");
      continue;
    }
    int a = cols[u], b = cols[v];
    if (sz(vecs[a]) > sz(vecs[b])) {
      swap(a, b);
    }
    auto curtype = mp(a, b);
    if (mem.find(curtype) != mem.end()) {
      printf("%.18f\n", mem[curtype]);
      continue;
    }
    double res = 0;
    for (int i = 0; i < sz(vecs[a]); i++) {
      tmpa[i] = vecs[a][i];
    }
    for (int i = 0; i < sz(vecs[a]); i++) {
      tmpb[i] = vecs[b][i + sz(vecs[b]) - sz(vecs[a])];
    }
    int cursize = FFT::mult(sz(vecs[a]), tmpa, sz(vecs[a]), tmpb, tmpans);
    double sum = 0;
    for (int i = sz(vecs[a]) - 1; i < cursize; i++) {
      sum += tmpans[i];
      res += tmpans[i] * (i + sz(vecs[b]) - sz(vecs[a]) + 1);
    }
    res += (1 - sum) * (sz(vecs[b]) - 1);
    mem[curtype] = res;
    printf("%.18f\n", res);
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