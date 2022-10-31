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

const int maxn = 1e6 + 100;
int n, k;
bitset<maxn> a, b;
int p[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    p[i]--;
  }
  return true;
}

int cnt[maxn];
int used[maxn];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  memset(used, 0, sizeof(used));
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    } else {
      int cur = i;
      int curcnt = 1;
      used[cur] = 1;
      for (cur = p[cur]; cur != i; cur = p[cur]) {
        curcnt++;
        used[cur] = 1;
      }
      cnt[curcnt]++;
    }
  }
  int mx = 0;
  for (int i = 0; i <= n; i++) {
    mx += i / 2 * cnt[i];
  }
  int res2 = min(min(k, mx) * 2 + (k - min(k, mx)), n);
  a = bitset<maxn>();
  a[0] = 1;
  for (int i = 0; i <= n; i++) {
    if (!cnt[i]) {
      continue;
    }
    b = a;
    int cur = 1;
    int have = 0;
    while (cnt[i]) {
      if (cnt[i] & 1) {
        a |= (b << ((have + 1) * i));
        have += cur;
      }
      b |= (b << (cur * i));
      cur <<= 1;
      cnt[i] >>= 1;
    }
  }
  assert(a[n]);
  int res1 = k;
  if (!a[k]) {
    res1++;
  }
  printf("%d %d\n", res1, res2);
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