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

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int cur = 10000;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    int t;
    string s;
    cin >> t >> s;
    if (cur == 10000 && s != "South") {
      ok = false;
    }
    if (cur == -10000 && s != "North") {
      ok = false;
    }
    if (s == "North") {
      cur += t;
    }
    if (s == "South") {
      cur -= t;
    }
    if (cur > 10000 || cur < -10000) {
      ok = false;
    }
  }
  if (cur != 10000) {
    ok = false;
  }
  printf(ok ? "YES\n" : "NO\n");
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