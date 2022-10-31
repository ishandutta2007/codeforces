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

const int maxn = (int) 2e5 + 100;

int n, a, b, k;
char s[maxn];

bool read() {
  if (scanf("%d%d%d%d%s", &n, &a, &b, &k, s) < 4) {
    return false;
  }
  return true;
}

void solve() {
  int last = -1;
  vector<int> good;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      last = i;
    }
    if (i - last == b) {
      cnt++;
      last = i;
      good.pb(i);
    }
  }
  vector<int> ans;
  while (cnt >= a) {
    ans.pb(good.back());
    good.pop_back();
    cnt--;
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
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