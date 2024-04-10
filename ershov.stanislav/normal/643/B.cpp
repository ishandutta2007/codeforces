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

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9 + 100;
const ld eps = 1e-11;
const ld pi = acos(-1.0L); 

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

unsigned rdtsc() {
  unsigned ans;
  asm("rdtsc" : "=a"(ans));
  return ans;
}

int rnd(int x) {
  return myrand() % x;
}

void precalc() {
}

int n, k;
int a, b, c, d;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%d%d%d%d", &a, &b, &c, &d);
  return true;
}

void solve() {
  if (n <= 4 || k < n + 1) {
    printf("-1\n");
    return;
  }
  vector<int> path;
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) {
      path.pb(i);
    }
  }
  printf("%d %d ", a, c);
  for (int i = 0; i < sz(path); i++) {
    printf("%d ", path[i]);
  }
  printf("%d %d\n", d, b);
  printf("%d %d ", c, a);
  for (int i = 0; i < sz(path); i++) {
    printf("%d ", path[i]);
  }
  printf("%d %d\n", b, d);
}

int main() {
  srand(rdtsc());
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