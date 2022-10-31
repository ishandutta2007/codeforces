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

struct Q {
  int r, s, t, id;

  Q(int r, int s, int t, int id) : r(r), s(s), t(t), id(id) {} ;
};

int n, m, q;
const int maxn = 1100, maxm = (int) 2e5 + 100;
int v[maxm], u[maxm];
vector<vector<Q> > qs;

bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", v + i, u + i);
    v[i]--, u[i]--;
  }
  qs = vector<vector<Q> > (m);
  for (int i = 0; i < q; i++) {
    int l, r, s, t;
    scanf("%d%d%d%d", &l, &r, &s, &t);
    qs[l - 1].pb(Q(r - 1, s - 1, t - 1, i));
  }
  return true;
}

bool ans[maxm];
int dist[maxn][maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = (i == j) ? 0 : inf;
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    int a = v[i], b = u[i];
    for (int j = 0; j < n; j++) {
      if (j != b) {
        dist[a][j] = min(dist[a][j], dist[b][j]);
      } else {
        dist[a][j] = i;
      }
      if (j != a) {
        dist[b][j] = min(dist[a][j], dist[b][j]);
      } else {
        dist[b][j] = i;
      }
    }
    for (auto cur : qs[i]) {
      ans[cur.id] = (dist[cur.s][cur.t] <= cur.r);
    }
  }
  for (int i = 0; i < q; i++) {
    printf(ans[i] ? "Yes\n" : "No\n");
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