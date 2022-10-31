#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define sz(s) ((int) ((s).size()))

#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-12;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

int n, m, k;
vector<vector<int> > graph;

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  graph = vector<vector<int> > (n);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  return true;
}

void solve() {
  int cntcols = 0;
  int mx = 0;
  vector<int> cnt(n);
  vector<int> cols(n);
  vector<int> left;
  for (int i = 1; i < n; i++) {
    left.pb(i);
  }
  while (sz(left)) {
    queue<int> q;
    q.push(left[0]);
    while (sz(q)) {
      int cur = q.front();
      q.pop();
      cols[cur] = cntcols;
      for (auto i : graph[cur]) {
        cnt[i]++;
      }
      mx++;
      vector<int> nleft;
      for (auto i : left) {
        if (cnt[i] == mx) {
          nleft.pb(i);
        } else {
          q.push(i);
        }
      }
      left = nleft;
    }
    cntcols++;
  }
  vector<int> connected(cntcols);
  vector<int> connected2(n, 1);
  for (auto i : graph[0]) {
    connected2[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    if (connected2[i]) {
      connected[cols[i]] = 1;
    }
  }
  bool ok = true;
  for (int i = 0; i < cntcols; i++) {
    ok &= connected[i];
  }
  if (ok && n - 1 - sz(graph[0]) >= k && k >= cntcols) {
    printf("possible\n");
  } else {
    printf("impossible\n");
  }
}

int main() {
  srand(rdtsc());
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