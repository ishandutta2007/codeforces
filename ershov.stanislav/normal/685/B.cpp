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

const int maxn = 5e5;

int n, q;
vector<vector<int> > tree;
int cnt[maxn];
int go[maxn][20];
int mx[maxn];

bool read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  tree = vector<vector<int> > (n);
  for (int i = 0; i < n - 1; i++) {
    int p;
    scanf("%d", &p);
    p--;
    tree[p].pb(i + 1);
  }
  return true;
}

void dfs(int v) {
  cnt[v] = 1;
  go[v][0] = v;
  int curmx = 0;
  for (int i = 0; i < sz(tree[v]); i++) {
    dfs(tree[v][i]);
    cnt[v] += cnt[tree[v][i]];
    if (cnt[tree[v][i]] > curmx) {
      curmx = cnt[tree[v][i]];
      go[v][0] = tree[v][i];
    }
  }
  mx[v] = curmx;
}

void solve() {
  dfs(0);
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n; j++) {
      go[j][i] = go[go[j][i - 1]][i - 1];
    }
  }
  for (int t = 0; t < q; t++) {
    int v;
    scanf("%d", &v);
    v--;
    int need = cnt[v] / 2;
    for (int i = 19; i >= 0; i--) {
      if (mx[go[v][i]] > need) {
        v = go[v][i];
      }
    }
    if (mx[v] > need) {
      v = go[v][0];
    }
    printf("%d\n", v + 1);
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