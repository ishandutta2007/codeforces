#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int myrand() {
#ifdef _WIN32
  return abs((rand() << 15) ^ rand());
#else
  return rand();
#endif
}

ll rdtsc() {
  ll ans;
  asm("rdtsc" : "=A"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = 2e6;
int n, m;
int used[maxn], maxu, cols[maxn], a[maxn];
vector<vector<int> > graph, revgraph;
vector<int> sorted;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n * m; i++) {
    scanf("%d", a + i);
  }
  return true;
}

void dfs(int v) {
  if (used[v] == maxu) {
    return;
  }
  used[v] = maxu;
  for (int i = 0; i < sz(graph[v]); i++) {
    dfs(graph[v][i]);
  }
  sorted.pb(v);
}

void makecols(int v, int col) {
  if (used[v] == maxu) {
    return;
  }
  used[v] = maxu;
  cols[v] = col;
  for (int i = 0; i < sz(revgraph[v]); i++) {
    makecols(revgraph[v][i], col);
  }
}

void solve() {
  graph = revgraph = vector<vector<int> > (n * m);
  for (int i = 0; i < n; i++) {
    vector<pair<int, int> > v;
    for (int j = 0; j < m; j++) {
      v.eb(a[i * m + j], i * m + j);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < sz(v) - 1; i++) {
      graph[v[i].second].pb(v[i + 1].second);
      if (v[i].first == v[i + 1].first) {
        graph[v[i + 1].second].pb(v[i].second);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    vector<pair<int, int> > v;
    for (int j = 0; j < n; j++) {
      v.eb(a[j * m + i], j * m + i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < sz(v) - 1; i++) {
      graph[v[i].second].pb(v[i + 1].second);
      if (v[i].first == v[i + 1].first) {
        graph[v[i + 1].second].pb(v[i].second);
      }
    }
  }
  for (int i = 0; i < n * m; i++) {
    for (int j = 0; j < sz(graph[i]); j++) {
      revgraph[graph[i][j]].pb(i);
    }
  }
  maxu++;
  sorted.clear();
  for (int i = 0; i < n * m; i++) {
    dfs(i);
  }
  maxu++;
  int cntcols = 0;
  for (int i = n * m - 1; i >= 0; i--) {
    int v = sorted[i];
    if (used[v] != maxu) {
      makecols(v, cntcols++);
    }
  }
  vector<vector<int> > graphcols = vector<vector<int> > (cntcols);
  for (int i = 0; i < n * m; i++) {
    for (int j = 0; j < sz(revgraph[i]); j++) {
      int a = cols[i], b = cols[revgraph[i][j]];
      if (a != b) {
        graphcols[a].pb(b);
      }
    }
  }
  vector<int> dp(cntcols, 1);
  for (int i = 0; i < cntcols; i++) {
    for (int j = 0; j < sz(graphcols[i]); j++) {
      dp[i] = max(dp[i], dp[graphcols[i][j]] + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d%c", dp[cols[i * m + j]], " \n"[j == m - 1]);
    }
  }
}

int main() {
  srand(rdtsc());
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (true) {
    if (!read()) {
      break;
    }
    solve();
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}