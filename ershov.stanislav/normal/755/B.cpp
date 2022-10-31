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

const int maxn = 1100;

int n, m;
set<string> s1, s2;
char s[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  s1.clear(), s2.clear();
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    s1.insert(string(s));
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    s2.insert(string(s));
  }
  return true;
}

void solve() {
  int c = 0;
  for (auto str : s1) {
    if (s2.find(str) != s2.end()) {
      n--, m--;
      c++;
    }
  }
  for (int i = 0; ; i++) {
    if (c) {
      c--;
    } else {
      if (!(i & 1)) {
        if (n == 0) {
          printf("NO\n");
          return;
        } else {
          n--;
        }
      } else {
        if (m == 0) {
          printf("YES\n");
          return;
        } else {
          m--;
        }
      }
    }
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