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

const int maxn = 1e5 + 100;

int n;
int go[2 * maxn];
int col[2 * maxn];
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", a + i, b + i);
    a[i]--, b[i]--;
    go[a[i]] = b[i];
    go[b[i]] = a[i];
  }
  return true;
}

void solve() {
  memset(col, -1, sizeof(col));
  for (int i = 0; i < 2 * n; i++) {
    if (col[i] != -1) {
      continue;
    }
    int cur = i;
    while (col[cur] == -1) {
      col[cur] = 0;
      cur = go[cur];
      assert(col[cur] == -1);
      col[cur] = 1;
      cur = cur ^ 1;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", col[a[i]] + 1, col[b[i]] + 1);
  }
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