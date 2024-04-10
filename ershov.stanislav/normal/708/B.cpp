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

int a00, a01, a10, a11;

bool read() {
  if (scanf("%d%d%d%d", &a00, &a01, &a10, &a11) < 4) {
    return false;
  }
  return true;
}

int getcnt(ll val) {
  ll l = 1, r = 1e9;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (mid * (mid - 1) / 2 < val) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (l == 1) {
    l = 0;
  }
  return l;
}

void solve() {
  if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
    printf("0\n");
    return;
  }
  int cnt0 = 0, cnt1 = 0;
  cnt0 = getcnt(a00), cnt1 = getcnt(a11);
  if (a01 != 0 || a10 != 0) {
    cnt0 = max(cnt0, 1);
    cnt1 = max(cnt1, 1);
  }
  if (cnt0 * (cnt0 - 1) / 2 != a00 || cnt1 * (cnt1 - 1) / 2 != a11) {
    printf("Impossible\n");
    return;
  }
  if (cnt0 * cnt1 != a01 + a10) {
    printf("Impossible\n");
    return;
  }
  if (cnt0 == 0) {
    for (int i = 0; i < cnt1; i++) {
      printf("1");
    }
    printf("\n");
    return;
  }
  int f = a10 / cnt0;
  for (int i = 0; i < f; i++) {
    printf("1");
    cnt1--;
  }
  int r = a10 % cnt0;
  for (int i = 0; i < cnt0 - r; i++) {
    printf("0");
  }
  if (r) {
    printf("1");
    cnt1--;
  }
  for (int i = 0; i < r; i++) {
    printf("0");
  }
  while (cnt1) {
    printf("1");
    cnt1--;
  }
  printf("\n");
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