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

const int maxn = 1e6 + 100;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  return true;
}

vector<vector<pair<int, int> > > graph;

void solve() {
  graph = vector<vector<pair<int, int> > > (n);
  for (int i = 0; i < n; i++) {
    if (i) {
      graph[i].eb(i - 1, 1);
    }
    if (i < n - 1) {
      graph[i].eb(i + 1, 1);
    }
  }
  for (int i = 0; i < n; i++) {
    graph[i].eb(a[i], 1);
  }
  vector<int> dist(n, inf);
  dist[0] = 0;
  set<pair<int, int> > s;
  s.insert(mp(0, 0));
  while (sz(s)) {
    int cur = s.begin()->second;
    s.erase(s.begin());
    for (int i = 0; i < sz(graph[cur]); i++) {
      int to = graph[cur][i].first;
      int ndist = dist[cur] + graph[cur][i].second;
      if (ndist < dist[to]) {
        s.erase(mp(dist[to], to));
        dist[to] = ndist;
        s.insert(mp(dist[to], to));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", dist[i], " \n" [i == n - 1]);
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