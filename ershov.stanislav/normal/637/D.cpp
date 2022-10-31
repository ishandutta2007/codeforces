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
int n, m, s, d;
int a[maxn];

bool read() {
  if (scanf("%d%d%d%d", &n, &m, &s, &d) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  return true;
}

bool has(int val) {
  int j = (int) (lower_bound(a, a + n, val) - a);
  return j != n && a[j] == val;
}

void solve() {
  vector<int> good = {0, m};
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (!has(a[i] - 1)) {
      good.pb(a[i] - 1);
    }
    if (!has(a[i] + 1)) {
      good.pb(a[i] + 1);
    }
  }
  sort(good.begin(), good.end());
  good.resize(unique(good.begin(), good.end()) - good.begin());
  vector<int> canrun(sz(good)), jumpto(sz(good));
  for (int i = 0; i < sz(good) - 1; i++) {
    auto j = (int) (lower_bound(a, a + n, good[i]) - a);
    if (j == n || a[j] > good[i + 1]) {
      canrun[i] = 1;
    }
    if (i) {
      if (canrun[i - 1]) {
        if (good[i] - good[i - 1] >= s) {
          jumpto[i] = (int) (upper_bound(good.begin(), good.end(), good[i] + d) - good.begin());
        }
      }
    }
  }
  /*for (int i = 0; i < sz(good); i++) {
    eprintf("%d%c", good[i], " \n" [i == sz(good) - 1]);
  }
  eprintf("canrun: \n");
  for (int i = 0; i < sz(good); i++) {
    eprintf("%d%c", canrun[i], " \n" [i == sz(good) - 1]);
  }*/
  vector<int> pr(sz(good), -1), prtype(sz(good), -1);
  for (int i = 0, j = 0, k = -1; i < sz(good); i++) {
    //eprintf("%d %d\n", i, j);
    if (i < j && pr[i] == -1) {
      pr[i] = k;
      prtype[i] = 0;
    }
    if (canrun[i] && (pr[i] != -1 || i == 0)) {
      pr[i + 1] = i;
      prtype[i + 1] = 1;
    }
    if (pr[i] != -1 || i == 0) {
      if (j < jumpto[i]) {
        j = jumpto[i];
        k = i;
      }
    }
  }
  if (pr.back() == -1) {
    printf("IMPOSSIBLE\n");
  } else {
    vector<pair<string, int> > v;
    for (int i = sz(good) - 1; i > 0; i = pr[i]) {
      v.pb(mp(prtype[i] ? "RUN" : "JUMP", good[i] - good[pr[i]]));
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < sz(v); i++) {
      printf("%s %d\n", v[i].first.c_str(), v[i].second);
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
    //break;
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
  }
  return 0;
}