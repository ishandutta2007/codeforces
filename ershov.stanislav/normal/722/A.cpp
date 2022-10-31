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

int n;
int a, b;

bool read() {
  if (scanf("%d%d:%d", &n, &a, &b) < 3) {
    return false;
  }
  return true;
}

void solve() {
  int a2, b2;
  int ans = 1e9;
  for (int i = 0; i < 24; i++) {
    if (n == 12) {
      if (i == 0 || i > 12) {
        continue;
      }
    }
    for (int j = 0; j < 60; j++) {
      int cnt = 0;
      if (i % 10 != a % 10) {
        cnt++;
      }
      if (i / 10 != a / 10) {
        cnt++;
      }
      if (j % 10 != b % 10) {
        cnt++;
      }
      if (j / 10 != b / 10) {
        cnt++;
      }
      if (cnt < ans) {
        ans = cnt;
        a2 = i, b2 = j;
      }
    }
  }
  printf("%02d:%02d\n", a2, b2);
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