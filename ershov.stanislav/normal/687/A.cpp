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
int n, m;
vector<vector<int> > graph;
bool can;
int col[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  graph = vector<vector<int> > (n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  return true;
}

void dfs(int v, int c) {
  if (col[v] != -1) {
    can &= (c == col[v]);
    return;
  }
  col[v] = c;
  for (int i = 0; i < sz(graph[v]); i++) {
    int to = graph[v][i];
    dfs(to, c ^ 1);
  }
}

void solve() {
  memset(col, -1, sizeof(col));
  can = true;
  for (int i = 0; i < n; i++) {
    if (col[i] == -1) {
      dfs(i, 0);
    }
  }
  if (!can) {
    printf("-1\n");
  } else {
    vector<vector<int> > ans(2);
    for (int i = 0; i < n; i++) {
      ans[col[i]].pb(i);
    }
    for (int i = 0; i < 2; i++) {
      printf("%d\n", sz(ans[i]));
      for (int j = 0; j < sz(ans[i]); j++) {
        printf("%d%c", ans[i][j] + 1, " \n"[j == sz(ans[i]) - 1]);
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