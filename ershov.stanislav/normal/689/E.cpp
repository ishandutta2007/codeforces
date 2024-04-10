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

const int mod = (int) 1e9 + 7;
const int maxn = 2e5 + 100;

void add(int & a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mult(int a, int b) {
  return (ll) a * b % mod;
}

void precalc() {
}

int n, k;
int l[maxn], r[maxn];
int c[maxn];
int inv[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", l + i, r + i);
  }
  return true;
}

void solve() {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = mult(mod - mod / i, inv[mod % i]);
  }
  c[k] = 1;
  for (int i = k + 1; i <= n; i++) {
    c[i] = mult(c[i - 1], i);
    c[i] = mult(c[i], inv[i - k]);
  }
  vector<pair<int, int> > events;
  for (int i = 0; i < n; i++) {
    events.eb(l[i], 1);
    events.eb(r[i] + 1, -1);
  }
  sort(events.begin(), events.end());
  int ans = 0;
  for (int i = 0, cur = 0; i < sz(events); i++) {
    cur += events[i].second;
    if (cur >= k) {
      add(ans, mult(events[i + 1].first - events[i].first, c[cur]));
    }
  }
  printf("%d\n", ans);
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