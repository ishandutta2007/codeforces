#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const ld EPS = 1e-12;
const ld PI = acos(-1.0L); 

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

unsigned int rdtsc() {
  unsigned int ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

const int maxn = (int) 1e5 + 100;
int n, m;
int u[maxn], v[maxn];
vector<vector<int> > graph;
vector<int> sorted;
int used[maxn], maxu;

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", u + i, v + i);
    u[i]--, v[i]--;
  }
  return true;
}

void topsort(int v) {
  if (used[v] == maxu) {
    return;
  }
  used[v] = maxu;
  for (int i = 0; i < sz(graph[v]); i++) {
    topsort(graph[v][i]);
  }
  sorted.pb(v);
}

void solve() {
  int l = 0, r = m + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    graph = vector<vector<int> > (n);
    for (int i = 0; i < mid; i++) {
      graph[u[i]].pb(v[i]);
    }
    sorted.clear();
    maxu++;
    for (int i = 0; i < n; i++) {
      topsort(i);
    }
    bool ok = true;
    for (int i = 1; i < n; i++) {
      int a = sorted[i], b = sorted[i - 1];
      bool curok = false;
      for (int j = 0; j < sz(graph[a]); j++) {
        if (graph[a][j] == b) {
          curok = true;
          break;
        }
      }
      if (!curok) {
        ok = false;
        break;
      }
    }
    if (ok) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l == m + 1) {
    printf("-1\n");
  } else {
    printf("%d\n", l);
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
#ifdef DEBUG
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}