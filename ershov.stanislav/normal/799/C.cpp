#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define sz(s) ((int) ((s).size()))

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef long double ld;

const int inf = (int) 1.01e9;
const ld eps = 1e-11;
const ld pi = acos(-1.0L);

mt19937 mrand(random_device{} ());
int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 1e5 + 100;

int n;
int have[2];
vector<pair<int, int> > a[2];

bool read() {
  if (scanf("%d%d%d", &n, have, have + 1) < 2) {
    return false;
  }
  a[0].clear();
  a[1].clear();
  for (int i = 0; i < n; i++) {
    int b, p;
    char c;
    scanf("%d%d %c", &b, &p, &c);
    if (c == 'C') {
      a[0].pb(mp(p, b));
    } else {
      a[1].pb(mp(p, b));
    }
  }
  return true;
}

int fenw[maxn];

void add(int i, int val) {
  for (; i < maxn; i |= (i + 1)) {
    fenw[i] = max(fenw[i], val);
  }
}

int get(int i) {
  int res = -inf;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res = max(res, fenw[i]);
  }
  return res;
}

void solve() {
  int res = 0;
  vector<int> best(2, -inf);
  for (int it = 0; it < 2; it++) {
    for (int i = 0; i < sz(a[it]); i++) {
      if (a[it][i].first <= have[it]) {
        best[it] = max(best[it], a[it][i].second);
      }
    }
    for (int i = 0; i < maxn; i++) {
      fenw[i] = -inf;
    }
    for (auto i : a[it]) {
      if (i.first <= have[it]) {
        res = max(res, i.second + get(have[it] - i.first));
        add(i.first, i.second);
      }
    }
  }
  res = max(res, best[0] + best[1]);
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen("text.in", "r", stdin));
  assert(freopen("text.out", "w", stdout));
#endif

  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time: %.3f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}