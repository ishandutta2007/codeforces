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

const int maxn = 1000;
int n;
int p[maxn];
char s[maxn];

char vowels[maxn] = "aeiouy";

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  return true;
}

void solve() {
  scanf("\n");
  bool ok = true;
  for (int i = 0; i < n; i++) {
    fgets(s, 1000, stdin);
    int cnt = 0;
    for (int j = 0; s[j]; j++) {
      if (find(vowels, vowels + 6, s[j]) != vowels + 6) {
        cnt++;
      }
    }
    if (cnt != p[i]) {
      ok = false;
    }
  }
  printf(ok ? "YES\n" : "NO\n");
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