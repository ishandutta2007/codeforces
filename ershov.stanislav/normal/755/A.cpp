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

bool isprime[maxn];

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  for (int i = 2; i < maxn; i++) {
    isprime[i] = 1;
  }
  for (int i = 2; i * i < maxn; i++) {
    if (isprime[i]) {
      for (int j = i * i; j < maxn; j += i) {
        isprime[j] = 0;
      }
    }
  }
  for (int m = 1; m <= 1000; m++) {
    if (isprime[m * n + 1]) {
      continue;
    }
    printf("%d\n", m);
    return;
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