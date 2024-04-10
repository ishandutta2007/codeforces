#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 105;
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int ok[maxn];

void solve() {
  if (!a[0]) {
    printf("-1\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    ok[i] = false;
  }
  ok[0] = true;
  vector< pair<int, int> > ans;
  int p = 0;
  for (int i = 1; i < n; i++) {
    if (a[i]) {
      ans.push_back(make_pair(p, i));
      a[p]--;
      ok[i] = true;
      p = i;
    }
  }
  for (int i = 0, j = 0; i < n; i++) {
    if (ok[i]) {
      continue;
    }
    while (j < n && !a[j]) {
      j++;
    }
    if (j >= n) {
      printf("-1\n");
      return;
    }
    ans.push_back(make_pair(j, i));
    a[j]--;
    ok[i] = true;
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}