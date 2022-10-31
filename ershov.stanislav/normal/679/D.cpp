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

const int maxn = 410;
int n, m;
vector<vector<int> > graph;

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

vector<int> ondist[maxn][maxn];
int maxdist[maxn];

ld ans[maxn][maxn];
int cols[maxn][maxn];

ld vals[maxn];
int good[maxn], cntgood;

ld mx[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ondist[i][j].clear();
    }
    queue<int> q;
    vector<int> dist(n, inf);
    q.push(i);
    dist[i] = 0;
    while (sz(q)) {
      int cur = q.front();
      q.pop();
      for (int k = 0; k < sz(graph[cur]); k++) {
        int to = graph[cur][k];
        if (dist[to] == inf) {
          dist[to] = dist[cur] + 1;
          q.push(to);
        }
      }
    }
    maxdist[i] = 0;
    for (int j = 0; j < n; j++) {
      ondist[i][dist[j]].pb(j);
      cols[i][j] = dist[j];
      maxdist[i] = max(maxdist[i], dist[j]);
    }
    for (int j = 0; j <= maxdist[i] ; j++) {
      ans[i][j] = (ld) 1 / n;
    }
  }
  memset(vals, 0, sizeof(vals));
  memset(mx, 0, sizeof(mx));
  for (int fs = 0; fs < n; fs++) {
    for (int dist1 = 0; dist1 <= maxdist[fs]; dist1++) {
      for (auto i : ondist[fs][dist1]) {
        for (auto j : graph[i]) {
          vals[j] += (ld) 1 / n / sz(graph[i]);
        }
      }
      /*for (int i = 0; i < n; i++) {
        eprintf("%.18f%c", (double) vals[i], " \n"[i == n - 1]);
      }*/
      cntgood = 0;
      for (int dist = max(0, dist1 - 1); dist <= min(dist1 + 1, maxdist[fs]); dist++) {
        for (auto i : ondist[fs][dist]) {
          good[cntgood++] = i;
        }
      }
      for (int sec = 0; sec < n; sec++) {
        ld curans = 0;
        for (int i = 0; i < cntgood; i++) {
          int cur = cols[sec][good[i]];
          mx[cur] = max(mx[cur], vals[good[i]]);
        }
        for (int i = 0; i < cntgood; i++) {
          int cur = cols[sec][good[i]];
          curans += mx[cur];
          mx[cur] = 0;
        }
        ans[fs][dist1] = max(ans[fs][dist1], curans);
      }
      for (auto i : ondist[fs][dist1]) {
        for (auto j : graph[i]) {
          vals[j] = 0;
        }
      }
    }
  }
  ld res = 0;
  for (int i = 0; i < n; i++) {
    ld curres = 0;
    for (int j = 0; j <= maxdist[i]; j++) {
      //eprintf("%.18f%c", (double) ans[i][j], " \n"[j == maxdist[i]]);
      curres += ans[i][j];
    }
    res = max(res, curres);
  }
  printf("%.18f\n", (double) res);
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