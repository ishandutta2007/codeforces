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

const int maxn = 2e5 + 100;

int n;
int p[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    p[i]--;
  }
  for (int j = 0; j < n; j++) {
    scanf("%d", b + j);
  }
  return true;
}

int used[maxn];

void solve() {
  int res = 0;
  int odd = 0;
  for (int i = 0; i < n; i++) {
    odd ^= b[i];
  }
  res += !odd;
  memset(used, 0, sizeof(used));
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    } else {
      cnt++;
      used[i] = true;
      for (int cur = p[i]; cur != i; cur = p[cur]) {
        used[cur] = true;
      }
    }
  }
  if (cnt > 1) {
    res += cnt;
  }
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
    eprintf("Time: %.18f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}