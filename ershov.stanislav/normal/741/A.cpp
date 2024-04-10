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

const int maxn = 1100;

int n;
int c[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
    c[i]--;
  }
  return true;
}

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int used[maxn];

void solve() {
  memset(used, 0, sizeof(used));
  ll l = 1;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    int cur = i;
    int cnt = 0;
    while (!used[cur]) {
      used[cur] = 1;
      cur = c[cur];
      cnt++;
    }
    if (cur != i) {
      printf("-1\n");
      return;
    }
    l = l / gcd(l, cnt) * cnt;
  }
  if (!(l & 1)) {
    l /= 2;
  }
  printf("%lld\n", l);
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}