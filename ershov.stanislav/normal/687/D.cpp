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

const int maxn = 1010;
const int maxm = 5e5 + 10;
int n, m, q;
int par[maxn], col[maxn];
int rk[maxn];
int a[maxm], b[maxm];
pair<int, int> tosort[maxm];

bool read() {
  
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    a--, b--;
    tosort[i] = mp(w, i);
    ::a[i] = a, ::b[i] = b;
  }
  /*n = 1000;
  m = n * (n - 1) / 2;
  q = 1000;
  int i = 0;
  for (int a = 0; a < n; a++) {
    for (int b = a + 1; b < n; b++) {
      int w = rnd(1e9);
      tosort[i] = mp(w, i);
      ::a[i] = a, ::b[i] = b;
      i++;
    }
  }*/
  return true;
}

int getpar(int v) {
  if (par[v] == v) {
    return v;
  } else {
    int res = getpar(par[v]);
    col[v] = col[v] ^ col[par[v]];
    return par[v] = res;
  }
}

void solve() {
  sort(tosort, tosort + m);
  reverse(tosort, tosort + m);
  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    for (int j = 0; j < n; j++) {
      par[j] = j;
      col[j] = 0;
    }
    int res = -1;
    for (int j = 0; j < m; j++) {
      int cur = tosort[j].second;
      if (cur < l || cur >= r) {
        continue;
      }
      int u = getpar(a[cur]), v = getpar(b[cur]);
      if (u == v) {
        if (col[a[cur]] == col[b[cur]]) {
          res = tosort[j].first;
          break;
        }
      } else {
        par[v] = u;
        col[v] = 1 ^ col[a[cur]] ^ col[b[cur]];
      }
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