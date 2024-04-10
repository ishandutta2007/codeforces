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
int y[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", y + i);
  }
  return true;
}

void solve() {
  set<int> all;
  for (int i = 0; i < n; i++) {
    all.insert(y[i]);
  }
  while (true) {
    int curmx = *all.rbegin();
    curmx /= 2;
    while (all.count(curmx) && curmx >= 1) {
      curmx /= 2;
    }
    if (curmx == 0) {
      break;
    }
    all.erase(*all.rbegin());
    all.insert(curmx);
  }
  vector<int> toprint;
  for (auto i : all) {
    toprint.pb(i);
  }
  for (int i = 0; i < sz(toprint); i++) {
    printf("%d%c", toprint[i], " \n"[i == sz(toprint) - 1]);
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