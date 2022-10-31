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

const int maxn = (int) 5e5 + 100;

int n;
vector<pair<int, int> > edges[2];
vector<pair<int, int> > change[2];
#define rank mrank
int pr[maxn], rank[maxn];
vector<pair<int *, int> > was;

void totime(int t) {
  while (sz(was) > t) {
    *(was.back().first) = was.back().second;
    was.pop_back();
  }
}

int getpar(int v) {
  if (pr[v] == v) {
    return v;
  } else {
    return getpar(pr[v]);
  }
}

void myUnion(int a, int b) {
  a = getpar(a);
  b = getpar(b);
  if (a == b) {
    return;
  }
  if (rank[a] == rank[b]) {
    was.eb(rank + a, rank[a]);
    rank[a]++;
  }
  if (rank[a] < rank[b]) {
    swap(a, b);
  }
  was.eb(pr + b, pr[b]);
  pr[b] = a;
}

inline void myUnion(pair<int, int> ab) {
  myUnion(ab.first, ab.second);
}

void precalc() {
  for (int i = 0; i < maxn; i++) {
    pr[i] = i;
    rank[i] = 0;
  }
}

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int it = 0; it < 2; it++) {
    edges[it] = vector<pair<int, int> >(n - 1);
    for (int i = 0; i < n - 1; i++) {
      scanf("%d%d", &edges[it][i].first, &edges[it][i].second);
      if (edges[it][i].first > edges[it][i].second) {
        swap(edges[it][i].first, edges[it][i].second);
      }
    }
  }
  return true;
}

bool solve(int vl, int vr) {
  if (vr > vl + 1) {
    int mid = (vl + vr) / 2;
    int t1 = sz(was);
    for (int i = mid; i < vr; i++) {
      myUnion(change[0][i]);
    }
    int pos = vl;
    int t2 = sz(was);
    for (int i = vl; pos < mid && i < vr; i++) {
      int a = change[1][i].first, b = change[1][i].second;
      a = getpar(a), b = getpar(b);
      if (a == b) {
        continue;
      }
      myUnion(a, b);
      swap(change[1][pos++], change[1][i]);
    }
    if (pos < mid) {
      return false;
    }
    totime(t2);
    if (!solve(vl, mid)) {
      return false;
    }
    totime(t1);
    for (int i = vl; i < mid; i++) {
      myUnion(change[1][i]);
    }
    if (!solve(mid, vr)) {
      return false;
    }
    totime(t1);
  }
  return true;
}

void solve() {
  for (int it = 0; it < 2; it++) {
    sort(edges[it].begin(), edges[it].end());
    change[!it].clear();
    for (int i = 0; i < n - 1; i++) {
      auto j = lower_bound(edges[it].begin(), edges[it].end(), edges[!it][i]);
      if (j == edges[it].end() || *j != edges[!it][i]) {
        change[!it].pb(edges[!it][i]);
      } else if (it) {
        myUnion(edges[!it][i]);
      }
    }
  }
  bool ok = solve(0, sz(change[0]));
  if (!ok) {
    assert(0);
    printf("-1\n");
  } else {
    printf("%d\n", sz(change[0]));
    for (int i = 0; i < sz(change[0]); i++) {
      printf("%d %d %d %d\n", change[0][i].first, change[0][i].second, change[1][i].first, change[1][i].second);
    }
  }
  totime(0);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}