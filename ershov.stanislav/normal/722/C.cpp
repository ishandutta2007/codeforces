#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
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

void precalc() {
}

const int maxn = 1e5 + 100;
int n;
int a[maxn], perm[maxn];
ll sums[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", perm + i);
    perm[i]--;
  }
  return true;
}

void solve() {
  set<int> s;
  s.insert(-1);
  s.insert(n);
  sums[0] = 0;
  for (int i = 0; i < n; i++) {
    sums[i + 1] = sums[i] + a[i];
  }
  multiset<ll> ms;
  ms.insert(sums[n]);
  for (int i = 0; i < n; i++) {
    auto j = s.lower_bound(perm[i]);
    int r = *j;
    int l = *(--j);
    int mid = perm[i];
    ms.erase(ms.lower_bound(sums[r] - sums[l + 1]));
    ms.insert(sums[mid] - sums[l + 1]);
    ms.insert(sums[r] - sums[mid + 1]);
    s.insert(mid);
    printf("%lld\n", *ms.rbegin());
  }
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